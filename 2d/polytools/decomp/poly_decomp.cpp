#include "poly_decomp.h"
#include "core/math/triangulate.h"

Vector<Vector<Point2> > PolyDecompBase2D::decompose_polygons(DecompType p_type, const Vector<Vector<Point2> > &p_polygons) {
	Vector<Vector<Point2> > ret;
	
	switch (p_type) {
		case DECOMP_TRIANGLES: {
			ret = triangulate_polygons(p_polygons);
		} break;
		case DECOMP_CONVEX: {
			ret = decompose_polygons_into_convex(p_polygons);
		} break;
	}
	return ret;
}

Vector<Vector<Point2> > PolyDecompBase2D::triangulate_polygons(const Vector<Vector<Point2> > &p_polygons) {
    Vector<Vector<Point2> > triangles;
    
    for (int i = 0; i < p_polygons.size(); ++i) {
        const Vector<Point2> &polygon = p_polygons[i];
        Vector<int> indices;
        if (!Triangulate::triangulate(polygon, indices)) {
            continue;
        }
        const int size = indices.size() / 3;
        for (int j = 0; j < size; ++j) {
            Vector<Point2> tri;
            tri.push_back(polygon[indices[j * 3 + 0]]);
            tri.push_back(polygon[indices[j * 3 + 1]]);
            tri.push_back(polygon[indices[j * 3 + 2]]);
            triangles.push_back(tri);
        }
    }
    return triangles;
}

Vector<Vector<Point2> > PolyDecompBase2D::decompose_polygons_into_convex(const Vector<Vector<Point2> > &p_polygons) {
    Vector<Vector<Point2> > convex;
    return convex;
}

void PolyDecompParameters2D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_fill_rule", "fill_rule"), &PolyDecompParameters2D::set_fill_rule);
    ClassDB::bind_method(D_METHOD("get_fill_rule"), &PolyDecompParameters2D::get_fill_rule);
    
    BIND_ENUM_CONSTANT(FILL_RULE_EVEN_ODD);
    BIND_ENUM_CONSTANT(FILL_RULE_NON_ZERO);
    BIND_ENUM_CONSTANT(FILL_RULE_POSITIVE);
    BIND_ENUM_CONSTANT(FILL_RULE_NEGATIVE);
    
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fill_rule"), "set_fill_rule", "get_fill_rule");
}
