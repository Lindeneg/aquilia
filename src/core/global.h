#ifndef AQUILIA_GLOBAL_H_
#define AQUILIA_GLOBAL_H_

#include <godot_cpp/core/math.hpp>

namespace godot::aquilia::global {

// used to produce epsilon relative
// to value of some given operands
const float REL_EPSILON{1e-8f};
// absolute epsilon value
const float ABS_EPSILON{1e-12f};

// 90 degrees in radians
const float R90{Math::deg_to_rad(90.f)};
// 180 degrees in radians
const float R180{Math::deg_to_rad(180.f)};

// TODO: perhaps use some templates instead
bool equalf(float a, float b);
bool greater_equalf(float a, float b);
bool less_equalf(float a, float b);
bool greaterf(float a, float b);
bool lesserf(float a, float b);
}  // namespace godot::aquilia::global

#endif  // AQUILIA_GLOBAL_H_
