#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "../nodes/attacker.h"
#include "../nodes/mouse-moveable.h"
#include "../nodes/moveable.h"
#include "../nodes/player.h"
#include "../nodes/rotational_animation.h"
#include "../objects/logger.h"

using namespace godot;

void initialize_aquilia_extension_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    ClassDB::register_class<aquilia::Logger>();
    ClassDB::register_class<aquilia::Attacker>();
    ClassDB::register_class<aquilia::Moveable>();
    ClassDB::register_class<aquilia::MouseMoveable>();
    ClassDB::register_class<aquilia::RotationalAnimation>();
    ClassDB::register_class<aquilia::Player>();
}

void uninitialize_aquilia_extension_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
GDExtensionBool GDE_EXPORT aquilia_extension_library_init(
    GDExtensionInterfaceGetProcAddress p_get_proc_address,
    const GDExtensionClassLibraryPtr p_library,
    GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address,
                                                   p_library, r_initialization);

    init_obj.register_initializer(initialize_aquilia_extension_module);
    init_obj.register_terminator(uninitialize_aquilia_extension_module);
    init_obj.set_minimum_library_initialization_level(
        MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}

