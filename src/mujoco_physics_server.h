// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_PHYSICS_SERVER_H
#define MUJOCO_PHYSICS_SERVER_H

#include <godot_cpp/classes/physics_server3d_extension.hpp>
#include <godot_cpp/classes/physics_server3d_rendering_server_handler.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/typed_array.hpp>
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

	// --- auto-generated no-op stubs for the rest of the required surface ---
	virtual RID _separation_ray_shape_create()  override { return RID(); }
	virtual RID _convex_polygon_shape_create()  override { return RID(); }
	virtual RID _concave_polygon_shape_create()  override { return RID(); }
	virtual RID _heightmap_shape_create()  override { return RID(); }
	virtual RID _custom_shape_create()  override { return RID(); }
	virtual void _shape_set_custom_solver_bias(const RID &p_shape, float p_bias)  override {  }
	virtual void _shape_set_margin(const RID &p_shape, float p_margin)  override {  }
	virtual float _shape_get_margin(const RID &p_shape) const override { return 0; }
	virtual float _shape_get_custom_solver_bias(const RID &p_shape) const override { return 0; }
	virtual void _space_set_param(const RID &p_space, PhysicsServer3D::SpaceParameter p_param, float p_value)  override {  }
	virtual float _space_get_param(const RID &p_space, PhysicsServer3D::SpaceParameter p_param) const override { return 0; }
	virtual void _space_set_debug_contacts(const RID &p_space, int32_t p_max_contacts)  override {  }
	virtual PackedVector3Array _space_get_contacts(const RID &p_space) const override { return PackedVector3Array(); }
	virtual int32_t _space_get_contact_count(const RID &p_space) const override { return 0; }
	virtual RID _area_create()  override { return RID(); }
	virtual void _area_set_space(const RID &p_area, const RID &p_space)  override {  }
	virtual RID _area_get_space(const RID &p_area) const override { return RID(); }
	virtual void _area_add_shape(const RID &p_area, const RID &p_shape, const Transform3D &p_transform, bool p_disabled)  override {  }
	virtual void _area_set_shape(const RID &p_area, int32_t p_shape_idx, const RID &p_shape)  override {  }
	virtual void _area_set_shape_transform(const RID &p_area, int32_t p_shape_idx, const Transform3D &p_transform)  override {  }
	virtual void _area_set_shape_disabled(const RID &p_area, int32_t p_shape_idx, bool p_disabled)  override {  }
	virtual int32_t _area_get_shape_count(const RID &p_area) const override { return 0; }
	virtual RID _area_get_shape(const RID &p_area, int32_t p_shape_idx) const override { return RID(); }
	virtual Transform3D _area_get_shape_transform(const RID &p_area, int32_t p_shape_idx) const override { return Transform3D(); }
	virtual void _area_remove_shape(const RID &p_area, int32_t p_shape_idx)  override {  }
	virtual void _area_clear_shapes(const RID &p_area)  override {  }
	virtual void _area_attach_object_instance_id(const RID &p_area, uint64_t p_id)  override {  }
	virtual uint64_t _area_get_object_instance_id(const RID &p_area) const override { return 0; }
	virtual void _area_set_param(const RID &p_area, PhysicsServer3D::AreaParameter p_param, const Variant &p_value)  override {  }
	virtual void _area_set_transform(const RID &p_area, const Transform3D &p_transform)  override {  }
	virtual Variant _area_get_param(const RID &p_area, PhysicsServer3D::AreaParameter p_param) const override { return Variant(); }
	virtual Transform3D _area_get_transform(const RID &p_area) const override { return Transform3D(); }
	virtual void _area_set_collision_layer(const RID &p_area, uint32_t p_layer)  override {  }
	virtual uint32_t _area_get_collision_layer(const RID &p_area) const override { return 0; }
	virtual void _area_set_collision_mask(const RID &p_area, uint32_t p_mask)  override {  }
	virtual uint32_t _area_get_collision_mask(const RID &p_area) const override { return 0; }
	virtual void _area_set_monitorable(const RID &p_area, bool p_monitorable)  override {  }
	virtual void _area_set_ray_pickable(const RID &p_area, bool p_enable)  override {  }
	virtual void _area_set_monitor_callback(const RID &p_area, const Callable &p_callback)  override {  }
	virtual void _area_set_area_monitor_callback(const RID &p_area, const Callable &p_callback)  override {  }
	virtual RID _body_get_space(const RID &p_body) const override { return RID(); }
	virtual void _body_set_shape(const RID &p_body, int32_t p_shape_idx, const RID &p_shape)  override {  }
	virtual void _body_set_shape_transform(const RID &p_body, int32_t p_shape_idx, const Transform3D &p_transform)  override {  }
	virtual void _body_set_shape_disabled(const RID &p_body, int32_t p_shape_idx, bool p_disabled)  override {  }
	virtual int32_t _body_get_shape_count(const RID &p_body) const override { return 0; }
	virtual RID _body_get_shape(const RID &p_body, int32_t p_shape_idx) const override { return RID(); }
	virtual Transform3D _body_get_shape_transform(const RID &p_body, int32_t p_shape_idx) const override { return Transform3D(); }
	virtual void _body_remove_shape(const RID &p_body, int32_t p_shape_idx)  override {  }
	virtual void _body_clear_shapes(const RID &p_body)  override {  }
	virtual void _body_attach_object_instance_id(const RID &p_body, uint64_t p_id)  override {  }
	virtual uint64_t _body_get_object_instance_id(const RID &p_body) const override { return 0; }
	virtual void _body_set_enable_continuous_collision_detection(const RID &p_body, bool p_enable)  override {  }
	virtual bool _body_is_continuous_collision_detection_enabled(const RID &p_body) const override { return false; }
	virtual void _body_set_collision_layer(const RID &p_body, uint32_t p_layer)  override {  }
	virtual uint32_t _body_get_collision_layer(const RID &p_body) const override { return 0; }
	virtual void _body_set_collision_mask(const RID &p_body, uint32_t p_mask)  override {  }
	virtual uint32_t _body_get_collision_mask(const RID &p_body) const override { return 0; }
	virtual void _body_set_collision_priority(const RID &p_body, float p_priority)  override {  }
	virtual float _body_get_collision_priority(const RID &p_body) const override { return 0; }
	virtual void _body_set_user_flags(const RID &p_body, uint32_t p_flags)  override {  }
	virtual uint32_t _body_get_user_flags(const RID &p_body) const override { return 0; }
	virtual void _body_set_param(const RID &p_body, PhysicsServer3D::BodyParameter p_param, const Variant &p_value)  override {  }
	virtual Variant _body_get_param(const RID &p_body, PhysicsServer3D::BodyParameter p_param) const override { return Variant(); }
	virtual void _body_reset_mass_properties(const RID &p_body)  override {  }
	virtual void _body_apply_central_impulse(const RID &p_body, const Vector3 &p_impulse)  override {  }
	virtual void _body_apply_impulse(const RID &p_body, const Vector3 &p_impulse, const Vector3 &p_position)  override {  }
	virtual void _body_apply_torque_impulse(const RID &p_body, const Vector3 &p_impulse)  override {  }
	virtual void _body_apply_central_force(const RID &p_body, const Vector3 &p_force)  override {  }
	virtual void _body_apply_force(const RID &p_body, const Vector3 &p_force, const Vector3 &p_position)  override {  }
	virtual void _body_apply_torque(const RID &p_body, const Vector3 &p_torque)  override {  }
	virtual void _body_add_constant_central_force(const RID &p_body, const Vector3 &p_force)  override {  }
	virtual void _body_add_constant_force(const RID &p_body, const Vector3 &p_force, const Vector3 &p_position)  override {  }
	virtual void _body_add_constant_torque(const RID &p_body, const Vector3 &p_torque)  override {  }
	virtual void _body_set_constant_force(const RID &p_body, const Vector3 &p_force)  override {  }
	virtual Vector3 _body_get_constant_force(const RID &p_body) const override { return Vector3(); }
	virtual void _body_set_constant_torque(const RID &p_body, const Vector3 &p_torque)  override {  }
	virtual Vector3 _body_get_constant_torque(const RID &p_body) const override { return Vector3(); }
	virtual void _body_set_axis_velocity(const RID &p_body, const Vector3 &p_axis_velocity)  override {  }
	virtual void _body_set_axis_lock(const RID &p_body, PhysicsServer3D::BodyAxis p_axis, bool p_lock)  override {  }
	virtual bool _body_is_axis_locked(const RID &p_body, PhysicsServer3D::BodyAxis p_axis) const override { return false; }
	virtual void _body_add_collision_exception(const RID &p_body, const RID &p_excepted_body)  override {  }
	virtual void _body_remove_collision_exception(const RID &p_body, const RID &p_excepted_body)  override {  }
	virtual TypedArray<RID> _body_get_collision_exceptions(const RID &p_body) const override { return TypedArray<RID>(); }
	virtual void _body_set_max_contacts_reported(const RID &p_body, int32_t p_amount)  override {  }
	virtual int32_t _body_get_max_contacts_reported(const RID &p_body) const override { return 0; }
	virtual void _body_set_contacts_reported_depth_threshold(const RID &p_body, float p_threshold)  override {  }
	virtual float _body_get_contacts_reported_depth_threshold(const RID &p_body) const override { return 0; }
	virtual void _body_set_omit_force_integration(const RID &p_body, bool p_enable)  override {  }
	virtual bool _body_is_omitting_force_integration(const RID &p_body) const override { return false; }
	virtual void _body_set_force_integration_callback(const RID &p_body, const Callable &p_callable, const Variant &p_userdata)  override {  }
	virtual void _body_set_ray_pickable(const RID &p_body, bool p_enable)  override {  }
	virtual bool _body_test_motion(const RID &p_body, const Transform3D &p_from, const Vector3 &p_motion, float p_margin, int32_t p_max_collisions, bool p_collide_separation_ray, bool p_recovery_as_collision, PhysicsServer3DExtensionMotionResult *r_result) const override { return false; }
	virtual void _soft_body_update_rendering_server(const RID &p_body, PhysicsServer3DRenderingServerHandler *p_rendering_server_handler)  override {  }
	virtual void _soft_body_set_space(const RID &p_body, const RID &p_space)  override {  }
	virtual RID _soft_body_get_space(const RID &p_body) const override { return RID(); }
	virtual void _soft_body_set_ray_pickable(const RID &p_body, bool p_enable)  override {  }
	virtual void _soft_body_set_collision_layer(const RID &p_body, uint32_t p_layer)  override {  }
	virtual uint32_t _soft_body_get_collision_layer(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_collision_mask(const RID &p_body, uint32_t p_mask)  override {  }
	virtual uint32_t _soft_body_get_collision_mask(const RID &p_body) const override { return 0; }
	virtual void _soft_body_add_collision_exception(const RID &p_body, const RID &p_body_b)  override {  }
	virtual void _soft_body_remove_collision_exception(const RID &p_body, const RID &p_body_b)  override {  }
	virtual TypedArray<RID> _soft_body_get_collision_exceptions(const RID &p_body) const override { return TypedArray<RID>(); }
	virtual void _soft_body_set_state(const RID &p_body, PhysicsServer3D::BodyState p_state, const Variant &p_variant)  override {  }
	virtual Variant _soft_body_get_state(const RID &p_body, PhysicsServer3D::BodyState p_state) const override { return Variant(); }
	virtual void _soft_body_set_transform(const RID &p_body, const Transform3D &p_transform)  override {  }
	virtual void _soft_body_set_simulation_precision(const RID &p_body, int32_t p_simulation_precision)  override {  }
	virtual int32_t _soft_body_get_simulation_precision(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_total_mass(const RID &p_body, float p_total_mass)  override {  }
	virtual float _soft_body_get_total_mass(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_linear_stiffness(const RID &p_body, float p_linear_stiffness)  override {  }
	virtual float _soft_body_get_linear_stiffness(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_shrinking_factor(const RID &p_body, float p_shrinking_factor)  override {  }
	virtual float _soft_body_get_shrinking_factor(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_pressure_coefficient(const RID &p_body, float p_pressure_coefficient)  override {  }
	virtual float _soft_body_get_pressure_coefficient(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_damping_coefficient(const RID &p_body, float p_damping_coefficient)  override {  }
	virtual float _soft_body_get_damping_coefficient(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_drag_coefficient(const RID &p_body, float p_drag_coefficient)  override {  }
	virtual float _soft_body_get_drag_coefficient(const RID &p_body) const override { return 0; }
	virtual void _soft_body_set_mesh(const RID &p_body, const RID &p_mesh)  override {  }
	virtual AABB _soft_body_get_bounds(const RID &p_body) const override { return AABB(); }
	virtual void _soft_body_move_point(const RID &p_body, int32_t p_point_index, const Vector3 &p_global_position)  override {  }
	virtual void _soft_body_remove_all_pinned_points(const RID &p_body)  override {  }
	virtual void _soft_body_pin_point(const RID &p_body, int32_t p_point_index, bool p_pin)  override {  }
	virtual bool _soft_body_is_point_pinned(const RID &p_body, int32_t p_point_index) const override { return false; }
	virtual void _soft_body_apply_point_impulse(const RID &p_body, int32_t p_point_index, const Vector3 &p_impulse)  override {  }
	virtual void _soft_body_apply_point_force(const RID &p_body, int32_t p_point_index, const Vector3 &p_force)  override {  }
	virtual void _soft_body_apply_central_impulse(const RID &p_body, const Vector3 &p_impulse)  override {  }
	virtual void _soft_body_apply_central_force(const RID &p_body, const Vector3 &p_force)  override {  }
	virtual RID _joint_create()  override { return RID(); }
	virtual void _joint_clear(const RID &p_joint)  override {  }
	virtual void _joint_make_pin(const RID &p_joint, const RID &p_body_A, const Vector3 &p_local_A, const RID &p_body_B, const Vector3 &p_local_B)  override {  }
	virtual void _pin_joint_set_param(const RID &p_joint, PhysicsServer3D::PinJointParam p_param, float p_value)  override {  }
	virtual float _pin_joint_get_param(const RID &p_joint, PhysicsServer3D::PinJointParam p_param) const override { return 0; }
	virtual void _pin_joint_set_local_a(const RID &p_joint, const Vector3 &p_local_A)  override {  }
	virtual Vector3 _pin_joint_get_local_a(const RID &p_joint) const override { return Vector3(); }
	virtual void _pin_joint_set_local_b(const RID &p_joint, const Vector3 &p_local_B)  override {  }
	virtual Vector3 _pin_joint_get_local_b(const RID &p_joint) const override { return Vector3(); }
	virtual void _joint_make_hinge(const RID &p_joint, const RID &p_body_A, const Transform3D &p_hinge_A, const RID &p_body_B, const Transform3D &p_hinge_B)  override {  }
	virtual void _joint_make_hinge_simple(const RID &p_joint, const RID &p_body_A, const Vector3 &p_pivot_A, const Vector3 &p_axis_A, const RID &p_body_B, const Vector3 &p_pivot_B, const Vector3 &p_axis_B)  override {  }
	virtual void _hinge_joint_set_param(const RID &p_joint, PhysicsServer3D::HingeJointParam p_param, float p_value)  override {  }
	virtual float _hinge_joint_get_param(const RID &p_joint, PhysicsServer3D::HingeJointParam p_param) const override { return 0; }
	virtual void _hinge_joint_set_flag(const RID &p_joint, PhysicsServer3D::HingeJointFlag p_flag, bool p_enabled)  override {  }
	virtual bool _hinge_joint_get_flag(const RID &p_joint, PhysicsServer3D::HingeJointFlag p_flag) const override { return false; }
	virtual void _joint_make_slider(const RID &p_joint, const RID &p_body_A, const Transform3D &p_local_ref_A, const RID &p_body_B, const Transform3D &p_local_ref_B)  override {  }
	virtual void _slider_joint_set_param(const RID &p_joint, PhysicsServer3D::SliderJointParam p_param, float p_value)  override {  }
	virtual float _slider_joint_get_param(const RID &p_joint, PhysicsServer3D::SliderJointParam p_param) const override { return 0; }
	virtual void _joint_make_cone_twist(const RID &p_joint, const RID &p_body_A, const Transform3D &p_local_ref_A, const RID &p_body_B, const Transform3D &p_local_ref_B)  override {  }
	virtual void _cone_twist_joint_set_param(const RID &p_joint, PhysicsServer3D::ConeTwistJointParam p_param, float p_value)  override {  }
	virtual float _cone_twist_joint_get_param(const RID &p_joint, PhysicsServer3D::ConeTwistJointParam p_param) const override { return 0; }
	virtual void _joint_make_generic_6dof(const RID &p_joint, const RID &p_body_A, const Transform3D &p_local_ref_A, const RID &p_body_B, const Transform3D &p_local_ref_B)  override {  }
	virtual void _generic_6dof_joint_set_param(const RID &p_joint, Vector3::Axis p_axis, PhysicsServer3D::G6DOFJointAxisParam p_param, float p_value)  override {  }
	virtual float _generic_6dof_joint_get_param(const RID &p_joint, Vector3::Axis p_axis, PhysicsServer3D::G6DOFJointAxisParam p_param) const override { return 0; }
	virtual void _generic_6dof_joint_set_flag(const RID &p_joint, Vector3::Axis p_axis, PhysicsServer3D::G6DOFJointAxisFlag p_flag, bool p_enable)  override {  }
	virtual bool _generic_6dof_joint_get_flag(const RID &p_joint, Vector3::Axis p_axis, PhysicsServer3D::G6DOFJointAxisFlag p_flag) const override { return false; }
	virtual PhysicsServer3D::JointType _joint_get_type(const RID &p_joint) const override { return (PhysicsServer3D::JointType)0; }
	virtual void _joint_set_solver_priority(const RID &p_joint, int32_t p_priority)  override {  }
	virtual int32_t _joint_get_solver_priority(const RID &p_joint) const override { return 0; }
	virtual void _joint_disable_collisions_between_bodies(const RID &p_joint, bool p_disable)  override {  }
	virtual bool _joint_is_disabled_collisions_between_bodies(const RID &p_joint) const override { return false; }
	virtual int32_t _get_process_info(PhysicsServer3D::ProcessInfo p_process_info)  override { return 0; }

	MuJoCoPhysicsServer() = default;
	~MuJoCoPhysicsServer() override = default;
};

} // namespace godot

#endif // MUJOCO_PHYSICS_SERVER_H
