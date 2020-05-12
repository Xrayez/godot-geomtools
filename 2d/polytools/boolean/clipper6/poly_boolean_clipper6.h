#ifndef GODOT_GEOMETRY_TOOLS_CLIPPER6
#define GODOT_GEOMETRY_TOOLS_CLIPPER6

#include "modules/geomtools/2d/polytools/boolean/poly_boolean.h"
#include "thirdparty/misc/clipper.hpp"

class PolyBoolean2DClipper6 : public PolyBooleanBase2D {
public:
 	virtual Vector<Vector<Point2> > polypath_boolean(Operation p_op, const Vector<Point2> &p_polypath_a, const Vector<Point2> &p_polypath_b) override;
	virtual Vector<Vector<Point2> > polypaths_boolean_array(Operation p_op, const Vector<Vector<Point2> > &p_polypaths_a, const Vector<Vector<Point2> > &p_polypaths_b) override;
	virtual Ref<PolyNode2D> polypaths_boolean_tree(Operation p_op, const Vector<Vector<Point2> > &p_polypaths_a, const Vector<Vector<Point2> > &p_polypaths_b) override;

protected:
	ClipperLib::Clipper configure(Operation p_op, const Ref<PolyBooleanParameters2D> &p_params);
	
private:
	ClipperLib::ClipType clip_type;
	ClipperLib::PolyFillType subject_fill_type;
	ClipperLib::PolyFillType clip_fill_type;
	bool subject_open;
};

using PolyBoolean2D = PolyBoolean2DClipper6; // 6.4.2 (stable)

#endif // GODOT_GEOMETRY_TOOLS_CLIPPER6
