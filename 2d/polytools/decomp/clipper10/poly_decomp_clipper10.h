#ifndef GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
#define GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10

#include "modules/geomtools/2d/polytools/decomp/poly_decomp.h"
#include "modules/geomtools/thirdparty/clipper/clipper_triangulation.h"

class PolyDecomp2DClipper10 : public PolyDecompBase2D {
public:
	virtual Vector<Vector<Point2> > triangulate_polygons(const Vector<Vector<Point2> > &p_polygons) override;

protected:
	clipperlib::ClipperTri configure(const Ref<PolyDecompParameters2D> &p_params);

private:
	clipperlib::FillRule fill_rule;
};

using PolyDecomp2D = PolyDecomp2DClipper10;

#endif // GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
