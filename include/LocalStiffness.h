#ifndef LOCALSTIFFNESS_H
#define LOCALSTIFFNESS_H

#include <vector>
#include "Node.h"
#include "Matrix.h"
#include "ShapeFunctions.h"

class LocalStiffness {
public:
    static Matrix compute(const std::vector<Node*>& nodes);
};

#endif
