#include "attacker.h"

#include "../core/utils.h"

namespace godot::aquilia {

void Attacker::_process(double) {
    if (utils::is_in_editor()) return;
    if (utils::input_down(attack_action_)) {
        attacking_ = true;
    }
    if (utils::input_up(attack_action_)) {
        attacking_ = false;
    }
}

void Attacker::_bind_methods() {
    MPV_BIND(attack_action, Attacker, Variant::STRING_NAME);
    MPV_BIND(health, Attacker, Variant::INT);
    M_BIND(attacking, Attacker);
}

Attacker::Attacker() = default;
Attacker::~Attacker() = default;
}  // namespace godot::aquilia
