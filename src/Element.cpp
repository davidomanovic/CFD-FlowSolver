#include "Element.h"

Element::Element(int id, const std::vector<Node*>& nodes)
    : id(id), nodes(nodes) {}

const std::vector<Node*>& Element::getNodes() const {
    return nodes;
}

int Element::getId() const {
    return id;
}
