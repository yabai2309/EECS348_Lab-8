/*
EECS 348 Lab 08
Matrix operation program

Inputs: A file with size of the matrix and 2 matrixes
Outputs: Execute whatever function the user want

Collaborators: None
Other sources: None
Author's name: Anh Hoang
Creation date: 3/25/25

*/
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix {//Define class matrix
public://Define public method
    Matrix(std::size_t N);//Constructor
    Matrix(std::vector<std::vector<int>> nums);//Copy constructor
    //List out all of the method
    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
private://Define private parameters
    std::vector<std::vector<int>> data;//Matrix data
};

#endif // __MATRIX_HPP__