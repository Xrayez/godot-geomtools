#include "geometry_tools.h"

PolyTool GeometryTools::pt = PolyTool();

real_t GeometryTools::polygon_area(const Vector<Vector2> &p_polygon) {
	return pt.polygon_area(p_polygon);
}
