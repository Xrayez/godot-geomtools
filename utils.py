import os

def detect_polyboolean_backends():
    from SCons.Script import Glob

    dirs = Glob(os.path.join(get_module_path(), "polytools", "backends", "boolean", "*"))
    dirs.sort()
    
    backends = {}

    for b in dirs:
        if not os.path.isdir(b.path):
            continue
        backends[os.path.basename(b.path)] = b.abspath

    return backends


def get_module_path():
    return os.path.dirname(os.path.realpath(__file__))
