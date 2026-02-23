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
        // declare variable
    double price;

    // user input
        // prompt for price
    printf("Type the price: ");
        // read price
    scanf("%lf", &price);

    // output
        // print a message
    printf("Price: %.2lf\n", price);

    // end program
        // return success
    return 0;
}
