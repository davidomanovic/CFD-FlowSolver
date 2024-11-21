#include "VTKWriter.h"
#include <fstream>
#include <iostream>

void VTKWriter::writeSolution(const std::string& filename, const Mesh& mesh, const Vector& solution) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    // Write VTK header
    file << "# vtk DataFile Version 3.0\n";
    file << "FEM Solution\n";
    file << "ASCII\n";
    file << "DATASET UNSTRUCTURED_GRID\n";

    // Write nodal points
    const auto& nodes = mesh.getNodes();
    file << "POINTS " << nodes.size() << " double\n";
    for (const auto& node : nodes) {
        file << node.x << " " << node.y << " 0.0\n"; // z=0 for 2D
    }

    // Write elements
    const auto& elements = mesh.getElements();
    int totalConnectivity = 4 * elements.size(); // 3 nodes + 1 size entry per element
    file << "\nCELLS " << elements.size() << " " << totalConnectivity << "\n";
    for (const auto& element : elements) {
        file << "3 "; // Number of nodes per element
        for (const auto* node : element.getNodes()) {
            file << node->id << " ";
        }
        file << "\n";
    }

    // Write cell types (5 = VTK_TRIANGLE)
    file << "\nCELL_TYPES " << elements.size() << "\n";
    for (size_t i = 0; i < elements.size(); ++i) {
        file << "5\n";
    }

    // Write solution values at nodes
    file << "\nPOINT_DATA " << nodes.size() << "\n";
    file << "SCALARS solution double\n";
    file << "LOOKUP_TABLE default\n";
    for (size_t i = 0; i < nodes.size(); ++i) {
        file << solution[i] << "\n";
    }

    file.close();
    std::cout << "Solution written to " << filename << "\n";
}

