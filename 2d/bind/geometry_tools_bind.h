#ifndef GODOT_GEOMETRY_TOOLS_BIND_H
#define GODOT_GEOMETRY_TOOLS_BIND_H

#include "modules/geomtools/2d/geometry_tools.h"

namespace module_bind {

class GeometryTools2D : public Object {
	GDCLASS(GeometryTools2D, Object);

private:
	static GeometryTools2D *singleton;

protected:
	static void _bind_methods();

public:
	static GeometryTools2D *get_singleton() { return singleton; }
	
public:
	Array merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	
	Array merge_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array clip_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array intersect_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array exclude_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;

	Ref<PolyNode2D> polygons_boolean_tree(PolyBooleanBase2D::Operation p_op, Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	
	Array clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params) const;
	Array intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params) const;
	Array clip_polylines_with_polygons_array(const Array &p_polylines, const Array &p_polygons, Ref<PolyBooleanParameters2D> p_params) const;
	Array intersect_polylines_with_polygons_array(const Array &p_polylines, const Array &p_polygons, Ref<PolyBooleanParameters2D> p_params) const;
	
	Array inflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	Array deflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	Array inflate_polygons_array(const Array &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	Array deflate_polygons_array(const Array &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	
	Array deflate_polyline(const Vector<Point2> &p_polyline, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	Array deflate_polylines_array(const Array &p_polylines, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	
	Array offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	Array offset_polygons_array(const Array &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const;
	
	Vector<Point2> triangulate_polygon_vertices(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params) const;
	
	Vector2 polygon_centroid(const Vector<Vector2> &p_polygon) const;
	real_t polygon_area(const Vector<Vector2> &p_polygon) const;
	real_t polygon_perimeter(const Vector<Vector2> &p_polygon) const;
	real_t polyline_length(const Vector<Vector2> &p_polyline) const;
	
	Vector<Point2> regular_polygon(int p_edge_count, real_t p_size) const;
	
	GeometryTools2D();
};

VARIANT_ENUM_CAST(PolyBooleanBase2D::Operation);

} // namespace module_bind

#endif // GODOT_GEOMETRY_TOOLS_BIND_H
