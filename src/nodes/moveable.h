#ifndef AQUILIA_NODES_MOVEABLE_H_
#define AQUILIA_NODES_MOVEABLE_H_

#include <godot_cpp/classes/node2d.hpp>

#include "../core/macros.h"

namespace godot::aquilia {

class Moveable : public Node2D {
    GDCLASS_EX(Moveable, Node2D)

    MDV_GET_SET(base_speed, float, 150.f);
    MDV_GET_SET(target_threshold, int, 50);
    MDV_GET_SET(moving, bool, false);
    MDV_GET_SET(destination, Vector2, Vector2());
    MDV_GET_SET(direction, Vector2, Vector2());

   public:
    void _physics_process(double delta) override;

    [[nodiscard]] bool destination_reached(const Vector2 &position) const;
    [[nodiscard]] int distance_to_target(const Vector2 &position) const;
    [[nodiscard]] float angle_to_target(const Vector2 &position) const;
    Vector2 velocity(const float delta) const;
};
}  // namespace godot::aquilia

#endif  // AQUILIA_NODES_MOVEABLE_H_
