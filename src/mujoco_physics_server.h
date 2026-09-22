// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef MUJOCO_PHYSICS_SERVER_H
#define MUJOCO_PHYSICS_SERVER_H

#include <godot_cpp/classes/physics_server3d_extension.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/rid.hpp>

#include "mujoco_bridge.h"

namespace godot {

// A Godot 3D physics server backed by MuJoCo running in the godot-sandbox guest.
//
// The class holds the proven bridge (mujoco_bridge::Bridge): create/free move it
// to `dirty`, and a step is forwarded to the guest only when it is `compiled`,
// which is exactly what model/PhysicsBridge.lean proves keeps a stale model from
// being stepped and keeps RID <-> index from aliasing.
//
// The heavy lifting still to land: turning the buffered create/add calls into an
// MJCF (or mjSpec) description the guest compiles, and marshalling body and
// flex-vertex state back across the sandbox boundary via the Sandbox vmcalls
// (mjc_load_xml, mjc_step, mjc_bodies, mjc_flexverts). The ~150-method
// PhysicsServer3DExtension surface is declared incrementally as each is wired.
class MuJoCoPhysicsServer : public PhysicsServer3DExtension {
	GDCLASS(MuJoCoPhysicsServer, PhysicsServer3DExtension)

	mujoco_bridge::Bridge bridge;
	Object *sandbox = nullptr; // the godot-sandbox Sandbox instance running mujoco.elf
	bool flushing = false;
	bool model_dirty = true;

protected:
	static void _bind_methods() {}

public:
	// The creator PhysicsServer3DManager calls when the project selects "MuJoCo".
	static PhysicsServer3D *create();

	// --- lifecycle / stepping (the proven guard lives here) ---
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

	// --- rigid bodies (crowd) ---
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
