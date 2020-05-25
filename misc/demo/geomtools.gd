extends Node2D

# This is just a master script to run demo scenes.

export(Array, PackedScene) var scenes

var current_id = 0
var current_scene = null


func _ready():
	if not scenes.empty():
		create_from_scene(scenes[0])


func _on_previous_pressed():
	if scenes.empty():
		return
	current_id = wrapi(current_id - 1, 0, scenes.size())
	create_from_scene(scenes[current_id])


func _on_next_pressed():
	if scenes.empty():
		return
	current_id = wrapi(current_id + 1, 0, scenes.size())
	create_from_scene(scenes[current_id])


func create_from_scene(p_scene):
	for node in $scene.get_children():
		node.queue_free()
	var demo = p_scene.instance()
	$scene.add_child(demo)
