/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// write your program here

#include <stdio.h>

// main program
int main()
{
    // start program
        // print title
    printf("Swapping Program\n\n");

    // initializaition
        // declare variables
    int number1, number2;

    // user input
        // prompt for number 1
    printf("Please type the first number: ");

        // read number 1
    scanf("%d", &number1);

        // prompt for number 2
    printf("Please type the second number: ");

        // read number 2
    scanf("%d", &number2);

    // print a message
    printf("Before the swap first: %d second: %d\n\n", number1, number2);

    // calculation
    number1 = number1 + number2;

    number2 = number1 - number2;

    number1 = number1 - number2;

    // output
        // print a message
    printf("After the swap first: %d second: %d\n", number1, number2);

    // end program
        // return success
    return 0;
}