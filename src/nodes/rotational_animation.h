#ifndef AQUILIA_NODES_ROTATIONAL_ANIMATION_H_
#define AQUILIA_NODES_ROTATIONAL_ANIMATION_H_

#include <godot_cpp/classes/animated_sprite2d.hpp>

#include "../core/global.h"
#include "../core/macros.h"

namespace godot {
class Dictionary;
}  // namespace godot

namespace godot::aquilia {
class Moveable;

class RotationalAnimation : public AnimatedSprite2D {
    struct RotationLimit {
        float min;
        float max;

        RotationLimit() : min(0), max(0) {}
        RotationLimit(const float min, const float max) : min(min), max(max) {}
    };

    struct RotationLimits {
        RotationLimit rhs = {0, 0};
        RotationLimit lhs_upper = {-global::R180, 0};
        RotationLimit lhs_lower = {0, global::R180};
    };

    GDCLASS_EX(RotationalAnimation, AnimatedSprite2D)

   private:
    // boundary is in radians
    float rotation_boundary_ = 0.f;
    RotationLimits limits_ = RotationLimits();

    // flips the animation sprite and returns
    // min and max rotation boundaries given a radian angle
    RotationLimit flip_rotation(float angle);

    void update_limits();
    void initialize_sprite_frames_();
    float play_animation_(const StringName &name, const float angle);

   public:
    void _ready() override;

    [[nodiscard]] inline float get_rotation_boundary() const {
        return Math::rad_to_deg(rotation_boundary_);
    }
    inline void set_rotation_boundary(const float d) {
        rotation_boundary_ = Math::deg_to_rad(d);
        update_limits();
    }

    void idle_fixed();
    void idle_free(const float angle);
    // TODO: set animation fps given current velocity
    void walk(const float angle);
    void attack(const float angle);
};
}  // namespace godot::aquilia

#endif  // AQUILIA_NODES_ROTATIONAL_ANIMATION_H_
