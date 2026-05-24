#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    std::vector<std::vector<double>> data;

    Matrix(int rows, int cols);

    int rows() const;
    int cols() const;

    void randomize();

    Matrix transpose() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix scalarMultiply(double value) const;

    void print() const;
};

#endif