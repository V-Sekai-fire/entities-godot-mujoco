// SPDX-License-Identifier: Apache-2.0 OR MIT
#ifndef REGISTER_TYPES_H
#define REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_mujoco_module(ModuleInitializationLevel p_level);
void uninitialize_mujoco_module(ModuleInitializationLevel p_level);

#endif // REGISTER_TYPES_H
