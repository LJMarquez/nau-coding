/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// main program
int main()
{
    // declare variable that fits the longest english word from a dictionary
    char word[50];
    // supporting variables
    char oldChar, newChar;

    // get the word from the user input
    printf("Enter a word: ");
    scanf("%49s", word);

    // get the characters from user
    printf("Enter the character to replace: ");
    scanf(" %c", &oldChar);
    
    printf("Enter the new character: ");
    scanf(" %c", &newChar);

    // TODO: replace occurrences of oldChar with newChar
    for(int i = 0; i < strlen(word); i++)
    {
        if(word[i] == oldChar)
        {
            word[i] = newChar;
        }
    }
    

    // print the modified string
    printf("Modified string: %s\n", word);

    // return success
    return 0;
}
