#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/poly_tools_backend.gen.h"

class GeometryTools {
private:
	static PolyTool pt;
public:
	static real_t polygon_area(const Vector<Vector2> &p_polygon);
};

#endif // GODOT_GEOMETRY_TOOLS_H
