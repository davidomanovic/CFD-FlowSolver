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

## Example Use Case: Lid-Driven Cavity Flow
This solver can simulate classic CFD benchmark problems like the 2D lid-driven cavity flow. A square domain is discretized into triangular elements, and the top boundary is assigned a velocity while others are stationary.

---

## Project Structure
