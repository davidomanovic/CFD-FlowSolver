#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

class Vector {
private:
    size_t size;
    std::vector<double> data;

public:
    Vector(size_t size);
    double& operator[](size_t index);
    const double& operator[](size_t index) const;
    size_t getSize() const;

    // Basic operations
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double dot(const Vector& other) const; // Dot product
    Vector operator*(double scalar) const;

    // Debugging
    void print() const;
};

#endif
