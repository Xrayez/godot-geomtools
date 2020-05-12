import utils


def can_build(env, platform):
    return True


def configure(env):
    from SCons.Script import Glob, Variables, BoolVariable, Help, Exit
    import os
    
    opts = Variables()
    
    polyboolean_backends = utils.detect_polyboolean_backends()
    blist = list(polyboolean_backends.keys())
    opts.Add("geomtools_polyboolean", "Library used for polygon operations. (%s)" % ("|".join(blist)), "clipper6")
    
    polyoffset_backends = utils.detect_polyoffset_backends()
    blist = list(polyoffset_backends.keys())
    opts.Add("geomtools_polyoffset", "Library used for polygon offsetting. (%s)" % ("|".join(blist)), "clipper6")
    
    polydecomp_backends = utils.detect_polydecomp_backends()
    blist = list(polydecomp_backends.keys())
    opts.Add("geomtools_polydecomp", "Library used for polygon decomposition. (%s)" % ("|".join(blist)), "builtin")

    opts.Update(env)
    Help(opts.GenerateHelpText(env))


def get_doc_classes():
    return [
        "GeometryTools2D",
    ]


def get_doc_path():
    return "docs"
