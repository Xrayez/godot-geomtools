#ifndef GEOMETRY_POLY_DECOMP_H
#define GEOMETRY_POLY_DECOMP_H

#include "core/reference.h"

class PolyDecompParameters2D;

class PolyDecompBase2D {
public:
	virtual Vector<Point2> triangulate_polygon_vertices(const Vector<Point2> &p_polygon) = 0;
	virtual Vector<Point2> triangulate_multiple_polygons_vertices(const Vector<Vector<Point2> > &p_polygons) = 0;

public:
	void set_params(const Ref<PolyDecompParameters2D> &p_params) { params = p_params; }
protected:
	Ref<PolyDecompParameters2D> params;
};

class PolyDecompParameters2D : public Reference {
	GDCLASS(PolyDecompParameters2D, Reference);
	
public:
	enum FillRule { 
		FILL_RULE_EVEN_ODD, 
		FILL_RULE_NON_ZERO, 
		FILL_RULE_POSITIVE, 
		FILL_RULE_NEGATIVE, 
	};
	
public:
	FillRule fill_rule = FILL_RULE_NON_ZERO;
	
protected:
	static void _bind_methods();
	
public:
	void set_fill_rule(FillRule p_fill_rule) { fill_rule = p_fill_rule; }
	FillRule get_fill_rule() const { return fill_rule; }
};

VARIANT_ENUM_CAST(PolyDecompParameters2D::FillRule);

#endif // GEOMETRY_POLY_DECOMP_H
