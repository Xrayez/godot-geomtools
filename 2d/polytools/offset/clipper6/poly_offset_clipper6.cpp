#include "poly_offset_clipper6.h"
#include "modules/geomtools/2d/polytools/utils/clipper/godot_clipper_path_convert.h"

#define SCALE_FACTOR 100000.0 // Based on CMP_EPSILON.

Vector<Vector<Point2> > PolyOffset2DClipper6::offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta) {
	ClipperLib::ClipperOffset clp = configure(params);
	
	ClipperLib::Path subject;
	GodotClipperUtils::scale_up_polypath(p_polygon, subject);
	clp.AddPath(subject, join_type, end_type);
	
	ClipperLib::Paths solution;
	clp.Execute(solution, p_delta * SCALE_FACTOR);
	
	Vector<Vector<Point2> > ret;
	GodotClipperUtils::scale_down_polypaths(solution, ret);

	return ret;
}

ClipperLib::ClipperOffset PolyOffset2DClipper6::configure(const Ref<PolyOffsetParameters2D> &p_params) {
	using namespace ClipperLib;
	
	if (p_params.is_valid()) {
		switch (p_params->join_type) {
			case PolyOffsetParameters2D::JOIN_SQUARE: join_type = jtSquare; break;
			case PolyOffsetParameters2D::JOIN_ROUND: join_type = jtRound; break;
			case PolyOffsetParameters2D::JOIN_MITER: join_type = jtMiter; break;
		}
		switch (p_params->end_type) {
			case PolyOffsetParameters2D::END_POLYGON: end_type = etClosedPolygon; break;
			case PolyOffsetParameters2D::END_JOINED: end_type = etClosedLine; break;
			case PolyOffsetParameters2D::END_BUTT: end_type = etOpenButt; break;
			case PolyOffsetParameters2D::END_SQUARE: end_type = etOpenSquare; break;
			case PolyOffsetParameters2D::END_ROUND: end_type = etOpenRound; break;
		}
	} else {
		join_type = jtSquare;
		end_type = etOpenSquare;
	}
	if (p_params.is_valid()) {
		return ClipperOffset(p_params->miter_limit, p_params->arc_tolerance * SCALE_FACTOR);
	}
	return ClipperOffset();
}
