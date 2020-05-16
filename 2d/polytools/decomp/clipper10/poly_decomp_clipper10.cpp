#include "poly_decomp_clipper10.h"
#include "modules/geomtools/2d/polytools/utils/godot_clipper10_path_convert.h"

Vector<Point2> PolyDecomp2DClipper10::triangulate_polygon_vertices(const Vector<Point2> &p_polygon) {
	clipperlib::ClipperTri clp = configure(params);
	
	clipperlib::Path subject;
	GodotClipperUtils::scale_up_polypath(p_polygon, subject);
	clp.AddPath(subject, clipperlib::ptSubject);

	clipperlib::Paths triangles;
	clp.Execute(clipperlib::ctUnion, triangles, fill_rule);
	
	Vector<Point2> ret;
	_scale_down_triangles(triangles, ret);
	
	return ret;
}

Vector<Point2> PolyDecomp2DClipper10::triangulate_multiple_polygons_vertices(const Vector<Vector<Point2> > &p_polygons) {
	clipperlib::ClipperTri clp = configure(params);
	
	clipperlib::Paths subject;
	GodotClipperUtils::scale_up_polypaths(p_polygons, subject);
	clp.AddPaths(subject, clipperlib::ptSubject);

	clipperlib::Paths triangles;
	clp.Execute(clipperlib::ctUnion, triangles, fill_rule);

	Vector<Point2> ret;
	_scale_down_triangles(triangles, ret);
	
	return ret;
}

void PolyDecomp2DClipper10::_scale_down_triangles(const clipperlib::Paths &p_triangles_in, Vector<Point2> &p_vertices_out) const {
	p_vertices_out.clear();
	
	for (int i = 0; i < p_triangles_in.size(); ++i) {
		Vector<Point2> tri;
		GodotClipperUtils::scale_down_polypath(p_triangles_in[i], tri);
		p_vertices_out.push_back(tri[0]);
		p_vertices_out.push_back(tri[1]);
		p_vertices_out.push_back(tri[2]);
	}
}

clipperlib::ClipperTri PolyDecomp2DClipper10::configure(const Ref<PolyDecompParameters2D> &p_params) {
	using namespace clipperlib;

	fill_rule = FillRule(p_params->fill_rule);

	return ClipperTri();
}
