/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>

// global constants
#define MULTIPLIER 3

// main program
int main()
{
    // initialization
        // declare the variable
    int mult, num;

    // user input
        // prompt for a number
    printf("Type the number: ");
        // read the number
    scanf("%d", &num);

    // processing
        // TODO: multiply num and 3
    mult = num * 3;

        // print number after change
    printf("%d x 3: %d.\n", num, mult);

    // end program
        // return success
    return 0;
}
