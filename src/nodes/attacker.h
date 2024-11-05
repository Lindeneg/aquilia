#ifndef AQUILIA_NODES_ATTACKER_H_
#define AQUILIA_NODES_ATTACKER_H_

#include <godot_cpp/classes/node.hpp>

#include "../core/macros.h"

namespace godot::aquilia {

class Attacker : public Node {
    GDCLASS_EX(Attacker, Node);

    MDV_GET_SET(health, int, 100);
    MDV_GET_SET(attacking, bool, false);
    MDV_GET_SET_R(attack_action, StringName, "attack-action");

   public:
    void _process(double) override;
};
}  // namespace godot::aquilia

#endif  // AQUILIA_NODES_ATTACKER_H_
