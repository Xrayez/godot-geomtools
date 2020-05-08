#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/poly_tools_backends.h"

class GeometryTools {
private:
	static PolyTool pt;
public:
	static real_t polygon_area() {
		return pt.polygon_area();
	}
};

#endif // GODOT_GEOMETRY_TOOLS_H
