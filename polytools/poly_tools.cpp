#include "poly_tools.h"

void PolyParams::_bind_methods() {
    
}

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
