# Godot GeometryTools

[![Build Status](https://travis-ci.com/Xrayez/godot-geomtools.svg?branch=master-gd3)](https://travis-ci.com/Xrayez/godot-geomtools)
[![Build status](https://ci.appveyor.com/api/projects/status/tbtra8e221si05bq/branch/master-gd3?svg=true)](https://ci.appveyor.com/project/Xrayez/godot-geomtools/branch/master-gd3)

This is a [Godot](https://github.com/godotengine/godot) module which provides
geometry math methods not typically provided by the built-in `Geometry`
singleton. The module provides a `GeometryTools` singleton, which aims cater
specific user needs.

### Compatibility
There are separate branches which are targeted for specific Godot Engine's major
version.

Regarding latest module version in development, switch to
* [`master-gd3`](https://github.com/Xrayez/godot-geomtools/tree/master-gd3) branch for Godot 3
* [`master-gd4`](https://github.com/Xrayez/godot-geomtools/tree/master-gd4) branch for Godot 4

Similarly, you may use any of the stable branches with a similar branch
encoding, such as `1.0-gd3` or `1.0-gd4`, if available.

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

## Contributing
     
See [Contributing](CONTRIBUTING.md) if you are interested in extending the
module in any way.

Any new features are encouraged to be developed against the latest Godot
Engine's *stable* version, and later ported to the latest engine's *development*
version.

## License and third-party libraries

The module is under MIT license.

The module uses [Clipper](url) library for polygon operations which is under
LICENSE license, see [thirdparty/README.md](thirdparty/README.md)
