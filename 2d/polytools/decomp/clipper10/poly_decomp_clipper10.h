#ifndef GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
#define GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10

#include "modules/geomtools/2d/polytools/decomp/poly_decomp.h"
#include "modules/geomtools/thirdparty/clipper/clipper_triangulation.h"

class PolyDecomp2DClipper10 : public PolyDecompBase2D {
public:
	virtual Vector<Point2> triangulate_polygon_vertices(const Vector<Point2> &p_polygon) override;
	virtual Vector<Point2> triangulate_multiple_polygons_vertices(const Vector<Vector<Point2> > &p_polygons) override;

protected:
	clipperlib::ClipperTri configure(const Ref<PolyDecompParameters2D> &p_params);

private:
	clipperlib::FillRule fill_rule;
	
	void _scale_down_triangles(const clipperlib::Paths &p_triangles_in, Vector<Point2> &p_vertices_out) const;
};

using PolyDecomp2D = PolyDecomp2DClipper10;

#endif // GEOMETRY_TOOLS_POLY_DECOMP_CLIPPER10
