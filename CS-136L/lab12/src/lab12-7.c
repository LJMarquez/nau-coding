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
    // TODO: allocate the memory for the array of size 3
    int *fives = (int *)malloc(3 * sizeof(int));
    // TODO: initialize the array with the requested values
    fives[0] = 0;
    fives[1] = 5;
    fives[2] = 10;

    // print the original array
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", fives[i]);
    }
    printf("\n");

    // TODO: resize fives to hold 5 integers
    fives = (int *)realloc(fives, 5 * sizeof(int));

    // TODO: initialize the new elements (indexes 3-4 only)
    fives[3] = 15;
    fives[4] = 20;

    // print the resized array
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", fives[i]);
    }
    printf("\n");

    // TODO: free the dynamically allocated memory
    free(fives);
    
    // return success
    return 0;
}
