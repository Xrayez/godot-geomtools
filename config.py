
def can_build(env, platform):
    return True


def configure(env):
    from SCons.Script import Variables, Help
    from utils import detect_backends

    opts = Variables()
    
    types = detect_backends()
    for name, backends in types.items():
        choices = "|".join(backends.keys())
        if name == "polyboolean_2d":
            opts.Add("geomtools_polyboolean_2d", "Library used for polygon boolean operations. (%s)" % (choices), "clipper6")
        elif name == "polyoffset_2d":
            opts.Add("geomtools_polyoffset_2d", "Library used for polygon offsetting. (%s)" % (choices), "clipper6")
        elif name == "polydecomp_2d":
            opts.Add("geomtools_polydecomp_2d", "Library used for polygon decomposition. (%s)" % (choices), "clipper10")

    opts.Add("geomtools_scale_factor", 
        "The precision used for converting between integer and float coordinates throughout " +
        "poly backends implementations for computational robustness purposes.", "1e5")

    opts.Update(env)
    
    def help_format(env, opt, help, default, actual, aliases):
        if opt == "geomtools_scale_factor":
            fmt = "\n%s: %s.\n    default: %s (based on CMP_EPSILON)\n    actual: %s\n"
        else:
            fmt = "\n%s: %s.\n    default: %s\n    actual: %s\n"
        return fmt % (opt, help, default, actual)
    
    opts.FormatVariableHelpText = help_format
    Help(opts.GenerateHelpText(env))


def get_doc_classes():
    return [
        "GeometryTools2D",
        "PolyBooleanParameters2D",
        "PolyOffsetParameters2D",
        "PolyDecompParameters2D",
        "PolyNode2D",
    ]


def get_doc_path():
    return "docs"
