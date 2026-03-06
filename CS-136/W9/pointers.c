#include "pointers.h"

#include <stdio.h>

bool findRange(int arr[], int size, int *min, int *max)
{
    if(size <= 0)
    {
        return false;
    }
    else
    {
        *min = arr[0];
        *max = arr[0];
        for(int i = 1; i < size; i++)
        {
            if(arr[i] < *min)
            {
                *min = arr[i];
            }
            if(arr[i] > *max)
            {
                *max = arr[i];
            }
        }
        return true;
    }
}

float safeDivision(int numerator, int denominator, ErrorCode *errorCode)
{
    if(denominator == 0)
    {
        *errorCode = ZERODIVISION;
        return 0.0;
    }
    else
    {
        *errorCode = SUCCESS;
        return (float)numerator / (float)denominator;
    }
}

void fillInArray(int arr[], int *size)
{
    int input;
    int continueChoice = 1;

    while(*size < MAX_ARR_SIZE && continueChoice == 1)
    {
        printf("Type a number: ");
        scanf("%d", &input);
        arr[*size] = input;
        (*size)++;

        if(*size < MAX_ARR_SIZE)
        {
            printf("Continue (1 for Yes, 0 for No)? ");
            scanf("%d", &continueChoice);
        }
    }
}

int searchNeighbors(int arr[], int size, int target, int *left, int *right)
{
    int index = NOTFOUND;

    *left = NOTFOUND;
    *right = NOTFOUND;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            index = i;
            if(i == 0)
            {
                *left = OUTOFBOUNDS;
            }
            else
            {
                *left = arr[i - 1];
            }
            if(i == size - 1)
            {
                *right = OUTOFBOUNDS;
            }
            else
            {
                *right = arr[i + 1];
            }

            return index;
        }
    }

    return NOTFOUND;
}

bool isUnique(int arr[], int size, int target, int *count)
{
    *count = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            (*count)++;
        }
    }

    return *count == 1;
}