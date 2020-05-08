#ifndef GEOMETRY_POLY_TOOLS_H
#define GEOMETRY_POLY_TOOLS_H

#include "core/object.h"

class PolyToolBase {
public:
	virtual real_t polygon_area(const Vector<Vector2> &p_polygon);
};

#endif // GEOMETRY_POLY_TOOLS_H
