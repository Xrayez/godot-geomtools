#ifndef GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
#define GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10

#include "modules/geomtools/2d/polytools/decomp/polypartition/poly_decomp_polypartition.h"
#include "modules/geomtools/thirdparty/clipper/clipper_triangulation.h"

class PolyDecomp2DClipper10 : public PolyDecomp2DPolyPartition {
public:
	// Seems like Clipper 10.0.0 uses monotone partitioning (?)
	virtual Vector<Vector<Point2> > triangulate_mono(const Vector<Vector<Point2> > &p_polygons) override;
	
protected:
	clipperlib::ClipperTri configure(const Ref<PolyDecompParameters2D> &p_params);

private:
	clipperlib::FillRule fill_rule;
};

#endif // GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
