extends Node2D

const SIZE = 100.0
const base = PoolVector2Array([Vector2(-1, -1), Vector2(1, -1), Vector2(1, 1), Vector2(-1, 1)])
var subject = Transform2D(0, Vector2.ZERO).scaled(Vector2.ONE * SIZE).xform(base)

var solution = []


func _process(_delta):
	var pos = get_global_mouse_position()
	var brush = GeometryTools2D.regular_polygon(16, SIZE / 2)
	brush = Transform2D(0, pos).xform(brush)
	var polys = GeometryTools2D.clip_polygons(subject, brush)
	solution = GeometryTools2D.decompose_multiple_polygons_into_convex(polys)
	update()


func _draw():
	for poly in solution:
		draw_polyline(poly, Color.greenyellow, 1.0)
		draw_polyline([poly[0], poly[-1]], Color.greenyellow, 1.0)
