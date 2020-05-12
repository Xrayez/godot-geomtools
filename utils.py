import os

def detect_polyboolean_backends():
    return detect_backends(os.path.join(get_module_path(), "2d", "polytools", "boolean", "*"))


def detect_polyoffset_backends():
    return detect_backends(os.path.join(get_module_path(), "2d", "polytools", "offset", "*"))


def detect_polydecomp_backends():
    return detect_backends(os.path.join(get_module_path(), "2d", "polytools", "decomp", "*"))


def detect_backends(path):
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
