#ifndef GEOMETRY_POLY_OFFSET_H
#define GEOMETRY_POLY_OFFSET_H

#include "core/reference.h"

class PolyOffsetParameters2D;

class PolyOffsetBase2D {
public:
	virtual Vector<Vector<Point2> > offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta) = 0;

public:
	void set_params(const Ref<PolyOffsetParameters2D> &p_params) { params = p_params; }
protected:
	Ref<PolyOffsetParameters2D> params;
};

class PolyOffsetParameters2D : public Reference {
	GDCLASS(PolyOffsetParameters2D, Reference);

public:
	enum JoinType {
		JOIN_SQUARE,
		JOIN_ROUND,
		JOIN_MITER,
	};
	enum EndType {
		END_POLYGON,
		END_JOINED,
		END_BUTT,
		END_SQUARE,
		END_ROUND,
	};
	
public:
	JoinType join_type;
	EndType end_type;
	real_t arc_tolerance;
	real_t miter_limit;
	
protected:
	static void _bind_methods();
	
public:
	void set_join_type(JoinType p_join_type) { join_type = p_join_type; }
	JoinType get_join_type() const { return join_type; }
	
	void set_end_type(EndType p_end_type) { end_type = p_end_type; }
	EndType get_end_type() const { return end_type; }
	
	void set_arc_tolerance(real_t p_arc_tolerance) { arc_tolerance = p_arc_tolerance; }
	real_t get_arc_tolerance() const { return arc_tolerance; }
	
	void set_miter_limit(real_t p_miter_limit) { miter_limit = p_miter_limit; }
	real_t get_miter_limit() const { return miter_limit; }
	
	PolyOffsetParameters2D();
};

VARIANT_ENUM_CAST(PolyOffsetParameters2D::JoinType);
VARIANT_ENUM_CAST(PolyOffsetParameters2D::EndType);

#endif // GEOMETRY_POLY_OFFSET_H
