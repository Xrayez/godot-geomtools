#ifndef GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER10
#define GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER10

#include "modules/geomtools/2d/polytools/offset/poly_offset.h"
#include "modules/geomtools/thirdparty/clipper/clipper_offset.h"

class PolyOffset2DClipper10 : public PolyOffset2D {
public:
	virtual Vector<Vector<Point2> > offset_polypaths(const Vector<Vector<Point2> > &p_polypaths, real_t p_delta) override;
	
	virtual String get_name() const override { return "clipper10"; }
	
protected:
	clipperlib::ClipperOffset configure(const Ref<PolyOffsetParameters2D> &p_params);
	
private:
	clipperlib::JoinType join_type;
	clipperlib::EndType end_type;
};

#endif // GODOT_GEOMETRY_TOOLS_POLY_OFFSET_CLIPPER10
