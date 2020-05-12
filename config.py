
def can_build(env, platform):
    return True


def configure(env):
    from SCons.Script import Variables, Help
    from utils import detect_backends

    opts = Variables()
    
    types = detect_backends()
    for name, backends in types.items():
        choices = "|".join(backends.keys())
        if name == "polyboolean":
            opts.Add("geomtools_polyboolean", "Library used for polygon boolean operations. (%s)" % (choices), "clipper6")
        elif name == "polyoffset":
            opts.Add("geomtools_polyoffset", "Library used for polygon offsetting. (%s)" % (choices), "clipper6")
        elif name == "polydecomp":
            opts.Add("geomtools_polydecomp", "Library used for polygon decomposition. (%s)" % (choices), "builtin")

    opts.Update(env)
    Help(opts.GenerateHelpText(env))


def get_doc_classes():
    return [
        "GeometryTools2D",
    ]


def get_doc_path():
    return "docs"
