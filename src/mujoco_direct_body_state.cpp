// SPDX-License-Identifier: Apache-2.0 OR MIT
#include "mujoco_direct_body_state.h"

using namespace godot;

Transform3D MuJoCoDirectBodyState3D::_get_transform() const {
	Transform3D t;
	if (model == nullptr || data == nullptr || body_id < 0) {
		return t;
	}
	const double *xp = data->xpos + body_id * 3;
	const double *xq = data->xquat + body_id * 4; // MuJoCo quat is wxyz
	t.basis = Basis(Quaternion(xq[1], xq[2], xq[3], xq[0]));
	t.origin = Vector3(xp[0], xp[1], xp[2]);
	return t;
}

Vector3 MuJoCoDirectBodyState3D::_get_linear_velocity() const {
	if (model == nullptr || data == nullptr || body_id < 0) {
		return Vector3();
	}
	mjtNum vel[6];
	mj_objectVelocity(model, data, mjOBJ_BODY, body_id, vel, 0); // [angular; linear], global
	return Vector3(vel[3], vel[4], vel[5]);
}

Vector3 MuJoCoDirectBodyState3D::_get_angular_velocity() const {
	if (model == nullptr || data == nullptr || body_id < 0) {
		return Vector3();
	}
	mjtNum vel[6];
	mj_objectVelocity(model, data, mjOBJ_BODY, body_id, vel, 0);
	return Vector3(vel[0], vel[1], vel[2]);
}

Vector3 MuJoCoDirectBodyState3D::_get_velocity_at_local_position(const Vector3 &p_local_position) const {
	// v + w x r, in the world frame.
	const Vector3 v = _get_linear_velocity();
	const Vector3 w = _get_angular_velocity();
	return v + w.cross(p_local_position);
}

Vector3 MuJoCoDirectBodyState3D::_get_total_gravity() const {
	if (model == nullptr) {
		return Vector3(0, -9.81, 0);
	}
	const double *g = model->opt.gravity;
	return Vector3(g[0], g[1], g[2]);
}

Vector3 MuJoCoDirectBodyState3D::_get_center_of_mass() const {
	if (data == nullptr || body_id < 0) {
		return Vector3();
	}
	const double *c = data->xipos + body_id * 3; // world inertial-frame position
	return Vector3(c[0], c[1], c[2]);
}

Vector3 MuJoCoDirectBodyState3D::_get_center_of_mass_local() const {
	if (model == nullptr || body_id < 0) {
		return Vector3();
	}
	const double *c = model->body_ipos + body_id * 3;
	return Vector3(c[0], c[1], c[2]);
}

float MuJoCoDirectBodyState3D::_get_inverse_mass() const {
	if (model == nullptr || body_id < 0) {
		return 0.0f;
	}
	const double m = model->body_mass[body_id];
	return m > 0.0 ? (float)(1.0 / m) : 0.0f;
}

Vector3 MuJoCoDirectBodyState3D::_get_inverse_inertia() const {
	if (model == nullptr || body_id < 0) {
		return Vector3();
	}
	const double *I = model->body_inertia + body_id * 3;
	return Vector3(I[0] > 0 ? 1.0 / I[0] : 0.0, I[1] > 0 ? 1.0 / I[1] : 0.0, I[2] > 0 ? 1.0 / I[2] : 0.0);
}

Basis MuJoCoDirectBodyState3D::_get_inverse_inertia_tensor() const {
	const Vector3 inv = _get_inverse_inertia();
	return Basis(Vector3(inv.x, 0, 0), Vector3(0, inv.y, 0), Vector3(0, 0, inv.z));
}

float MuJoCoDirectBodyState3D::_get_step() const {
	return model ? (float)model->opt.timestep : 0.0f;
}
