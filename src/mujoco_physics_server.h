// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_PHYSICS_SERVER_H
#define MUJOCO_PHYSICS_SERVER_H

#include <godot_cpp/classes/physics_server3d_extension.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/rid.hpp>

#include <mujoco/mujoco.h>

#include <cstdint>
#include <unordered_map>

#include "mujoco_bridge.h"
#include "mujoco_direct_body_state.h"

namespace godot {

// A Godot 3D physics server backed by MuJoCo linked natively. Godot builds the
// world incrementally; MuJoCo compiles it whole. Create/add calls accumulate
// into an mjSpec, the model is compiled before it steps, and any topology change
// forces a recompile -- the ordering proved in model/PhysicsBridge.lean and
// enforced by the bridge here.
class MuJoCoPhysicsServer : public PhysicsServer3DExtension {
	GDCLASS(MuJoCoPhysicsServer, PhysicsServer3DExtension)

	struct Shape {
		mjtGeom type = mjGEOM_SPHERE;
		double size[3] = { 0.1, 0.1, 0.1 };
	};

	mujoco_bridge::Bridge bridge;
	mjSpec *spec = nullptr;
	mjModel *model = nullptr;
	mjData *data = nullptr;
	std::unordered_map<uint64_t, mjsBody *> spec_bodies; // rid -> spec body
	std::unordered_map<uint64_t, Shape> shapes; // rid -> shape
	std::unordered_map<uint64_t, Callable> sync_callbacks; // body rid -> state sync callable
	MuJoCoDirectBodyState3D *direct_state = nullptr;
	bool flushing = false;

	void recompile_if_dirty();
	int body_mjid(uint64_t rid) const;

protected:
	static void _bind_methods() {}

public:
	static PhysicsServer3D *create();

	// --- lifecycle / stepping ---
	virtual void _init() override;
	virtual void _finish() override;
	virtual void _set_active(bool p_active) override;
	virtual void _step(float p_step) override;
	virtual void _sync() override;
	virtual void _end_sync() override;
	virtual void _flush_queries() override;
	virtual bool _is_flushing_queries() const override;

	// --- spaces ---
	virtual RID _space_create() override;
	virtual void _space_set_active(const RID &p_space, bool p_active) override;
	virtual bool _space_is_active(const RID &p_space) const override;

	// --- shapes ---
	virtual RID _box_shape_create() override;
	virtual RID _sphere_shape_create() override;
	virtual RID _capsule_shape_create() override;
	virtual RID _cylinder_shape_create() override;
	virtual RID _world_boundary_shape_create() override;
	virtual void _shape_set_data(const RID &p_shape, const Variant &p_data) override;
	virtual PhysicsServer3D::ShapeType _shape_get_type(const RID &p_shape) const override;
	virtual Variant _shape_get_data(const RID &p_shape) const override;

	// --- rigid bodies ---
	virtual RID _body_create() override;
	virtual void _body_set_space(const RID &p_body, const RID &p_space) override;
	virtual void _body_set_mode(const RID &p_body, PhysicsServer3D::BodyMode p_mode) override;
	virtual PhysicsServer3D::BodyMode _body_get_mode(const RID &p_body) const override;
	virtual void _body_add_shape(const RID &p_body, const RID &p_shape,
			const Transform3D &p_transform, bool p_disabled) override;
	virtual Variant _body_get_state(const RID &p_body,
			PhysicsServer3D::BodyState p_state) const override;
	virtual void _body_set_state(const RID &p_body,
			PhysicsServer3D::BodyState p_state, const Variant &p_value) override;
	virtual void _body_set_state_sync_callback(const RID &p_body, const Callable &p_callable) override;
	virtual PhysicsDirectBodyState3D *_body_get_direct_state(const RID &p_body) override;

	// --- soft bodies (cloth -> MuJoCo flex) ---
	virtual RID _soft_body_create() override;
	virtual Vector3 _soft_body_get_point_global_position(const RID &p_body,
			int32_t p_point_index) const override;

	// --- teardown ---
	virtual void _free_rid(const RID &p_rid) override;

	MuJoCoPhysicsServer() = default;
	~MuJoCoPhysicsServer() override = default;
};

} // namespace godot

#endif // MUJOCO_PHYSICS_SERVER_H
