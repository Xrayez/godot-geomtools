#include "poly_decomp_builtin.h"
#include "core/math/triangulate.h"

Vector<Point2> PolyDecomp2DBuiltin::triangulate_polygon_vertices(const Vector<Point2> &p_polygon) {
	// This is similar to Geometry::triangulate_polygon() 
	// but returns vertices instead of indices.
	Vector<int> indices;
	if (!Triangulate::triangulate(p_polygon, indices)) {
		return Vector<Point2>();
	}
	Vector<Point2> vertices;
	for (int i = 0; i < indices.size(); i++) {
		vertices.push_back(p_polygon[indices[i]]);
	}
	return vertices;
}
