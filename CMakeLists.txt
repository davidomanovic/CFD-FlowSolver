cmake_minimum_required(VERSION 3.10)
project(FEMSolver)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/Matrix.cpp
    src/Vector.cpp
    src/Element.cpp
    src/BoundaryConditions.cpp
    src/Mesh.cpp
    src/MeshGenerator.cpp
    src/Node.cpp
    src/PostProcessor.cpp
    src/Solver.cpp
    src/Utils.cpp
    src/ShapeFunctions.cpp
    src/LocalStiffness.cpp
    src/VTKWriter.cpp
)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add the executable
add_executable(FEMSolver ${SOURCES})

