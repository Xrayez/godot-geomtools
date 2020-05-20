#ifndef GODOT_GEOMETRY_TOOLS_H
#define GODOT_GEOMETRY_TOOLS_H

#include "core/object.h"
#include "polytools/boolean/poly_boolean.h"
#include "polytools/offset/poly_offset.h"
#include "polytools/decomp/poly_decomp.h"

class GeometryTools2D {
public:
	enum PolyBooleanOperation {
		OPERATION_NONE, // May perform polygons fixup, build hierarchy etc.
		OPERATION_UNION,
		OPERATION_DIFFERENCE,
		OPERATION_INTERSECTION,
		OPERATION_XOR,
	};
	/* Polygon and polyline boolean operations */
	static Vector<Vector<Point2> > merge_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > clip_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > exclude_polygons(const Vector<Point2> &p_polygon_a, const Vector<Point2> &p_polygon_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	static Vector<Vector<Point2> > merge_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > clip_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > exclude_multiple_polygons(const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b, Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	// General-purpose polygon boolean operations.
	static Vector<Vector<Point2> > polygons_boolean(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >(), Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	// Returns a top-level root node which represents an hierarchy of polygons.
	static Ref<PolyNode2D> polygons_boolean_tree(PolyBooleanOperation p_op, const Vector<Vector<Point2> > &p_polygons_a, const Vector<Vector<Point2> > &p_polygons_b = Vector<Vector<Point2> >(), Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	// Note: UNION and XOR do not apply here.
	static Vector<Vector<Point2> > clip_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_polyline_with_polygon(const Vector<Point2> &p_polyline, const Vector<Point2> &p_polygon, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > clip_multiple_polylines_with_polygons(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, Ref<PolyBooleanParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > intersect_multiple_polylines_with_polygons(const Vector<Vector<Point2> > &p_polylines, const Vector<Vector<Point2> > &p_polygons, Ref<PolyBooleanParameters2D> p_params = nullptr);
	
	/* Polygon inflating and deflating */
	static Vector<Vector<Point2> > inflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > deflate_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > inflate_multiple_polygons(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > deflate_multiple_polygons(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	
	// Grows polyline into a polygon.
	// Note: negative delta does not apply here.
	static Vector<Vector<Point2> > deflate_polyline(const Vector<Point2> &p_polyline, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > deflate_multiple_polylines(const Vector<Vector<Point2> > &p_polylines, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	
	// General-purpose offsetting, accepts both negative and positive delta.
	static Vector<Vector<Point2> > offset_polygon(const Vector<Point2> &p_polygon, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > offset_multiple_polygons(const Vector<Vector<Point2> > &p_polygons, real_t p_delta, Ref<PolyOffsetParameters2D> p_params = nullptr);
	
	/* Polygon decomposition */
	enum PolyDecompType {
		DECOMP_TRIANGLES_EC, // Ear clipping algorithm.
		DECOMP_TRIANGLES_OPT, // Minimal edge length.
		DECOMP_TRIANGLES_MONO, // Mono polygon partitioning, then triangulate.
		DECOMP_CONVEX_HM, // Hertel-Mehlhorn algorithm.
		DECOMP_CONVEX_OPT, // Minimal number of convex polygons.
	};
	static Vector<Vector<Point2> > triangulate_polygon(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > triangulate_multiple_polygons(const Vector<Vector<Point2> > &p_polygons, Ref<PolyDecompParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > decompose_polygon_into_convex(const Vector<Point2> &p_polygon, Ref<PolyDecompParameters2D> p_params = nullptr);
	static Vector<Vector<Point2> > decompose_multiple_polygons_into_convex(const Vector<Vector<Point2> > &p_polygons, Ref<PolyDecompParameters2D> p_params = nullptr);
	
	// General-purpose polygon decomposition.
	static Vector<Vector<Point2> > decompose_polygons(PolyDecompType p_type, const Vector<Vector<Point2> > &p_polygons, Ref<PolyDecompParameters2D> p_params = nullptr);
	
	/* Polygon/Polyline attributes */
	static Point2 polygon_centroid(const Vector<Point2> &p_polygon);
	static real_t polygon_area(const Vector<Point2> &p_polygon);
	static real_t polygon_perimeter(const Vector<Point2> &p_polygon);
	static real_t polyline_length(const Vector<Point2> &p_polyline);
	
	// Returns 0 if false, +1 if true, -1 if point is exactly on the polygon's boundary.
	static int point_in_polygon(const Point2 &p_point, const Vector<Point2> &p_polygon);
	
	/* Polygon/shapes generation methods */
	static Vector<Point2> regular_polygon(int p_edge_count, real_t p_size);
	static Vector<Point2> circle(real_t p_radius, real_t p_max_error = 0.25);
	
public:
	static void initialize();
	static void finalize();
	
	static String get_backend_name(const String &p_type);
	
protected:
	static Ref<PolyBooleanParameters2D> configure_boolean(const Ref<PolyBooleanParameters2D> &p_params);
	static Ref<PolyOffsetParameters2D> configure_offset(const Ref<PolyOffsetParameters2D> &p_params);
	static Ref<PolyDecompParameters2D> configure_decomp(const Ref<PolyDecompParameters2D> &p_params);
	
private:
	static PolyBooleanBase2D *poly_boolean;
	static PolyOffsetBase2D *poly_offset;
	static PolyDecompBase2D *poly_decomp;
	
	static Ref<PolyBooleanParameters2D> default_poly_boolean_params;
	static Ref<PolyOffsetParameters2D> default_poly_offset_params;
	static Ref<PolyDecompParameters2D> default_poly_decomp_params;
};

// typedef PolyBackend *(*CreatePolyBackendCallback)();

template <class T>
class PolyBackend2DManager {
	struct Backend {
		String name;
		T instance;

		Backend() :
				name(""),
				instance(nullptr) {}

		Backend(String p_name, T p_instance) :
				name(p_name),
				instance(p_instance) {}

		// Backend(const Backend &p_ci) :
		// 		name(p_ci.name),
		// 		instance(p_ci.instance) {}

		// Backend operator=(const Backend &p_ci) {
		// 	name = p_ci.name;
		// 	instance = p_ci.instance;
		// 	return *this;
	};

	Vector<Backend> backends;
// 	static int default_backend_id;
// 	static int default_backend_priority;

public:
	String setting_name;

// private:
// 	static void on_backends_changed();

public:
	void register_backend(const String &p_name, T p_instance) {
		backends.push_back(Backend(p_name, p_instance));
	}
	// void set_default_backend(const String &p_name, int p_priority = 0);
	
	int find_backend_id(const String &p_name) const {
		for (int i = 0; i < backends.size(); ++i) {
			if (p_name == backends[i].name) {
				return i;
			}
		}
		return -1;
	}
	
	T get_backend_instance(const String &p_name) const {
		return backends[find_backend_id(p_name)].instance;
	}
	
	int get_backends_count() const { return backends.size(); }
	
	String get_backend_name(int p_id) const { 
		CRASH_BAD_INDEX(p_id, backends.size());
		return backends[p_id].name;
	}
	// T new_default_backend();
	// T new_backend(const String &p_name);
};

class GeometryTools2DManager {
public:
	static PolyBackend2DManager<PolyBooleanBase2D *> poly_boolean;
};

#endif // GODOT_GEOMETRY_TOOLS_H
