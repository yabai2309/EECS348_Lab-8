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

void printMenu(){
    cout << "Choose what do you want to do:" << endl;
    cout << "1) Add two matrix together" <<endl;
    cout << "2) Multiply two matrix together" <<endl;
    cout << "3) Calculate sum of the diagonal" <<endl;
    cout << "4) Swap row" <<endl;
    cout << "5) Swap column" <<endl;
    cout << "6) Update value at a location" <<endl;
    cout << "7) Exit" << endl;
    cout << "Enter: " <<endl;
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
    int choice = 0;
    printMenu();
    cin >> choice;
    while(choice != 7){
        switch(choice){
            case 1: {
                Matrix matrix3 = matrix1+matrix2;
                matrix3.print_matrix();
                break;
            }
            case 2: {
                Matrix matrix3 = matrix1*matrix2;
                matrix3.print_matrix();
                break;
            }
            case 3: {
                int matrix_choice;
                int num;
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " << endl;
                cin >> matrix_choice;
                if (matrix_choice == 1){
                    num = matrix1.sum_diagonal();
                } else {
                    num = matrix2.sum_diagonal();
                }
                cout << "Diagonal sum is: " << num << endl;
                break;
            }
            case 4: {
                int matrix_choice;
                int row_from, row_to;
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " << endl;
                cin >> matrix_choice;
                cout << "Enter the first row you want to swap" << endl;
                cin >> row_from;
                cout << "Enter the second row you want to swap" << endl;
                cin >> row_to;
                if (matrix_choice == 1){
                    matrix1.swap_rows(row_from, row_to);
                    cout << "Swapped! Here is your output:" << endl;
                    matrix1.print_matrix();
                } else {
                    matrix2.swap_rows(row_from, row_to);
                    cout << "Swapped! Here is your output:" << endl;
                    matrix2.print_matrix();
                }
                break;
            }
            case 5: {
                int matrix_choice;
                int col_from, col_to;
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " << endl;
                cin >> matrix_choice;
                cout << "Enter the first row you want to swap" << endl;
                cin >> col_from;
                cout << "Enter the second row you want to swap" << endl;
                cin >> col_to;
                if (matrix_choice == 1){
                    matrix1.swap_rows(col_from, col_to);
                    cout << "Swapped! Here is your output:" << endl;
                    matrix1.print_matrix();
                } else {
                    matrix2.swap_rows(col_from, col_to);
                    cout << "Swapped! Here is your output:" << endl;
                    matrix2.print_matrix();
                }
                break;
            }
            case 6: {
                int matrix_choice;
                int num;
                int col, row;
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " << endl;
                cin >> matrix_choice;
                cout << "Enter the row you want to update" << endl;
                cin >> row;
                cout << "Enter the column you want to update" << endl;
                cin >> col;
                cout << "Enter the value you want to update at that position" << endl;
                cin >> num;
                if (matrix_choice == 1){
                    matrix1.set_value(row, col, num);
                    cout << "Updated! Here is your output:" << endl;
                    matrix1.print_matrix();
                } else {
                    matrix2.set_value(row, col,num);
                    cout << "Updated! Here is your output:" << endl;
                    matrix2.print_matrix();
                }
                break;
            }
    }}

    return 0;
}