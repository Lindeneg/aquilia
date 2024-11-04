#ifndef AQUILIA_NODES_PLAYER_H_
#define AQUILIA_NODES_PLAYER_H_

#include <godot_cpp/classes/character_body2d.hpp>

#include "../core/macros.h"
#include "../objects/logger.h"

namespace godot {
class AnimatedSprite2D;
class CollisionShape2D;
}  // namespace godot

namespace godot::aquilia {
class Moveable;
class RotationalAnimation;
class MouseMoveable;

class Player : public CharacterBody2D {
    GDCLASS_EX(Player, CharacterBody2D);

    MDV_GET_SET_T(body_sprite, RotationalAnimation*, nullptr);
    MDV_GET_SET_T(weapon_sprite, RotationalAnimation*, nullptr);
    MDV_GET_SET_T(moveable, MouseMoveable*, nullptr);
    MDV_GET_SET_T(collision_shape, CollisionShape2D*, nullptr);

   private:
    Ref<Logger> log_ = {};
    void update_animation_() const;

   public:
    void _ready() override;
    void _physics_process(double) override;
};
}  // namespace godot::aquilia

#endif  // AQUILIA_NODES_PLAYER_H_
