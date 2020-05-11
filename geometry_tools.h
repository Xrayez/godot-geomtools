#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/poly_tools.h"
#include "polytools/poly_tools_backend.gen.h"

class GeometryTools {
public:
	/* POLYGON vs POLYGON */
	
	// Single polygon vs polygon boolean operations.
	static Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	
	// Multiple polygons vs polygons boolean operations.
	static Vector<Vector<Point2> > merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParams> &p_params = nullptr);
	
	// General-purpose polygon boolean operations.
	static Ref<PolyNode> polygons_boolean(PolyBooleanBase::Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >(), const Ref<PolyBooleanParams> &p_params = nullptr);
	
	/* POLYLINE vs POLYGON */
	// Note: UNION and XOR do not apply here.
	
	// Single polyline vs polygon boolean operations.
	static Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParams> &p_params = nullptr);
	
	// Multiple polylines vs polygons boolean operations.
	static Vector<Vector<Point2> > clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, const Ref<PolyBooleanParams> &p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, const Ref<PolyBooleanParams> &p_params = nullptr);
	
	static Point2 polygon_centroid(const Vector<Point2> &p_polygon);
	static real_t polygon_area(const Vector<Vector2> &p_polygon);

public:
	static void initialize();
	static void finalize();
private:
	static PolyBoolean *poly_boolean;
};

#endif // GODOT_GEOMETRY_TOOLS_H
