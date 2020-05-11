#include "poly_tools.h"

void PolyBooleanParams::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_subject_fill_rule", "subject_fill_rule"), &PolyBooleanParams::set_subject_fill_rule);
    ClassDB::bind_method(D_METHOD("get_subject_fill_rule"), &PolyBooleanParams::get_subject_fill_rule);
    ClassDB::bind_method(D_METHOD("set_clip_fill_rule", "clip_fill_rule"), &PolyBooleanParams::set_clip_fill_rule);
    ClassDB::bind_method(D_METHOD("get_clip_fill_rule"), &PolyBooleanParams::get_clip_fill_rule);
    ClassDB::bind_method(D_METHOD("set_reverse_solution", "reverse_solution"), &PolyBooleanParams::set_reverse_solution);
    ClassDB::bind_method(D_METHOD("is_reverse_solution"), &PolyBooleanParams::is_reverse_solution);
    ClassDB::bind_method(D_METHOD("set_strictly_simple", "strictly_simple"), &PolyBooleanParams::set_strictly_simple);
    ClassDB::bind_method(D_METHOD("is_strictly_simple"), &PolyBooleanParams::is_strictly_simple);
    ClassDB::bind_method(D_METHOD("set_preserve_collinear", "preserve_collinear"), &PolyBooleanParams::set_preserve_collinear);
    ClassDB::bind_method(D_METHOD("is_preserve_collinear"), &PolyBooleanParams::is_preserve_collinear);
    
    BIND_ENUM_CONSTANT(FILL_RULE_EVEN_ODD);
    BIND_ENUM_CONSTANT(FILL_RULE_NON_ZERO);
    BIND_ENUM_CONSTANT(FILL_RULE_POSITIVE);
    BIND_ENUM_CONSTANT(FILL_RULE_NEGATIVE);
    
    ADD_PROPERTY(PropertyInfo(Variant::INT, "subject_fill_rule"), "set_subject_fill_rule", "get_subject_fill_rule");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "clip_fill_rule"), "set_clip_fill_rule", "get_clip_fill_rule");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "reverse_solution"), "set_reverse_solution", "is_reverse_solution");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "strictly_simple"), "set_strictly_simple", "is_strictly_simple");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "preserve_collinear"), "set_preserve_collinear", "is_preserve_collinear");
}

PolyBooleanParams::PolyBooleanParams(): 
    subject_fill_rule(FILL_RULE_NON_ZERO),
    clip_fill_rule(FILL_RULE_NON_ZERO),
	reverse_solution(false),
	strictly_simple(false),
	preserve_collinear(false)
{}

Ref<PolyNode> PolyNode::new_child(const Vector<Point2> &p_path) {
    Ref<PolyNode> child;
    child.instance();
    child->path = p_path;
    children.push_back(child);
    return child;
}

Ref<PolyNode> PolyNode::get_child(int p_idx) {
    ERR_FAIL_INDEX_V(p_idx, children.size(), nullptr);
    return children[p_idx];
}

bool PolyNode::is_hole() const {
    bool hole = true;
    Ref<PolyNode> n = parent;
    while (n.is_valid()) {
      hole = !hole;
      n = n->parent;
    }
    return hole;
}

void PolyNode::clear() {
    children.clear();
}

void PolyNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("new_child", "path"), &PolyNode::new_child);
    ClassDB::bind_method(D_METHOD("get_child", "index"), &PolyNode::get_child);
    ClassDB::bind_method(D_METHOD("get_child_count"), &PolyNode::get_child_count);
    ClassDB::bind_method(D_METHOD("get_parent"), &PolyNode::get_parent);
    ClassDB::bind_method(D_METHOD("set_path", "path"), &PolyNode::set_path);
    ClassDB::bind_method(D_METHOD("get_path"), &PolyNode::get_path);
    ClassDB::bind_method(D_METHOD("is_hole"), &PolyNode::is_hole);
    ClassDB::bind_method(D_METHOD("clear"), &PolyNode::clear);
}
