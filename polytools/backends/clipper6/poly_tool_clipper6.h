#ifndef GODOT_GEOMETRY_TOOLS_CLIPPER6
#define GODOT_GEOMETRY_TOOLS_CLIPPER6

#include "modules/geomtools/polytools/poly_tools.h"

class PolyToolClipper6 : public PolyToolBase {
public:
    virtual Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
	virtual Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
	virtual Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
	virtual Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) override;
    
    virtual Vector<Vector<Point2> > merge_polygons_array(const Vector<Vector<Point2> > &p_polygons) override;
	virtual Vector<Vector<Point2> > clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) override;
	virtual Vector<Vector<Point2> > intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) override;
	virtual Vector<Vector<Point2> > exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) override;

    virtual Ref<PolyNode> polygons_boolean(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >()) override;
	
	virtual Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) override;
	virtual Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) override;
	
	virtual Vector<Vector<Point2> > clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) override;
	virtual Vector<Vector<Point2> > intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) override;
	
private:
    Vector<Vector<Point2> > _polygons_boolean_single(PolyBooleanOperation p_op, const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b);
    Vector<Vector<Point2> > _polygons_boolean_multiple(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >());
	
    Vector<Vector<Point2> > _polylines_boolean_single(PolyBooleanOperation p_op, const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon);
    Vector<Vector<Point2> > _polylines_boolean_multiple(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons);
};

using PolyTool = PolyToolClipper6; // 6.4.2 (stable)

#endif // GODOT_GEOMETRY_TOOLS_CLIPPER6
