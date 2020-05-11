#ifndef GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER6
#define GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER6

#include "modules/geomtools/2d/polytools/offset/poly_offset.h"
#include "thirdparty/misc/clipper.hpp"

class PolyOffset2DClipper6 : public PolyOffsetBase2D {
public:
	virtual Vector<Vector<Point2> > offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta) override;

protected:
	ClipperLib::ClipperOffset configure(const Ref<PolyOffsetParameters2D> &p_params);
	
private:
	ClipperLib::JoinType join_type;
	ClipperLib::EndType end_type;
};

using PolyOffset2D = PolyOffset2DClipper6; // 6.4.2 (stable)

#endif // GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER6
