/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// TODO: write your function here
char* duplicateString(const char* str)
{
    int length = strlen(str);
    char *newStr = (char *)malloc(length * sizeof(char));
    strcpy(newStr, str);
    return newStr;
}