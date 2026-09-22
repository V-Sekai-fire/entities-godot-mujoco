// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_BRIDGE_H
#define MUJOCO_BRIDGE_H

// The proven core of the bridge, translated 1:1 from model/PhysicsBridge.lean.

#include <cstddef>
#include <cstdint>
#include <vector>

namespace mujoco_bridge {

using Rid = uint64_t;

struct Reg {
	std::vector<Rid> bodies;
	Rid next_rid = 0;

	Rid create() {
		const Rid rid = next_rid;
		bodies.push_back(rid);
		next_rid += 1;
		return rid;
	}

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

	bool valid() const {
		for (Rid r : bodies) {
			if (r >= next_rid) {
				return false;
			}
		}
		return true;
	}

	void free(Rid rid) {
		for (size_t i = 0; i < bodies.size(); i++) {
			if (bodies[i] == rid) {
				bodies.erase(bodies.begin() + i);
				return;
			}
		}
	}
};

enum class Phase { BUILDING, COMPILED, DIRTY };

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

	bool step_allowed() const {
		return phase == Phase::COMPILED;
	}
};

} // namespace mujoco_bridge

#endif // MUJOCO_BRIDGE_H
