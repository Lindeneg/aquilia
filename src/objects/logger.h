#ifndef AQUILIA_OBJECTS_LOGGER_H_
#define AQUILIA_OBJECTS_LOGGER_H_

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/time.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/variant.hpp>

#include "../core/macros.h"

namespace godot::aquilia {

enum LogLevel { SILENT, DEBUG, WARN, ERROR, FATAL };

class Logger : public RefCounted {
    GDCLASS_EX(Logger, RefCounted)

#ifdef AQUILIA_EXTENSION_DEBUG
    MDV_GET_SET(level, LogLevel, FATAL);
#else
    MDV_GET_SET(level, LogLevel, SILENT);
#endif

    MDV_GET_SET(prefix, String, "Global");

   public:
    static Ref<Logger> with_prefix(const String &prefix);

   private:
    static const char *level_names_[4];
    void log_(const LogLevel level, const String &msg);

   public:
    // TODO: add rest of methods
    void debug(const String &msg);
    template <typename... VarArgs>
    void debugf(const String &msg, const VarArgs... args);
};

template <typename... VarArgs>
void Logger::debugf(const String &msg, const VarArgs... args) {
    debug(vformat(msg, args...));
}
}  // namespace godot::aquilia

VARIANT_ENUM_CAST(godot::aquilia::LogLevel);

#endif  // AQUILIA_OBJECTS_LOGGER_H_
