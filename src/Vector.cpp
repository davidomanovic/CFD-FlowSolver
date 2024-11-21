#include "Vector.h"
#include <stdexcept>

// Constructor
Vector::Vector(size_t size) : size(size), data(size, 0.0) {}

// Access elements
double& Vector::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Vector index out of range");
    }
    return data[index];
}

const double& Vector::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Vector index out of range");
    }
    return data[index];
}

// Get size
size_t Vector::getSize() const { return size; }

// Addition
Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector dimensions must match for addition");
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i] + other[i];
    }
    return result;
}

// Subtraction
Vector Vector::operator-(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector dimensions must match for subtraction");
    }
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i] - other[i];
    }
    return result;
}

// Dot product
double Vector::dot(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Vector dimensions must match for dot product");
    }
    double result = 0.0;
    for (size_t i = 0; i < size; ++i) {
        result += data[i] * other[i];
    }
    return result;
}

// Scalar multiplication
Vector Vector::operator*(double scalar) const {
    Vector result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = data[i] * scalar;
    }
    return result;
}

// Print vector
void Vector::print() const {
    for (double val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
