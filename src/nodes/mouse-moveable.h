#ifndef AQUILIA_NODES_MOUSE_MOVEABLE_H_
#define AQUILIA_NODES_MOUSE_MOVEABLE_H_

#include <godot_cpp/classes/node.hpp>

#include "../core/macros.h"
#include "./moveable.h"

namespace godot::aquilia {

class MouseMoveable : public Moveable {
    GDCLASS_EX(MouseMoveable, Moveable)

    // minimum range for mouse click to cause movement
    MDV_GET_SET(min_move_threshold, int, 10000);
    // input action to move player
    MDV_GET_SET_R(move_action, StringName, "move-action");
    // input action to halt player (but still be able to rotate)
    MDV_GET_SET_R(halt_action, StringName, "halt-action");
    MDV_GET_SET(halting, bool, false);

   private:
    void input_();

   public:
    void _process(double) override;
};
}  // namespace godot::aquilia

#endif  // AQUILIA_NODES_MOUSE_MOVEABLE_H_
