/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <stdlib.h>

// main program
int main()
{
    int m, n;
    // read the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &m);

    // read the number of columns
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    // TODO: dynamically allocate a 2D array
    int **matrix = (int**)malloc(m * sizeof(int*));

    // TODO: fill in the array with the values as requested
    for(int i = 0; i < m; i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    // print the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }

    // TODO: deallocate the matrix
    for(int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    // return success
    return 0;
}
