/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// TODO: write your function here
bool isPalindrome(const char* str)
{
    if(str == NULL || strlen(str) == 0)
    {
        return false;
    }

    bool strIsPalindrome = true;
    int startIndex = 0;
    int endIndex = strlen(str) - 1;

    while(startIndex != endIndex)
    {
        if(isalpha(str[startIndex]) == false)
        {
            startIndex++;
        }
        else if(isalpha(str[endIndex]) == false)
        {
            endIndex--;
        }
        else
        {
            if(tolower(str[startIndex]) != tolower(str[endIndex]))
            {
                strIsPalindrome = false;
            }
            startIndex++;
            endIndex--;
        }

    }

    return strIsPalindrome;
}
