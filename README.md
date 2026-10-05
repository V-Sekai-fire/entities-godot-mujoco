# entities-godot-mujoco

A physics server extension for the engine that gives ordinary rigid and soft bodies their physics from MuJoCo, stepped natively in-process.

## What it is for

Scenes keep their usual body nodes and get MuJoCo's solver underneath. Native floating point is not bit-identical across processors, so this backend trades cross-host determinism for speed. The bridge's invariants are proved in Lean 4 under `model`.

## Build and run

The engine bindings and MuJoCo are vendored, so one script builds the extension into the addon under `demo`.

```sh
scripts/build.sh
```

## Licence

Apache-2.0 OR MIT; see LICENSE-APACHE and LICENSE-MIT. Vendored code keeps its own licence.
