
#include "Solver.h"
#include <stdexcept>

Vector Solver::solve(const Matrix& K, const Vector& rhs) {
    size_t n = K.getRows();
    Vector u(n);

    // Simple Gaussian elimination (not optimized for large problems)
    Matrix A = K; // Make a copy to preserve K
    Vector b = rhs;

    // Forward elimination
    for (size_t k = 0; k < n; ++k) {
        // Pivot (naively assuming no zero pivot)
        double pivot = A(k, k);
        if (pivot == 0.0) {
            throw std::runtime_error("Matrix is singular or nearly singular.");
        }

        for (size_t j = k; j < n; ++j) {
            A(k, j) /= pivot;
        }
        b[k] /= pivot;

        for (size_t i = k + 1; i < n; ++i) {
            double factor = A(i, k);
            for (size_t j = k; j < n; ++j) {
                A(i, j) -= factor * A(k, j);
            }
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; --i) {
        u[i] = b[i];
        for (size_t j = i + 1; j < n; ++j) {
            u[i] -= A(i, j) * u[j];
        }
    }

    return u;
}
