// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_DIRECT_BODY_STATE_H
#define MUJOCO_DIRECT_BODY_STATE_H

#include <godot_cpp/classes/physics_direct_body_state3d_extension.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
#include <godot_cpp/variant/rid.hpp>

#include <mujoco/mujoco.h>

namespace godot {

class MuJoCoDirectBodyState3D : public PhysicsDirectBodyState3DExtension {
	GDCLASS(MuJoCoDirectBodyState3D, PhysicsDirectBodyState3DExtension)

	Vector3 constant_force;
	Vector3 constant_torque;

protected:
	static void _bind_methods() {}

public:
	mjModel *model = nullptr;
	mjData *data = nullptr;
	int body_id = -1;

	void point_at(mjModel *m, mjData *d, int id) { model = m; data = d; body_id = id; }

	Vector3 _get_total_gravity() const override;
	float _get_total_linear_damp() const override { return 0.0f; }
	float _get_total_angular_damp() const override { return 0.0f; }
	Vector3 _get_center_of_mass() const override;
	Vector3 _get_center_of_mass_local() const override;
	Basis _get_principal_inertia_axes() const override { return Basis(); }
	float _get_inverse_mass() const override;
	Vector3 _get_inverse_inertia() const override;
	Basis _get_inverse_inertia_tensor() const override;

	void _set_linear_velocity(const Vector3 &p_velocity) override {}
	Vector3 _get_linear_velocity() const override;
	void _set_angular_velocity(const Vector3 &p_velocity) override {}
	Vector3 _get_angular_velocity() const override;
	void _set_transform(const Transform3D &p_transform) override {}
	Transform3D _get_transform() const override;
	Vector3 _get_velocity_at_local_position(const Vector3 &p_local_position) const override;

	void _apply_central_impulse(const Vector3 &p_impulse) override {}
	void _apply_impulse(const Vector3 &p_impulse, const Vector3 &p_position) override {}
	void _apply_torque_impulse(const Vector3 &p_impulse) override {}
	void _apply_central_force(const Vector3 &p_force) override {}
	void _apply_force(const Vector3 &p_force, const Vector3 &p_position) override {}
	void _apply_torque(const Vector3 &p_torque) override {}
	void _add_constant_central_force(const Vector3 &p_force) override { constant_force += p_force; }
	void _add_constant_force(const Vector3 &p_force, const Vector3 &p_position) override { constant_force += p_force; }
	void _add_constant_torque(const Vector3 &p_torque) override { constant_torque += p_torque; }
	void _set_constant_force(const Vector3 &p_force) override { constant_force = p_force; }
	Vector3 _get_constant_force() const override { return constant_force; }
	void _set_constant_torque(const Vector3 &p_torque) override { constant_torque = p_torque; }
	Vector3 _get_constant_torque() const override { return constant_torque; }

	void _set_sleep_state(bool p_enabled) override {}
	bool _is_sleeping() const override { return false; }
	uint32_t _get_collision_layer() const override { return 1; }
	uint32_t _get_collision_mask() const override { return 1; }

	int32_t _get_contact_count() const override { return 0; }
	Vector3 _get_contact_local_position(int32_t p_contact_idx) const override { return Vector3(); }
	Vector3 _get_contact_local_normal(int32_t p_contact_idx) const override { return Vector3(); }
	Vector3 _get_contact_impulse(int32_t p_contact_idx) const override { return Vector3(); }
	int32_t _get_contact_local_shape(int32_t p_contact_idx) const override { return 0; }
	Vector3 _get_contact_local_velocity_at_position(int32_t p_contact_idx) const override { return Vector3(); }
	RID _get_contact_collider(int32_t p_contact_idx) const override { return RID(); }
	Vector3 _get_contact_collider_position(int32_t p_contact_idx) const override { return Vector3(); }
	uint64_t _get_contact_collider_id(int32_t p_contact_idx) const override { return 0; }
	Object *_get_contact_collider_object(int32_t p_contact_idx) const override { return nullptr; }
	int32_t _get_contact_collider_shape(int32_t p_contact_idx) const override { return 0; }
	Vector3 _get_contact_collider_velocity_at_position(int32_t p_contact_idx) const override { return Vector3(); }

	float _get_step() const override;
	void _integrate_forces() override {}
	PhysicsDirectSpaceState3D *_get_space_state() override { return nullptr; }
};

} // namespace godot

#endif // MUJOCO_DIRECT_BODY_STATE_H
