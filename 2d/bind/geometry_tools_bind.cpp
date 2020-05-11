#include "geometry_tools_bind.h"

_GeometryTools2D *_GeometryTools2D::singleton = nullptr;

Array _GeometryTools2D::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polys = GeometryTools2D::merge_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools2D::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polys = GeometryTools2D::clip_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools2D::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polys = GeometryTools2D::intersect_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools2D::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polys = GeometryTools2D::exclude_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools2D::merge_polygons_array(Array p_polygons_a, Array p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools2D::merge_polygons_array(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools2D::clip_polygons_array(Array p_polygons_a, Array p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools2D::clip_polygons_array(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools2D::intersect_polygons_array(Array p_polygons_a, Array p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools2D::intersect_polygons_array(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools2D::exclude_polygons_array(Array p_polygons_a, Array p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools2D::exclude_polygons_array(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Ref<PolyNode2D> _GeometryTools2D::polygons_boolean(PolyBooleanBase2D::Operation p_op, Array p_polygons_a, Array p_polygons_b, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); i++) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Point2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); i++) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	return GeometryTools2D::polygons_boolean(p_op, polygons_a, polygons_b, p_params);
}

Array _GeometryTools2D::clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polylines = GeometryTools2D::clip_polyline_with_polygon(p_polyline, p_polygon, p_params);
	Array ret;
	for (int i = 0; i < polylines.size(); ++i) {
		ret.push_back(polylines[i]);
	}
	return ret;
}

Array _GeometryTools2D::intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polylines = GeometryTools2D::intersect_polyline_with_polygon(p_polyline, p_polygon, p_params);
	Array ret;
	for (int i = 0; i < polylines.size(); ++i) {
		ret.push_back(polylines[i]);
	}
	return ret;
}

Array _GeometryTools2D::clip_polylines_with_polygons_array(const Array &p_polylines, const Array &p_polygons, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polylines;
	for (int i = 0; i < p_polylines.size(); i++) {
		polylines.push_back(p_polylines[i]);
	}
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools2D::clip_polylines_with_polygons_array(polylines, polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools2D::intersect_polylines_with_polygons_array(const Array &p_polylines, const Array &p_polygons, const Ref<PolyBooleanParameters2D> &p_params) const {
	Vector<Vector<Point2> > polylines;
	for (int i = 0; i < p_polylines.size(); i++) {
		polylines.push_back(p_polylines[i]);
	}
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools2D::intersect_polylines_with_polygons_array(polylines, polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

real_t _GeometryTools2D::polygon_area(const Vector<Vector2> &p_polygon) {
	return GeometryTools2D::polygon_area(p_polygon);
}

void _GeometryTools2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("merge_polygons", "polygon_a", "polygon_b", "params"), &_GeometryTools2D::merge_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("clip_polygons", "polygon_a", "polygon_b", "params"), &_GeometryTools2D::clip_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_polygons", "polygon_a", "polygon_b", "params"), &_GeometryTools2D::intersect_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("exclude_polygons", "polygon_a", "polygon_b", "params"), &_GeometryTools2D::exclude_polygons, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("merge_polygons_array", "polygons_a", "polygons_b", "params"), &_GeometryTools2D::merge_polygons_array, DEFVAL(Variant()), DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("clip_polygons_array", "polygons_a", "polygons_b", "params"), &_GeometryTools2D::clip_polygons_array, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_polygons_array", "polygons_a", "polygons_b", "params"), &_GeometryTools2D::intersect_polygons_array, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("exclude_polygons_array", "polygons_a", "polygons_b", "params"), &_GeometryTools2D::exclude_polygons_array, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("polygons_boolean", "operation", "polygons_a", "polygons_b", "params"), &_GeometryTools2D::polygons_boolean, DEFVAL(Variant()), DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("clip_polyline_with_polygon", "polyline", "polygon", "params"), &_GeometryTools2D::clip_polyline_with_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_polyline_with_polygon", "polyline", "polygon", "params"), &_GeometryTools2D::intersect_polyline_with_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("clip_polylines_with_polygons_array", "polylines", "polygons", "params"), &_GeometryTools2D::clip_polylines_with_polygons_array, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_polylines_with_polygons_array", "polylines", "polygons", "params"), &_GeometryTools2D::intersect_polylines_with_polygons_array, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("polygon_area", "polygon"), &_GeometryTools2D::polygon_area);
}

_GeometryTools2D::_GeometryTools2D() {
	singleton = this;
}
