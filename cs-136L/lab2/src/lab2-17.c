/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>

// global constants
#define DIVISOR 2.0

// main program
int main()
{
    // initialization
        // declare the variable
    int num;
    double div;

    // user input
        // prompt for a number
    printf("Type the number: ");
        // read the number
    scanf("%d", &num);

    // processing
        // TODO: calculate the division
    div = num / 2.0;

        // print number after change
    printf("%d/2.0: %lf.\n", num, div);

    // end program
        // return success
    return 0;
}
