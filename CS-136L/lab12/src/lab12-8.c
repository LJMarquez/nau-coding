/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <stdlib.h>

// TODO: write your function here
int *buildSquares(int n)
{
    int *squares = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        squares[i] = i * i;
    }

    return squares;
}