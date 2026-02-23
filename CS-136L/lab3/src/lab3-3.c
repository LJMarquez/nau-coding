/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// main program
int main()
{
    // initialization
        // declare variable
    double number1, number2, average = 0.0;

    // user input
        // prompt for a number
    printf("Type the first number: ");
        // read the number
    scanf("%lf", &number1);
        // prompt for a number
    printf("Type the second number: ");
        // read the number
    scanf("%lf", &number2);

    // processing
        // TODO: calculate the average if within the range [0,100]


    // output
        // print a message
    printf("Average: %.2lf\n", average);
    // end program
        // return success
    return 0;
}
