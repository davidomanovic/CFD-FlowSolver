# CFD-FlowSolver

### A Finite Element Method Solver for 2D Incompressible Flows

---

## Overview
`FEM-FlowSolver` is a lightweight, educational implementation of a 2D Finite Element Method (FEM) solver for incompressible fluid flow problems. It solves the steady-state Navier-Stokes equations using a stabilized FEM formulation, making it suitable for low Reynolds number flows.

The project demonstrates key concepts of FEM:
- Mesh generation and handling.
- Element-level matrix assembly.
- Sparse matrix solvers for large systems.
- Boundary condition enforcement.
- Result visualization using VTK.

---

## Features
- Triangular finite element discretization.
- Support for Dirichlet and Neumann boundary conditions.
- Stabilized FEM for incompressible flows (SUPG/PSPG).
- VTK output for visualization in ParaView.
- Modular and extensible C++ design.

---

### Project Structure
 ```graphql
FEM-FlowSolver/
├── src/
│   ├── main.cpp                 # Entry point of the application
│   ├── MeshGenerator.cpp        # Module for creating and managing finite element meshes
│   ├── Element.cpp              # Class representing a single finite element
│   ├── Solver.cpp               # Core FEM solver for assembling and solving equations
│   ├── PostProcessor.cpp        # Handles visualization and output
│   ├── Utils.cpp                # General utility functions
│   └── BoundaryConditions.cpp   # Functions for applying boundary conditions
│
├── include/
│   ├── MeshGenerator.h          # Header for MeshGenerator
│   ├── Element.h                # Header for Element class
│   ├── Solver.h                 # Header for Solver class
│   ├── PostProcessor.h          # Header for PostProcessor
│   ├── Utils.h                  # Header for utility functions
│   └── BoundaryConditions.h     # Header for boundary conditions
│
├── data/
│   ├── sample_mesh.vtk          # Example mesh for testing
│   ├── boundary_conditions.txt  # Example boundary conditions file
│   └── material_properties.txt  # Material properties for the fluid
│
├── tests/
│   ├── test_solver.cpp          # Unit tests for the FEM solver
│   ├── test_mesh.cpp            # Unit tests for the mesh generator
│   └── test_utils.cpp           # Unit tests for utility functions
│
├── results/
│   └── velocity_field.vtk       # Sample output (VTK format)
│
├── CMakeLists.txt               # Build system configuration
├── README.md                    # Documentation
└── LICENSE                      # Licensing information

```



## Example Use Case: Lid-Driven Cavity Flow
This solver can simulate classic CFD benchmark problems like the 2D lid-driven cavity flow. A square domain is discretized into triangular elements, and the top boundary is assigned a velocity while others are stationary.

---

## Project Structure



---

## Getting Started

### Prerequisites
- **C++ Compiler**: GCC or Clang (C++17 or later).
- **CMake**: For building the project.
- **VTK**: Optional, for visualizing results.

### Installation
1. Clone the repository:
```bash
git clone https://github.com/username/FEM-FlowSolver.git
cd FEM-FlowSolver
```
2. Build project:
```bash
mkdir build
cd build
cmake ..
make
```

4. Run solver
