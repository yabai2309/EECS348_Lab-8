#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "matrix.hpp"

using namespace std;

// Helper function to read a matrix from an input stream.
vector<vector<int>> readMatrix(istream &file, int size) {
    vector<vector<int>> matrix;
    for (int i = 0; i < size; i++){
        vector<int> row;
        int num;
        string line;
        getline(file, line);
        istringstream iss(line);
        while (iss >> num){
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    return matrix;
}

int main() {
    string filename;
    cout << "Specify the file you want to read: ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file) {
        cerr << "File is not found" << endl;
        return 1;
    }
    
    // First line of the file is the size of the matrix.
    int size;
    string line;
    getline(file, line);
    size = stoi(line);
    
    // Read two matrices from the file.
    vector<vector<int>> matData1 = readMatrix(file, size);
    vector<vector<int>> matData2 = readMatrix(file, size);
    
    // Create Matrix objects from the read data.
    Matrix matrix1(matData1);
    Matrix matrix2(matData2);  // Currently not used but demonstrates using the second matrix.
    
    // Create a copy of matrix1 and swap columns 1 and 3 (if possible).
    Matrix matrix3 = matrix1;
    if (size > 3) {
        matrix3.swap_cols(1, 3);
    } else {
        cout << "Matrix size too small for swapping columns 1 and 3" << endl;
    }
    
    // Create another copy of matrix1 and update element (1,1) to 30.
    Matrix matrix4 = matrix1;
    if (size > 1) {
        matrix4.set_value(1, 1, 30);
    } else {
        cout << "Matrix size too small for updating element (1,1)" << endl;
    }
    
    // Print the matrices after modifications.
    cout << "Matrix after swapping columns 1 and 3:" << endl;
    matrix3.print_matrix();
    
    cout << "Matrix after updating element (1,1) to 30:" << endl;
    matrix4.print_matrix();
    
    // Calculate the sum of both diagonals from the original matrix.
    // (For an odd-sized matrix, the center element is subtracted once as it is counted twice.)
    int sumBoth = matrix1.sum_diagonal_major() + matrix1.sum_diagonal_minor();
    if (size % 2 == 1) {
        int center = matrix1.get_value(size / 2, size / 2);
        sumBoth -= center;
    }
    cout << "Sum of both diagonals (adjusted): " << sumBoth << endl;
    
    return 0;
}