#ifndef GODOT_GEOMETRY_TOOLS_BIND_H
#define GODOT_GEOMETRY_TOOLS_BIND_H

#include "geometry_tools.h"

class _GeometryTools : public Object {
	GDCLASS(_GeometryTools, Object);

private:
	static _GeometryTools *singleton;

protected:
	static void _bind_methods();

public:
	static _GeometryTools *get_singleton() { return singleton; }
	
public:
	Array merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const;
	Array clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const;
	Array intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const;
	Array exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const;
	
	Array merge_multiple_polygons(Array p_polygons) const;
	Array clip_multiple_polygons(Array p_polygons_a, Array p_polygons_b) const;
	Array intersect_multiple_polygons(Array p_polygons_a, Array p_polygons_b) const;
	Array exclude_multiple_polygons(Array p_polygons_a, Array p_polygons_b) const;

	Ref<PolyNode> polygons_boolean(PolyToolBase::PolyBooleanOperation p_op, Array p_polygons_a, Array p_polygons_b);
	
	Array clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) const;
	Array intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) const;
	Array clip_multiple_polylines_with_polygons(const Array &p_polylines, const Array &p_polygons) const;
	Array intersect_multiple_polylines_with_polygons(const Array &p_polylines, const Array &p_polygons) const;
	
	real_t polygon_area(const Vector<Vector2> &p_polygon);
	
	_GeometryTools();
};

VARIANT_ENUM_CAST(PolyToolBase::PolyBooleanOperation);

#endif // GODOT_GEOMETRY_TOOLS_BIND_H
