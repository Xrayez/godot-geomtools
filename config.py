import utils


def can_build(env, platform):
    return True


def configure(env):
    from SCons.Script import Glob, Variables, BoolVariable, Help, Exit
    import os
    
    opts = Variables()
    
    polyboolean_backends = utils.detect_polyboolean_backends()
    blist = list(polyboolean_backends.keys())
    opts.Add("geomtools_polyboolean", "The library used for polygon operations. (%s)" % ("|".join(blist)), "clipper6")

    opts.Update(env)
    Help(opts.GenerateHelpText(env))


def get_doc_classes():
    return [
        "GeometryTools",
    ]


def get_doc_path():
    return "docs"
