#ifndef GODOT_GEOMETRY_TOOLS_CLIPPER6
#define GODOT_GEOMETRY_TOOLS_CLIPPER6

#include "../polytools/poly_tools.h"

class Clipper6; // 6.4.2 (stable)
using PolyTool = Clipper6;

class Clipper6 : public PolyMethods<Clipper6> {
public:
	real_t polygon_area_impl() {
		return 6.0;
	}
};

#endif // GODOT_GEOMETRY_TOOLS_CLIPPER6
