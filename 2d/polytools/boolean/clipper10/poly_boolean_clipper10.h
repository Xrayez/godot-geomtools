#ifndef GODOT_GEOMETRY_TOOLS_CLIPPER10
#define GODOT_GEOMETRY_TOOLS_CLIPPER10

#include "modules/geomtools/2d/polytools/boolean/poly_boolean.h"
#include "modules/geomtools/thirdparty/clipper/clipper.h"

class PolyBoolean2DClipper10 : public PolyBooleanBase2D {
public:
	virtual Vector<Vector<Point2> > polypaths_boolean(Operation p_op, const Vector<Vector<Point2> > &p_polypaths_a, const Vector<Vector<Point2> > &p_polypaths_b) override;
	virtual Ref<PolyNode2D> polypaths_boolean_tree(Operation p_op, const Vector<Vector<Point2> > &p_polypaths_a, const Vector<Vector<Point2> > &p_polypaths_b) override;

protected:
	clipperlib::Clipper configure(Operation p_op, const Ref<PolyBooleanParameters2D> &p_params);
	
private:
	clipperlib::ClipType clip_type;
	clipperlib::FillRule subject_fill_rule;
	clipperlib::FillRule clip_fill_rule;
	bool subject_open;
};

using PolyBoolean2D = PolyBoolean2DClipper10; // 10.0.0 (sandbox)

#endif // GODOT_GEOMETRY_TOOLS_CLIPPER10
