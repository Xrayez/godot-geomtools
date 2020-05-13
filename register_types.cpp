#include "register_types.h"
#include "core/engine.h"

#include "2d/bind/geometry_tools_bind.h"
#include "2d/geometry_tools.h"

static module_bind::GeometryTools2D *_geometry_tools = nullptr;

void register_geomtools_types() {
	_geometry_tools = memnew(module_bind::GeometryTools2D);
	GeometryTools2D::initialize();
	
	ClassDB::register_class<module_bind::GeometryTools2D>();
	Engine::get_singleton()->add_singleton(Engine::Singleton("GeometryTools2D", module_bind::GeometryTools2D::get_singleton()));
	
	ClassDB::register_class<PolyBooleanParameters2D>();
	ClassDB::register_class<PolyOffsetParameters2D>();
	ClassDB::register_class<PolyDecompParameters2D>();
	
	ClassDB::register_class<PolyNode2D>();
}

void unregister_geomtools_types() {
	memdelete(_geometry_tools);
	GeometryTools2D::finalize();
}
