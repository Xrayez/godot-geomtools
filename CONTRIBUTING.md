# Contributing

Thanks for taking interest in contributing!

If you think that the module is missing some useful geometry utility methods,
you can open an issue describing your use case or discuss the ways of
implementing such methods if you want to do it yourself.

---

## Where do I start?

Any utility methods must be implemented as static methods in:

* [geometry_tools.h](geometry_tools.h)
* [geometry_tools.cpp](geometry_tools.cpp) 

and later exposed to scripting in:

* [bind/geometry_tools_bind.h](bind/geometry_tools_bind.h)
* [bind/geometry_tools_bind.cpp](bind/geometry_tools_bind.cpp)

You can leave the binding part and let other contributors finish your work. In
that's the case, the method will be available within the engine only.

---

## Thirdparty

Binding to thirdparty libraries is acceptable but they must be compatible with
MIT license.
