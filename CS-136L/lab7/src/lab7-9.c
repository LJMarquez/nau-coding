/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lab7-9_lib.h"

// TODO: write the `authenticate` function here
bool authenticate(const char* username, const char* password)
{
    char *storedPassword = getCredentials(username);
    if(strcmp(storedPassword, password) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}