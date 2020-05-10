#include "geometry_tools_bind.h"
#include "geometry_tools.h"

_GeometryTools *_GeometryTools::singleton = nullptr;

Array _GeometryTools::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const {
	Vector<Vector<Point2> > polys = GeometryTools::merge_polygons(p_polygon_a, p_polygon_b);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const {
	Vector<Vector<Point2> > polys = GeometryTools::clip_polygons(p_polygon_a, p_polygon_b);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const {
	Vector<Vector<Point2> > polys = GeometryTools::intersect_polygons(p_polygon_a, p_polygon_b);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

Array _GeometryTools::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) const {
	Vector<Vector<Point2> > polys = GeometryTools::exclude_polygons(p_polygon_a, p_polygon_b);
	Array ret;
	for (int i = 0; i < polys.size(); ++i) {
		ret.push_back(polys[i]);
	}
	return ret;
}

real_t _GeometryTools::polygon_area(const Vector<Vector2> &p_polygon) {
	return GeometryTools::polygon_area(p_polygon);
}

Array _GeometryTools::merge_multiple_polygons(Array p_polygons) const {
	Vector<Vector<Vector2> > polygons;
	for (int i = 0; i < p_polygons.size(); ++i) {
		polygons.push_back(p_polygons[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools::merge_multiple_polygons(polygons);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools::clip_multiple_polygons(Array p_polygons_a, Array p_polygons_b) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools::clip_multiple_polygons(polygons_a, polygons_b);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools::intersect_multiple_polygons(Array p_polygons_a, Array p_polygons_b) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools::intersect_multiple_polygons(polygons_a, polygons_b);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Array _GeometryTools::exclude_multiple_polygons(Array p_polygons_a, Array p_polygons_b) const {
	Vector<Vector<Vector2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); ++i) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Vector2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); ++i) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	Vector<Vector<Vector2> > solution = GeometryTools::exclude_multiple_polygons(polygons_a, polygons_b);
	Array ret;
	for (int i = 0; i < solution.size(); ++i) {
		ret.push_back(solution[i]);
	}
	return ret;
}

Ref<PolyNode> _GeometryTools::polygons_boolean(PolyToolBase::PolyBooleanOperation p_op, Array p_polygons_a, Array p_polygons_b) {
	Vector<Vector<Point2> > polygons_a;
	for (int i = 0; i < p_polygons_a.size(); i++) {
		polygons_a.push_back(p_polygons_a[i]);
	}
	Vector<Vector<Point2> > polygons_b;
	for (int i = 0; i < p_polygons_b.size(); i++) {
		polygons_b.push_back(p_polygons_b[i]);
	}
	return GeometryTools::polygons_boolean(p_op, polygons_a, polygons_b);
}

void _GeometryTools::_bind_methods() {
	ClassDB::bind_method(D_METHOD("merge_polygons", "polygon_a", "polygon_b"), &_GeometryTools::merge_polygons);
	ClassDB::bind_method(D_METHOD("clip_polygons", "polygon_a", "polygon_b"), &_GeometryTools::clip_polygons);
	ClassDB::bind_method(D_METHOD("intersect_polygons", "polygon_a", "polygon_b"), &_GeometryTools::intersect_polygons);
	ClassDB::bind_method(D_METHOD("exclude_polygons", "polygon_a", "polygon_b"), &_GeometryTools::exclude_polygons);
	
	ClassDB::bind_method(D_METHOD("merge_multiple_polygons", "polygons"), &_GeometryTools::merge_multiple_polygons);
	ClassDB::bind_method(D_METHOD("clip_multiple_polygons", "polygons_a", "polygons_b"), &_GeometryTools::clip_multiple_polygons);
	ClassDB::bind_method(D_METHOD("intersect_multiple_polygons", "polygons_a", "polygons_b"), &_GeometryTools::intersect_multiple_polygons);
	ClassDB::bind_method(D_METHOD("exclude_multiple_polygons", "polygons_a", "polygons_b"), &_GeometryTools::exclude_multiple_polygons);
	
	ClassDB::bind_method(D_METHOD("polygon_area"), &_GeometryTools::polygon_area);
	ClassDB::bind_method(D_METHOD("polygons_boolean", "polygons_a", "polygons_b"), &_GeometryTools::polygons_boolean, DEFVAL(Variant()));
}

_GeometryTools::_GeometryTools() {
	singleton = this;
}
