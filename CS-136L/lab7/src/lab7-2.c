/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// function prototype
void printCharacters(char* str);

// main program
int main()
{
    // print each character of a string in a new line
    printCharacters("grapes");
    // end program
    return 0;
}

// function implementation
void printCharacters(char* str)
{
    // TODO: write a for loop to traverse the string and print each individual character
    for(int i = 0; i < strlen(str); i++)
    {
        printf("%c\n", str[i]);
    }
    
}
