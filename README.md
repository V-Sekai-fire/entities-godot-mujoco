# entities-godot-mujoco

A Godot physics backend that implements `PhysicsServer3DExtension`, so ordinary
`RigidBody3D` and `SoftBody3D` nodes get their physics from MuJoCo. MuJoCo is
vendored as a git subtree under `third_party/mujoco` and linked directly into
this extension -- `mj_step` runs natively, in-process.

This is migrated from an earlier design that delegated stepping to a RISC-V
godot-sandbox guest. Native MuJoCo is fast, but native floating point is not
bit-identical across CPUs, so this backend is not cross-host deterministic. That
determinism story lives in the sandbox demos (`interactor-taskweft-crowd`,
`interactor-mujoco-cloth-sim`); this backend trades it for speed.
