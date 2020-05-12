#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/boolean/poly_boolean.h"
#include "polytools/poly_backends.gen.h"

class GeometryTools2D {
public:
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
	static Ref<PolyNode2D> polygons_boolean_tree(PolyBooleanBase2D::Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >(), Ref<PolyBooleanParameters2D> p_params = nullptr);
	
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
	
	// Polygon attributes.
	static Point2 polygon_centroid(const Vector<Point2> &p_polygon);
	static real_t polygon_area(const Vector<Vector2> &p_polygon);
	
protected:
	static Ref<PolyBooleanParameters2D> configure_boolean(const Ref<PolyBooleanParameters2D> &p_params);
	static Ref<PolyOffsetParameters2D> configure_offset(const Ref<PolyOffsetParameters2D> &p_params);

public:
	static void initialize();
	static void finalize();
private:
	static PolyBoolean2D *poly_boolean;
	static PolyOffset2D *poly_offset;
	
	static Ref<PolyBooleanParameters2D> default_poly_boolean_params;
	static Ref<PolyOffsetParameters2D> default_poly_offset_params;
};

#endif // GODOT_GEOMETRY_TOOLS_H
