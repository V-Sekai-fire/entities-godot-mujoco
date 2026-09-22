// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_BRIDGE_H
#define MUJOCO_BRIDGE_H

// The proven core of the MuJoCo <-> PhysicsServer3D bridge, translated 1:1 from
// model/PhysicsBridge.lean. The physics server below leans on two facts the
// proof establishes, so they are implemented here once and reused:
//
//   * a fresh RID never aliases a live one, and index <-> rid round-trips, so
//     Godot never reads the wrong body (Lean: create_valid, fresh_not_live,
//     roundtrip_8);
//   * step is allowed only when compiled, and any create or free returns to
//     dirty, so a stale model can never be stepped (Lean: step_needs_compiled,
//     no_step_after_create, no_step_after_free, compile_enables_step).
//
// Keeping this a small header, separate from the ~150-method server surface,
// keeps the proven part proven: the code that must match the Lean is all here.

#include <cstddef>
#include <cstdint>
#include <vector>

namespace mujoco_bridge {

using Rid = uint64_t;

// A dense registry: a body's MuJoCo index is its position in `bodies`, and
// `next_rid` only ever increases (Lean: structure Reg, def create).
struct Reg {
	std::vector<Rid> bodies;
	Rid next_rid = 0;

	// Lean: def create -- mint next_rid, append so its index is the old length.
	Rid create() {
		const Rid rid = next_rid;
		bodies.push_back(rid);
		next_rid += 1;
		return rid;
	}

	// Lean: def ridAt / def indexOf. -1 stands for Lean's Option none.
	bool rid_at(size_t index, Rid &out) const {
		if (index >= bodies.size()) {
			return false;
		}
		out = bodies[index];
		return true;
	}

	bool index_of(Rid rid, size_t &out) const {
		for (size_t i = 0; i < bodies.size(); i++) {
			if (bodies[i] == rid) {
				out = i;
				return true;
			}
		}
		return false;
	}

	// Lean: def Valid -- every live RID is below the counter, so the RID a create
	// hands back is distinct from every live one (Lean: fresh_not_live).
	bool valid() const {
		for (Rid r : bodies) {
			if (r >= next_rid) {
				return false;
			}
		}
		return true;
	}

	// Freeing shifts the dense indices, which is why it must force a recompile
	// (Lean: free_shifts_indices).
	void free(Rid rid) {
		for (size_t i = 0; i < bodies.size(); i++) {
			if (bodies[i] == rid) {
				bodies.erase(bodies.begin() + i);
				return;
			}
		}
	}
};

// Lean: inductive Phase.
enum class Phase { BUILDING, COMPILED, DIRTY };

// Lean: structure Bridge, with the phase transitions and the step guard.
struct Bridge {
	Reg reg;
	Phase phase = Phase::BUILDING;

	Rid create() {
		const Rid rid = reg.create();
		phase = Phase::DIRTY; // Lean: Bridge.create -> dirty
		return rid;
	}

	void free(Rid rid) {
		reg.free(rid);
		phase = Phase::DIRTY; // Lean: Bridge.free -> dirty
	}

	void compile() {
		phase = Phase::COMPILED; // Lean: Bridge.compile
	}

	// Lean: def Bridge.step is `some` only in `compiled`. The server must consult
	// this before forwarding a step to the sandbox guest; a stale model is never
	// stepped (Lean: step_needs_compiled, no_step_after_{create,free}).
	bool step_allowed() const {
		return phase == Phase::COMPILED;
	}
};

} // namespace mujoco_bridge

#endif // MUJOCO_BRIDGE_H
