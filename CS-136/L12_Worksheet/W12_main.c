// header files
#include "W12_lib.h"

// main function
int main()
{
    // initialize program
        // declare input variables
    int A[ROWS][COLS] = {{3, 6, 2}, {1, 3, 2}, {5, 3, 1}, {2, 5, 6}, {4, 3, 6}};
    int B[ROWS][COLS] = {{7, 3, 1}, {3, 1, 4}, {2, 6, 3}, {5, 2, 7}, {3, 3, 6}};
    int C[COLS][COLS] = {{4, 2, 5}, {6, 3, 4}, {2, 7, 2}};

    // declare output variables
    int productAB[ROWS][COLS];
    int productBC[ROWS][COLS];
    int Bt[COLS][ROWS];
    bool success;
    // initilize the matrices with zeros
        // function: memset
    memset(productAB, 0, sizeof(productAB));
    memset(productBC, 0, sizeof(productBC));
    memset(Bt, 0, sizeof(Bt));

    // processing
    // multiply matrices A and B and store the result in product
    // function: multiplyMatrix
    success = multiplyMatrix(ROWS, COLS, ROWS, COLS, A, B, productAB);
    // check if the multiplication was performed
    if(success)
    {
        // print the message for the result
        //function: puts
        puts("\nA . B =");
        // print the matrix
        // function: printMatrix
        printMatrix(ROWS, COLS, productAB, DIGITS);
    }
    // if the multiplication was not possible
    else
    {
        // print a message
        // function: printf
        printf("Multiplication is not possible.\n");
    }

    // multiply matrices B and C and store the result in product
    // function: multiplyMatrix
    success = multiplyMatrix(ROWS, COLS, COLS, COLS, B, C, productBC);
    // check if the multiplication was performed
    if(success)
    {
        // print the message for the result
        //function: puts
        puts("\nB . C =");
        // print the matrix
        // function: printMatrix
        printMatrix(ROWS, COLS, productBC, DIGITS);
    }
    // if the multiplication was not possible
    else
    {
        // inform the user
        // function: printf
        printf("Multiplication is not possible.\n");
    }

    // transpose matrix B and store the result in Bt
    // function: multiplyMatrix
    transposeMatrix(ROWS, COLS, B, Bt);
    // print the message
    //function: puts
    puts("\nBt =");
    // print the transpose
    // function: printMatrix
    printMatrix(COLS, ROWS, Bt, DIGITS);
}

