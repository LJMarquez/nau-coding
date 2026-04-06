/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// main program
int main()
{
    // declare variables
    int num1, num2;
    
    // prompt for number
    puts("Type two integer numbers: ");

    // TODO: write your solution here
    int read = fscanf(stdin, "%d %d", &num1, &num2);

    if(read != 2)
    {
        fprintf(stderr, "Error: invalid input format");
    }
    else if(num2 == 0)
    {
        fprintf(stderr, "Error: division by zero is not allowed");
    }
    else
    {
        int result = num1 / num2;
        fprintf(stdout, "Result: %d", result);
    }

    // return success
    return 0;
}
