#include "logger.h"

#include <godot_cpp/variant/utility_functions.hpp>

namespace godot::aquilia {

const char *Logger::level_names_[4]{"DEBUG", "WARN", "ERROR", "FATAL"};

Ref<Logger> Logger::with_prefix(const String &prefix) {
    Ref<Logger> l{};
    l.instantiate();
    l->set_prefix(prefix);
    return l;
}

void Logger::debug(const String &msg) const { log_(DEBUG, msg); }

void Logger::log_(const LogLevel level, const String &msg) const {
    if (level <= SILENT || level_ < level) return;
    const String formatted =
        vformat("[%s] [%s] [%s]: %s", level_names_[level - 1], prefix_,
                Time::get_singleton()->get_datetime_string_from_system(), msg);
    UtilityFunctions::print(formatted);
}

void Logger::_bind_methods() {
    MPV_BIND(level, Logger, Variant::INT);
    MPV_BIND(prefix, Logger, Variant::STRING);

    ClassDB::bind_method(D_METHOD("debug", "msg"), &Logger::debug);

    ClassDB::bind_method(D_METHOD("debugf", "msg", "args"),
                         &Logger::debugf<Variant>);

    ClassDB::bind_static_method("Logger", D_METHOD("with_prefix", "prefix"),
                                &Logger::with_prefix);

    BIND_ENUM_CONSTANT(SILENT);
    BIND_ENUM_CONSTANT(DEBUG);
    BIND_ENUM_CONSTANT(WARN);
    BIND_ENUM_CONSTANT(ERROR);
    BIND_ENUM_CONSTANT(FATAL);
}

Logger::Logger() = default;
Logger::~Logger() = default;

}  // namespace godot::aquilia

