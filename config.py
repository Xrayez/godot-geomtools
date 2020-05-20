
def can_build(env, platform):
    return True


def configure(env):
    from SCons.Script import Variables, Help

    opts = Variables()

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
