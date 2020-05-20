# Godot GeometryTools

[![Build Status](https://travis-ci.com/Xrayez/godot-geomtools.svg?branch=master-gd3)](https://travis-ci.com/Xrayez/godot-geomtools)
[![Build status](https://ci.appveyor.com/api/projects/status/tbtra8e221si05bq/branch/master-gd3?svg=true)](https://ci.appveyor.com/project/Xrayez/godot-geomtools/branch/master-gd3)

This is a [Godot](https://github.com/godotengine/godot) module which provides
various geometry methods and aims to build upon the builtin `Geometry` singleton.

## Overview

The module exposes a `GeometryTools2D` singleton with the methods for performing
polygon clipping, offsetting (deflating/buffering) and decomposition
(triangulation, convex decomposition), as well as providing polypath queries
such as polygon area, centroid of a polygon, point in polygon, and generating
geometrical shapes at run-time.

The interface is similar to what you can see in the `Geometry` singleton
regarding polygon clipping and offsetting first introduced in
[Godot Engine 3.2](https://github.com/godotengine/godot/pull/28987), yet the
module brings many other possibilities such as multiple polygon clipping,
building polygon hierarchy, exposing other not-so-common parameters and of
course QoL methods, if necessary.

Each class of the methods are implemented by their respective back-ends and can
be switched at compile-time. See below instructions on the various options on
how to configure the build.

## Installation

Before installing, you must be able to 
[compile Godot Engine](https://docs.godotengine.org/en/latest/development/compiling/) 
from source.

```bash
# Change directory to `modules` subfolder of Godot repository
cd godot/modules/
# Clone the module under directory named `geomtools`
git clone https://github.com/Xrayez/godot-geomtools.git geomtools && cd ..
# Compile the engine manually, for instance:
scons platform=windows target=release_debug bits=64
```

## Configuring the build

### Switching backends

There are a handful of back-ends to choose from:

| Class             | Backends                | Default     |
| ----------------- | ----------------------- | ----------- |
| `poly_boolean_2d` | `clipper6`, `clipper10` | `clipper6`  |
| `poly_offset_2d`  | `clipper6`, `clipper10` | `clipper6`  |
| `poly_decomp_2d`  | `clipper10`, `builtin`  | `clipper10` |

#### Differences

`clipper6` backend implements both polygon clipping and offsetting. Uses
[Clipper 6.4.2
stable](https://sourceforge.net/p/polyclipping/code/HEAD/tree/trunk/) version
which is bundled with Godot Engine since 3.2.

Experimental `clipper10` backend implements most major features which `clipper6`
provides, with an additional ability to triangulate the clipping output. Uses
[Clipper 10.0.0 sandbox](https://sourceforge.net/p/polyclipping/code/HEAD/tree/sandbox/Clipper2/)
version which is still under development.

`builtin` backend aims to take advantage of the existing code bundled with Godot
Engine by default if you need stability and/or consistency, or if you don't want
to rely on the module's experimental implementations (such as `clipper10`).

#### Command line options

| Name                        | Description                                                                                                                                                      |
| --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `geomtools_poly_boolean_2d` | The backend used for polygon and polyline clipping.                                                                                                              |
| `geomtools_poly_offset_2d`  | The backend used for polygon and polyline deflating and inflating.                                                                                               |
| `geomtools_poly_decomp_2d`  | The backend used for polygon decomposition (triangulation).                                                                                                      |
| `geomtools_scale_factor`    | The precision used for converting between the integer and the float coordinates. Beware of the too high scale factors as it may lead to integer overflow issues. |

The default backends used can be overridden before a build. For instance, to use
the latest Clipper backend for all methods:
```
scons geomtools_poly_boolean_2d=clipper10 geomtools_poly_offset_2d=clipper10 geomtools_poly_decomp_2d=clipper10
```

## Contributing
     
See [Contributing](CONTRIBUTING.md) if you are interested in extending the
module in any way.

The module lacks implementation on 3D, so feel free to be the first one to
contribute in this area.

Any new features are encouraged to be developed against the latest Godot
Engine's *stable* version, and later ported to the latest engine's *development*
version.

## License

The module is under the [MIT license](LICENSE.md).

See the full list of third-party libraries at [thirdparty/README.md](thirdparty/README.md).
