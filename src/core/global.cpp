#include "global.h"

static bool equal_rel(const float a, const float b) {
    return (godot::Math::absf(a - b) <=
            (godot::Math::max(godot::Math::absf(a), godot::Math::absf(b)) *
             godot::aquilia::global::REL_EPSILON));
}

namespace godot::aquilia::global {
bool equalf(const float a, const float b) {
    if (Math::absf(a - b) <= ABS_EPSILON) {
        return true;
    }
    return equal_rel(a, b);
}

bool greater_equalf(const float a, const float b) {
    if (equalf(a, b)) {
        return true;
    }
    return a > b;
}

bool less_equalf(const float a, const float b) {
    if (equalf(a, b)) {
        return true;
    }
    return a < b;
}

bool greaterf(const float a, const float b) {
    if (equalf(a, b)) {
        return false;
    }
    return a > b;
}

bool lesserf(const float a, const float b) {
    if (equalf(a, b)) {
        return false;
    }
    return a < b;
}
}  // namespace godot::aquilia::global

