/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function prototype
void uppercase(char* str);

// main program
int main()
{
    // declare variables
    char str[] = "this string should be all uppercase.";

    // convert to uppercase
    uppercase(str);

    // print the modified string
    printf("Uppercase sentence: %s\n", str);

    return 0;
}

// function implementation
void uppercase(char* str)
{
    // for each character in the string
    for (int i = 0; i < strlen(str); i++)
    {
        // convert the character to uppercase
        str[i] = toupper(str[i]);
    }
}
