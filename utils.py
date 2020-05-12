import os


def detect_backends():
    types = {}
    types["polyboolean"] = detect_backends_at_path(os.path.join(get_module_path(), "2d", "polytools", "boolean", "*"))
    types["polyoffset"] = detect_backends_at_path(os.path.join(get_module_path(), "2d", "polytools", "offset", "*"))
    types["polydecomp"] = detect_backends_at_path(os.path.join(get_module_path(), "2d", "polytools", "decomp", "*"))
    return types


def detect_backends_at_path(path):
    from SCons.Script import Glob

    dirs = Glob(path)
    dirs.sort()
    
    backends = {}

    for b in dirs:
        if not os.path.isdir(b.path):
            continue
        backends[os.path.basename(b.path)] = b.abspath

    return backends


def get_module_path():
    return os.path.dirname(os.path.realpath(__file__))
