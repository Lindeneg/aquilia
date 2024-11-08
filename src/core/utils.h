#ifndef AQUILIA_UTILS_H_
#define AQUILIA_UTILS_H_

#include <godot_cpp/classes/node.hpp>

namespace godot {
class String;
class StringName;
class Callable;
class Resource;
}  // namespace godot

namespace godot::aquilia::utils {

template <typename T>
T *create_component(Node *owner, const bool add_child = true) {
    T *obj = memnew(T);
    if (add_child) {
        owner->add_child(obj);
        obj->set_owner(owner);
    }
    return obj;
}

bool is_in_editor();
bool is_in_game();
const char *convert_gd_string(const Node *n);
const char *convert_gd_string(const Resource *n);
const char *convert_gd_string(const String &s);
const char *convert_gd_string(const StringName &s);
void connect(Node *node, const StringName &name, const Callable &callable);
void disconnect(Node *node, const StringName &name, const Callable &callable);
void queue_delete(Node *node);
bool input_pressed(const StringName &name);
bool input_down(const StringName &name);
bool input_up(const StringName &name);
}  // namespace godot::aquilia::utils

#endif  // AQUILIA_UTILS_H_

