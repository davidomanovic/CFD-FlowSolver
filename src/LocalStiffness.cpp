#include "LocalStiffness.h"

Matrix LocalStiffness::compute(const std::vector<Node*>& nodes) {
    double area = ShapeFunctions::calculateArea(nodes);
    auto gradients = ShapeFunctions::computeGradient(nodes);

    Matrix K(3, 3); // 3x3 for triangular element
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            double dotProduct = gradients[i][0] * gradients[j][0] + gradients[i][1] * gradients[j][1];
            K(i, j) = (dotProduct * area);
        }
    }

    return K;
}
