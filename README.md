# entities-godot-mujoco

MuJoCo physics for Godot via PhysicsServer3DExtension, delegating steps to the godot-sandbox RISC-V guest. Proved in Lean 4, then C++.

## What this is

A Godot physics backend whose simulation runs as interpreted, sandboxed
user-generated content, not a native engine. The extension implements Godot's
`PhysicsServer3DExtension`, so ordinary `RigidBody3D` and `SoftBody3D` nodes get
their physics from MuJoCo -- but the MuJoCo actually runs as a RISC-V guest under
libriscv (`interactor-mujoco-sandbox-demo`), which is what makes the simulation
bit-identical on every host. The native extension is a thin bridge: it forwards
`_step` to the guest and reads body and flex-vertex state back.

## The impedance mismatch, and why it is proved first

Godot builds a world incrementally -- create a body, get an RID, add shapes at
runtime. MuJoCo compiles an `mjModel` whole and cannot grow a body afterwards.
So the bridge buffers the create/add calls, assigns each body a dense MuJoCo
index by insertion order, and compiles the model before it steps. Two failures
follow from that design, and both are proved impossible before any C++ was
written:

  1. **Never read the wrong body.** RIDs are unique and index <-> rid
     round-trips (`model/PhysicsBridge.lean`: `create_valid`, `fresh_not_live`,
     `roundtrip_8`).
  2. **Never step a stale model.** Any create or free returns the bridge to
     `dirty`; `step` runs only when `compiled` (`step_needs_compiled`,
     `no_step_after_create`, `no_step_after_free`, `compile_enables_step`,
     `free_shifts_indices`).

`src/mujoco_bridge.h` is that proof translated 1:1 to C++, and
`src/mujoco_bridge_test.cpp` re-checks each theorem natively, so the code and the
proof cannot drift.

## Layout

    model/PhysicsBridge.lean     the proof (lake build)
    src/mujoco_bridge.h          the proven core, translated to C++
    src/mujoco_bridge_test.cpp   native re-check, one assert per theorem
    src/mujoco_physics_server.*  the PhysicsServer3DExtension surface (in progress)
    src/register_types.cpp       registers the server with PhysicsServer3DManager

## Status

Proved and verified: the bridge invariants (Lean) and their C++ core (native
test). In progress: the full ~150-method PhysicsServer3DExtension surface and the
MJCF/mjSpec model builder that turns buffered create/add calls into a model the
guest loads. CineForm capture is a separate GDExtension, `godot-cineform`.

## Credit

V-Sekai-fire and chibifire.
