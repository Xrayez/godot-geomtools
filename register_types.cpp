#include "register_types.h"
#include "core/engine.h"
#include "bind/geometry_tools_bind.h"
#include "geometry_tools.h"

static _GeometryTools *_geometry_tools = nullptr;

void register_geomtools_types() {
	_geometry_tools = memnew(_GeometryTools);
	GeometryTools::initialize();
	ClassDB::register_class<_GeometryTools>();
	Engine::get_singleton()->add_singleton(Engine::Singleton("GeometryTools", _GeometryTools::get_singleton()));
}

void unregister_geomtools_types() {
	memdelete(_geometry_tools);
	GeometryTools::finalize();
}
