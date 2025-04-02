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
#include "matrix.hpp"
#include <stdexcept>
#include <iomanip>
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

//Constructor of the class
Matrix::Matrix(std::size_t N) : data(N, std::vector<int>(N, 0)) {}//Normal constructor
Matrix::Matrix(std::vector<std::vector<int>> nums) : data(nums) {}//Copy constructor

// Overloaded addition operator
Matrix Matrix::operator+(const Matrix &rhs) const {
    std::size_t N = get_size();//Get the size of the matrix
    if (rhs.get_size() != N) {//If the target size is not the same
        throw std::invalid_argument("Matrix sizes do not match");//Print out the error to user
    }
    Matrix result(N);//Create a new matrix in the same size as the current one 
    for (std::size_t i = 0; i < N; i++) {//Loop through each row
        for (std::size_t j = 0; j < N; j++) {//Loop through each column
            result.data[i][j] = data[i][j] + rhs.data[i][j];//Calculate the value at that position
        }
    }
    return result;//Return the matrix back to user
}

// Overloaded multiplication operator
Matrix Matrix::operator*(const Matrix &rhs) const {
    std::size_t N = get_size();//Get the size of the matrix
    if (rhs.get_size() != N) {//If the target size is not the same
        throw std::invalid_argument("Matrix sizes do not match");//Print out the error to user
    }
    Matrix result(N);//Create a new matrix in the same size as the current one
    for (std::size_t i = 0; i < N; i++) {//Loop through each row
        for (std::size_t j = 0; j < N; j++) {//Loop through each column
            int sum = 0;//Create a place holder to save the value of one position
            for (std::size_t k = 0; k < N; k++) {//Loop through that column again to calculate the 1 part of the actual value
                sum += data[i][k] * rhs.data[k][j];//Calculate the actual value of that position
            }
            result.data[i][j] = sum;//Update the data at the target position
        }
    }
    return result;//Return the matrix back to user
}

// Set a specific value in the matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= get_size() || j >= get_size()) {//Because it's 0-indexed, so chekc if i and j is larger or equal to the size
        throw std::out_of_range("Index out of range in set_value.");//Throw an error 
    }
    data[i][j] = n;//Else update that position in the matrix
}

// Get a specific value from the matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= get_size() || j >= get_size()) {//Because it's 0-indexed, so chekc if i and j is larger or equal to the size
        throw std::out_of_range("Index out of range in get_value.");//Throw an error 
    }
    return data[i][j];//Return the specific data in the matrix
}

// Return the size (number of rows/columns) of the square matrix
int Matrix::get_size() const {
    return data.size();//return the matrix size
}

// Sum of the primary (major) diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;//Create a variable to save the return value
    std::size_t N = get_size();//Get the size of the matrix
    for (std::size_t i = 0; i < N; i++) {//Loop by the size
        sum += data[i][i];//Calculate the major diagonal
    }
    return sum;//Return the number to user
}

// Sum of the secondary (minor) diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0;//Create a variable to save the return value
    std::size_t N = get_size();//Get the size of the matrix
    for (std::size_t i = 0; i < N; i++) {//Loop by the size
        sum += data[i][N - 1 - i];//Calculate the minor diagonal by subtracting the value i to find the corresponding position
    }
    return sum;//Return the number to user
}

// Swap two rows in the matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    std::size_t N = get_size();//Get the size of the current matrix
    if (r1 >= N || r2 >= N) {//Verify the input number, if out of range
        throw std::out_of_range("Row index out of range in swap_rows.");//Throw and error to user
    }
    std::swap(data[r1], data[r2]);//Else, swap the row together
}

// Swap two columns in the matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    std::size_t N = get_size();//Get the size of the current matrix
    if (c1 >= N || c2 >= N) {//Verify the input number, if out of range
        throw std::out_of_range("Column index out of range in swap_cols.");//Throw and error to user
    }
    for (std::size_t i = 0; i < N; i++) {//Loop through all the row
        std::swap(data[i][c1], data[i][c2]);//Swap each value in each row
    }
}

// Print the matrix to standard output
void Matrix::print_matrix() const {
    std::size_t N = get_size();//Get the size of the current matrix
    for (std::size_t i = 0; i < N; i++) {//Loop through all the row
        for (std::size_t j = 0; j < N; j++) {//Loop through all the column
            std::cout << data[i][j] << " ";//Print out the current data on one row
        }
        std::cout << std::endl;//Jump down and be ready for the next row of the matrix
    }
}
