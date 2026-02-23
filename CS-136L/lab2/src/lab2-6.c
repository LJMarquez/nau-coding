/**
 * Driver: Leo Marquez
 * Navigator: Austin Squier
 **/

// header file
#include <stdio.h>

// global constants
#define MAX_NAME_LENGTH 20

// main program
int main()
{
    // initialization
        // TODO: declare the variable
    char product[20];
    double price;

    // user input
        // TODO: prompt for the price
    printf("Please type the price: ");
    
        // TODO: read the price
    scanf("%lf", &price);
    
        // TODO: prompt for the product name
    printf("Please type the product name: ");
    
        // TODO: read the product name
    scanf("%s", product);
    
    // output
        // TODO: print the message
    printf("%s costs USD %.2lf.", product, price);
    
    // end program
        // return success
    return 0;
}
