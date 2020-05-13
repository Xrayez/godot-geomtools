#ifndef GEOMETRY_POLY_DECOMP_H
#define GEOMETRY_POLY_DECOMP_H

#include "core/reference.h"

class PolyDecompParameters2D;

class PolyDecompBase2D {
public:
	virtual Vector<Point2> triangulate_polygon_vertices(const Vector<Point2> &p_polygon) = 0;

public:
	void set_params(const Ref<PolyDecompParameters2D> &p_params) { params = p_params; }
protected:
	Ref<PolyDecompParameters2D> params;
};

class PolyDecompParameters2D : public Reference {
	GDCLASS(PolyDecompParameters2D, Reference);
	
protected:
	static void _bind_methods();
};

#endif // GEOMETRY_POLY_DECOMP_H
