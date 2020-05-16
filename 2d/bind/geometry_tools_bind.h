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
	enum PolyBooleanOperation {
		OPERATION_NONE,
		OPERATION_UNION,
		OPERATION_DIFFERENCE,
		OPERATION_INTERSECTION,
		OPERATION_XOR,
	};
	Array merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const;
	
	Array merge_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array clip_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array intersect_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	Array exclude_polygons_array(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;

	Ref<PolyNode2D> polygons_boolean_tree(PolyBooleanOperation p_op, Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const;
	
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
	
	enum PolyDecompType {
		DECOMP_TRIANGLES,
		DECOMP_CONVEX,
	};
	Array triangulate_polygon(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params) const;
	Array triangulate_multiple_polygons(const Array &p_polygons, Ref<PolyDecompParameters2D> p_params) const;
	Array decompose_polygon_into_convex(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params) const;
	Array decompose_multiple_polygons_into_convex(const Array &p_polygons, Ref<PolyDecompParameters2D> p_params) const;

	Array decompose_polygons(PolyDecompType p_type, const Array &p_polygons, Ref<PolyDecompParameters2D> p_params) const;

	Vector2 polygon_centroid(const Vector<Vector2> &p_polygon) const;
	real_t polygon_area(const Vector<Vector2> &p_polygon) const;
	real_t polygon_perimeter(const Vector<Vector2> &p_polygon) const;
	real_t polyline_length(const Vector<Vector2> &p_polyline) const;
	
	int point_in_polygon(const Point2 &p_point, const Vector<Point2> &p_polygon) const;
	
	Vector<Point2> regular_polygon(int p_edge_count, real_t p_size) const;
	Vector<Point2> circle(real_t p_radius, real_t p_max_error) const;
	
	GeometryTools2D();
};

VARIANT_ENUM_CAST(GeometryTools2D::PolyBooleanOperation);
VARIANT_ENUM_CAST(GeometryTools2D::PolyDecompType);

} // namespace module_bind

#endif // GODOT_GEOMETRY_TOOLS_BIND_H
