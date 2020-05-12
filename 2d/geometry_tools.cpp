#include "geometry_tools.h"

PolyBoolean2D *GeometryTools2D::poly_boolean = nullptr;
PolyOffset2D *GeometryTools2D::poly_offset = nullptr;
Ref<PolyBooleanParameters2D> GeometryTools2D::default_poly_boolean_params = nullptr;
Ref<PolyOffsetParameters2D> GeometryTools2D::default_poly_offset_params = nullptr;

void GeometryTools2D::initialize() {
	default_poly_boolean_params.instance();
	default_poly_offset_params.instance();
	poly_boolean = memnew(PolyBoolean2D);
	poly_offset = memnew(PolyOffset2D);
}

void GeometryTools2D::finalize() {
	default_poly_boolean_params.unref();
	default_poly_offset_params.unref();
	memdelete(poly_boolean);
	memdelete(poly_offset);
}

Ref<PolyBooleanParameters2D> GeometryTools2D::configure_boolean(const Ref<PolyBooleanParameters2D> &p_params) {
	if (p_params.is_valid()) {
		poly_boolean->set_params(p_params);
		return p_params;
	}
	poly_boolean->set_params(default_poly_boolean_params);
	return default_poly_boolean_params;
}

Ref<PolyOffsetParameters2D> GeometryTools2D::configure_offset(const Ref<PolyOffsetParameters2D> &p_params) {
	if (p_params.is_valid()) {
		poly_offset->set_params(p_params);
		return p_params;
	}
	poly_offset->set_params(default_poly_offset_params);
	return default_poly_offset_params;
}

Vector<Vector<Point2> > GeometryTools2D::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypath_boolean(PolyBooleanBase2D::OPERATION_UNION, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypath_boolean(PolyBooleanBase2D::OPERATION_DIFFERENCE, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypath_boolean(PolyBooleanBase2D::OPERATION_INTERSECTION, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypath_boolean(PolyBooleanBase2D::OPERATION_XOR, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools2D::merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypaths_boolean_array(PolyBooleanBase2D::OPERATION_UNION, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypaths_boolean_array(PolyBooleanBase2D::OPERATION_DIFFERENCE, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypaths_boolean_array(PolyBooleanBase2D::OPERATION_INTERSECTION, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypaths_boolean_array(PolyBooleanBase2D::OPERATION_XOR, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = true;
	return poly_boolean->polypath_boolean(PolyBooleanBase2D::OPERATION_DIFFERENCE, p_polyline, p_polygon);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = true;
	return poly_boolean->polypath_boolean(PolyBooleanBase2D::OPERATION_INTERSECTION, p_polyline, p_polygon);
}

Vector<Vector<Point2> > GeometryTools2D::clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = true;
	return poly_boolean->polypaths_boolean_array(PolyBooleanBase2D::OPERATION_DIFFERENCE, p_polylines, p_polygons);
}

Vector<Vector<Point2> > GeometryTools2D::intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = true;
	return poly_boolean->polypaths_boolean_array(PolyBooleanBase2D::OPERATION_INTERSECTION, p_polylines, p_polygons);
}

Ref<PolyNode2D> GeometryTools2D::polygons_boolean_tree(PolyBooleanBase2D::Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params) {
	configure_boolean(p_params)->subject_open = false;
	return poly_boolean->polypaths_boolean_tree(p_op, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools2D::inflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	ERR_FAIL_COND_V(p_delta < 0, Vector<Vector<Point2> >());
	configure_offset(p_params)->end_type = PolyOffsetParameters2D::END_POLYGON;
	return poly_offset->offset_polypath(p_polygon, -p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::deflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	ERR_FAIL_COND_V(p_delta < 0, Vector<Vector<Point2> >());
	configure_offset(p_params)->end_type = PolyOffsetParameters2D::END_POLYGON;
	return poly_offset->offset_polypath(p_polygon, p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::inflate_polygons_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	ERR_FAIL_COND_V(p_delta < 0, Vector<Vector<Point2> >());
	configure_offset(p_params)->end_type = PolyOffsetParameters2D::END_POLYGON;
	return poly_offset->offset_polypaths_array(p_polygons, -p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::deflate_polygons_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	ERR_FAIL_COND_V(p_delta < 0, Vector<Vector<Point2> >());
	configure_offset(p_params)->end_type = PolyOffsetParameters2D::END_POLYGON;
	return poly_offset->offset_polypaths_array(p_polygons, p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::deflate_polyline(const Vector<Point2> &p_polyline, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	ERR_FAIL_COND_V(p_delta < 0, Vector<Vector<Point2> >());
	Ref<PolyOffsetParameters2D> params = configure_offset(p_params);
	if (params->end_type == PolyOffsetParameters2D::END_POLYGON) {
		WARN_PRINT("END_POLYGON does not apply for polyline deflating, fallback to END_JOINED.");
		params->end_type = PolyOffsetParameters2D::END_JOINED;
	}
	return poly_offset->offset_polypath(p_polyline, p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::deflate_polylines_array(const Vector<Vector<Point2> > &p_polylines, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	ERR_FAIL_COND_V(p_delta < 0, Vector<Vector<Point2> >());
	Ref<PolyOffsetParameters2D> params = configure_offset(p_params);
	if (params->end_type == PolyOffsetParameters2D::END_POLYGON) {
		WARN_PRINT("END_POLYGON does not apply for polyline deflating, fallback to END_JOINED.");
		params->end_type = PolyOffsetParameters2D::END_JOINED;
	}
	return poly_offset->offset_polypaths_array(p_polylines, p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	configure_offset(p_params)->end_type = PolyOffsetParameters2D::END_POLYGON;
	return poly_offset->offset_polypath(p_polygon, p_delta);
}

Vector<Vector<Point2> > GeometryTools2D::offset_polygons_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) {
	configure_offset(p_params)->end_type = PolyOffsetParameters2D::END_POLYGON;
	return poly_offset->offset_polypaths_array(p_polygons, p_delta);
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
