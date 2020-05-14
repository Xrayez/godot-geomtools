#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/poly_backends.gen.h"

class GeometryTools2D {
public:
	enum PolyBooleanOperation {
		OPERATION_NONE, // May perform polygons fixup, build hierarchy etc.
		OPERATION_UNION,
		OPERATION_DIFFERENCE,
		OPERATION_INTERSECTION,
		OPERATION_XOR,
	};
	/* Polygon and polyline boolean operations */
	static Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	static Vector<Vector<Point2> > merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	// General-purpose polygon boolean operations.
	// Returns a top-level root node which represents an hierarchy of polygons.
	static Ref<PolyNode2D> polygons_boolean_tree(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >(), Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	// Note: UNION and XOR do not apply here.
	static Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	/* Polygon inflating and deflating */
	static Vector<Vector<Point2> > inflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > deflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > inflate_polygons_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > deflate_polygons_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	
	// Grows polyline into a polygon.
	// Note: negative delta does not apply here.
	static Vector<Vector<Point2> > deflate_polyline(const Vector<Point2> &p_polyline, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > deflate_polylines_array(const Vector<Vector<Point2> > &p_polylines, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	
	// General-purpose offsetting, accepts both negative and positive delta.
	static Vector<Vector<Point2> > offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > offset_polygons_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	
	/* Polygon decomposition */
	static Vector<Point2> triangulate_polygon_vertices(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params = nullptr);
	
	/* Polygon/Polyline attributes */
	static Point2 polygon_centroid(const Vector<Point2> &p_polygon);
	static real_t polygon_area(const Vector<Point2> &p_polygon);
	static real_t polygon_perimeter(const Vector<Point2> &p_polygon);
	static real_t polyline_length(const Vector<Point2> &p_polyline);
	
	// Returns 0 if false, +1 if true, -1 if point is exactly on the polygon's boundary.
	static int point_in_polygon(const Point2 &p_point, const Vector<Point2> &p_polygon);
	
	/* Polygon/shapes generation methods */
	static Vector<Point2> regular_polygon(int p_edge_count, real_t p_size);
	static Vector<Point2> circle(real_t p_radius, real_t p_max_error = 0.25);
	
protected:
	static Ref<PolyBooleanParameters2D> configure_boolean(const Ref<PolyBooleanParameters2D> &p_params);
	static Ref<PolyOffsetParameters2D> configure_offset(const Ref<PolyOffsetParameters2D> &p_params);
	static Ref<PolyDecompParameters2D> configure_decomp(const Ref<PolyDecompParameters2D> &p_params);

public:
	static void initialize();
	static void finalize();
private:
	static PolyBoolean2D *poly_boolean;
	static PolyOffset2D *poly_offset;
	static PolyDecomp2D *poly_decomp;
	
	static Ref<PolyBooleanParameters2D> default_poly_boolean_params;
	static Ref<PolyOffsetParameters2D> default_poly_offset_params;
	static Ref<PolyDecompParameters2D> default_poly_decomp_params;
};

#endif // GODOT_GEOMETRY_TOOLS_H
