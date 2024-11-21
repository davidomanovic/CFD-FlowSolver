#define _USE_MATH_DEFINES
#include "Mesh.h"
#include <iostream>
#include <cmath>

// Add a node to the mesh
void Mesh::addNode(int id, double x, double y, bool isBoundary) {
    nodes.emplace_back(id, x, y, isBoundary);
}

// Add an element to the mesh
void Mesh::addElement(int id, const std::vector<int>& nodeIds) {
    std::vector<Node*> elementNodes;
    for (int nodeId : nodeIds) {
        elementNodes.push_back(&nodes[nodeId]);
    }
    elements.emplace_back(id, elementNodes);
}

// Getters
const std::vector<Node>& Mesh::getNodes() const {
    return nodes;
}

const std::vector<Element>& Mesh::getElements() const {
    return elements;
}

// Debugging: print the mesh
void Mesh::print() const {
    std::cout << "Nodes:\n";
    for (const Node& node : nodes) {
        std::cout << "ID: " << node.id << ", Coordinates: (" << node.x << ", " << node.y << ")";
        if (node.isBoundary) std::cout << " [Boundary]";
        std::cout << "\n";
    }

    std::cout << "\nElements:\n";
    for (const Element& element : elements) {
        std::cout << "ID: " << element.getId() << ", Nodes: ";
        for (const Node* node : element.getNodes()) {
            std::cout << node->id << " ";
        }
        std::cout << "\n";
    }
}


// Assemble the global stiffness matrix
Matrix Mesh::assembleGlobalStiffness() const {
    size_t numNodes = nodes.size();
    Matrix globalK(numNodes, numNodes);

    for (const auto& element : elements) {
        const auto& elementNodes = element.getNodes();
        Matrix localK = LocalStiffness::compute(elementNodes);

        std::cout << "\nLocal Stiffness Matrix for Element " << element.getId() << ":\n";
        localK.print(); // Print the local stiffness matrix

        // Map local stiffness matrix to global stiffness matrix
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                globalK(elementNodes[i]->id, elementNodes[j]->id) += localK(i, j);
            }
        }
    }

    return globalK;
}

// Assemble the RHS vector (e.g., for f = 0 everywhere)
Vector Mesh::assembleRHS() const {
    size_t numNodes = nodes.size();
    Vector rhs(numNodes);

    // Populate RHS with f(x, y) = 2π² sin(πx) sin(πy)
    for (const auto& node : nodes) {
        if (!node.isBoundary) {
            rhs[node.id] = 2 * M_PI * M_PI * std::sin(M_PI * node.x) * std::sin(M_PI * node.y);
        }
    }

    return rhs;
}

// Apply boundary conditions to the global system
void Mesh::applyBoundaryConditions(Matrix& globalK, Vector& rhs) const {
    for (const auto& node : nodes) {
        if (node.isBoundary) {
            int id = node.id;

            // Set the corresponding row and column in K to zero
            for (size_t j = 0; j < globalK.getCols(); ++j) {
                globalK(id, j) = 0.0;
                globalK(j, id) = 0.0;
            }

            // Set the diagonal to 1
            globalK(id, id) = 1.0;
            rhs[id] = 0.0;
        }
    }
}
