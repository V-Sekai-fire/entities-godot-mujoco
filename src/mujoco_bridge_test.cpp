// SPDX-License-Identifier: Apache-2.0 OR MIT
// A native mirror of model/PhysicsBridge.lean: each check corresponds to a
#include "mujoco_bridge.h"
#include <cstdio>

using namespace mujoco_bridge;

static int fails = 0;
static void check(const char *name, bool ok) {
	std::printf("%s  %s\n", ok ? "PASS" : "FAIL", name);
	if (!ok) fails++;
}

int main() {
	{
		Reg r;
		for (int i = 0; i < 8; i++) r.create();
		bool ok = r.bodies.size() == 8;
		for (size_t i = 0; i < 8 && ok; i++) {
			Rid got; size_t idx;
			ok = r.rid_at(i, got) && got == (Rid)i && r.index_of((Rid)i, idx) && idx == i;
		}
		check("roundtrip: index<->rid on 8 bodies", ok);
	}
	{
		Reg r; r.create(); r.create();
		bool valid = r.valid();
		Rid next = r.next_rid; size_t idx;
		check("freshness: valid and next RID not live", valid && !r.index_of(next, idx));
	}
	{
		Bridge b;
		b.create();
		bool after_create = !b.step_allowed();
		b.compile();
		bool after_compile = b.step_allowed();
		b.free(0);
		bool after_free = !b.step_allowed();
		check("phase: step only when compiled, create/free -> dirty",
		      after_create && after_compile && after_free);
	}
	{
		Reg r; r.create(); r.create(); r.create();
		Rid a; r.rid_at(1, a);
		r.free(1);
		Rid b; r.rid_at(1, b);
		check("free shifts indices (why recompile is mandatory)", a == 1 && b == 2);
	}
	std::printf("%s\n", fails == 0 ? "all bridge checks pass" : "BRIDGE CHECKS FAILED");
	return fails == 0 ? 0 : 1;
}
