/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>

// main program
int main()
{
    // initialization
        // declare the variable
    int sum, num1, num2;

    // user input
        // prompt for a number
    printf("Type the first number: ");
        // read the number
    scanf("%d", &num1);
        // prompt for a number
    printf("Type the second number: ");
        // read the number
    scanf("%d", &num2);

    // processing
        // TODO: sum the numbers
    sum = num1 + num2;

        // print number after change
    printf("Sum: %d.\n", sum);

    // end program
        // return success
    return 0;
}
