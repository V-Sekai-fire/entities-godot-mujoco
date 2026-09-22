// SPDX-License-Identifier: Apache-2.0 OR MIT
#include "register_types.h"
#include "mujoco_physics_server.h"
#include "mujoco_direct_body_state.h"

#include <godot_cpp/classes/physics_server3d_manager.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/callable.hpp>

using namespace godot;

void initialize_mujoco_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SERVERS) {
		return;
	}
	GDREGISTER_CLASS(MuJoCoDirectBodyState3D);
	GDREGISTER_CLASS(MuJoCoPhysicsServer);
	PhysicsServer3DManager *mgr = PhysicsServer3DManager::get_singleton();
	if (mgr) {
		mgr->register_server("MuJoCo", callable_mp_static(&MuJoCoPhysicsServer::create));
	}
}

void uninitialize_mujoco_module(ModuleInitializationLevel p_level) {
	(void)p_level;
}

extern "C" {
GDExtensionBool GDE_EXPORT mujoco_library_init(
		GDExtensionInterfaceGetProcAddress p_get_proc_address,
		const GDExtensionClassLibraryPtr p_library,
		GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
	init_obj.register_initializer(initialize_mujoco_module);
	init_obj.register_terminator(uninitialize_mujoco_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SERVERS);
	return init_obj.init();
}
}
