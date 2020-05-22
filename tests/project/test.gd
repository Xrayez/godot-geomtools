tool
extends Node2D

const SIZE = 50.0

var base_poly = PoolVector2Array([Vector2(-1, -1), Vector2(1, -1), Vector2(1, 1), Vector2(-1, 1)])

var poly_a = Transform2D(0, Vector2.ONE).scaled(Vector2.ONE * SIZE).xform(base_poly)
var poly_b = Transform2D(0, Vector2.ONE * SIZE).xform(poly_a)
var poly_c = Transform2D(0, Vector2.ONE * SIZE).xform(poly_b)
var poly_d = Transform2D(0, Vector2.ONE * SIZE).xform(poly_c)

var poly_boundary = GeometryTools2D.regular_polygon(8, SIZE * 2)
var poly_hole = GeometryTools2D.regular_polygon(4, SIZE)

export var tests_delay := 0.0 # Pause in seconds between tests (to see results).
export var inspect_method := ""

var current_test = ""
var test_passed = true
var solution = []


func _ready():
	poly_boundary.invert()

	if not inspect_method.empty():
		current_test = inspect_method
		call(inspect_method)
		if typeof(solution) == TYPE_ARRAY:
			for idx in solution.size():
				var poly = solution[idx]
				print("Poly #%s vertices (total: %s): %s" % [idx, poly.size(), poly])
		update()
		return

	var tests = []
	for method in get_script().get_script_method_list():
		if method.name.begins_with("test_"):
			tests.push_back(method)
	tests.sort_custom(self, "_tests_sorter")

	var success = true

	for method in tests:
		current_test = method.name
		test_passed = true
		$ui/test.text = current_test

		print("Running: %s" % current_test)
		call(current_test)
		update()

		if tests_delay > 0:
			yield(get_tree().create_timer(tests_delay), "timeout")

		assert(test_passed, "Test `%s` failed." % current_test)
		success = success and test_passed

	if not Engine.editor_hint:
		get_tree().quit(255 if not success else 0)


func _tests_sorter(test_a, test_b):
	if test_a.name < test_b.name:
		return true
	return false


func assert_eq(a, b):
	assert(a == b)
	test_passed = test_passed and a == b


func test_merge_polygons():
	solution = GeometryTools2D.merge_polygons(poly_a, poly_b)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 8)


func test_clip_polygons():
	solution = GeometryTools2D.clip_polygons(poly_a, poly_b)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 6)


func test_intersect_polygons():
	solution = GeometryTools2D.intersect_polygons(poly_a, poly_b)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 4)


func test_exclude_polygons():
	solution = GeometryTools2D.exclude_polygons(poly_a, poly_b)
	assert_eq(solution.size(), 2)
	assert_eq(solution[0].size(), 6)
	assert_eq(solution[1].size(), 6)


func test_merge_multiple_polygons():
	solution = GeometryTools2D.merge_multiple_polygons([poly_a, poly_b, poly_c, poly_d])
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 16)


func test_clip_multiple_polygons():
	solution = GeometryTools2D.clip_multiple_polygons([poly_a, poly_b], [poly_c, poly_d])
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 10)


func test_intersect_multiple_polygons():
	solution = GeometryTools2D.intersect_multiple_polygons([poly_a, poly_c], [poly_b, poly_d])
	assert_eq(solution.size(), 3)
	assert_eq(solution[0].size(), 4)
	assert_eq(solution[1].size(), 4)
	assert_eq(solution[2].size(), 4)


func test_exclude_multiple_polygons():
	solution = GeometryTools2D.exclude_multiple_polygons([poly_a, poly_b], [poly_c, poly_d])
	assert_eq(solution.size(), 2)
	assert_eq(solution[0].size(), 10)
	assert_eq(solution[1].size(), 10)


func test_polygons_boolean():
	solution = GeometryTools2D.polygons_boolean(GeometryTools2D.OPERATION_UNION, [poly_a, poly_b, poly_c, poly_d])
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 16)


func test_polygons_boolean_tree():
	var a = GeometryTools2D.regular_polygon(4, 150)
	var b = GeometryTools2D.regular_polygon(4, 100)
	var clip = GeometryTools2D.clip_polygons(a, b)
	var c = GeometryTools2D.regular_polygon(4, 50)
	solution = GeometryTools2D.polygons_boolean_tree(GeometryTools2D.OPERATION_UNION, clip, [c])
	var inner = solution.get_child(0).get_child(0).get_child(0).path
	assert_eq(inner.size(), c.size())


func test_clip_polyline_with_polygon():
	solution = GeometryTools2D.clip_polyline_with_polygon(poly_a, poly_b)
	assert_eq(solution.size(), 2)
	assert_eq(solution[0].size(), 2)
	assert_eq(solution[1].size(), 3)


func test_intersect_polyline_with_polygon():
	solution = GeometryTools2D.intersect_polyline_with_polygon(poly_a, poly_b)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 3)


func test_clip_multiple_polylines_with_polygons():
	solution = GeometryTools2D.clip_multiple_polylines_with_polygons([poly_a, poly_c], [poly_b, poly_d])
	assert_eq(solution.size(), 4)
	assert_eq(solution[0].size(), 2)
	assert_eq(solution[1].size(), 3)
	assert_eq(solution[2].size(), 2)
	assert_eq(solution[3].size(), 3)


func test_intersect_multiple_polylines_with_polygons():
	solution = GeometryTools2D.intersect_multiple_polylines_with_polygons([poly_a, poly_c], [poly_b, poly_d])
	assert_eq(solution.size(), 3)
	assert_eq(solution[0].size(), 3)
	assert_eq(solution[1].size(), 2)
	assert_eq(solution[2].size(), 3)


func test_inflate_polygon():
	solution = GeometryTools2D.inflate_polygon(poly_a, SIZE / 2.0)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 4)


func test_deflate_polygon():
	solution = GeometryTools2D.deflate_polygon(poly_a, SIZE / 2.0)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 8)


func test_inflate_multiple_polygons():
	solution = GeometryTools2D.inflate_multiple_polygons([poly_a, poly_c], SIZE / 2.0)
	assert_eq(solution.size(), 2)
	assert_eq(solution[0].size(), 4)
	assert_eq(solution[1].size(), 4)


func test_deflate_multiple_polygons():
	solution = GeometryTools2D.deflate_multiple_polygons([poly_a, poly_c], SIZE / 2.0)
	assert_eq(solution.size(), 1) # Successfully merged together.
	assert_eq(solution[0].size(), 14)


func test_deflate_polyline():
	solution = GeometryTools2D.deflate_polyline(poly_a, SIZE / 2.0)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 10)


func test_deflate_multiple_polylines():
	solution = GeometryTools2D.deflate_multiple_polylines([poly_a, poly_c], SIZE / 2.0)
	assert_eq(solution.size(), 1) # Successfully merged together.
	assert_eq(solution[0].size(), 17)


func test_offset_polygon():
	var params = PolyOffsetParameters2D.new()
	params.join_type = PolyOffsetParameters2D.JOIN_ROUND
	params.end_type = PolyOffsetParameters2D.END_ROUND
	solution = GeometryTools2D.offset_polygon(poly_a, SIZE / 2.0, params)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 28)


func test_offset_multiple_polygons():
	var params = PolyOffsetParameters2D.new()
	params.join_type = PolyOffsetParameters2D.JOIN_ROUND
	params.end_type = PolyOffsetParameters2D.END_ROUND
	solution = GeometryTools2D.offset_multiple_polygons([poly_a, poly_c], SIZE / 2.0, params)
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 44)


func test_triangulate_polygon():
	solution = GeometryTools2D.triangulate_polygon(poly_boundary)
	assert_eq(solution.size(), 6)
	assert_eq(solution[0].size(), 3)
	assert_eq(solution[1].size(), 3)
	assert_eq(solution[2].size(), 3)
	assert_eq(solution[3].size(), 3)
	assert_eq(solution[4].size(), 3)
	assert_eq(solution[5].size(), 3)


func test_triangulate_multiple_polygons():
	solution = GeometryTools2D.triangulate_multiple_polygons([poly_boundary, poly_hole])
	assert_eq(solution.size(), 12)
	assert_eq(solution[0].size(), 3)
	assert_eq(solution[1].size(), 3)
	assert_eq(solution[2].size(), 3)
	assert_eq(solution[3].size(), 3)
	assert_eq(solution[4].size(), 3)
	assert_eq(solution[5].size(), 3)
	assert_eq(solution[6].size(), 3)
	assert_eq(solution[7].size(), 3)
	assert_eq(solution[8].size(), 3)
	assert_eq(solution[9].size(), 3)
	assert_eq(solution[10].size(), 3)
	assert_eq(solution[11].size(), 3)


func test_decompose_polygon_into_convex():
	solution = GeometryTools2D.decompose_polygon_into_convex(poly_boundary)
	assert_eq(solution.size(), 1)


func test_decompose_multiple_polygons_into_convex():
	solution = GeometryTools2D.decompose_multiple_polygons_into_convex([poly_boundary, poly_hole, poly_c])
	assert_eq(solution.size(), 6)
	assert_eq(solution[0].size(), 4)
	assert_eq(solution[1].size(), 4)
	assert_eq(solution[2].size(), 4)
	assert_eq(solution[3].size(), 5)
	assert_eq(solution[4].size(), 5)
	assert_eq(solution[5].size(), 4)


func test_decompose_polygons_triangles_opt():
	solution = GeometryTools2D.decompose_polygons(GeometryTools2D.DECOMP_TRIANGLES_OPT, [poly_boundary])
	assert_eq(solution.size(), 6)
	assert_eq(solution[0].size(), 3)
	assert_eq(solution[1].size(), 3)
	assert_eq(solution[2].size(), 3)
	assert_eq(solution[3].size(), 3)
	assert_eq(solution[4].size(), 3)
	assert_eq(solution[5].size(), 3)


func test_decompose_polygons_triangles_mono():
	if ProjectSettings.get_setting("modules/geometry_tools/2d/backends/poly_decomp") == "polypartition":
		push_error("Skip, internal bug in PolyPartition.Triangulate_MONO...")
		return true

	solution = GeometryTools2D.decompose_polygons(GeometryTools2D.DECOMP_TRIANGLES_MONO, [poly_boundary, poly_hole])
	assert_eq(solution.size(), 12)
	assert_eq(solution[0].size(), 3)
	assert_eq(solution[1].size(), 3)
	assert_eq(solution[2].size(), 3)
	assert_eq(solution[3].size(), 3)
	assert_eq(solution[4].size(), 3)
	assert_eq(solution[5].size(), 3)
	assert_eq(solution[6].size(), 3)
	assert_eq(solution[7].size(), 3)
	assert_eq(solution[8].size(), 3)
	assert_eq(solution[9].size(), 3)
	assert_eq(solution[10].size(), 3)
	assert_eq(solution[11].size(), 3)


func test_decompose_polygons_convex_opt():
	solution = GeometryTools2D.decompose_polygons(GeometryTools2D.DECOMP_CONVEX_OPT, [poly_boundary])
	assert_eq(solution.size(), 1)
	assert_eq(solution[0].size(), 8)


func test_polygon_centroid():
	solution = GeometryTools2D.polygon_centroid(poly_a)
	assert_eq(solution, Vector2(50, 50))


func test_polygon_perimeter():
	solution = GeometryTools2D.polygon_perimeter(poly_a)
	assert_eq(solution, 400.0)


func test_polyline_length():
	solution = GeometryTools2D.polyline_length(poly_a)
	assert_eq(solution, 300.0)


func test_point_in_polygon():
	solution = GeometryTools2D.point_in_polygon(Vector2(50, 50), poly_a)
	assert_eq(solution, 1) # inside
	solution = GeometryTools2D.point_in_polygon(Vector2(-50, 50), poly_a)
	assert_eq(solution, 0) # outside
	solution = GeometryTools2D.point_in_polygon(Vector2(0, 50), poly_a)
	assert_eq(solution, -1) # exactly


func test_regular_polygon():
	solution = GeometryTools2D.regular_polygon(64, SIZE)
	assert_eq(solution.size(), 64)


func test_circle():
	solution = GeometryTools2D.circle(SIZE, 0.25)
	assert_eq(solution.size(), 32)


func _draw():
	# Some specific methods which have to be drawn with `draw_polyline`.
	var polyline_test_methods = [
		"test_clip_polyline_with_polygon",
		"test_intersect_polyline_with_polygon",
		"test_clip_multiple_polylines_with_polygons",
		"test_intersect_multiple_polylines_with_polygons"
	]
	var polygons_only = not (current_test in polyline_test_methods)

	if polygons_only:
		match typeof(solution):
			TYPE_ARRAY:
				for poly in solution:
					draw_colored_polygon(poly, Color(randf(), randf(), randf()))
			TYPE_OBJECT:
				var c = Color.green
				if solution is PolyNode2D:
					var nodes = [solution]
					while not nodes.empty():
						var node = nodes.back()
						nodes.pop_back()

						if node.path.size() > 0:
							draw_colored_polygon(node.path, c)

						for child in node.get_children():
							nodes.push_back(child)

						c.v -= 0.25
	else: # polylines
		for poly in solution:
			draw_polyline(poly, Color(randf(), randf(), randf()), 2)
