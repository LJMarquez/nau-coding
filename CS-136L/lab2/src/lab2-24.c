/**
 * Driver: Leo Marquez
 * Navigator: Austin Squier
 **/

#include <stdio.h>
#include <math.h>

// main program
int main()
{
    // initialization
        // declare variables
    int number;
    double result;

    // user input
        // prompt for number
    printf("Type a number: ");
        // read number
    scanf("%d", &number);

    // processing
        // calculate the square root of number
    result = sqrt(number);

    // output
        // print a message
    printf("The square root of %d is %.1lf\n", number, result);

    // end program
        // return success
    return 0;
}
