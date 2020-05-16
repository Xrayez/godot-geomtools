#ifndef GEOMETRY_TOOLS_POLY_DECOMP_BUILTIN
#define GEOMETRY_TOOLS_POLY_DECOMP_BUILTIN

#include "modules/geomtools/2d/polytools/decomp/poly_decomp.h"

class PolyDecomp2DBuiltin : public PolyDecompBase2D {
public:
	virtual Vector<Point2> triangulate_polygon_vertices(const Vector<Point2> &p_polygon) override;
	virtual Vector<Point2> triangulate_multiple_polygons_vertices(const Vector<Vector<Point2> > &p_polygons) override;
};

using PolyDecomp2D = PolyDecomp2DBuiltin;

#endif // GEOMETRY_TOOLS_POLY_DECOMP_BUILTIN
