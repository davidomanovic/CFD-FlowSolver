#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "Node.h"

class Element {
private:
    int id;                    // Element ID
    std::vector<Node*> nodes;  // Pointers to nodes defining the element

public:
    Element(int id, const std::vector<Node*>& nodes);
    const std::vector<Node*>& getNodes() const;
    int getId() const;
};

#endif
