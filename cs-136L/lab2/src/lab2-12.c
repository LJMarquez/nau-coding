/**
 * Driver: Leo Marquez
 * Navigator: Austin Squier
 **/

// header file
#include <stdio.h>

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
        // TODO: increment number
    number++;
    

        // print number after change
    printf("Number after: %d.\n", number);

    // end program
        // return success
    return 0;
}
