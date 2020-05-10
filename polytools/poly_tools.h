#ifndef GEOMETRY_POLY_TOOLS_H
#define GEOMETRY_POLY_TOOLS_H

#include "core/reference.h"

class PolyNode;
class PolyParams;

class PolyToolBase {
public:
	enum PolyBooleanOperation {
		OPERATION_UNION,
		OPERATION_DIFFERENCE,
		OPERATION_INTERSECTION,
		OPERATION_XOR,
	};
	enum PolyJoinType {
		JOIN_SQUARE,
		JOIN_ROUND,
		JOIN_MITER,
	};
	enum PolyEndType {
		END_POLYGON,
		END_JOINED,
		END_BUTT,
		END_SQUARE,
		END_ROUND,
	};
	virtual Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	virtual Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	virtual Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	virtual Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b) = 0;
	
	virtual Vector<Vector<Point2> > merge_multiple_polygons(const Vector<Vector<Point2> > &p_polygons) = 0;
	virtual Vector<Vector<Point2> > clip_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	virtual Vector<Vector<Point2> > intersect_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	virtual Vector<Vector<Point2> > exclude_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b) = 0;
	
	virtual Ref<PolyNode> polygons_boolean(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >()) = 0;
	
	virtual Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) = 0;
	virtual Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon) = 0;
	virtual Vector<Vector<Point2> > clip_multiple_polylines_with_polygons(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) = 0;
	virtual Vector<Vector<Point2> > intersect_multiple_polylines_with_polygons(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons) = 0;
	
	// virtual Point2 polygon_centroid(const Vector<Point2> &p_polygon);
	virtual real_t polygon_area(const Vector<Point2> &p_polygon);
	
	PolyToolBase();

protected:
	Ref<PolyParams> params;
	Ref<PolyNode> poly_tree;
};

class PolyParams : public Reference {
	GDCLASS(PolyParams, Reference);
	
protected:
	static void _bind_methods();
};

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
