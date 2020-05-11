#include "poly_boolean_clipper6.h"
#include "modules/geomtools/2d/polytools/utils/clipper/godot_clipper_path_convert.h"

Vector<Vector<Point2> > PolyBoolean2DClipper6::merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_UNION, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_DIFFERENCE, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_INTERSECTION, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	return _polygons_boolean_single(OPERATION_XOR, p_polygon_a, p_polygon_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::_polygons_boolean_single(Operation p_op, const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) {
	ClipperLib::Clipper clp = configure(p_op, params);
	
	ClipperLib::Path subject, clip;
	GodotClipperUtils::scale_up_polypath(p_polygon_a, subject);
	GodotClipperUtils::scale_up_polypath(p_polygon_b, clip);
	
	clp.AddPath(subject, ClipperLib::ptSubject, true);
	clp.AddPath(clip, ClipperLib::ptClip, true);
	
	ClipperLib::Paths solution;
    clp.Execute(clip_type, solution, subject_fill_type, clip_fill_type);

	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(solution, ret);

	return ret;
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return _polygons_boolean_multiple(OPERATION_UNION, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return _polygons_boolean_multiple(OPERATION_DIFFERENCE, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return _polygons_boolean_multiple(OPERATION_INTERSECTION, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	return _polygons_boolean_multiple(OPERATION_XOR, p_polygons_a, p_polygons_b);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::_polygons_boolean_multiple(Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	ClipperLib::Clipper clp = configure(p_op, params);
	
	ClipperLib::Paths subject;
	GodotClipperUtils::scale_up_polypaths(p_polygons_a, subject);
	clp.AddPaths(subject, ClipperLib::ptSubject, true);
	
	if (!p_polygons_b.empty()) { // Optional for the merge operation.
		ClipperLib::Paths clip;
		GodotClipperUtils::scale_up_polypaths(p_polygons_b, clip);
		clp.AddPaths(clip, ClipperLib::ptClip, true);
	}
	
	ClipperLib::Paths solution;
    clp.Execute(clip_type, solution, subject_fill_type, clip_fill_type);

	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(solution, ret);

	return ret;
}

Ref<PolyNode2D> PolyBoolean2DClipper6::polygons_boolean(Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) {
	ClipperLib::Clipper clp = configure(p_op, params);

	ClipperLib::Paths subject;
	GodotClipperUtils::scale_up_polypaths(p_polygons_a, subject);
	clp.AddPaths(subject, ClipperLib::ptSubject, true);
	
	ClipperLib::Paths clip;
	GodotClipperUtils::scale_up_polypaths(p_polygons_b, clip);
	clp.AddPaths(clip, ClipperLib::ptClip, true);

    ClipperLib::PolyTree tree;
    clp.Execute(clip_type, tree, subject_fill_type, clip_fill_type);
    
    ClipperLib::PolyNode *n = tree.GetFirst();
    
    List<ClipperLib::PolyNode*> nodes;
	nodes.push_back(n);
    Ref<PolyNode2D> poly_tree;
	poly_tree.instance();

	while (!nodes.empty()) {
        ClipperLib::PolyNode *cp = nodes.back()->get();
		nodes.pop_back();
        
        Vector<Point2> parent_path;
        GodotClipperUtils::scale_down_polypath(cp->Contour, parent_path);
        Ref<PolyNode2D> c = poly_tree->new_child(parent_path);

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

Vector<Vector<Point2> > PolyBoolean2DClipper6::clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) {
	return _polylines_boolean_single(OPERATION_DIFFERENCE, p_polyline, p_polygon);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) {
	return _polylines_boolean_single(OPERATION_INTERSECTION, p_polyline, p_polygon);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) {
	return _polylines_boolean_multiple(OPERATION_DIFFERENCE, p_polylines, p_polygons);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) {
	return _polylines_boolean_multiple(OPERATION_INTERSECTION, p_polylines, p_polygons);
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::_polylines_boolean_single(Operation p_op, const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) {
	ClipperLib::Clipper clp = configure(p_op, params);

	ClipperLib::Path subject;
	GodotClipperUtils::scale_up_polypath(p_polyline, subject);
	clp.AddPath(subject, ClipperLib::ptSubject, false);
	
	ClipperLib::Path clip;
	GodotClipperUtils::scale_up_polypath(p_polygon, clip);
	clp.AddPath(clip, ClipperLib::ptClip, true);
	
	// Populate polylines, have to use PolyTree.
	ClipperLib::PolyTree tree;
	clp.Execute(clip_type, tree, subject_fill_type, clip_fill_type);
	ClipperLib::Paths polylines;
	ClipperLib::OpenPathsFromPolyTree(tree, polylines);
	
	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(polylines, ret);

	return ret;
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::_polylines_boolean_multiple(Operation p_op, const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) {
	ClipperLib::Clipper clp = configure(p_op, params);

	ClipperLib::Paths subject;
	GodotClipperUtils::scale_up_polypaths(p_polylines, subject);
	clp.AddPaths(subject, ClipperLib::ptSubject, false);
	
	ClipperLib::Paths clip;
	GodotClipperUtils::scale_up_polypaths(p_polygons, clip);
	clp.AddPaths(clip, ClipperLib::ptClip, true);
	
	// Populate polylines, have to use PolyTree.
	ClipperLib::PolyTree tree;
	clp.Execute(clip_type, tree, subject_fill_type, clip_fill_type);
	ClipperLib::Paths polylines;
	ClipperLib::OpenPathsFromPolyTree(tree, polylines);

	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(polylines, ret);

	return ret;
}

ClipperLib::Clipper PolyBoolean2DClipper6::configure(Operation p_op, const Ref<PolyBooleanParameters2D> &p_params) {
	using namespace ClipperLib;

	switch (p_op) {
		case OPERATION_UNION: clip_type = ctUnion; break;
		case OPERATION_DIFFERENCE: clip_type = ctDifference; break;
		case OPERATION_INTERSECTION: clip_type = ctIntersection; break;
		case OPERATION_XOR: clip_type = ctXor; break;
	}
	
	int init_options = 0;
	
	if (params.is_valid()) {
		subject_fill_type = PolyFillType(params->subject_fill_rule);
		clip_fill_type = PolyFillType(params->clip_fill_rule);
		init_options |= params->reverse_solution ? InitOptions::ioReverseSolution : 0;
		init_options |= params->strictly_simple ? InitOptions::ioStrictlySimple : 0;
		init_options |= params->preserve_collinear ? InitOptions::ioPreserveCollinear : 0;
	} else {
		subject_fill_type = pftNonZero;
		clip_fill_type = pftNonZero;
	}
	return Clipper(init_options);
}
