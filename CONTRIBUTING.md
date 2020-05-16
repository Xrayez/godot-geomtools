# Contributing

Thanks for taking interest in contributing!

If you think that the module is missing some useful geometry utility methods,
you can open an issue describing your use case or discuss the ways of
implementing such methods if you want to do it yourself.

---

## Where do I start?

Any utility methods must be implemented as static methods, for instance:

* [2d/geometry_tools.h](2d/geometry_tools.h)
* [2d/geometry_tools.cpp](2d/geometry_tools.cpp) 

and later exposed to scripting, for instance:

* [2d/bind/geometry_tools_bind.h](2d/bind/geometry_tools_bind.h)
* [2d/bind/geometry_tools_bind.cpp](2d/bind/geometry_tools_bind.cpp)

You can leave the binding part and let other contributors finish your work. If
that's the case, the method will be available within the engine for C++
development only.

## Implementing back-ends

Polygon (polypath) clipping, offsetting, and decomposition back-ends can be
implemented independently by extending various `Poly*[2D,3D]` base classes:

* [2d\polytools\boolean\poly_boolean.h](2d\polytools\boolean\poly_boolean.h)
* [2d\polytools\offset\poly_offset.h](2d\polytools\offset\poly_offset.h)
* [2d\polytools\decomp\poly_decomp.h](2d\polytools\decomp\poly_decomp.h)

The exact implementation must reside in either of those base folders under the
dedicated folder. The rest is handled by the build system by detecting the newly
implemented back-ends. The implemented back-end's name (matching the folder
name) can be passed as an option to `scons` while building.

Don't forget to add `using Poly*[2D,3D] = Poly*[2D,3D]YourClass` typedef statement to
actually override the implementation at compile-time.

## 3D realms

If you're a person interested in 3D development, feel free to dive into the
[3d/SCsub](3d/SCsub) and go wild, similarly to the 2D module by implementing
`GeometryTools3D` singleton.

---

## Third-party

Binding to thirdparty libraries is acceptable but they must be compatible with
the MIT license. It might be OK linking other not-so-permissive libraries as
long as they can be implemented as back-ends which can be disabled and not to be
provided by default.
