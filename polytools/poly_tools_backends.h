#ifndef GEOMETRY_POLY_TOOLS_BACKENDS_H
#define GEOMETRY_POLY_TOOLS_BACKENDS_H

#if defined(GEOMETRY_POLY_TOOLS_CLIPPER6)
#include "polytools/backends/clipper6/clipper6_backend.h"
#elif defined(GEOMETRY_POLY_TOOLS_CLIPPER10)
#include "polytools/backends/clipper10/clipper10_backend.h"
#endif

#endif // GEOMETRY_POLY_TOOLS_BACKENDS_H
