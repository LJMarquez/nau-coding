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
    // TODO: allocate the memory for a double variable
    double *num = (double *)malloc(sizeof(double));

    // TODO: assign a value to the dynamically allocated variable
    *num = 3.14;

    // TODO: print the value in the variable
    printf("Value: %.2lf", *num);

    // TODO: deallocate the memory
    free(num);

    // return success
    return 0;
}
