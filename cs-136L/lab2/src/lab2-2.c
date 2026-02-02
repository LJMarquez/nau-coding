/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header files
#include <stdio.h>

// global constants
#define MAX_NAME_LENGTH 20

// main program
int main()
{
    // initialization
        // TODO: declare the variable
    char name[20];
    
    // user input
        // prompt for name
    printf("Type your name: ");
        // TODO: read name
    scanf("%19s", name);
    
    // output
        // print the result
    printf("You typed %s.\n", name);
    // end program
        // return success
    return 0;
}
