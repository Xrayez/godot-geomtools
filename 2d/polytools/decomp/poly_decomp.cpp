#include "modules/geomtools/2d/geometry_tools.h"
#include "poly_decomp.h"
#include "core/math/triangulate.h"
#include "thirdparty/misc/triangulator.h"

List<TriangulatorPoly> configure(PolyDecompBase2D::DecompType p_type, const Vector<Vector<Point2> > &p_polygons) {
	List<TriangulatorPoly> in_poly;
    
    // Split between inner and outer polygons first.
    Vector<int> outer_indices, inner_indices;
    for (int i = 0; i < p_polygons.size(); ++i) {
        if (GeometryTools2D::polygon_area(p_polygons[i]) >= 0.0) {
            outer_indices.push_back(i);
        } else {
            if (p_type == PolyDecompBase2D::DECOMP_TRIANGLES_OPT || p_type == PolyDecompBase2D::DECOMP_CONVEX_OPT) {
                // The solution would no longer be optimal with the inner holes, skip.
                continue;
            }
            inner_indices.push_back(i);
        }
    }
    ERR_FAIL_COND_V_MSG(outer_indices.empty(), List<TriangulatorPoly>(), "No outer polygons detected.");
    
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
    return in_poly;
}

Vector<Vector<Point2> > partition(List<TriangulatorPoly> &p_out_poly) {
    Vector<Vector<Point2> > polys;
	polys.resize(p_out_poly.size());
	int idx = 0;
	for (List<TriangulatorPoly>::Element *E = p_out_poly.front(); E; E = E->next()) {
		TriangulatorPoly &tp = E->get();
		polys.write[idx].resize(tp.GetNumPoints());
		for (int64_t i = 0; i < tp.GetNumPoints(); i++) {
			polys.write[idx].write[i] = tp.GetPoint(i);
		}
		++idx;
	}
    return polys;
}

Vector<Vector<Point2> > PolyDecompBase2D::decompose_polygons(DecompType p_type, const Vector<Vector<Point2> > &p_polygons) {
    Vector<Vector<Point2> > polys;

    switch (p_type) {
		case DECOMP_TRIANGLES_EC: {
            polys = triangulate_ec(p_polygons);
        } break;
		case DECOMP_TRIANGLES_OPT: {
            polys = triangulate_opt(p_polygons);
        } break;
		case DECOMP_TRIANGLES_MONO: {
            polys = triangulate_mono(p_polygons);
        } break;
		case DECOMP_CONVEX_HM: {
            polys = decompose_convex_hm(p_polygons);
        } break;
		case DECOMP_CONVEX_OPT: {
            polys = decompose_convex_opt(p_polygons);
        } break;
    }
    return polys;
}

Vector<Vector<Point2> > PolyDecompBase2D::triangulate_ec(const Vector<Vector<Point2> > &p_polygons) {
    List<TriangulatorPoly> in_poly = configure(DECOMP_TRIANGLES_EC, p_polygons);
    
    TriangulatorPartition tpart;
    List<TriangulatorPoly> out_poly;
    
    if (tpart.Triangulate_EC(&in_poly, &out_poly) == 0) {
		ERR_PRINT("Triangulation failed!");
		return Vector<Vector<Point2> >();
    }
	return partition(out_poly);
}

Vector<Vector<Point2> > PolyDecompBase2D::triangulate_opt(const Vector<Vector<Point2> > &p_polygons) {
    List<TriangulatorPoly> in_poly = configure(DECOMP_TRIANGLES_OPT, p_polygons);
    
    TriangulatorPartition tpart;
    List<TriangulatorPoly> out_poly;
    
    if (tpart.Triangulate_OPT(&in_poly[0], &out_poly) == 0) {
		ERR_PRINT("Triangulation failed!");
		return Vector<Vector<Point2> >();
    }
	return partition(out_poly);
}

Vector<Vector<Point2> > PolyDecompBase2D::triangulate_mono(const Vector<Vector<Point2> > &p_polygons) {
    List<TriangulatorPoly> in_poly = configure(DECOMP_TRIANGLES_MONO, p_polygons);
    
    TriangulatorPartition tpart;
    List<TriangulatorPoly> out_poly;
    
    // FIXME: This crashes for some reason!
    if (tpart.Triangulate_MONO(&in_poly, &out_poly) == 0) {
		ERR_PRINT("Triangulation failed!");
		return Vector<Vector<Point2> >();
    }
	return partition(out_poly);
}

Vector<Vector<Point2> > PolyDecompBase2D::decompose_convex_hm(const Vector<Vector<Point2> > &p_polygons) {
    List<TriangulatorPoly> in_poly = configure(DECOMP_CONVEX_HM, p_polygons);
    
    TriangulatorPartition tpart;
    List<TriangulatorPoly> out_poly;
    
    if (tpart.ConvexPartition_HM(&in_poly, &out_poly) == 0) {
		ERR_PRINT("Convex decomposition failed!");
		return Vector<Vector<Point2> >();
    }
	return partition(out_poly);
}

Vector<Vector<Point2> > PolyDecompBase2D::decompose_convex_opt(const Vector<Vector<Point2> > &p_polygons) {
    List<TriangulatorPoly> in_poly = configure(DECOMP_CONVEX_OPT, p_polygons);
    
    TriangulatorPartition tpart;
    List<TriangulatorPoly> out_poly;
    
    if (tpart.ConvexPartition_OPT(&in_poly[0], &out_poly) == 0) {
		ERR_PRINT("Convex decomposition failed!");
		return Vector<Vector<Point2> >();
    }
	return partition(out_poly);
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
