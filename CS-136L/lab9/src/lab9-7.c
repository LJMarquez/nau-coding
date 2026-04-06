/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// global definitions
#define ROW 3
#define COL 3

// main program
int main()
{
    // declare variables
    int numbers[ROW][COL] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int row, col, newValue;

    // print the original array
    printf("Original table: ");

    // TODO: traverse the array (both dimensions)
    
    
            // TODO: print the current index
    

    // make a newline
    printf("\n");

    // prompt the user for the row
    printf("Enter a row (0-2): ");
    // read the row
    scanf("%d", &row);

    // TODO: if the row is out of range

    {
        // print a message
        printf("Invalid row! Please enter a value between 0 and 2.\n");
    }
    // the row is valid
    else
    {
        // prompt the user for the row
        printf("Enter a column (0-2): ");
        // read the column
        scanf("%d", &col);

        // TODO: if the column is out of range
        
        {
            // print a message
            printf("Invalid column! Please enter a value between 0 and 2.\n");
        }
        // column is valid
        else
        {
            // prompt for a new value
            printf("Enter a new value: ");
            // read a new value
            scanf("%d", &newValue);

            // TODO: update the array at the specified index
            
        }
    }

    // print the updated array
    printf("Updated table: ");

    // TODO: traverse the array (both dimensions)


            // TODO: print the current index


    // make a newline
    printf("\n");

    // end program 
        // return success
    return 0;
}
