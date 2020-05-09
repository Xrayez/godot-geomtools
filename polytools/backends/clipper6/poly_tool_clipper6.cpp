#include "poly_tool_clipper6.h"
#include "thirdparty/misc/clipper.hpp"

#define SCALE_FACTOR 100000.0 // Based on CMP_EPSILON.

namespace GodotClipperUtils {
	
// Methods to scale polypath vertices (Clipper's requirement for robust computation).

using namespace ClipperLib;

static void scale_up_polypaths(const Vector<Vector<Point2> > &p_polypaths_in, Paths &p_polypaths_out) {
	p_polypaths_out.clear();
	p_polypaths_out.resize(p_polypaths_in.size());

	for (int i = 0; i < p_polypaths_in.size(); ++i) {

		const Vector<Point2> &polypath_in = p_polypaths_in[i];
		Path &polypath_out = p_polypaths_out[i];

		for (int j = 0; j < polypath_in.size(); ++j) {
			polypath_out << IntPoint(
					polypath_in[j].x * SCALE_FACTOR,
					polypath_in[j].y * SCALE_FACTOR);
		}
	}
}

static void scale_down_polypaths(const Paths &p_polypaths_in, Vector<Vector<Point2> > &p_polypaths_out) {
	p_polypaths_out.clear();

	for (Paths::size_type i = 0; i < p_polypaths_in.size(); ++i) {

		const Path &polypath_in = p_polypaths_in[i];
		Vector<Vector2> polypath_out;

		for (Paths::size_type j = 0; j < polypath_in.size(); ++j) {
			polypath_out.push_back(Point2(
					static_cast<real_t>(polypath_in[j].X) / SCALE_FACTOR,
					static_cast<real_t>(polypath_in[j].Y) / SCALE_FACTOR));
		}
		p_polypaths_out.push_back(polypath_out);
	}
}

static void scale_up_polypath(const Vector<Point2> &p_polypath_in, Path &p_polypath_out) {
	p_polypath_out.clear();

    for (int i = 0; i < p_polypath_in.size(); ++i) {
        p_polypath_out << IntPoint(
                p_polypath_in[i].x * SCALE_FACTOR,
                p_polypath_in[i].y * SCALE_FACTOR);
    }
}

static void scale_down_polypath(const Path &p_polypath_in, Vector<Point2> &p_polypath_out) {
	p_polypath_out.clear();

    for (Path::size_type i = 0; i < p_polypath_in.size(); ++i) {
        p_polypath_out.push_back(Point2(
                static_cast<real_t>(p_polypath_in[i].X) / SCALE_FACTOR,
                static_cast<real_t>(p_polypath_in[i].Y) / SCALE_FACTOR));
    }
}

} // namespace GodotClipperUtils

Vector<Vector<Point2> > PolyToolClipper6::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_UNION, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyToolClipper6::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_DIFFERENCE, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyToolClipper6::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_INTERSECTION, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyToolClipper6::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_XOR, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyToolClipper6::_polygons_boolean_single(PolyBooleanOperation p_op, const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	ClipperLib::ClipType op = ClipperLib::ctUnion;
	switch (p_op) {
		case OPERATION_UNION: op = ClipperLib::ctUnion; break;
		case OPERATION_DIFFERENCE: op = ClipperLib::ctDifference; break;
		case OPERATION_INTERSECTION: op = ClipperLib::ctIntersection; break;
		case OPERATION_XOR: op = ClipperLib::ctXor; break;
	}
	ClipperLib::Path subject, clip;
	
	GodotClipperUtils::scale_up_polypath(p_polygon_a, subject);
	GodotClipperUtils::scale_up_polypath(p_polygon_b, clip);
	
	ClipperLib::Clipper clp;
	clp.AddPath(subject, ClipperLib::ptSubject, true);
	clp.AddPath(clip, ClipperLib::ptClip, true);
	
	ClipperLib::Paths solution;
    clp.Execute(op, solution, ClipperLib::pftNonZero);

	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(solution, ret);

	return ret;
}

Ref<PolyNode> PolyToolClipper6::polygons_boolean(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	ClipperLib::ClipType op = ClipperLib::ctUnion;
	switch (p_op) {
		case OPERATION_UNION: op = ClipperLib::ctUnion; break;
		case OPERATION_DIFFERENCE: op = ClipperLib::ctDifference; break;
		case OPERATION_INTERSECTION: op = ClipperLib::ctIntersection; break;
		case OPERATION_XOR: op = ClipperLib::ctXor; break;
	}
	ClipperLib::Paths subject, clip;

	GodotClipperUtils::scale_up_polypaths(p_polygons_a, subject);
	GodotClipperUtils::scale_up_polypaths(p_polygons_b, clip);

	ClipperLib::Clipper clp;
	clp.AddPaths(subject, ClipperLib::ptSubject, true);
	clp.AddPaths(clip, ClipperLib::ptClip, true);

    ClipperLib::PolyTree tree;
    clp.Execute(op, tree, ClipperLib::pftNonZero);
    
    ClipperLib::PolyNode *n = tree.GetFirst();
    
    List<ClipperLib::PolyNode*> nodes;
	nodes.push_back(n);
    poly_tree->clear();

	while (!nodes.empty()) {
        ClipperLib::PolyNode *cp = nodes.back()->get();
		nodes.pop_back();
        
        Vector<Point2> parent_path;
        GodotClipperUtils::scale_down_polypath(cp->Contour, parent_path);
        Ref<PolyNode> c = poly_tree->new_child(parent_path);

		for (int i = 0; i < cp->ChildCount(); ++i) {
			ClipperLib::PolyNode *cc = cp->Childs[i];
            Vector<Point2> child_path;
            GodotClipperUtils::scale_down_polypath(cc->Contour, child_path);
			c->new_child(child_path);
            nodes.push_back(cc);
		}
    }
    return poly_tree;
}
