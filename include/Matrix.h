#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
private:
    size_t rows, cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(size_t rows, size_t cols);
    double& operator()(size_t row, size_t col);
    const double& operator()(size_t row, size_t col) const;
    size_t getRows() const;
    size_t getCols() const;

    // Basic operations
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix transpose() const;

    // Debugging
    void print() const;
};

#endif
