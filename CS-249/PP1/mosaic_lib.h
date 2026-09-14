#ifndef MOSAIC_LIB_H
#define MOSAIC_LIB_H

// header files
#include <iostream>
#include <cstdlib>
#include <ctime>

// global constants
const int SIZE = 6;
const int STEPS = 3;
const int ARRAY_SIZE = 36;

class Mosaic
{
public:

    // Constructor
    /**
     * Constructor: Mosaic
     * Input argument: the mural as a 2D array of integer
     * Output argument: none
     * Return: none
     * Dependencies: none
     * Description: Initializes the Mosaic object with the given matrix data
     */
    Mosaic(const int inputMatrix[SIZE][SIZE]);

    // Public method prototypes
    /**
     * Method: setMatrix
     * Input argument: the mural as a 2D array of integer
     * Output argument: none
     * Return: none
     * Dependencies: none
     * Description: Loads data into the internal matrix
     */
    void setMatrix(const int inputMatrix[SIZE][SIZE]);

    /**
     * Method: transpose (Task 1)
     * Input argument: none (operates on internal matrix)
     * Output argument: none (modifies internal matrix)
     * Return: none
     * Dependencies: none
     */
    void transpose();

    /**
     * Method: rotate (Task 2)
     * Input argument: none (operates on internal matrix)
     * Output argument: none (modifies internal matrix)
     * Return: none
     * Dependencies: none
     */
    void rotate();

    /**
     * Method: zeroMatrix (Task 3)
     * Input argument: none (operates on internal matrix)
     * Output argument: none (modifies internal matrix)
     * Return: none
     * Dependencies: none
     */
    void zeroMatrix();

    /**
     * Method: rotateRow (Task 4)
     * Input argument: k number of steps
     * Output argument: none (modifies internal matrix)
     * Return: none
     * Dependencies: cstdlib - rand
     */
    void rotateRow(int k);

    /**
     * Method: spiralOrder (Task 5)
     * Input argument: none (operates on internal matrix)
     * Output argument: none
     * Return: dynamically allocated array of integers
     * Dependencies: none
     */
    int* spiralOrder();

    /**
     * Method: printMatrix (provided)
     * Input argument: none (operates on internal matrix)
     * Output argument: none
     * Return: none
     * Dependencies: iostream - cout
     */
    void printMatrix();

    /**
     * Method: getElement (for testing purposes)
     * Input argument: row and column indices
     * Output argument: none
     * Return: the value at matrix[row][col]
     * Dependencies: none
     */
    int getElement(int row, int col) const;

private:
    // Private data member
    int matrix[SIZE][SIZE];

    // Private helper method
    void reverse(int arr[], int start, int end);
};

#endif // MOSAIC_LIB_H
