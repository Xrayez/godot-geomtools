#ifndef GODOT_GEOMETRY_TOOLS_CLIPPER6
#define GODOT_GEOMETRY_TOOLS_CLIPPER6

#include "../polytools/poly_tools.h"

class PolyToolClipper6 : public PolyToolBase {
public:
    virtual Ref<PolyNode> polygons_boolean(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >()) override;
};

using PolyTool = PolyToolClipper6; // 6.4.2 (stable)

#endif // GODOT_GEOMETRY_TOOLS_CLIPPER6
