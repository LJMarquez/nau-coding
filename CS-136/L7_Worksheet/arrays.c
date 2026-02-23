#include "arrays.h"

// function definitions

int findMin(int array[], int size)
{
    int min = array[0];
    
    for(int i = 1; i < size; i++)
    {
        if(array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

double findAvg(double array[], int size)
{
    double sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum / size;
}

int searchLetter(char array[], char letter)
{
    int index = NOT_FOUND;
    int size = sizeof(array);

    for(int i = 0; i < size; i++)
    {
        if(array[i] == letter && index == NOT_FOUND)
        {
            index = i;
        }
    }

    return index;
}

void merge(int array1[], int array2[], int size, int output[])
{
    int i = 0, j = 0;

    for(int k = 0; k < 2 * size; k++)
    {
        if(j >= size || (i < size && array1[i] <= array2[j]))
        {
            output[k] = array1[i];
            i++;
        }
        else
        {
            output[k] = array2[j];
            j++;
        }
    }
}

int dotProduct(int array1[], int array2[], int size)
{
    int dotProduct = 0;
    for(int i = 0; i < size; i++)
    {
        dotProduct += (array1[i] * array2[i]);
    }

    return dotProduct;
}