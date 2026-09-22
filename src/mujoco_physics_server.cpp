// SPDX-License-Identifier: Apache-2.0 OR MIT
#include "mujoco_physics_server.h"

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

PhysicsServer3D *MuJoCoPhysicsServer::create() {
	return memnew(MuJoCoPhysicsServer);
}

void MuJoCoPhysicsServer::_init() {
	// The Sandbox instance running mujoco.elf is attached by the demo project;
	// wiring it and shipping the compiled MJCF to it is the next step.
}

void MuJoCoPhysicsServer::_finish() {}

void MuJoCoPhysicsServer::_set_active(bool p_active) {
	(void)p_active;
}

void MuJoCoPhysicsServer::_step(float p_step) {
	// The proven guard: a step is forwarded to the guest only on a compiled
	// model. If a create or free left the bridge dirty, compile first so the
	// guest never steps a stale layout (Lean: no_step_after_{create,free},
	// step_needs_compiled). Model compilation and the mjc_step vmcall land here.
	if (model_dirty) {
		bridge.compile();
		model_dirty = false;
	}
	if (!bridge.step_allowed()) {
		return;
	}
	// TODO: sandbox->call("vmcall", "mjc_step");  read mjc_bodies / mjc_flexverts.
	(void)p_step;
}

void MuJoCoPhysicsServer::_sync() {}
void MuJoCoPhysicsServer::_end_sync() {}
void MuJoCoPhysicsServer::_flush_queries() { flushing = true; flushing = false; }
bool MuJoCoPhysicsServer::_is_flushing_queries() const { return flushing; }

RID MuJoCoPhysicsServer::_space_create() { return RID(); }
void MuJoCoPhysicsServer::_space_set_active(const RID &p_space, bool p_active) { (void)p_space; (void)p_active; }
bool MuJoCoPhysicsServer::_space_is_active(const RID &p_space) const { (void)p_space; return true; }

RID MuJoCoPhysicsServer::_body_create() {
	// A create returns a fresh RID and marks the model for recompile (Lean:
	// Bridge.create -> dirty). The RID Godot gets back maps to the dense MuJoCo
	// index the bridge assigns, and never aliases a live one (Lean: fresh_not_live).
	const mujoco_bridge::Rid rid = bridge.create();
	model_dirty = true;
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

void MuJoCoPhysicsServer::_body_set_space(const RID &p_body, const RID &p_space) { (void)p_body; (void)p_space; }

Variant MuJoCoPhysicsServer::_body_get_state(const RID &p_body, PhysicsServer3D::BodyState p_state) const {
	(void)p_body; (void)p_state;
	// TODO: index_of(p_body) -> read the guest's mjc_bodies transform for it.
	return Variant();
}

void MuJoCoPhysicsServer::_body_set_state(const RID &p_body, PhysicsServer3D::BodyState p_state, const Variant &p_value) {
	(void)p_body; (void)p_state; (void)p_value;
}

RID MuJoCoPhysicsServer::_soft_body_create() {
	const mujoco_bridge::Rid rid = bridge.create();
	model_dirty = true;
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

Vector3 MuJoCoPhysicsServer::_soft_body_get_point_global_position(const RID &p_body, int32_t p_point_index) const {
	(void)p_body; (void)p_point_index;
	// TODO: read the guest's mjc_flexverts for this soft body's vertex.
	return Vector3();
}

void MuJoCoPhysicsServer::_free_rid(const RID &p_rid) {
	// A free shifts the dense indices, so it must force a recompile before the
	// next step (Lean: free_shifts_indices, no_step_after_free).
	bridge.free((mujoco_bridge::Rid)(p_rid.get_id() - 1));
	model_dirty = true;
}
