#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/poly_tools.h"
#include "polytools/poly_tools_backend.gen.h"

class GeometryTools {
private:
	static PolyTool *pt;
public:
	static void poly_tool_init();
	static void poly_tool_deinit();
public:
	static real_t polygon_area(const Vector<Vector2> &p_polygon);
	static Ref<PolyNode> polygons_boolean(PolyToolBase::PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >());
};

#endif // GODOT_GEOMETRY_TOOLS_H
