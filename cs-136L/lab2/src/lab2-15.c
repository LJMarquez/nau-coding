/**
 * Driver: Leo Marquez
 * Navigator: Austin Squier
 **/

// header file
#include <stdio.h>

// global constants
#define DIVISOR 2

// main program
int main()
{
    // initialization
        // declare the variable
    int intDiv, num;

    // user input
        // prompt for a number
    printf("Type the number: ");
        // read the number
    scanf("%d", &num);

    // processing
        // TODO: divide num by 2
    intDiv = num / 2;

        // print number after change
    printf("%d/2: %d.\n", num, intDiv);

    // end program
        // return success
    return 0;
}
