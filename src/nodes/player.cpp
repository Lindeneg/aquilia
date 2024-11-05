#include "player.h"

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>

#include "../core/utils.h"
#include "../nodes/mouse-moveable.h"
#include "../nodes/rotational_animation.h"

namespace godot::aquilia {
void Player::_ready() {
    log_ = Logger::with_prefix(get_name());
    REQUIRED_CHILD(body_sprite_, "Body", RotationalAnimation);
    REQUIRED_CHILD(weapon_sprite_, "Weapon", RotationalAnimation);
    REQUIRED_CHILD(moveable_, "MouseMoveable", MouseMoveable);
    REQUIRED_CHILD(collision_shape_, "CollisionShape", CollisionShape2D);
}

void Player::_physics_process(const double delta) {
    if (utils::is_in_editor()) return;
    move_and_collide(moveable_->velocity(static_cast<float>(delta)));
    update_animation_();
}

void Player::update_animation_() const {
    const float angle{moveable_->angle_to_target(get_global_position())};
    const bool moving{moveable_->get_moving()};
    const bool halting{moveable_->get_halting()};

    if (moving && !halting) {
        body_sprite_->walk(angle);
    } else {
        body_sprite_->idle_fixed();
    }

    if (moving || halting) {
        weapon_sprite_->idle_free(angle);
    } else {
        weapon_sprite_->idle_fixed();
    }
}

void Player::_bind_methods() {
    MPN_BIND(collision_shape, Player, CollisionShape2D)
    MPN_BIND(moveable, Player, Moveable)
    MPN_BIND(body_sprite, Player, RotationalAnimation);
    MPN_BIND(weapon_sprite, Player, RotationalAnimation);
}

Player::Player() = default;
Player::~Player() {
    utils::queue_delete(body_sprite_);
    utils::queue_delete(weapon_sprite_);
    utils::queue_delete(moveable_);
    utils::queue_delete(collision_shape_);
}
}  // namespace godot::aquilia

