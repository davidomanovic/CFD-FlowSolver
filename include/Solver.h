#ifndef SOLVER_H
#define SOLVER_H

#include "Matrix.h"
#include "Vector.h"

class Solver {
public:
    static Vector solve(const Matrix& K, const Vector& rhs);
};

#endif
