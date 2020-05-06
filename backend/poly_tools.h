#ifndef GODOT_GEOMETRY_POLY_TOOLS_H
#define GODOT_GEOMETRY_POLY_TOOLS_H

#include "core/object.h"

class Clipper6; // 6.4.2 (stable)
class Clipper10; // 10.0.0 (sandbox)

#ifndef GEOMETRY_TOOLS_CLIPPER_VERSION_MAJOR
	#define GEOMETRY_TOOLS_CLIPPER_VERSION_MAJOR 6
#endif

#if GEOMETRY_TOOLS_CLIPPER_VERSION_MAJOR == 6
	using PolyTool = Clipper6;
#elif GEOMETRY_TOOLS_CLIPPER_VERSION_MAJOR == 10
	using PolyTool = Clipper10;
#endif

template <typename T>
class PolyMethods {
public:
	real_t polygon_area() {
		return backend().polygon_area_impl();
	}
	T &backend() {
		return *static_cast<T*>(this);
	}
};

class Clipper6 : public PolyMethods<Clipper6> {
public:
	real_t polygon_area_impl() {
		return 6.0;
	}
};

#if GEOMETRY_TOOLS_CLIPPER_VERSION_MAJOR == 10
// Latest development version.
class Clipper10 : public PolyMethods<Clipper10> {
public:
	real_t polygon_area_impl() {
		return 10.0;
	}
};
#endif

#endif // GODOT_GEOMETRY_POLY_TOOLS_H
