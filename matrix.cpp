#include <vector>

#include "matrix.hpp"

Matrix::Matrix(std::size_t N) {}

Matrix::Matrix(std::vector<std::vector<int>> nums) {}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(this->get_size());
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(this->get_size());
    return result;
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {

}
int Matrix::get_value(std::size_t i, std::size_t j) const {
    return 0;
}

int Matrix::get_size() const {
    return 0;
}

int Matrix::sum_diagonal_major() const {
    return 0;
}
int Matrix::sum_diagonal_minor() const {
    return 0;
}
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    
}

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {

}

void Matrix::print_matrix() const {

}