/-
The MuJoCo <-> Godot PhysicsServer3D bridge, and the two invariants that make it
safe. Proved here before the C++ is written.

Godot's PhysicsServer3D builds a world incrementally: create a body, get an
opaque RID back, add shapes and joints at runtime. MuJoCo does not work that way
-- an mjModel is compiled whole from a description and cannot grow a body
afterwards. So the bridge buffers the create/add calls, gives each body a DENSE
MuJoCo index by insertion order, and compiles the model before it steps. Two
things can go wrong, and neither can survive the proofs below:

  1. Reading the wrong body. Godot hands back an RID and expects THAT body's
     transform. If the RID -> index map aliased or drifted, Godot would read
     another body's state. We prove RIDs are unique (a fresh RID is never a live
     one) and that index <-> rid round-trips on a compiled layout.

  2. Stepping a stale model. Adding or freeing a body changes the compiled
     layout, so stepping before recompiling would read indices that no longer
     mean what the caller thinks. We prove the phase machine forbids it: create
     and free move the bridge to `dirty`, and `step` is defined only in
     `compiled`, so a step after a change is impossible until `compile` runs.

Concrete over Nat with `decide` / `native_decide` and short inductions, so it
needs no Mathlib and checks in seconds. It is the same shape as the sandbox's
other models: state the property, make it decidable, let the kernel settle it.
-/

namespace PhysicsBridge

/-! ## The RID registry

A body's MuJoCo index is its position in `bodies`, an insertion-ordered list of
live RIDs. `nextRid` hands out fresh tokens and only ever increases. -/

structure Reg where
  bodies : List Nat
  nextRid : Nat
deriving DecidableEq, Repr

def empty : Reg := ⟨[], 0⟩

/-- Create a body: mint `nextRid`, append it so its index is the old length. -/
def create (r : Reg) : Nat × Reg :=
  (r.nextRid, ⟨r.bodies ++ [r.nextRid], r.nextRid + 1⟩)

/-- The RID at a MuJoCo index, and the index of an RID: the two directions Godot
crosses every frame when it reads a body's transform back. -/
def ridAt (r : Reg) (i : Nat) : Option Nat := r.bodies[i]?
def indexOf (r : Reg) (rid : Nat) : Option Nat := r.bodies.findIdx? (· == rid)

/-! ## Freshness: a new RID never aliases a live one

`Valid` says every live RID is below the counter. It holds at the start and is
preserved by create, so the RID handed back is always distinct from every RID
already in the world -- the map can never alias. -/

def Valid (r : Reg) : Prop := ∀ x ∈ r.bodies, x < r.nextRid

theorem empty_valid : Valid empty := by
  intro x hx; simp [empty] at hx

theorem create_valid (r : Reg) (h : Valid r) : Valid (create r).2 := by
  intro x hx
  simp [create] at hx
  rcases hx with hx | hx
  · exact Nat.lt_succ_of_lt (h x hx)
  · subst hx; exact Nat.lt_succ_self _

/-- The minted RID is not already live: the map cannot alias an existing body. -/
theorem fresh_not_live (r : Reg) (h : Valid r) : (create r).1 ∉ r.bodies := by
  intro hmem
  exact Nat.lt_irrefl _ (h (create r).1 hmem)

/-! ## A dense, deterministic layout

Building `n` bodies from empty gives `bodies = [0, 1, ..., n-1]`: the index and
the RID coincide, and the layout is a pure function of the create count -- no
RID hashing, no ordering by anything but insertion. That is the determinism the
sandbox guest then carries across hosts. -/

def createN : Nat → Reg
  | 0 => empty
  | n + 1 => (create (createN n)).2

theorem createN_nextRid (n : Nat) : (createN n).nextRid = n := by
  induction n with
  | zero => rfl
  | succ k ih => simp [createN, create, ih]

theorem createN_bodies (n : Nat) : (createN n).bodies = List.range n := by
  induction n with
  | zero => rfl
  | succ k ih => simp [createN, create, ih, createN_nextRid, List.range_succ]

/-- Round-trip on a fresh run of eight bodies: the body at index i is RID i, and
the index of RID i is i. Read at the index the bridge assigned and you get back
exactly that body, never another. -/
theorem roundtrip_8 :
    (List.range 8).all
      (fun i => (ridAt (createN 8) i == some i) && (indexOf (createN 8) i == some i)) = true := by
  native_decide

/-! ## The phase machine: no stepping a stale model -/

inductive Phase where
  | building
  | compiled
  | dirty
deriving DecidableEq, Repr

structure Bridge where
  reg : Reg
  phase : Phase
deriving Repr

/-- A topology change leaves the model out of date, so both create and free move
to `dirty`. `compile` is the only way to `compiled`, and `step` runs only there. -/
def Bridge.create (b : Bridge) : Bridge :=
  ⟨(PhysicsBridge.create b.reg).2, Phase.dirty⟩

def Bridge.free (b : Bridge) (rid : Nat) : Bridge :=
  ⟨⟨b.reg.bodies.filter (· != rid), b.reg.nextRid⟩, Phase.dirty⟩

def Bridge.compile (b : Bridge) : Bridge :=
  ⟨b.reg, Phase.compiled⟩

def Bridge.step (b : Bridge) : Option Bridge :=
  match b.phase with
  | Phase.compiled => some b
  | _ => none

/-- Stepping is possible only when compiled. -/
theorem step_needs_compiled (b : Bridge) (h : b.step.isSome) : b.phase = Phase.compiled := by
  cases hp : b.phase <;> simp [Bridge.step, hp] at h ⊢

/-- A create cannot be stepped until it is compiled. -/
theorem no_step_after_create (b : Bridge) : b.create.step = none := by
  simp [Bridge.create, Bridge.step]

/-- Nor can a free: this is what stops Godot reading a shifted index. -/
theorem no_step_after_free (b : Bridge) (rid : Nat) : (b.free rid).step = none := by
  simp [Bridge.free, Bridge.step]

/-- Compiling after a create makes the world steppable again. -/
theorem compile_enables_step (b : Bridge) : (b.create.compile.step).isSome := by
  simp [Bridge.create, Bridge.compile, Bridge.step]

/-- Why the recompile is mandatory, not cosmetic: freeing the middle body of
three shifts index 1 from RID 1 to RID 2. A step on the old indices would read
the wrong body, which the phase machine above forbids. -/
theorem free_shifts_indices :
    ridAt (createN 3) 1 = some 1
    ∧ ridAt ⟨(createN 3).bodies.filter (· != 1), (createN 3).nextRid⟩ 1 = some 2 := by
  native_decide

end PhysicsBridge
