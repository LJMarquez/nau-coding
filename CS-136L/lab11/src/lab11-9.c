/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// TODO: define your enum here
typedef enum DocType
{
    SSN,
    US_PASSPORT,
    AZ_DRIVER_LICENSE,
    CA_DRIVER_LICENSE,
    NUM_DOCUMENT_TYPES
} DocType;

// TODO: write your function here
bool validateDocFormat(DocType type, const char *docNumber)
{
    if(type == SSN)
    {
        if(strlen(docNumber) == 11)
        {
            for(int i = 0; i < 11; i++)
            {
                if(i == 3 || i == 6)
                {
                    if(docNumber[i] != '-')
                    {
                        return false;
                    }
                }
                else
                {
                    if(!isdigit(docNumber[i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type == US_PASSPORT)
    {
        if(strlen(docNumber) == 9 && isalpha(docNumber[0]))
        {
            for(int i = 1; i < 9; i++)
            {
                if(!isdigit(docNumber[i]))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type == AZ_DRIVER_LICENSE)
    {
        if(strlen(docNumber) == 9 && isalpha(docNumber[0]))
        {
            for(int i = 1; i < 9; i++)
            {
                if(!isdigit(docNumber[i]))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type == CA_DRIVER_LICENSE)
    {
        if(strlen(docNumber) == 8 && isalpha(docNumber[0]))
        {
            for(int i = 1; i < 8; i++)
            {
                if(!isdigit(docNumber[i]))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}