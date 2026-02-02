/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>

// global constants
#define MAX_NAME_LENGTH 20

// main program
int main()
{
    // initialization
        // TODO: declare variables
    char name[19];
    int age;
    
    // user input
        // prompt for age
    printf("Type your age: ");
        // TODO: read age
    scanf("%d", &age);
    
        // TODO: prompt for name
    printf("Type your name: ");
    
        // TODO: read up to 19 characters as the name
    scanf("%19s", name);
    
    // output
        // TODO: print the message
    printf("Hello %s, you are %d years old.", name, age);
    
    // end program
        // return success
    return 0;
}
