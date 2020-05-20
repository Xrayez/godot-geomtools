#ifndef GEOMETRY_TOOLS_POLY_DECOMP_BUILTIN
#define GEOMETRY_TOOLS_POLY_DECOMP_BUILTIN

#include "modules/geomtools/2d/polytools/decomp/poly_decomp.h"

// Just so it compiles with the existing approach.
class PolyDecomp2DBuiltin : public PolyDecomp2D {};

using PolyDecomp2D = PolyDecomp2DBuiltin;

#endif // GEOMETRY_TOOLS_POLY_DECOMP_BUILTIN
