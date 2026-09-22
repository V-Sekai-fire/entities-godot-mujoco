#!/usr/bin/env bash
# One-step build of the MuJoCo PhysicsServer3DExtension.
# Both dependencies -- godot-cpp and MuJoCo -- are vendored as subtrees under
# third_party/, so there is nothing to fetch: configure and build.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cmake -S "$ROOT" -B "$ROOT/build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_POLICY_VERSION_MINIMUM=3.5 "$@"
cmake --build "$ROOT/build" -j
echo "built -> $ROOT/demo/addons/mujoco/bin/"
