#include "poly_decomp.h"

void PolyDecompParameters2D::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_fill_rule", "fill_rule"), &PolyDecompParameters2D::set_fill_rule);
    ClassDB::bind_method(D_METHOD("get_fill_rule"), &PolyDecompParameters2D::get_fill_rule);
    
    BIND_ENUM_CONSTANT(FILL_RULE_EVEN_ODD);
    BIND_ENUM_CONSTANT(FILL_RULE_NON_ZERO);
    BIND_ENUM_CONSTANT(FILL_RULE_POSITIVE);
    BIND_ENUM_CONSTANT(FILL_RULE_NEGATIVE);
    
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fill_rule"), "set_fill_rule", "get_fill_rule");
}
