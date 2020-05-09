#ifndef GODOT_GEOMETRY_TOOLS_BIND_H
#define GODOT_GEOMETRY_TOOLS_BIND_H

#include "geometry_tools.h"

class _GeometryTools : public Object {
	GDCLASS(_GeometryTools, Object);

private:
	static _GeometryTools *singleton;

protected:
	static void _bind_methods();

public:
	static _GeometryTools *get_singleton() { return singleton; }
	
public:
	real_t polygon_area(const Vector<Vector2> &p_polygon);
	Ref<PolyNode> polygons_boolean(PolyToolBase::PolyBooleanOperation p_op, Array p_polygons_a, Array p_polygons_b);
	
	_GeometryTools();
};

VARIANT_ENUM_CAST(PolyToolBase::PolyBooleanOperation);

#endif // GODOT_GEOMETRY_TOOLS_BIND_H
