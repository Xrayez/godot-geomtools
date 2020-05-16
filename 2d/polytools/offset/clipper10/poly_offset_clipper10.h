#ifndef GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER10
#define GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER10

#include "modules/geomtools/2d/polytools/offset/poly_offset.h"
#include "modules/geomtools/thirdparty/clipper/clipper_offset.h"

class PolyOffset2DClipper10 : public PolyOffsetBase2D {
public:
	virtual Vector<Vector<Point2> > offset_polypath(const Vector<Point2> &p_polygon, real_t p_delta) override;
	virtual Vector<Vector<Point2> > offset_polypaths_array(const Vector<Vector<Point2> > &p_polygons, real_t p_delta) override;

protected:
	clipperlib::ClipperOffset configure(const Ref<PolyOffsetParameters2D> &p_params);
	
private:
	clipperlib::JoinType join_type;
	clipperlib::EndType end_type;
};

using PolyOffset2D = PolyOffset2DClipper10; // 10.0.0 (sandbox)

#endif // GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER10