#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

class Matrix {
public:
    virtual Matrix operator+(const Matrix &rhs) = 0;
    virtual Matrix operator*(const Matrix &rhs) = 0;
    virtual void set_value(std::size_t i, std::size_t j, int n) = 0;
    virtual int get_value(std::size_t i, std::size_t j) = 0;
    virtual int get_size() = 0;
    virtual int sum_diagonal_major() = 0;
    virtual int sum_diagonal_minor() = 0;
    virtual void swap_rows(std::size_t r1, std::size_t r2) = 0;
    virtual void swap_cols(std::size_t c1, std::size_t c2) = 0;
    virtual void print_matrix() = 0;
};

class MyMatrix : public Matrix {
public:
    MyMatrix(std::vector<std::vector<int>> nums);
private:

};

#endif // __MATRIX_HPP__