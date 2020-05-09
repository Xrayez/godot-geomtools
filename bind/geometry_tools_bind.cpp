#include "geometry_tools_bind.h"
#include "geometry_tools.h"

_GeometryTools *_GeometryTools::singleton = nullptr;

real_t _GeometryTools::polygon_area(const Vector<Vector2> &p_polygon) {
	return GeometryTools::polygon_area(p_polygon);
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
	ClassDB::bind_method(D_METHOD("polygon_area"), &_GeometryTools::polygon_area);
	ClassDB::bind_method(D_METHOD("polygons_boolean", "polygons_a", "polygons_b"), &_GeometryTools::polygons_boolean, DEFVAL(Variant()));
}

_GeometryTools::_GeometryTools() {
	singleton = this;
}
