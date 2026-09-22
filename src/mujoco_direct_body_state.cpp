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

Vector3 MuJoCoDirectBodyState3D::_get_total_gravity() const {
	if (model == nullptr) {
		return Vector3(0, -9.81, 0);
	}
	const double *g = model->opt.gravity;
	return Vector3(g[0], g[1], g[2]);
}

float MuJoCoDirectBodyState3D::_get_step() const {
	return model ? (float)model->opt.timestep : 0.0f;
}

float MuJoCoDirectBodyState3D::_get_inverse_mass() const {
	if (model == nullptr || body_id < 0) {
		return 0.0f;
	}
	const double m = model->body_mass[body_id];
	return m > 0.0 ? (float)(1.0 / m) : 0.0f;
}

// MuJoCo integrates in mj_step, so forces are already applied.
void MuJoCoDirectBodyState3D::_integrate_forces() {}
