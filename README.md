# entities-godot-mujoco

MuJoCo physics for Godot as a PhysicsServer3DExtension, with MuJoCo linked natively from a subtree. Proved in Lean 4, then coded in C++.

## What this is

A Godot physics backend that implements `PhysicsServer3DExtension`, so ordinary
`RigidBody3D` and `SoftBody3D` nodes get their physics from MuJoCo. MuJoCo is
vendored as a git subtree under `third_party/mujoco` and linked directly into
this extension -- `mj_step` runs natively, in-process.

This is migrated from an earlier design that delegated stepping to a RISC-V
godot-sandbox guest. Native MuJoCo is fast, but native floating point is not
bit-identical across CPUs, so this backend is not cross-host deterministic. That
determinism story lives in the sandbox demos (`interactor-taskweft-crowd`,
`interactor-mujoco-cloth-sim`); this backend trades it for speed.

## The impedance mismatch, proved before the C++

Godot builds a world incrementally -- create a body, get an RID, add shapes at
runtime. MuJoCo compiles an `mjModel` whole from a description (here via
`mjSpec`) and cannot grow a body afterwards. So the extension accumulates the
create/add calls into an `mjSpec`, compiles the model before it steps, and
recompiles on any topology change. Two failures follow, and both are proved
impossible in `model/PhysicsBridge.lean`:

  1. **Never read the wrong body.** RIDs are unique and index <-> rid
     round-trips (`create_valid`, `fresh_not_live`, `roundtrip_8`).
  2. **Never step a stale model.** Any create or free returns the bridge to
     `dirty`; `mj_step` runs only when `compiled` (`step_needs_compiled`,
     `no_step_after_create`, `no_step_after_free`, `compile_enables_step`).

`src/mujoco_bridge.h` is that proof translated 1:1, `src/mujoco_bridge_test.cpp`
re-checks each theorem natively, and `MuJoCoPhysicsServer::recompile_if_dirty`
is where the guard runs against a real `mjSpec`.

## Layout

    model/PhysicsBridge.lean     the proof (lake build)
    src/mujoco_bridge.h          the proven core, translated to C++
    src/mujoco_bridge_test.cpp   native re-check, one assert per theorem
    src/mujoco_physics_server.*  the PhysicsServer3DExtension over native MuJoCo
    third_party/mujoco           MuJoCo 3.13.0, vendored as a subtree

## Status

Proved and verified: the bridge invariants (Lean) and their C++ core (native
test). Migrated: the backend now links native MuJoCo via `mjSpec`/`mj_compile`/
`mj_step` rather than a sandbox guest; `_body_create` builds a free body,
`_step` recompiles when dirty and steps, `_body_get_state` reads the transform
back. In progress: mapping Godot shapes/joints onto `mjSpec` geoms/joints, and
the flex (soft-body/cloth) path.

## Credit

V-Sekai-fire and chibifire.
