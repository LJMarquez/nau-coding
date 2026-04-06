#include "W12_lib.h"

bool multiplyMatrix(int aRows, int aCols, int bRows, int bCols, int A[][aCols], int B[][bCols], int prod[aRows][bCols])
{
    if(aCols != bRows)
    {
        return false;
    }

    for(int i = 0; i < aRows; i++)
    {
        for(int j = 0; j < bCols; j++)
        {
            for(int k = 0; k < aCols; k++)
            {
                prod[i][j] = A[i][k] * B[k][j];
            }
        }
    }
    return true;
}

void transposeMatrix(int rows, int cols, int A[][cols], int At[][rows])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            At[j][i] = A[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int A[][cols], int digits)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%*d ", digits, A[i][j]);
        }
        printf("\n");
    }
}