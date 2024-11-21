#ifndef VTKWRITER_H
#define VTKWRITER_H

#include <string>
#include "Mesh.h"
#include "Vector.h"

class VTKWriter {
public:
    static void writeSolution(const std::string& filename, const Mesh& mesh, const Vector& solution);
};

#endif
