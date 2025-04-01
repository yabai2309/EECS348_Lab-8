#include "matrix.hpp"
#include <stdexcept>
#include <iomanip>
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

Matrix::Matrix(std::size_t N) : data(N, std::vector<int>(N, 0)) {}
Matrix::Matrix(std::vector<std::vector<int>> nums) : data(nums) {}

// Overloaded addition operator.
Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = get_size();
    if (rhs.get_size() != N) {
        throw std::invalid_argument("Matrix sizes do not match for addition.");
    }
    Matrix result(N);
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

// Overloaded multiplication operator.
Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = get_size();
    if (rhs.get_size() != N) {
        throw std::invalid_argument("Matrix sizes do not match for multiplication.");
    }
    Matrix result(N);
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            int sum = 0;
            for (std::size_t k = 0; k < N; k++) {
                sum += data[i][k] * rhs.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Set a specific value in the matrix.
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= get_size() || j >= get_size()) {
        throw std::out_of_range("Index out of range in set_value.");
    }
    data[i][j] = n;
}

// Get a specific value from the matrix.
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= get_size() || j >= get_size()) {
        throw std::out_of_range("Index out of range in get_value.");
    }
    return data[i][j];
}

// Return the size (number of rows/columns) of the square matrix.
int Matrix::get_size() const {
    return data.size();
}

// Sum of the primary (major) diagonal.
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    std::size_t N = get_size();
    for (std::size_t i = 0; i < N; i++) {
        sum += data[i][i];
    }
    return sum;
}

// Sum of the secondary (minor) diagonal.
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    std::size_t N = get_size();
    for (std::size_t i = 0; i < N; i++) {
        sum += data[i][N - 1 - i];
    }
    return sum;
}

// Swap two rows in the matrix.
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    std::size_t N = get_size();
    if (r1 >= N || r2 >= N) {
        throw std::out_of_range("Row index out of range in swap_rows.");
    }
    std::swap(data[r1], data[r2]);
}

// Swap two columns in the matrix.
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    std::size_t N = get_size();
    if (c1 >= N || c2 >= N) {
        throw std::out_of_range("Column index out of range in swap_cols.");
    }
    for (std::size_t i = 0; i < N; i++) {
        std::swap(data[i][c1], data[i][c2]);
    }
}

// Print the matrix to standard output.
void Matrix::print_matrix() const {
    std::size_t N = get_size();
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
