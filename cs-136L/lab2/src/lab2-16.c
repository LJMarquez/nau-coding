/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>

// global constants
#define DIVISOR 4

// main program
int main()
{
    // initialization
        // declare the variable
    int remainder, num;

    // user input
        // prompt for a number
    printf("Type the number: ");
        // read the number
    scanf("%d", &num);

    // processing
        // TODO: find the remainder
    remainder = num % 4;

        // print number after change
    printf("Remainder of %d/4: %d.\n", num, remainder);

    // end program
        // return success
    return 0;
}
