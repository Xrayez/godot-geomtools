#ifndef GEOMETRY_POLY_TOOLS_H
#define GEOMETRY_POLY_TOOLS_H

#include "core/reference.h"

class PolyNode;
class PolyBooleanParams;

class PolyBooleanBase {
public:
	enum Operation {
		OPERATION_UNION,
		OPERATION_DIFFERENCE,
		OPERATION_INTERSECTION,
		OPERATION_XOR,
	};
	virtual Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	virtual Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	virtual Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	virtual Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	
	virtual Vector<Vector<Point2> > merge_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	virtual Vector<Vector<Point2> > clip_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	virtual Vector<Vector<Point2> > intersect_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	virtual Vector<Vector<Point2> > exclude_polygons_array(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	
	virtual Ref<PolyNode> polygons_boolean(Operation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >()) = 0;
	
	virtual Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) = 0;
	virtual Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) = 0;
	
	virtual Vector<Vector<Point2> > clip_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) = 0;
	virtual Vector<Vector<Point2> > intersect_polylines_with_polygons_array(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) = 0;
	
public:
	void set_params(const Ref<PolyBooleanParams> &p_params) { params = p_params; }
protected:
	Ref<PolyBooleanParams> params;
};

class PolyBooleanParams : public Reference {
	GDCLASS(PolyBooleanParams, Reference);

public:
	enum FillRule { 
		FILL_RULE_EVEN_ODD, 
		FILL_RULE_NON_ZERO, 
		FILL_RULE_POSITIVE, 
		FILL_RULE_NEGATIVE, 
	};
	
public:
	FillRule subject_fill_rule;
	FillRule clip_fill_rule;
	bool reverse_solution;
	bool strictly_simple;
	bool preserve_collinear;
	
protected:
	static void _bind_methods();
	
public:
	void set_subject_fill_rule(FillRule p_subject_fill_rule) { subject_fill_rule = p_subject_fill_rule; }
	FillRule get_subject_fill_rule() const { return subject_fill_rule; }
	
	void set_clip_fill_rule(FillRule p_clip_fill_rule) { clip_fill_rule = p_clip_fill_rule; }
	FillRule get_clip_fill_rule() const { return clip_fill_rule; }

	void set_reverse_solution(bool p_reverse_solution) { reverse_solution = p_reverse_solution; }
	bool is_reverse_solution() const { return reverse_solution; }
	
	void set_strictly_simple(bool p_strictly_simple) { strictly_simple = p_strictly_simple; }
	bool is_strictly_simple() const { return strictly_simple; }
	
	void set_preserve_collinear(bool p_preserve_collinear) { preserve_collinear = p_preserve_collinear; }
	bool is_preserve_collinear() const { return preserve_collinear; }
	
	PolyBooleanParams();
};

VARIANT_ENUM_CAST(PolyBooleanParams::FillRule);

class PolyNode : public Reference {
	GDCLASS(PolyNode, Reference);

public:
    Ref<PolyNode> new_child(const Vector<Point2> &p_path);
	Ref<PolyNode> get_child(int p_idx);
    int get_child_count() const { return children.size(); }
    Ref<PolyNode> get_parent() const { return parent; }
	void set_path(const Vector<Point2> &p_path) { path = p_path; }
	Vector<Point2> get_path() const { return path; }
	bool is_hole() const;
	void clear();

protected:
	static void _bind_methods();
	
private:
	Ref<PolyNode> parent;
	Vector<Point2> path;
	Vector<Ref<PolyNode> > children;
};

#endif // GEOMETRY_POLY_TOOLS_H
