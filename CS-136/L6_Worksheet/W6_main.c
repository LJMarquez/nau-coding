// header files
#include "utils.h"
#define SIZE 3

// main program
int main()
{

    // initialization
        // print a title
            // function: printf
    printf("\nThis program tests the function for L6 Worksheet\n");
    printf("================================================\n\n");

    // test the function from utils
        // create the input variable
    int number = 24;
        // count the factors of number
            // function: countFactors
    int result = countFactors(number);
        // print the result
            // function: printf
    printf("Function countFactors:\n");
    printf("The number %d has %d factors.\n", number, result);
    printf("------------------------------------------------\n\n");

        // print the isMultiple header
            // function: printf
    printf("Function isMultiple:\n");
        // create the input variables
    int dividend[SIZE] = {15, 8, 12}, divisor[SIZE] = {5, 3, 4};
        // for each dividend and divisor pairs
    for (int i = 0; i < SIZE; i++)
    {
            // check if the divisor is a multiple of the dividend
                // function: is multiple
        bool multiple = isMultiple(dividend[i], divisor[i]);
        // if it is multiple
        if (multiple)
        {
            // print a message
                // function: printf
            printf("%d is a multiple of %d\n", divisor[i], dividend[i]);
        }
        // otherwise
        else
        {
            // print a message
                // function: printf
            printf("%d is not a multiple of %d\n", divisor[i], dividend[i]);
        }
    }
        // print the end of the function test
            // function: printf
    printf("------------------------------------------------\n\n");

        // print the printTriangle header
            // function: printf
    printf("Function printTriangle:\n");
        // create the input variables
    int sizes[SIZE] = {3, 5, 7};

    // for each size
    for (int i = 0; i < SIZE; ++i)
    {
        // print the triangle
            // function: printTriangle
        printTriangle(sizes[i]);
    }
        // print the end of the function test
            // function: printf
    printf("------------------------------------------------\n\n");

        // print the getPositiveNumber header
            // function: printf
    printf("Function getPositiveNumber:\n");
        // get the valid number
            // function: getPositiveNumber
    int positiveN = getPositiveNumber();
        // print the result
            // function: printf
    printf("The number is %d\n", positiveN);
        // print the end of the function test
            // function: printf
    printf("------------------------------------------------\n\n");

        // print the getYNOption header
            // function: printf
    printf("Function getYNOption:\n");
        // get the valid character
            // function: getYNOption
    char option = getYNOption();
        // print the result
            // function: printf
    printf("The option is %c\n", option);
        // print the end of the function test
            // function: printf
    printf("------------------------------------------------\n\n");

    // end program
        // print a message
            // function: printf
    printf("Test ended successfully\n\n");
        // return success
    return 0;
}