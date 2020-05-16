#include "modules/geomtools/2d/geometry_tools.h"
#include "poly_decomp.h"
#include "core/math/triangulate.h"
#include "thirdparty/misc/triangulator.h"

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
	List<TriangulatorPoly> in_poly, out_poly;
    
    // Split between inner and outer polygons first.
    Vector<int> outer_indices, inner_indices;
    for (int i = 0; i < p_polygons.size(); ++i) {
        if (GeometryTools2D::polygon_area(p_polygons[i]) >= 0.0) {
            outer_indices.push_back(i);
        } else {
            inner_indices.push_back(i);
        }
    }
    // Setup outer polygons.
    for (int i = 0; i < outer_indices.size(); ++i) {
        TriangulatorPoly inp_outer;
        const Vector<Point2> &polygon_outer = p_polygons[outer_indices[i]];
        inp_outer.Init(polygon_outer.size());
        for (int i = 0; i < polygon_outer.size(); i++) {
            inp_outer.GetPoint(i) = polygon_outer[i];
        }
        in_poly.push_back(inp_outer);
    }
    // Setup inner polygons.
    for (int i = 0; i < inner_indices.size(); ++i) {
        TriangulatorPoly inp_inner;
        const Vector<Point2> &polygon_inner = p_polygons[inner_indices[i]];
        inp_inner.Init(polygon_inner.size());
        for (int j = 0; j < polygon_inner.size(); ++j) {
            inp_inner.GetPoint(j) = polygon_inner[j];
        }
        inp_inner.SetHole(true);
        in_poly.push_back(inp_inner);
    }
    // Decompose!
	TriangulatorPartition tpart;
	if (tpart.ConvexPartition_HM(&in_poly, &out_poly) == 0) {
		ERR_PRINT("Convex decomposition failed!");
		return convex;
	}
	convex.resize(out_poly.size());
	int idx = 0;
	for (List<TriangulatorPoly>::Element *I = out_poly.front(); I; I = I->next()) {
		TriangulatorPoly &tp = I->get();
		convex.write[idx].resize(tp.GetNumPoints());
		for (int64_t i = 0; i < tp.GetNumPoints(); i++) {
			convex.write[idx].write[i] = tp.GetPoint(i);
		}
		idx++;
	}
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
