#include "geometry_tools.h"

PolyTool *GeometryTools::pt = nullptr;

void GeometryTools::poly_tool_init() {
	pt = memnew(PolyTool);
}

void GeometryTools::poly_tool_deinit() {
	memdelete(pt);
}

Vector<Vector<Point2> > GeometryTools::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return pt->merge_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return pt->clip_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return pt->intersect_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return pt->exclude_polygons(p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > GeometryTools::merge_polygons_array(const Vector<Vector<Point2> > &p_polygons) {
	return pt->merge_polygons_array(p_polygons);
}

Vector<Vector<Point2> > GeometryTools::clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return pt->clip_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools::intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return pt->intersect_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools::exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return pt->exclude_polygons_array(p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > GeometryTools::clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) {
	return pt->clip_polyline_with_polygon(p_polyline, p_polygon);
}

Vector<Vector<Point2> > GeometryTools::intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) {
	return pt->intersect_polyline_with_polygon(p_polyline, p_polygon);
}

Vector<Vector<Point2> > GeometryTools::clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) {
	return pt->clip_polylines_with_polygons_array(p_polylines, p_polygons);
}

Vector<Vector<Point2> > GeometryTools::intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) {
	return pt->intersect_polylines_with_polygons_array(p_polylines, p_polygons);
}

real_t GeometryTools::polygon_area(const Vector<Vector2> &p_polygon) {
	return pt->polygon_area(p_polygon);
}

Ref<PolyNode> GeometryTools::polygons_boolean(PolyToolBase::PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return pt->polygons_boolean(p_op, p_polygons_a, p_polygons_b);
}
