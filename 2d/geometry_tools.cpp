#include "geometry_tools.h"

PolyBoolean2D *GeometryTools2D::poly_boolean = nullptr;
PolyOffset2D *GeometryTools2D::poly_offset = nullptr;

void GeometryTools2D::initialize() {
	poly_boolean = memnew(PolyBoolean2D);
	poly_offset = memnew(PolyOffset2D);
}

void GeometryTools2D::finalize() {
	memdelete(poly_boolean);
	memdelete(poly_offset);
}

Vector<Vector<Point2> > GeometryTools2D::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->merge_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->clip_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->intersect_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->exclude_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->merge_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->clip_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->intersect_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->exclude_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->clip_polyline_with_polygon(p_polyline, p_polygon);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->intersect_polyline_with_polygon(p_polyline, p_polygon);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->clip_polylines_with_polygons_array(p_polylines, p_polygons);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->intersect_polylines_with_polygons_array(p_polylines, p_polygons);
}

Ref<PolyNode2D> GeometryTools2D::polygons_boolean(PolyBooleanBase2D::Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) {
	poly_boolean->set_params(p_params);
	return poly_boolean->polygons_boolean(p_op, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, const Ref<PolyOffsetParameters2D> &p_params) {
	poly_offset->set_params(p_params);
	return poly_offset->offset_polygon(p_polygon, p_delta);
}

real_t GeometryTools2D::polygon_area(const Vector<Vector2> &p_polygon) {
	if (p_polygon.size() < 3) {
        return 0.0;
    }
    real_t area = 0.0;
    for (int i = 0, j = p_polygon.size() - 1; i < p_polygon.size(); ++i) {
        area += (p_polygon[j].x + p_polygon[i].x) * (p_polygon[j].y - p_polygon[i].y);
        j = i;
    }
    return -area * 0.5;
}
