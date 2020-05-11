#include "godot_clipper_path_convert.h"

#define SCALE_FACTOR 100000.0 // Based on CMP_EPSILON.

namespace GodotClipperUtils {
	
// Methods to scale polypath vertices (Clipper's requirement for robust computation).

using namespace ClipperLib;

void scale_up_polypaths(const Vector<Vector<Point2> > &p_polypaths_in, Paths &p_polypaths_out) {
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

void scale_down_polypaths(const Paths &p_polypaths_in, Vector<Vector<Point2> > &p_polypaths_out) {
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

void scale_up_polypath(const Vector<Point2> &p_polypath_in, Path &p_polypath_out) {
	p_polypath_out.clear();

    for (int i = 0; i < p_polypath_in.size(); ++i) {
        p_polypath_out << IntPoint(
                p_polypath_in[i].x * SCALE_FACTOR,
                p_polypath_in[i].y * SCALE_FACTOR);
    }
}

void scale_down_polypath(const Path &p_polypath_in, Vector<Point2> &p_polypath_out) {
	p_polypath_out.clear();

    for (Path::size_type i = 0; i < p_polypath_in.size(); ++i) {
        p_polypath_out.push_back(Point2(
                static_cast<real_t>(p_polypath_in[i].X) / SCALE_FACTOR,
                static_cast<real_t>(p_polypath_in[i].Y) / SCALE_FACTOR));
    }
}

} // namespace GodotClipperUtils
