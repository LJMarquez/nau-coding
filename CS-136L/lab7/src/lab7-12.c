/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// TODO: write your function here
void appFileExtension(char* filenames[], int fileCount, const char* extension)
{
    for(int i = 0; i < fileCount; i++)
    {
        strcat(filenames[i], extension);
    }
}