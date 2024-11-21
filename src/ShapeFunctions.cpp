#include "ShapeFunctions.h"
#include <stdexcept>

// Calculate the area of a triangular element
double ShapeFunctions::calculateArea(const std::vector<Node*>& nodes) {
    if (nodes.size() != 3) {
        throw std::invalid_argument("Triangular element must have exactly 3 nodes.");
    }

    const Node* n1 = nodes[0];
    const Node* n2 = nodes[1];
    const Node* n3 = nodes[2];

    return 0.5 * std::abs(n1->x * (n2->y - n3->y) +
                          n2->x * (n3->y - n1->y) +
                          n3->x * (n1->y - n2->y));
}

// Compute coefficients (a, b, c) for shape function N_i
std::vector<double> ShapeFunctions::computeShapeFunctionCoefficients(const std::vector<Node*>& nodes, int i) {
    if (nodes.size() != 3 || i < 0 || i > 2) {
        throw std::invalid_argument("Invalid node index or nodes for triangular element.");
    }

    const Node* n1 = nodes[(i + 1) % 3];
    const Node* n2 = nodes[(i + 2) % 3];

    double a = n1->x * n2->y - n2->x * n1->y;
    double b = n1->y - n2->y;
    double c = n2->x - n1->x;

    return {a, b, c};
}

// Compute the gradient of shape functions (dN/dx, dN/dy)
std::vector<std::vector<double>> ShapeFunctions::computeGradient(const std::vector<Node*>& nodes) {
    double area = calculateArea(nodes);
    std::vector<std::vector<double>> gradients(3, std::vector<double>(2, 0.0));

    for (int i = 0; i < 3; ++i) {
        auto coeffs = computeShapeFunctionCoefficients(nodes, i);
        gradients[i][0] = coeffs[1] / (2 * area); // dN/dx
        gradients[i][1] = coeffs[2] / (2 * area); // dN/dy
    }

    return gradients;
}
