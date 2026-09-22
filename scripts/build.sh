#!/usr/bin/env bash
# One-step build of the MuJoCo PhysicsServer3DExtension.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cmake -S "$ROOT" -B "$ROOT/build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_POLICY_VERSION_MINIMUM=3.5 "$@"
cmake --build "$ROOT/build" -j
echo "built -> $ROOT/demo/addons/mujoco/bin/"
