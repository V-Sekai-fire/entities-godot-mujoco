// SPDX-License-Identifier: Apache-2.0 OR MIT
#include "mujoco_physics_server.h"

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/dictionary.hpp>
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

// Editing a geom, a body pose or a body's joints leaves the compiled model
// stale, so the model must recompile before the next step. That is the same
// dirty state a create/free produces (model/PhysicsBridge.lean).
static void mark_dirty(mujoco_bridge::Bridge &b) {
	b.phase = mujoco_bridge::Phase::DIRTY;
}

int MuJoCoPhysicsServer::body_mjid(uint64_t rid) const {
	if (model == nullptr) {
		return -1;
	}
	char name[32];
	body_name(name, sizeof(name), rid);
	return mj_name2id(model, mjOBJ_BODY, name);
}

void MuJoCoPhysicsServer::_init() {
	spec = mj_makeSpec();
	if (spec) {
		// Work in Godot's own frame (Y-up); MuJoCo integrates whatever axis.
		spec->option.gravity[0] = 0.0;
		spec->option.gravity[1] = -9.81;
		spec->option.gravity[2] = 0.0;
	}
	direct_state = memnew(MuJoCoDirectBodyState3D);
}

void MuJoCoPhysicsServer::_finish() {
	if (direct_state) { memdelete(direct_state); direct_state = nullptr; }
	if (data) { mj_deleteData(data); data = nullptr; }
	if (model) { mj_deleteModel(model); model = nullptr; }
	if (spec) { mj_deleteSpec(spec); spec = nullptr; }
}

void MuJoCoPhysicsServer::_set_active(bool p_active) { (void)p_active; }

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
	if (!(model && data && bridge.step_allowed())) {
		return;
	}
	mj_step(model, data);
	// Hand each body's simulated state back so its node follows.
	for (auto &kv : sync_callbacks) {
		const int id = body_mjid(kv.first);
		if (id < 0 || !kv.second.is_valid()) {
			continue;
		}
		direct_state->point_at(model, data, id);
		kv.second.call(direct_state);
	}
}

void MuJoCoPhysicsServer::_sync() {}
void MuJoCoPhysicsServer::_end_sync() {}
void MuJoCoPhysicsServer::_flush_queries() { flushing = true; flushing = false; }
bool MuJoCoPhysicsServer::_is_flushing_queries() const { return flushing; }

RID MuJoCoPhysicsServer::_space_create() { return RID(); }
void MuJoCoPhysicsServer::_space_set_active(const RID &p_space, bool p_active) { (void)p_space; (void)p_active; }
bool MuJoCoPhysicsServer::_space_is_active(const RID &p_space) const { (void)p_space; return true; }

// --- shapes ---

RID MuJoCoPhysicsServer::_box_shape_create() {
	const uint64_t rid = bridge.reg.next_rid++;
	shapes[rid].type = mjGEOM_BOX;
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}
RID MuJoCoPhysicsServer::_sphere_shape_create() {
	const uint64_t rid = bridge.reg.next_rid++;
	shapes[rid].type = mjGEOM_SPHERE;
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}
RID MuJoCoPhysicsServer::_capsule_shape_create() {
	const uint64_t rid = bridge.reg.next_rid++;
	shapes[rid].type = mjGEOM_CAPSULE;
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}
RID MuJoCoPhysicsServer::_cylinder_shape_create() {
	const uint64_t rid = bridge.reg.next_rid++;
	shapes[rid].type = mjGEOM_CYLINDER;
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}
RID MuJoCoPhysicsServer::_world_boundary_shape_create() {
	const uint64_t rid = bridge.reg.next_rid++;
	shapes[rid].type = mjGEOM_PLANE;
	shapes[rid].size[0] = shapes[rid].size[1] = 0.0; // infinite plane
	shapes[rid].size[2] = 1.0; // render grid spacing
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

void MuJoCoPhysicsServer::_shape_set_data(const RID &p_shape, const Variant &p_data) {
	auto it = shapes.find((uint64_t)(p_shape.get_id() - 1));
	if (it == shapes.end()) {
		return;
	}
	Shape &sh = it->second;
	switch (sh.type) {
		case mjGEOM_BOX: {
			const Vector3 h = p_data; // half-extents
			sh.size[0] = h.x; sh.size[1] = h.y; sh.size[2] = h.z;
		} break;
		case mjGEOM_SPHERE: {
			sh.size[0] = (double)p_data;
		} break;
		case mjGEOM_CAPSULE:
		case mjGEOM_CYLINDER: {
			double r = 0.5, ht = 1.0;
			if (p_data.get_type() == Variant::DICTIONARY) {
				Dictionary d = p_data;
				r = d.get("radius", 0.5);
				ht = d.get("height", 1.0);
			}
			sh.size[0] = r;
			const double half = ht * 0.5;
			sh.size[1] = sh.type == mjGEOM_CAPSULE ? (half - r > 1e-4 ? half - r : 1e-4) : half;
		} break;
		default:
			break;
	}
}

PhysicsServer3D::ShapeType MuJoCoPhysicsServer::_shape_get_type(const RID &p_shape) const {
	auto it = shapes.find((uint64_t)(p_shape.get_id() - 1));
	if (it == shapes.end()) {
		return PhysicsServer3D::SHAPE_CUSTOM;
	}
	switch (it->second.type) {
		case mjGEOM_BOX: return PhysicsServer3D::SHAPE_BOX;
		case mjGEOM_SPHERE: return PhysicsServer3D::SHAPE_SPHERE;
		case mjGEOM_CAPSULE: return PhysicsServer3D::SHAPE_CAPSULE;
		case mjGEOM_CYLINDER: return PhysicsServer3D::SHAPE_CYLINDER;
		case mjGEOM_PLANE: return PhysicsServer3D::SHAPE_WORLD_BOUNDARY;
		default: return PhysicsServer3D::SHAPE_CUSTOM;
	}
}

Variant MuJoCoPhysicsServer::_shape_get_data(const RID &p_shape) const {
	auto it = shapes.find((uint64_t)(p_shape.get_id() - 1));
	if (it == shapes.end()) {
		return Variant();
	}
	const Shape &sh = it->second;
	if (sh.type == mjGEOM_BOX) {
		return Vector3(sh.size[0], sh.size[1], sh.size[2]);
	}
	return sh.size[0];
}

// --- rigid bodies ---

RID MuJoCoPhysicsServer::_body_create() {
	const mujoco_bridge::Rid rid = bridge.create();
	if (spec) {
		mjsBody *world = mjs_findBody(spec, "world");
		mjsBody *b = mjs_addBody(world, nullptr);
		char name[32];
		body_name(name, sizeof(name), rid);
		mjs_setName(b->element, name);
		spec_bodies[rid] = b;
	}
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

void MuJoCoPhysicsServer::_body_set_space(const RID &p_body, const RID &p_space) { (void)p_body; (void)p_space; }

void MuJoCoPhysicsServer::_body_set_mode(const RID &p_body, PhysicsServer3D::BodyMode p_mode) {
	auto it = spec_bodies.find((uint64_t)(p_body.get_id() - 1));
	if (it == spec_bodies.end()) {
		return;
	}
	// A dynamic body moves, so it needs a free joint; static and kinematic
	// bodies stay fixed to the world (no joint).
	if (p_mode == PhysicsServer3D::BODY_MODE_RIGID || p_mode == PhysicsServer3D::BODY_MODE_RIGID_LINEAR) {
		mjs_addFreeJoint(it->second);
	}
	mark_dirty(bridge);
}

PhysicsServer3D::BodyMode MuJoCoPhysicsServer::_body_get_mode(const RID &p_body) const {
	(void)p_body;
	return PhysicsServer3D::BODY_MODE_RIGID;
}

void MuJoCoPhysicsServer::_body_add_shape(const RID &p_body, const RID &p_shape,
		const Transform3D &p_transform, bool p_disabled) {
	(void)p_disabled;
	auto b = spec_bodies.find((uint64_t)(p_body.get_id() - 1));
	auto s = shapes.find((uint64_t)(p_shape.get_id() - 1));
	if (b == spec_bodies.end() || s == shapes.end() || spec == nullptr) {
		return;
	}
	mjsGeom *g = mjs_addGeom(b->second, nullptr);
	const Shape &sh = s->second;
	g->type = sh.type;
	g->size[0] = sh.size[0]; g->size[1] = sh.size[1]; g->size[2] = sh.size[2];
	const Vector3 o = p_transform.origin;
	const Quaternion q = p_transform.basis.get_rotation_quaternion();
	g->pos[0] = o.x; g->pos[1] = o.y; g->pos[2] = o.z;
	g->quat[0] = q.w; g->quat[1] = q.x; g->quat[2] = q.y; g->quat[3] = q.z;
	mark_dirty(bridge);
}

Variant MuJoCoPhysicsServer::_body_get_state(const RID &p_body, PhysicsServer3D::BodyState p_state) const {
	if (model == nullptr || data == nullptr || p_state != PhysicsServer3D::BODY_STATE_TRANSFORM) {
		return Variant();
	}
	const int bid = body_mjid((uint64_t)(p_body.get_id() - 1));
	if (bid < 0) {
		return Variant();
	}
	const double *xp = data->xpos + bid * 3;
	const double *xq = data->xquat + bid * 4;
	Transform3D t;
	t.basis = Basis(Quaternion(xq[1], xq[2], xq[3], xq[0]));
	t.origin = Vector3(xp[0], xp[1], xp[2]);
	return t;
}

void MuJoCoPhysicsServer::_body_set_state(const RID &p_body, PhysicsServer3D::BodyState p_state, const Variant &p_value) {
	if (p_state != PhysicsServer3D::BODY_STATE_TRANSFORM) {
		return;
	}
	auto it = spec_bodies.find((uint64_t)(p_body.get_id() - 1));
	if (it == spec_bodies.end()) {
		return;
	}
	const Transform3D t = p_value;
	const Vector3 o = t.origin;
	const Quaternion q = t.basis.get_rotation_quaternion();
	it->second->pos[0] = o.x; it->second->pos[1] = o.y; it->second->pos[2] = o.z;
	it->second->quat[0] = q.w; it->second->quat[1] = q.x; it->second->quat[2] = q.y; it->second->quat[3] = q.z;
	mark_dirty(bridge);
}

void MuJoCoPhysicsServer::_body_set_state_sync_callback(const RID &p_body, const Callable &p_callable) {
	sync_callbacks[(uint64_t)(p_body.get_id() - 1)] = p_callable;
}

PhysicsDirectBodyState3D *MuJoCoPhysicsServer::_body_get_direct_state(const RID &p_body) {
	if (direct_state == nullptr) {
		return nullptr;
	}
	direct_state->point_at(model, data, body_mjid((uint64_t)(p_body.get_id() - 1)));
	return direct_state;
}

// --- soft bodies ---

RID MuJoCoPhysicsServer::_soft_body_create() {
	const mujoco_bridge::Rid rid = bridge.create();
	return UtilityFunctions::rid_from_int64((int64_t)(rid + 1));
}

Vector3 MuJoCoPhysicsServer::_soft_body_get_point_global_position(const RID &p_body, int32_t p_point_index) const {
	(void)p_body; (void)p_point_index;
	return Vector3();
}

void MuJoCoPhysicsServer::_free_rid(const RID &p_rid) {
	const uint64_t rid = (uint64_t)(p_rid.get_id() - 1);
	auto it = spec_bodies.find(rid);
	if (it != spec_bodies.end() && spec) {
		mjs_delete(spec, it->second->element);
		spec_bodies.erase(it);
		bridge.free(rid);
	}
	shapes.erase(rid);
	sync_callbacks.erase(rid);
}
