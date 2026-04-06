#ifndef LAB9_LIB_H
#define LAB9_LIB_H

// header files
#include <math.h>
#include <stdio.h>

// global definitions
#ifndef MAX_SIZE
    #define MAX_SIZE 10
#endif

#define ROWS       8
#define COLS       8
#define HORIZONTAL 0
#define VERTICAL   1
#define NOT_FOUND  -1

// lab9-9
void printTriangle(int matrix[][10], int rows);
// lab9-10
void generatePascalTriangle(int triangle[][MAX_SIZE], int rows);
// lab9-11
void findLargestPerRow(int data[][MAX_SIZE], int rows, int cols, int largestPerRow[]);
// lab9-12
int countPerfectSquares(int data[][10], int rows, int cols);
// lab9-14
int searchWord(char grid[ROWS][COLS], const char *word, int *row, int *col);

#endif
