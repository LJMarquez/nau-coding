/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// main program
int main()
{
    // create variables
    int array[] = {3, 6, 9, 12, 15};
    int size = sizeof(array) / sizeof(array[0]);

    // print the output
    printf("Index notation: ");
    // traverse array using index
    for (int i = 0; i < size; i++)
    {
        // TODO: print current value using subscript notation (i.e., [])
        

    }
    printf("\n");

    // print the output
    printf("Pointer notation: ");
    // traverse array using pointer arithmetic
    for (int i = 0; i < size; i++)
    {
        // TODO: print current value using pointer notation (i.e., *( + ))
        
        
    }
    printf("\n");

    // return success
    return 0;
}
