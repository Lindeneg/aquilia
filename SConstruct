#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["src/core/", "src/nodes/", "src/objects/"])

if env["target"] == "template_debug" or env["target"] == "editor":
    env.Append(CPPDEFINES=["AQUILIA_EXTENSION_DEBUG=1"])

sources = Glob("src/**/*.cpp")
library = env.SharedLibrary(
        "aquilia/bin/aquilia{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources)

Default(library)

