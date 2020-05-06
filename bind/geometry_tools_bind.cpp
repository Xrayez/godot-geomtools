#include "geometry_tools_bind.h"
#include "geometry_tools.h"

_GeometryTools *_GeometryTools::singleton = nullptr;

void _GeometryTools::_bind_methods() {
	ClassDB::bind_method(D_METHOD("polygon_area"), &_GeometryTools::polygon_area);
}

_GeometryTools::_GeometryTools() {
	singleton = this;
}
