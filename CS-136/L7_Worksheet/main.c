// header files
#include "arrays.h"

// main program
int main()
{

    // initialization
        // print a title
            // function: printf
    printf("\nThis program tests the functions for L7 Worksheet\n");
    printf("=================================================\n\n");

    // test the function from arrays
        // create an array of integers
    int array[] = {3, 12, 14, 5, 7, 16, 1, 10, 2, 11};
        // find the minimum in array
            // function: findMin
    int min = findMin(array, SIZE);
        // print the result
            // function: printf
    printf("Function findMin:\n");
    printf("Minimum value: %d\n", min);
    printf("------------------------------------------------\n\n");

        // create an array of doubles
    double arrayDouble[] = {1.5, 6.2, 7.1, 2.5, 9.3, 3.5, 9.9, 0.1, 4.5, 5.5};
        // find the average of elements in the array
            // function: findAvg
    double avg = findAvg(arrayDouble, SIZE);
        // print the result
            // function: printf
    printf("Function findAvg:\n");
    printf("Average value: %.2f\n", avg);
    printf("------------------------------------------------\n\n");

        // create a null-terminated array of characters
    char letters[] = {'m', 'a', 'm', 'm', 'a', 'm', 'i', 'a', '\0'};
        // create an array of characters to search
    char search[] = "main";
        // print the searchLetter header
            // function: printf
    printf("Function searchLetter:\n");
        // create an index for the search array
    int i = 0;
        // traverse the array of search characters
    while(search[i] != '\0')
    {
        // search for the first occurrence of 'a' in the array
            // function: searchLetter
        int index = searchLetter(letters, search[i]);
        // if the character is found
        if(index != NOT_FOUND)
        {
            // print the result
                // function: printf
            printf("Character %c found at index: %d\n", search[i], index);
        }
        // otherwise
        else
        {
            // print a message
                // function: printf
            printf("Character %c not found\n", search[i]);
        }
        // move to the next character
        i++;
    }
        // print the end of the function test
            // function: printf
    printf("------------------------------------------------\n\n");

        // declare the sorted input arrays
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};
        // declare a variable to hold their size
    int size = SIZE / 2;
        // declare an output array
    int output[SIZE];
        // merge the two input arrays into the output array
            // function: merge
    merge(array1, array2, size, output);
        // print the merge header
            // function: printf
    printf("Function merge:\n");
        // print the first input array
            // function: printf
    printf("Input array1: ");
        // traverse the array
    for(int i = 0; i < size; i++)
    {
        // print the current element
            // function: printf
        printf("%d ", array1[i]);
    }
    // cosmetic
    printf("\n");
        // print the second input array
            // function: printf
    printf("Input array2: ");
        // traverse the array
    for(int i = 0; i < size; i++)
    {
        // print the current element
            // function: printf
        printf("%d ", array2[i]);
    }
        // cosmetic
    printf("\n");
        // print the merged array
            // function: printf
    printf("Merged array: ");
        // traverse the array
    for(int i = 0; i < SIZE; i++)
    {
        // print the current element
        printf("%d ", output[i]);
    }
        // cosmetic
    printf("\n");
        // print the end of the function test
            // function: printf
    printf("------------------------------------------------\n\n");

        // get the dot product
            // function: dotProduct
    int dot = dotProduct(array1, array2, size);
        // print the result
            // function: printf
    printf("Function dotProduct:\n");
    printf("Dot product: %d\n", dot);
    printf("------------------------------------------------\n\n");

    // end program
        // print a message
            // function: printf
    printf("Test ended successfully\n\n");
        // return success
    return 0;
}
