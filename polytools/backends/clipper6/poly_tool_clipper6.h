#ifndef GODOT_GEOMETRY_TOOLS_CLIPPER6
#define GODOT_GEOMETRY_TOOLS_CLIPPER6

#include "modules/geomtools/polytools/poly_tools.h"

class PolyToolClipper6 : public PolyToolBase {
public:
    virtual Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
	virtual Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
	virtual Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
	virtual Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
    
    virtual Vector<Vector<Point2> > merge_multiple_polygons(const Vector<Vector<Point2> > &p_polygons) override;
	virtual Vector<Vector<Point2> > clip_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) override;
	virtual Vector<Vector<Point2> > intersect_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) override;
	virtual Vector<Vector<Point2> > exclude_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) override;

    virtual Ref<PolyNode> polygons_boolean(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >()) override;
private:
    Vector<Vector<Point2> > _polygons_boolean_single(PolyBooleanOperation p_op, const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b);
    Vector<Vector<Point2> > _polygons_boolean_multiple(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >());
};

using PolyTool = PolyToolClipper6; // 6.4.2 (stable)

#endif // GODOT_GEOMETRY_TOOLS_CLIPPER6
