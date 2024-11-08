#ifndef AQUILIA_GLOBAL_H_
#define AQUILIA_GLOBAL_H_

#include <godot_cpp/core/math.hpp>

namespace godot::aquilia::global {

// used to produce epsilon relative
// to value of some given operands
constexpr float REL_EPSILON{1e-8f};
// absolute epsilon value
constexpr float ABS_EPSILON{1e-12f};

// 90 degrees in radians
const float R90{Math::deg_to_rad(90.f)};
// 180 degrees in radians
const float R180{Math::deg_to_rad(180.f)};

// TODO: perhaps use some templates instead
bool equalf(const float a, const float b);
bool greater_equalf(const float a, const float b);
bool less_equalf(const float a, const float b);
bool greaterf(const float a, const float b);
bool lesserf(const float a, const float b);
}  // namespace godot::aquilia::global

#endif  // AQUILIA_GLOBAL_H_

