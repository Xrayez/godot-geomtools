#ifndef GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
#define GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10

#include "modules/geomtools/2d/polytools/decomp/poly_decomp.h"
#include "modules/geomtools/thirdparty/clipper/clipper_triangulation.h"

class PolyDecomp2DClipper10 : public PolyDecomp2D {
public:
	// Seems like Clipper 10.0.0 uses mono partitioning (?)
	virtual Vector<Vector<Point2> > triangulate_mono(const Vector<Vector<Point2> > &p_polygons) override;
	
	virtual String get_name() const override { return "clipper10"; }

protected:
	clipperlib::ClipperTri configure(const Ref<PolyDecompParameters2D> &p_params);

private:
	clipperlib::FillRule fill_rule;
};

using PolyDecomp2D = PolyDecomp2DClipper10;

#endif // GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
