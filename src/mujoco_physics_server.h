// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_PHYSICS_SERVER_H
#define MUJOCO_PHYSICS_SERVER_H

#include <godot_cpp/classes/physics_server3d_extension.hpp>
#include <godot_cpp/variant/rid.hpp>

#include <mujoco/mujoco.h>

#include <cstdint>
#include <unordered_map>

#include "mujoco_bridge.h"

namespace godot {

// A Godot 3D physics server backed by MuJoCo linked natively into this extension.
//
// Migrated from delegating to a RISC-V godot-sandbox guest to calling MuJoCo
// directly. The impedance mismatch is unchanged and still proved in
// model/PhysicsBridge.lean: Godot builds the world incrementally while MuJoCo
// compiles it whole, so create/add calls accumulate into an mjSpec, the model is
// compiled before it steps, and any topology change forces a recompile. The
// proven bridge (mujoco_bridge::Bridge) enforces that ordering here.
//
// Native MuJoCo is fast but not bit-identical across CPUs; the cross-host
// determinism story lives in the sandbox demos, not in this backend.
class MuJoCoPhysicsServer : public PhysicsServer3DExtension {
	GDCLASS(MuJoCoPhysicsServer, PhysicsServer3DExtension)

	mujoco_bridge::Bridge bridge;
	mjSpec *spec = nullptr;
	mjModel *model = nullptr;
	mjData *data = nullptr;
	std::unordered_map<uint64_t, mjsBody *> spec_bodies; // rid -> spec body
	bool flushing = false;

	void recompile_if_dirty();

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

	// --- rigid bodies ---
	virtual RID _body_create() override;
	virtual void _body_set_space(const RID &p_body, const RID &p_space) override;
	virtual Variant _body_get_state(const RID &p_body,
			PhysicsServer3D::BodyState p_state) const override;
	virtual void _body_set_state(const RID &p_body,
			PhysicsServer3D::BodyState p_state, const Variant &p_value) override;

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
