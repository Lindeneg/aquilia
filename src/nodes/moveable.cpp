#include "moveable.h"

#include "../core/utils.h"

namespace godot::aquilia {
void Moveable::_physics_process(double delta) {
    if (utils::is_in_editor()) return;
    if (moving_ && destination_reached(get_global_position())) {
        moving_ = false;
    }
}

bool Moveable::destination_reached(const Vector2 &position) const {
    if (!moving_) return true;
    return distance_to_target(position) <= target_threshold_;
}

int Moveable::distance_to_target(const Vector2 &position) const {
    return static_cast<int>((position - destination_).length_squared());
}

float Moveable::angle_to_target(const Vector2 &position) const {
    return position.angle_to_point(destination_);
}

Vector2 Moveable::velocity_(const float delta) const {
    if (!moving_) return {0, 0};
    return direction_ * base_speed_ * delta;
}

void Moveable::_bind_methods() {
    MPV_BIND(base_speed, Moveable, Variant::FLOAT)
    MPV_BIND(target_threshold, Moveable, Variant::INT)

    M_BIND(moving, Moveable);
    M_BIND(destination, Moveable);
    M_BIND(direction, Moveable);

    ClassDB::bind_method(D_METHOD("destination_reached", "position"),
                         &Moveable::destination_reached);

    ClassDB::bind_method(D_METHOD("distance_to_target", "position"),
                         &Moveable::distance_to_target);

    ClassDB::bind_method(D_METHOD("angle_to_target", "position"),
                         &Moveable::angle_to_target);
}

Moveable::Moveable() = default;

Moveable::~Moveable() = default;
}  // namespace godot::aquilia

