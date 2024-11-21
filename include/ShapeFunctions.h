#ifndef SHAPEFUNCTIONS_H
#define SHAPEFUNCTIONS_H

#include <vector>
#include "Node.h"

class ShapeFunctions {
public:
    static double calculateArea(const std::vector<Node*>& nodes);
    static std::vector<double> computeShapeFunctionCoefficients(const std::vector<Node*>& nodes, int i);
    static std::vector<std::vector<double>> computeGradient(const std::vector<Node*>& nodes);
};

#endif
