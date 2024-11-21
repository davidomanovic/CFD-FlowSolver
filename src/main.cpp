#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Mesh.h"
#include "Solver.h"
#include "VTKWriter.h"

// Analytical solution (for validation)
double analyticalSolution(double x, double y) {
    return std::sin(M_PI * x) * std::sin(M_PI * y);
}

// Source term for Poisson equation
double sourceTerm(double x, double y) {
    return 2 * M_PI * M_PI * std::sin(M_PI * x) * std::sin(M_PI * y);
}

int main() {
    // Create mesh
    Mesh mesh;
    mesh.addNode(0, 0.0, 0.0, true);   // Boundary node
    mesh.addNode(1, 1.0, 0.0, true);   // Boundary node
    mesh.addNode(2, 0.0, 1.0, true);   // Boundary node
    mesh.addNode(3, 1.0, 1.0, true);   // Boundary node
    mesh.addNode(4, 0.5, 0.5, false);  // Interior node
    mesh.addNode(5, 0.0, 0.5, false);  // Interior node
    mesh.addNode(6, 0.5, 0.0, false);  // Interior node

    // Define triangular elements (assumes counterclockwise ordering)
    mesh.addElement(0, {0, 5, 4});
    mesh.addElement(1, {5, 2, 4});
    mesh.addElement(2, {4, 6, 1});
    mesh.addElement(3, {6, 4, 0});

    // Print the mesh for debugging
    std::cout << "Mesh:\n";
    mesh.print();

    // Assemble global stiffness matrix
    Matrix globalK = mesh.assembleGlobalStiffness();
    std::cout << "\nGlobal Stiffness Matrix (Before BC):\n";
    globalK.print();

    // Assemble RHS vector (using the source term f(x, y))
    Vector rhs = mesh.assembleRHS();
    for (const auto& node : mesh.getNodes()) {
        if (!node.isBoundary) {
            rhs[node.id] = sourceTerm(node.x, node.y);
        }
    }
    std::cout << "\nRHS Vector (Before BC):\n";
    rhs.print();

    // Apply boundary conditions
    mesh.applyBoundaryConditions(globalK, rhs);
    std::cout << "\nGlobal Stiffness Matrix (After BC):\n";
    globalK.print();
    std::cout << "\nRHS Vector (After BC):\n";
    rhs.print();

    // Solve the system
    Vector solution = Solver::solve(globalK, rhs);

    // Print the solution
    std::cout << "\nSolution:\n";
    solution.print();

    // Write solution to VTK for visualization
    VTKWriter::writeSolution("solution.vtk", mesh, solution);

    // Validate against analytical solution
    std::cout << "\nNode-wise Errors:\n";
    for (const auto& node : mesh.getNodes()) {
        double exact = analyticalSolution(node.x, node.y);
        double error = std::abs(solution[node.id] - exact);
        std::cout << "Node " << node.id << ": Error = " << error << "\n";
    }

    return 0;
}
