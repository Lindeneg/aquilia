#include "mouse-moveable.h"

#include "../core/utils.h"

namespace godot::aquilia {

void MouseMoveable::_process(double) {
    if (utils::is_in_editor()) return;
    if (utils::input_pressed(move_action_)) input_();
}

void MouseMoveable::input_() {
    const Vector2 pos{get_global_position()};
    const Vector2 dest{get_global_mouse_position()};
    set_destination(dest);
    set_direction((dest - pos).normalized());
    set_moving(distance_to_target(pos) > min_move_threshold_);
}

void MouseMoveable::_bind_methods() {
    MPV_BIND(min_move_threshold, MouseMoveable, Variant::INT);
    MPV_BIND(move_action, MouseMoveable, Variant::STRING_NAME);
}

MouseMoveable::MouseMoveable() = default;
MouseMoveable::~MouseMoveable() = default;
}  // namespace godot::aquilia

