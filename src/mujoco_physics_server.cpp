// SPDX-License-Identifier: Apache-2.0 OR MIT
#include "mujoco_physics_server.h"

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <cstdio>

using namespace godot;

PhysicsServer3D *MuJoCoPhysicsServer::create() {
	return memnew(MuJoCoPhysicsServer);
}

static void body_name(char *out, size_t n, uint64_t rid) {
	std::snprintf(out, n, "b%llu", (unsigned long long)rid);
}

void MuJoCoPhysicsServer::_init() {
	spec = mj_makeSpec();
}

void MuJoCoPhysicsServer::_finish() {
	if (data) { mj_deleteData(data); data = nullptr; }
	if (model) { mj_deleteModel(model); model = nullptr; }
	if (spec) { mj_deleteSpec(spec); spec = nullptr; }
}

void MuJoCoPhysicsServer::_set_active(bool p_active) { (void)p_active; }

// Compile the accumulated spec into a model before stepping. This is the proven
// ordering: create/free leave the bridge dirty, and only a compiled model steps
// (model/PhysicsBridge.lean: no_step_after_{create,free}, step_needs_compiled).
void MuJoCoPhysicsServer::recompile_if_dirty() {
	if (spec == nullptr || bridge.step_allowed()) {
		return;
	}
	mjModel *nm = mj_compile(spec, nullptr);
	if (nm == nullptr) {
		UtilityFunctions::push_error(String("MuJoCo compile failed: ") + mjs_getError(spec));
		return;
	}
	if (data) { mj_deleteData(data); }
	if (model) { mj_deleteModel(model); }
	model = nm;
	data = mj_makeData(model);
	bridge.compile();
}

void MuJoCoPhysicsServer::_step(float p_step) {
	(void)p_step;
	recompile_if_dirty();
	if (model && data && bridge.step_allowed()) {
		mj_step(model, data);
	}
}

void MuJoCoPhysicsServer::_sync() {}
void MuJoCoPhysicsServer::_end_sync() {}
void MuJoCoPhysicsServer::_flush_queries() { flushing = true; flushing = false; }
bool MuJoCoPhysicsServer::_is_flushing_queries() const { return flushing; }

RID MuJoCoPhysicsServer::_space_create() { return RID(); }
void MuJoCoPhysicsServer::_space_set_active(const RID &p_space, bool p_active) { (void)p_space; (void)p_active; }
bool MuJoCoPhysicsServer::_space_is_active(const RID &p_space) const { (void)p_space; return true; }

RID MuJoCoPhysicsServer::_body_create() {
	// A create adds a free body to the spec and leaves the bridge dirty, so the
	// next step recompiles (Lean: Bridge.create -> dirty, fresh_not_live).
	const mujoco_bridge::Rid rid = bridge.create();
	if (spec) {
		mjsBody *world = mjs_findBody(spec, "world");
		mjsBody *b = mjs_addBody(world, nullptr);
		char name[32];
		body_name(name, sizeof(name), rid);
		mjs_setName(b->element, name);
		mjs_addFreeJoint(b);
		mjsGeom *g = mjs_addGeom(b, nullptr);
		g->type = mjGEOM_SPHERE;
		g->size[0] = g->size[1] = g->size[2] = 0.1;
		spec_bodies[rid] = b;
	}
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

void MuJoCoPhysicsServer::_body_set_space(const RID &p_body, const RID &p_space) { (void)p_body; (void)p_space; }

Variant MuJoCoPhysicsServer::_body_get_state(const RID &p_body, PhysicsServer3D::BodyState p_state) const {
	if (model == nullptr || data == nullptr || p_state != PhysicsServer3D::BODY_STATE_TRANSFORM) {
		return Variant();
	}
	char name[32];
	body_name(name, sizeof(name), (uint64_t)(p_body.get_id() - 1));
	const int bid = mj_name2id(model, mjOBJ_BODY, name);
	if (bid < 0) {
		return Variant();
	}
	const double *xp = data->xpos + bid * 3;
	const double *xq = data->xquat + bid * 4; // MuJoCo quat is wxyz
	Transform3D t;
	t.basis = Basis(Quaternion(xq[1], xq[2], xq[3], xq[0]));
	t.origin = Vector3(xp[0], xp[1], xp[2]);
	return t;
}

void MuJoCoPhysicsServer::_body_set_state(const RID &p_body, PhysicsServer3D::BodyState p_state, const Variant &p_value) {
	(void)p_body; (void)p_state; (void)p_value;
	// TODO: set the spec body's initial pos/quat and mark dirty.
}

RID MuJoCoPhysicsServer::_soft_body_create() {
	// TODO: build a flexcomp in the spec for cloth. For now it shares the rigid
	// path so RIDs stay unique and the bridge stays consistent.
	const mujoco_bridge::Rid rid = bridge.create();
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

Vector3 MuJoCoPhysicsServer::_soft_body_get_point_global_position(const RID &p_body, int32_t p_point_index) const {
	(void)p_body; (void)p_point_index;
	// TODO: read data->flexvert_xpos for this soft body's vertex.
	return Vector3();
}

void MuJoCoPhysicsServer::_free_rid(const RID &p_rid) {
	// A free removes the body from the spec and leaves the bridge dirty, so the
	// next step recompiles the model (Lean: free_shifts_indices, no_step_after_free).
	const uint64_t rid = (uint64_t)(p_rid.get_id() - 1);
	auto it = spec_bodies.find(rid);
	if (it != spec_bodies.end() && spec) {
		mjs_delete(spec, it->second->element);
		spec_bodies.erase(it);
	}
	bridge.free(rid);
}
