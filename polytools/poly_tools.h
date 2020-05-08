#ifndef GEOMETRY_POLY_TOOLS_H
#define GEOMETRY_POLY_TOOLS_H

#include "core/object.h"

template <typename T>
class PolyMethods {
public:
	real_t polygon_area() {
		return backend().polygon_area_impl();
	}
private:
	T &backend() {
		return *static_cast<T*>(this);
	}
};

#endif // GEOMETRY_POLY_TOOLS_H
