#include "rotational_animation.h"

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>
#include <godot_cpp/variant/dictionary.hpp>

#include "../core/utils.h"

#define DEFAULT "default"
#define IDLE "idle"
#define WALK "walk"
#define ATTACK "attack"

namespace godot::aquilia {

void RotationalAnimation::_ready() {
    if (utils::is_in_editor()) {
        Ref<SpriteFrames> frames{get_sprite_frames()};
        if (get_sprite_frames().is_null()) initialize_sprite_frames_();
    }
}

RotationalAnimation::RotationLimit RotationalAnimation::flip_rotation(
    const float angle) {
    if (angle > global::R90 || angle < -global::R90) {
        set_flip_v(true);
        if (angle < 0) return limits_.lhs_upper;
        return limits_.lhs_lower;
    }
    set_flip_v(false);
    return limits_.rhs;
}

void RotationalAnimation::update_limits() {
    limits_.rhs = RotationLimit(-rotation_boundary_, rotation_boundary_);
    limits_.lhs_upper.max = limits_.lhs_upper.min + rotation_boundary_;
    limits_.lhs_lower.min = limits_.lhs_lower.max - rotation_boundary_;
}

void RotationalAnimation::initialize_sprite_frames_() {
    Ref<SpriteFrames> frames{get_sprite_frames()};
    frames.instantiate();
    if (frames->has_animation(DEFAULT)) {
        frames->remove_animation(DEFAULT);
    }
    frames->add_animation(IDLE);
    frames->add_animation(WALK);
    frames->add_animation(ATTACK);
    set_sprite_frames(frames);
}

float RotationalAnimation::play_animation_(const StringName &name,
                                           const float angle) {
    play(name);
    const RotationLimit bounds{flip_rotation(angle)};
    return Math::clamp(angle, bounds.min, bounds.max);
}

void RotationalAnimation::update_animation(const bool moving,
                                           const bool attacking,
                                           const float angle) {
    if (attacking) {
        attack(angle);
    } else if (moving) {
        walk(angle);
    } else {
        idle();
    }
}

void RotationalAnimation::idle() {
    play(IDLE);
    set_rotation(is_flipped_v() ? global::R180 : 0.f);
}

void RotationalAnimation::walk(const float angle) {
    set_rotation(play_animation_(WALK, angle));
}

void RotationalAnimation::attack(const float angle) {
    set_rotation(play_animation_(ATTACK, angle));
}

void RotationalAnimation::_bind_methods() {
    MPV_BIND(rotation_boundary, RotationalAnimation, Variant::FLOAT);

    ClassDB::bind_method(D_METHOD("idle"), &RotationalAnimation::idle);
    ClassDB::bind_method(D_METHOD("walk", "angle"), &RotationalAnimation::walk);
    ClassDB::bind_method(D_METHOD("attack", "angle"),
                         &RotationalAnimation::attack);
    ClassDB::bind_method(D_METHOD("update_animation", "moving", "angle"),
                         &RotationalAnimation::update_animation);
}

RotationalAnimation::RotationalAnimation() = default;
RotationalAnimation::~RotationalAnimation() = default;
}  // namespace godot::aquilia

