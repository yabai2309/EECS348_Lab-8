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
#include "matrix.hpp"//Include necessary library
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "matrix.hpp"

using namespace std;

// Helper function to read a matrix from an input stream.
vector<vector<int>> readMatrix(istream &file, int size) {
    vector<vector<int>> matrix;//Initate a matrix to return back
    for (int i = 0; i < size; i++){//For loop iterate through lines
        vector<int> row;//Create a vector to save each row
        int num;//Create a placeholder for number
        string line;//Create a placeholder for string line
        getline(file, line);//Write each line to the line parameter
        istringstream iss(line);//Tokenize the line
        while (iss >> num){//While there is number written into num
            row.push_back(num);//Push the number to the row
        }
        matrix.push_back(row);//Push the row to the matrix when done reading the row
    }
    return matrix;//Return the matrix back to user
}

//Helper function to print out the menu for user
void printMenu(){
    cout << endl;
    cout << "Choose what you want to do:" << endl;
    cout << "1) Add two matrix together" <<endl;
    cout << "2) Multiply two matrix together" <<endl;
    cout << "3) Calculate sum of the diagonal" <<endl;
    cout << "4) Swap row" <<endl;
    cout << "5) Swap column" <<endl;
    cout << "6) Update value at a location" <<endl;
    cout << "7) Exit" << endl;
    cout << "Enter: " ;
}

//Main function
int main() {
    //Handle file I/O
    string filename;//Create a place holder for file name
    cout << "Specify the file you want to read: ";//Prompt user for file name
    cin >> filename;//Write to the place holder created
    ifstream file(filename);//Open file 
    if (!file) {//If we cannot open the file
        cerr << "File is not found" << endl;//Print out message to user
        return 1;//Return value 1 indicating error
    }
    
    //Read the first line as the size of the matrix
    int size;//Create a placeholder as integer for the size
    string line;//Create a placeholder for the string we're about to read
    getline(file, line);//Write the string to the place holder
    size = stoi(line);//Convert the string to number and save it in the size variable
   
    // Read two matrices from the file
    vector<vector<int>> matData1 = readMatrix(file, size);
    vector<vector<int>> matData2 = readMatrix(file, size);
    
    // Create Matrix objects from the read data
    Matrix matrix1(matData1);
    Matrix matrix2(matData2); 
   
    cout << "Your first matrix is: " << endl;
    matrix1.print_matrix();
    cout << endl;
    cout << "Your second matrix is: " << endl;
    matrix2.print_matrix();
    //Handle user choices from the command line menu
    int choice = 0;//Create a placeholder for user choice
    printMenu();//Print out the menu to the user
    cin >> choice;//Listen to user input
    while(choice != 7){//Create a loop to keep asking user until user want to quit
        try{
        switch(choice){//Switch-case to navigate the choices
            case 1: {//Handle the add function
                Matrix matrix3 = matrix1+matrix2;//Add 2 matrix together
                matrix3.print_matrix();//Print out that result matrix to user
                break;//Jump out of the switch-case block
            }
            case 2: {//Handle multiply function
                Matrix matrix3 = matrix1*matrix2;//Multiply 2 matrix together
                matrix3.print_matrix();//Print out that result matrix to user
                break;//Jump out of the switch-case block
            }
            case 3: {//Handle diagonal sum function
                int matrix_choice;//Create a placeholder for user to choose the matrix they want
                int sumBoth, majorSum, minorSum;//Create a placeholder for the return value
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: ";
                cin >> matrix_choice;//Prompt user and get the matrix choice
                if (matrix_choice == 1){//If they choose matrix 1 
                    majorSum = matrix1.sum_diagonal_major();
                    minorSum = matrix1.sum_diagonal_minor();
                    sumBoth = matrix1.sum_diagonal_major() + matrix1.sum_diagonal_minor();//Calculate the diagonal sum
                     if (size % 2 == 1) {//For the case it's odd number
                    int center = matrix1.get_value(size / 2, size / 2);//Get the middle value
                    sumBoth -= center;//Final value would minus that middle value because it's being calculated twice
                    }
                } else if (matrix_choice ==2 ){//If they choose matrix 2
                    majorSum = matrix2.sum_diagonal_major();
                    minorSum = matrix2.sum_diagonal_minor();
                    sumBoth = matrix2.sum_diagonal_major() + matrix2.sum_diagonal_minor();//Calculate the diagonal sum
                     if (size % 2 == 1) {//For the case it's odd number
                    int center = matrix2.get_value(size / 2, size / 2);//Get the middle value
                    sumBoth -= center;//Final value would minus that middle value because it's being calculated twice
                    }
                } else { 
                    throw out_of_range("Invalid choice. Please try again!");
                }
                cout << "Major diagonal sum is:" << majorSum << endl;
                cout << "Minor diagonal sum is: " << minorSum << endl;
                cout << "Diagonal sum is: " << sumBoth << endl;//Print out the sum to the user
                break;//Jump out of the switch-case block
            }
            case 4: {//Handle swap row funciton
                int matrix_choice;//Create a placeholder for user to choose the matrix they want
                int row_from, row_to;//Create a variable to save the 2 row from user
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                cin >> matrix_choice;//Prompt user and get the matrix choice
                if (matrix_choice > 2 || matrix_choice < 0){
                    throw out_of_range("Invalid choice of the matrix. Please try again!");
                }
                cout << "Enter the first row you want to swap (0-indexed): " ;
                cin >> row_from;//Prompt user for row 1 choice 
                cout << "Enter the second row you want to swap (0-indexed): " ;
                cin >> row_to;//Prompt user for row 2 choice 
                if (matrix_choice == 1){//If they choose matrix 1 
                    matrix1.swap_rows(row_from, row_to);//Swap the row
                    cout << "Swapped! Here is your output:" << endl;
                    matrix1.print_matrix();//Print out that result matrix to user
                } else {//If they choose matrix 2
                    matrix2.swap_rows(row_from, row_to);//Swap the row
                    cout << "Swapped! Here is your output:" << endl;
                    matrix2.print_matrix();//Print out that result matrix to user
                } 
                break;//Jump out of the switch-case block
            }
            case 5: {//Handle swap column function
                int matrix_choice;//Create a placeholder for user to choose the matrix they want
                int col_from, col_to;//Create a variable to save the 2 col from user
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                cin >> matrix_choice;//Prompt user and get the matrix choice
                if (matrix_choice > 2 || matrix_choice < 0){
                    throw out_of_range("Invalid choice of the matrix. Please try again!");
                }
                cout << "Enter the first column you want to swap (0-indexed): " ;
                cin >> col_from;//Prompt user for column 1 choice 
                cout << "Enter the second column you want to swap (0-indexed): ";
                cin >> col_to;//Prompt user for column 2 choice 
                if (matrix_choice == 1){//If they choose matrix 1
                    matrix1.swap_cols(col_from, col_to);//Swap the column
                    cout << "Swapped! Here is your output:" << endl;
                    matrix1.print_matrix();//Print out that result matrix to user
                } else if (matrix_choice == 2) {//If they choose matrix 2
                    matrix2.swap_cols(col_from, col_to);//Swap the column
                    cout << "Swapped! Here is your output:" << endl;
                    matrix2.print_matrix();//Print out that result matrix to user
                }
                break;//Jump out of the switch-case block
            }
            case 6: {//Handle update position function
                int matrix_choice;//Create a placeholder for user to choose the matrix they want
                int num, col, row;//Create a variable to save value of column, row and the target value after change
                cout << "Choose between matrix_1 (1) or matrix(2). Type in the number 1 or 2: " ;
                cin >> matrix_choice;//Prompt user and get the matrix choice
                if (matrix_choice > 2 || matrix_choice < 0){
                    throw out_of_range("Invalid choice of the matrix. Please try again!");
                }
                cout << "Enter the row you want to update: " ;
                cin >> row;//Prompt user for the row
                cout << "Enter the column you want to update: ";
                cin >> col;//Prompt user for the column
                cout << "Enter the value you want to update at that position: " ;
                cin >> num;//Prompt user for target value to change to
                if (matrix_choice == 1){//If they choose matrix 1
                    matrix1.set_value(row, col, num);//Change the value at that location
                    cout << "Updated! Here is your output:" << endl;
                    matrix1.print_matrix();//Print out that result matrix to user
                } else if (matrix_choice == 2){//If they choose matrix 2
                    matrix2.set_value(row, col,num);//Change the value at that location
                    cout << "Updated! Here is your output:" << endl;
                    matrix2.print_matrix();//Print out that result matrix to user
                }
                break;//Jump out of the switch-case block
            }
        }}
        catch (const std::exception& ex) {//If there is exception
            //std::cerr << "Exception: " << ex.what() << std::endl;//Print it out to user
            cout << "Invalid input. Please try again!" <<endl;
            continue;
        }
        printMenu();//Print menu again for user to continue choosing
        cin >> choice;//Overwrite the choice variable
}

    return 0;
}