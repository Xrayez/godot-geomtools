#include "register_types.h"
#include "core/engine.h"

#include "2d/bind/geometry_tools_bind.h"
#include "2d/geometry_tools.h"

static _GeometryTools2D *_geometry_tools = nullptr;

void register_geomtools_types() {
	_geometry_tools = memnew(_GeometryTools2D);
	GeometryTools2D::initialize();
	
	ClassDB::register_class<_GeometryTools2D>();
	Engine::get_singleton()->add_singleton(Engine::Singleton("GeometryTools2D", _GeometryTools2D::get_singleton()));
	
	ClassDB::register_class<PolyBooleanParameters2D>();
	ClassDB::register_class<PolyNode2D>();
}

void unregister_geomtools_types() {
	memdelete(_geometry_tools);
	GeometryTools2D::finalize();
}
