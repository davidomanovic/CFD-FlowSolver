#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Node.h"
#include "Element.h"
#include "Vector.h"
#include "Matrix.h"
#include "LocalStiffness.h" 

class Mesh {
private:
    std::vector<Node> nodes;
    std::vector<Element> elements;

public:
    void addNode(int id, double x, double y, bool isBoundary = false);
    void addElement(int id, const std::vector<int>& nodeIds);
    const std::vector<Node>& getNodes() const;
    const std::vector<Element>& getElements() const;
    void print() const;  // Debugging: print the mesh
    Matrix assembleGlobalStiffness() const;
    Vector assembleRHS() const; 
    void applyBoundaryConditions(Matrix& globalK, Vector& rhs) const; // Add this method

};

#endif
