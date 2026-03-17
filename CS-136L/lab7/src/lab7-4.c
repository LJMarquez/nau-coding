/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// TODO: write your function here
int countVowels(const char* str)
{
    if(str == NULL || strlen(str) == 0)
    {
        return 0;
    }

    int count = 0;

    for(int i = 0; i < strlen(str); i++)
    {
        char letter = tolower(str[i]);
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        {
            count++;
        }
    }
    return count;
}