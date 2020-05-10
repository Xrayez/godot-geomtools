#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/poly_tools.h"
#include "polytools/poly_tools_backend.gen.h"

class GeometryTools {
public:
	// Single polygon vs polygon boolean operations.
	static Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b);
	static Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b);
	static Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b);
	static Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b);
	
	// Multiple polygons vs polygons boolean operations.
	static Vector<Vector<Point2> > merge_multiple_polygons(const Vector<Vector<Point2> > &p_polygons);
	static Vector<Vector<Point2> > clip_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b);
	static Vector<Vector<Point2> > intersect_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b);
	static Vector<Vector<Point2> > exclude_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b);
	
	// General-purpose polygon boolean operations, accepts multiple polygons.
	static Ref<PolyNode> polygons_boolean(PolyToolBase::PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >());
	
	static real_t polygon_area(const Vector<Vector2> &p_polygon);
public:
	static void poly_tool_init();
	static void poly_tool_deinit();
private:
	static PolyTool *pt;
};

#endif // GODOT_GEOMETRY_TOOLS_H
