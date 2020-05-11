#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/boolean/poly_boolean.h"
#include "polytools/poly_backends.gen.h"

class GeometryTools2D {
public:
	/* POLYGON vs POLYGON */
	
	// Single polygon vs polygon boolean operations.
	static Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	
	// Multiple polygons vs polygons boolean operations.
	static Vector<Vector<Point2> > merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	
	// General-purpose polygon boolean operations.
	// Returns a top-level root node which represents an hierarchy of polygons.
	static Ref<PolyNode2D> polygons_boolean(PolyBooleanBase2D::Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >(), const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	
	/* POLYLINE vs POLYGON */
	// Note: UNION and XOR do not apply here.
	
	// Single polyline vs polygon boolean operations.
	static Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	
	// Multiple polylines vs polygons boolean operations.
	static Vector<Vector<Point2> > clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, const Ref<PolyBooleanParameters2D> &p_params = nullptr);
	
	/* POLYGON/POLYLINES OFFSET */
	static Vector<Vector<Point2> > offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, const Ref<PolyOffsetParameters2D> &p_params = nullptr);
	
	static Point2 polygon_centroid(const Vector<Point2> &p_polygon);
	static real_t polygon_area(const Vector<Vector2> &p_polygon);

public:
	static void initialize();
	static void finalize();
private:
	static PolyBoolean2D *poly_boolean;
	static PolyOffset2D *poly_offset;
};

#endif // GODOT_GEOMETRY_TOOLS_H
