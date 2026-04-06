// include guards
#ifndef W13_LIB_H
#define W13_LIB_H

// header files
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// global constants
#define ROWS 5
#define COLS 3
#define DIGITS 3

// function prototypes
/**
 * Function: multiplyMatrix
 * Input parameters: aRows, aCols - dimensions of matrix A
 *                   bRows, bCols - dimensions of matrix B
 *                   A, B - 2D arrays of integers
 * Output parameters: prod - 2D array with the result of the multiplaction
 *                           A x B, if possible
 * Return: true if the multiplication is possible
 *         false otherwise
 * Dependencies: none
 **/
bool multiplyMatrix(int aRows, int aCols, int bRows, int bCols, int A[][aCols],
    int B[][bCols], int prod[aRows][bCols]);
/**
 * Function: transposeMatrix
 * Input parameters: rows, cols - dimensions of A
 *                   A - 2D array of integers to transpose
 * Output parameters: At - 2D array of integers with the transposed A matrix
 * Return: none
 * Dependencies: none
 **/
void transposeMatrix(int rows, int cols, int A[][cols], int At[][rows]);

/**
 * Function: printMatrix
 * Input parameters: rows, cols - dimensions of A
 *                   A - 2D array of integers to transpose
 *                   digits - maximum number of digits for the integer numbers
 * Output parameters: none
 * Return: none
 * Dependencies: stdio.h - printf
 **/
void printMatrix(int rows, int cols, int A[][cols], int digits);

#endif