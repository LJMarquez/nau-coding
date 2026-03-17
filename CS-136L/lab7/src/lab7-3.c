/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// TODO: write your function here
bool isEmpty(const char* str)
{
    if(str == NULL || strlen(str) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}