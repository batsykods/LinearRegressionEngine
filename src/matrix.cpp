#include "../include/matrix.h"
#include <cstdlib>
#include <ctime>

Matrix::Matrix(int rows, int cols) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

int Matrix::rows() const {
    return data.size();
}

int Matrix::cols() const {
    return data[0].size();
}

void Matrix::randomize() {

    srand(time(0));

    for (auto& row : data) {
        for (auto& val : row) {
            val = ((double)rand() / RAND_MAX);
        }
    }
}

Matrix Matrix::transpose() const {

    Matrix result(cols(), rows());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            result.data[j][i] = data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {

    Matrix result(rows(), cols());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {

            result.data[i][j] =
                data[i][j] + other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {

    Matrix result(rows(), cols());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {

            result.data[i][j] =
                data[i][j] - other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {

    Matrix result(rows(), other.cols());

    for (int i = 0; i < rows(); i++) {

        for (int j = 0; j < other.cols(); j++) {

            double sum = 0;

            for (int k = 0; k < cols(); k++) {
                sum += data[i][k] * other.data[k][j];
            }

            result.data[i][j] = sum;
        }
    }

    return result;
}

Matrix Matrix::scalarMultiply(double value) const {

    Matrix result(rows(), cols());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {

            result.data[i][j] =
                data[i][j] * value;
        }
    }

    return result;
}

void Matrix::print() const {

    for (auto row : data) {

        for (auto val : row) {
            std::cout << val << " ";
        }

        std::cout << std::endl;
    }
}
