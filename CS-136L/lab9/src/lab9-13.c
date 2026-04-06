/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// main program
int main()
{
    // declare a 2D array
    int data[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    // TODO: calculate the size of the entire array
    int totalSize = sizeof(data);

    // TODO: calculate the size of one row
    int rowSize = sizeof(data[0]);

    // TODO: calculate the size of one element
    int elementSize = sizeof(data[0][0]);

    // TODO: calculate number of rows and columns
    int rows = totalSize / rowSize;
    int cols = rowSize / elementSize;

    // print the results
    printf("Total size of array: %d bytes\n", totalSize);
    printf("Size of one row: %d bytes\n", rowSize);
    printf("Size of one element: %d bytes\n", elementSize);
    printf("Number of rows: %d\n", rows);
    printf("Number of columns: %d\n", cols);

    // return success
    return 0;
}
