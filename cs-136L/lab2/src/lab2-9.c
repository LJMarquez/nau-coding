/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>

// global constants
#define INCREMENT 3

// main program
int main()
{
    // initialization
        // declare the variable
    int number;

    // user input
        // prompt for number
    printf("Type the number: ");
        // read number
    scanf("%d", &number);

    // processing
        // print number before change
    printf("Number before: %d.\n", number);
        // TODO: increase number in 3 integers
    number += 3;
    

        // print number after change
    printf("Number after: %d.\n", number);

    // end program
        // return success
    return 0;
}
