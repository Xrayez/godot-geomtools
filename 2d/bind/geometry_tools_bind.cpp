#include "geometry_tools_bind.h"

namespace module_bind {

GeometryTools2D *GeometryTools2D::singleton = nullptr;

Array GeometryTools2D::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polys = ::GeometryTools2D::merge_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array GeometryTools2D::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polys = ::GeometryTools2D::clip_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array GeometryTools2D::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polys = ::GeometryTools2D::intersect_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array GeometryTools2D::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polys = ::GeometryTools2D::exclude_polygons(p_polygon_a, p_polygon_b, p_params);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array GeometryTools2D::merge_multiple_polygons(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::merge_multiple_polygons(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::clip_multiple_polygons(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::clip_multiple_polygons(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::intersect_multiple_polygons(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::intersect_multiple_polygons(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::exclude_multiple_polygons(Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::exclude_multiple_polygons(polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::polygons_boolean(PolyBooleanOperation p_op, Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::polygons_boolean(::GeometryTools2D::PolyBooleanOperation(p_op), polygons_a, polygons_b, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Ref<PolyNode2D> GeometryTools2D::polygons_boolean_tree(PolyBooleanOperation p_op, Array p_polygons_a, Array p_polygons_b, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); i++) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Point2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); i++) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	return ::GeometryTools2D::polygons_boolean_tree(::GeometryTools2D::PolyBooleanOperation(p_op), polygons_a, polygons_b, p_params);
}

Array GeometryTools2D::clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polylines = ::GeometryTools2D::clip_polyline_with_polygon(p_polyline, p_polygon, p_params);
	Array ret;
	for (int i = 0; i < polylines.size(); ++i) {
		ret.push_back(polylines[i]);
	}
	return ret;
}

Array GeometryTools2D::intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polylines = ::GeometryTools2D::intersect_polyline_with_polygon(p_polyline, p_polygon, p_params);
	Array ret;
	for (int i = 0; i < polylines.size(); ++i) {
		ret.push_back(polylines[i]);
	}
	return ret;
}

Array GeometryTools2D::clip_multiple_polylines_with_polygons(const Array &p_polylines, const Array &p_polygons, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polylines;
	for (int i = 0; i < p_polylines.size(); i++) {
		polylines.push_back(p_polylines[i]);
	}
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::clip_multiple_polylines_with_polygons(polylines, polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::intersect_multiple_polylines_with_polygons(const Array &p_polylines, const Array &p_polygons, Ref<PolyBooleanParameters2D> p_params) const {
	Vector<Vector<Point2> > polylines;
	for (int i = 0; i < p_polylines.size(); i++) {
		polylines.push_back(p_polylines[i]);
	}
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::intersect_multiple_polylines_with_polygons(polylines, polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::inflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::inflate_polygon(p_polygon, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::deflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::deflate_polygon(p_polygon, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::inflate_multiple_polygons(const Array &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::inflate_multiple_polygons(polygons, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::deflate_multiple_polygons(const Array &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::deflate_multiple_polygons(polygons, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::deflate_polyline(const Vector<Point2> &p_polyline, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::deflate_polyline(p_polyline, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::deflate_multiple_polylines(const Array &p_polylines, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Point2> > polylines;
	for (int i = 0; i < p_polylines.size(); i++) {
		polylines.push_back(p_polylines[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::deflate_multiple_polylines(polylines, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::offset_polygon(p_polygon, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::offset_multiple_polygons(const Array &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::offset_multiple_polygons(polygons, p_delta, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::triangulate_polygon(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params) const {
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::triangulate_polygon(p_polygon, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::decompose_polygon_into_convex(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params) const {
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::decompose_polygon_into_convex(p_polygon, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::triangulate_multiple_polygons(const Array &p_polygons, Ref<PolyDecompParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::triangulate_multiple_polygons(polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::decompose_multiple_polygons_into_convex(const Array &p_polygons, Ref<PolyDecompParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::decompose_multiple_polygons_into_convex(polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array GeometryTools2D::decompose_polygons(PolyDecompType p_type, const Array &p_polygons, Ref<PolyDecompParameters2D> p_params) const {
	Vector<Vector<Point2> > polygons;
	for (int i = 0; i < p_polygons.size(); i++) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = ::GeometryTools2D::decompose_polygons(::GeometryTools2D::PolyDecompType(p_type), polygons, p_params);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Vector2 GeometryTools2D::polygon_centroid(const Vector<Vector2> &p_polygon) const {
	return ::GeometryTools2D::polygon_centroid(p_polygon);
}

real_t GeometryTools2D::polygon_area(const Vector<Vector2> &p_polygon) const {
	return ::GeometryTools2D::polygon_area(p_polygon);
}

real_t GeometryTools2D::polygon_perimeter(const Vector<Vector2> &p_polygon) const {
	return ::GeometryTools2D::polygon_perimeter(p_polygon);
}

real_t GeometryTools2D::polyline_length(const Vector<Vector2> &p_polyline) const {
	return ::GeometryTools2D::polyline_length(p_polyline);
}

int GeometryTools2D::point_in_polygon(const Point2 &p_point, const Vector<Point2> &p_polygon) const {
	return ::GeometryTools2D::point_in_polygon(p_point, p_polygon);
}

Vector<Point2> GeometryTools2D::regular_polygon(int p_edge_count, real_t p_size) const {
	return ::GeometryTools2D::regular_polygon(p_edge_count, p_size);
}

Vector<Point2> GeometryTools2D::circle(real_t p_radius, real_t p_max_error) const {
	return ::GeometryTools2D::circle(p_radius, p_max_error);
}

String GeometryTools2D::get_backend_name(const String &p_type) const {
	return ::GeometryTools2D::get_backend_name(p_type);
}

void GeometryTools2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("merge_polygons", "polygon_a", "polygon_b", "params"), &GeometryTools2D::merge_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("clip_polygons", "polygon_a", "polygon_b", "params"), &GeometryTools2D::clip_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_polygons", "polygon_a", "polygon_b", "params"), &GeometryTools2D::intersect_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("exclude_polygons", "polygon_a", "polygon_b", "params"), &GeometryTools2D::exclude_polygons, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("merge_multiple_polygons", "polygons_a", "polygons_b", "params"), &GeometryTools2D::merge_multiple_polygons, DEFVAL(Variant()), DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("clip_multiple_polygons", "polygons_a", "polygons_b", "params"), &GeometryTools2D::clip_multiple_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_multiple_polygons", "polygons_a", "polygons_b", "params"), &GeometryTools2D::intersect_multiple_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("exclude_multiple_polygons", "polygons_a", "polygons_b", "params"), &GeometryTools2D::exclude_multiple_polygons, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("polygons_boolean", "operation", "polygons_a", "polygons_b", "params"), &GeometryTools2D::polygons_boolean, DEFVAL(Variant()), DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("polygons_boolean_tree", "operation", "polygons_a", "polygons_b", "params"), &GeometryTools2D::polygons_boolean_tree, DEFVAL(Variant()), DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("clip_polyline_with_polygon", "polyline", "polygon", "params"), &GeometryTools2D::clip_polyline_with_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_polyline_with_polygon", "polyline", "polygon", "params"), &GeometryTools2D::intersect_polyline_with_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("clip_multiple_polylines_with_polygons", "polylines", "polygons", "params"), &GeometryTools2D::clip_multiple_polylines_with_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("intersect_multiple_polylines_with_polygons", "polylines", "polygons", "params"), &GeometryTools2D::intersect_multiple_polylines_with_polygons, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("inflate_polygon", "polygon", "delta", "params"), &GeometryTools2D::inflate_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("deflate_polygon", "polygon", "delta", "params"), &GeometryTools2D::deflate_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("inflate_multiple_polygons", "polygons", "delta", "params"), &GeometryTools2D::inflate_multiple_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("deflate_multiple_polygons", "polygons", "delta", "params"), &GeometryTools2D::deflate_multiple_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("deflate_polyline", "polyline", "delta", "params"), &GeometryTools2D::deflate_polyline, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("deflate_multiple_polylines", "polylines", "delta", "params"), &GeometryTools2D::deflate_multiple_polylines, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("offset_polygon", "polygon", "delta", "params"), &GeometryTools2D::offset_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("offset_multiple_polygons", "polygons", "delta", "params"), &GeometryTools2D::offset_multiple_polygons, DEFVAL(Variant()));

	ClassDB::bind_method(D_METHOD("triangulate_polygon", "polygon", "params"), &GeometryTools2D::triangulate_polygon, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("triangulate_multiple_polygons", "polygon", "params"), &GeometryTools2D::triangulate_multiple_polygons, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("decompose_polygon_into_convex", "polygon", "params"), &GeometryTools2D::decompose_polygon_into_convex, DEFVAL(Variant()));
	ClassDB::bind_method(D_METHOD("decompose_multiple_polygons_into_convex", "polygon", "params"), &GeometryTools2D::decompose_multiple_polygons_into_convex, DEFVAL(Variant()));
	
	ClassDB::bind_method(D_METHOD("decompose_polygons", "type", "polygons", "params"), &GeometryTools2D::decompose_polygons, DEFVAL(Variant()));

	ClassDB::bind_method(D_METHOD("polygon_centroid", "polygon"), &GeometryTools2D::polygon_centroid);
	ClassDB::bind_method(D_METHOD("polygon_area", "polygon"), &GeometryTools2D::polygon_area);
	ClassDB::bind_method(D_METHOD("polygon_perimeter", "polygon"), &GeometryTools2D::polygon_perimeter);
	ClassDB::bind_method(D_METHOD("polyline_length", "polyline"), &GeometryTools2D::polyline_length);
	
	ClassDB::bind_method(D_METHOD("point_in_polygon", "point", "polygon"), &GeometryTools2D::point_in_polygon);
	
	ClassDB::bind_method(D_METHOD("regular_polygon", "sides", "size"), &GeometryTools2D::regular_polygon, DEFVAL(64.0));
	ClassDB::bind_method(D_METHOD("circle", "radius", "max_error"), &GeometryTools2D::circle, DEFVAL(0.25));
	
	ClassDB::bind_method(D_METHOD("get_backend_name", "type"), &GeometryTools2D::get_backend_name);
	
	BIND_ENUM_CONSTANT(OPERATION_NONE);
	BIND_ENUM_CONSTANT(OPERATION_UNION);
	BIND_ENUM_CONSTANT(OPERATION_DIFFERENCE);
	BIND_ENUM_CONSTANT(OPERATION_INTERSECTION);
	BIND_ENUM_CONSTANT(OPERATION_XOR);
	
	BIND_ENUM_CONSTANT(DECOMP_TRIANGLES_EC);
	BIND_ENUM_CONSTANT(DECOMP_TRIANGLES_OPT);
	BIND_ENUM_CONSTANT(DECOMP_TRIANGLES_MONO);
	BIND_ENUM_CONSTANT(DECOMP_CONVEX_HM);
	BIND_ENUM_CONSTANT(DECOMP_CONVEX_OPT);
}

GeometryTools2D::GeometryTools2D() {
	singleton = this;
}

} // namespace module_bind
