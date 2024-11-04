#ifndef AQUILIA_EXTENSION_REGISTER_TYPES_H_
#define AQUILIA_EXTENSION_REGISTER_TYPES_H_

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_aquilia_extension_module(ModuleInitializationLevel p_level);
void uninitialize_aquilia_extension_module(ModuleInitializationLevel p_level);

#endif  // AQUILIA_EXTENSION_REGISTER_TYPES_H_

