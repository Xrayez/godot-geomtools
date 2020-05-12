#include "poly_boolean_clipper6.h"
#include "modules/geomtools/2d/polytools/utils/clipper/godot_clipper_path_convert.h"

Vector<Vector<Point2> > PolyBoolean2DClipper6::polypath_boolean(Operation p_op, const Vector<Point2> &p_polypath_a, const Vector<Point2> &p_polypath_b) {
	ClipperLib::Clipper clp = configure(p_op, params);
	
	ClipperLib::Path subject;
	GodotClipperUtils::scale_up_polypath(p_polypath_a, subject);
	clp.AddPath(subject, ClipperLib::ptSubject, !subject_open);
	
	ClipperLib::Path clip;
	GodotClipperUtils::scale_up_polypath(p_polypath_b, clip);
	clp.AddPath(clip, ClipperLib::ptClip, true);
	
	ClipperLib::Paths solution;
	if (!subject_open) {
    	clp.Execute(clip_type, solution, subject_fill_type, clip_fill_type);
	} else {
		ClipperLib::PolyTree tree;
		clp.Execute(clip_type, tree, subject_fill_type, clip_fill_type);
		ClipperLib::OpenPathsFromPolyTree(tree, solution);
	}
	
	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(solution, ret);

	return ret;
}

Vector<Vector<Point2> > PolyBoolean2DClipper6::polypaths_boolean_array(Operation p_op, const Vector<Vector<Point2> > &p_polypaths_a, const Vector<Vector<Point2> > &p_polypaths_b) {
	ClipperLib::Clipper clp = configure(p_op, params);
	
	ClipperLib::Paths subject;
	GodotClipperUtils::scale_up_polypaths(p_polypaths_a, subject);
	clp.AddPaths(subject, ClipperLib::ptSubject, !subject_open);
	
	if (!p_polypaths_b.empty()) { // Optional for merge operation.
		ClipperLib::Paths clip;
		GodotClipperUtils::scale_up_polypaths(p_polypaths_b, clip);
		clp.AddPaths(clip, ClipperLib::ptClip, true);
	}
	
	ClipperLib::Paths solution;
	if (!subject_open) {
    	clp.Execute(clip_type, solution, subject_fill_type, clip_fill_type);
	} else {
		ClipperLib::PolyTree tree;
		clp.Execute(clip_type, tree, subject_fill_type, clip_fill_type);
		ClipperLib::OpenPathsFromPolyTree(tree, solution);
	}
	
	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(solution, ret);

	return ret;
}

Ref<PolyNode2D> PolyBoolean2DClipper6::polypaths_boolean_tree(Operation p_op, const Vector<Vector<Point2> > &p_polypaths_a, const Vector<Vector<Point2> > &p_polypaths_b) {
	ClipperLib::Clipper clp = configure(p_op, params);

	ClipperLib::Paths subject;
	GodotClipperUtils::scale_up_polypaths(p_polypaths_a, subject);
	clp.AddPaths(subject, ClipperLib::ptSubject, !subject_open);
	
	if (!p_polypaths_b.empty()) { // Optional for merge operation.
		ClipperLib::Paths clip;
		GodotClipperUtils::scale_up_polypaths(p_polypaths_b, clip);
		clp.AddPaths(clip, ClipperLib::ptClip, true);
	}

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

ClipperLib::Clipper PolyBoolean2DClipper6::configure(Operation p_op, const Ref<PolyBooleanParameters2D> &p_params) {
	using namespace ClipperLib;

	switch (p_op) {
		case OPERATION_UNION: clip_type = ctUnion; break;
		case OPERATION_DIFFERENCE: clip_type = ctDifference; break;
		case OPERATION_INTERSECTION: clip_type = ctIntersection; break;
		case OPERATION_XOR: clip_type = ctXor; break;
	}
	
	int init_options = 0;
	
	if (p_params.is_valid()) {
		subject_fill_type = PolyFillType(p_params->subject_fill_rule);
		clip_fill_type = PolyFillType(p_params->clip_fill_rule);
		init_options |= p_params->reverse_solution ? InitOptions::ioReverseSolution : 0;
		init_options |= p_params->strictly_simple ? InitOptions::ioStrictlySimple : 0;
		init_options |= p_params->preserve_collinear ? InitOptions::ioPreserveCollinear : 0;
		subject_open = p_params->subject_open;
	} else {
		subject_fill_type = pftNonZero;
		clip_fill_type = pftNonZero;
		subject_open = false;
	}
	
	return Clipper(init_options);
}
