// header files
#include <stdio.h>
#include "pointers.h"

// main program
int main()
{
    // initialization
    // create a sample array
    int numbers[MAX_ARR_SIZE] = {1, 5, 7, 9, 2, 5, 7, 1, 3};
    // initial size of the array
    int size = 9;

    // Test findRange
    // print a title
    // function: puts
    puts("\nFunction: findRange");
    puts("===================");
    // print the initial array
    // function: puts
    printf("The initial array: ");
    // traverse the array
    for(int i = 0; i < size; i++)
    {
        // print the current number
        // function: printf
        printf("%d ", numbers[i]);
    }
    // cosmetic
    // function: printf
    printf("\n");
    // declare the min and max variables
    int min, max;
    bool hasRange;
    // TODO: find the range of the array
    // function: findRange
    hasRange = findRange(numbers, size, &min, &max);

    // print the result
    // function: printf
    if(hasRange)
    {
        printf("Range: Min = %d, Max = %d\n\n", min, max);
    }

    // Test safeDivision
    // print a title
    // function: puts
    puts("Function: safeDivision");
    puts("======================");
    // declare the error code variable
    ErrorCode errorCode;
    // declare the division-related variables
    float result;
    float numerators[] = {10.0, 5.5, 0};
    float denominators[] = {2.5, 0, 4.2};
    int divSize = sizeof(numerators) / sizeof(numerators[0]);
    // traverse the arrays of numerators and denominators
    for(int i = 0; i < divSize; i++)
    {
        // print the division
        // funciton: printf
        printf("Attempting to calculate %.1f/%.1f\n", numerators[i], denominators[i]);
        // TODO: divide the current numerator by the current denominator
        // function: safeDivision
        result = safeDivision(numerators[i], denominators[i], &errorCode);

        // if the division is successful
        if(errorCode == SUCCESS)
        {
            // print the result
            // function: printf
            printf("Division Result: %.2f\n\n", result);
        }
        // otherwise
        else
        {
            // print an error message
            // function: puts
            puts("Error: Division by Zero\n");
        }
    }

    // Test fillInArray
    // print a title
    // function: puts
    puts("Function: fillInArray");
    puts("=====================");
    // print the array before filling in
    // function: printf
    printf("Array before filling: ");
    //  traverse the array
    for(int i = 0; i < size; i++)
    {
        // print the current number
        // function: printf
        printf("%d ", numbers[i]);
    }
    // cosmetic
    // function printf
    printf("\n");
    // TODO: fill in the array of numbers
    // function: fillInArray
    fillInArray(numbers, &size);

    // print the array after filling in
    // function: printf
    printf("Array after filling: ");
    //  traverse the array
    for(int i = 0; i < size; i++)
    {
        // print the current number
        // function: printf
        printf("%d ", numbers[i]);
    }
    // cosmetic
    // function printf
    printf("\n\n");

    // Test searchNeighbors
    // print a title
    // function: puts
    puts("Function: searchNeighbors");
    puts("=========================");
    // declare variables
    int left, right, targetIndex;
    int targets[] = {1, 5, 7, 9, 4};
    int targetSize = sizeof(targets) / sizeof(targets[0]);
    // for each target
    for(int i = 0; i < targetSize; i++)
    {
        // TODO: find the neighbors
        // function: searchNeighbors
        targetIndex = searchNeighbors(numbers, size, targets[i], &left, &right);

        // if target is found
        if(targetIndex != NOTFOUND)
        {
            // print a message
            // function: printf
            printf("Found target %d at index %d, ", targets[i], targetIndex);
            // if the left neighbor exists
            if(left != OUTOFBOUNDS)
            {
                // print the left neighbor
                printf("left neighbor = %d, ", left);
            }
            // otherwise
            else
            {
                // print out of bounds
                puts("left neighbor = Out of bounds, ");
            }
            // if the right neighbor exists
            if(right != OUTOFBOUNDS)
            {
                // print the right neighbor
                printf("right neighbor = %d\n\n", right);
            }
            // otherwise
            else
            {
                // print out of bounds
                puts("right neighbor = Out of bounds\n\n");
            }
        }
        // otherwise, target is not found
        else
        {
            // print a message
            printf("Target %d not found\n\n", targets[i]);
        }
    }

    // Test isUnique
    // print a title
    // function: puts
    puts("Function: isUnique");
    puts("==================");
    // declare variables
    int count;
    bool unique;
    // for each target
    for(int i = 0; i < targetSize; i++)
    {
        // TODO: find if the target is unique
        // function: isUnique
        unique = isUnique(numbers, size, targets[i], &count);

        // if unique is true
        if(unique)
        {
            // print a message
            // function: printf
            printf("%d is unique in the array.\n\n", targets[i]);
        }
        // otherwise
        else
        {
            // print a message
            // function: printf
            printf("%d is not unique. It appears %d times.\n\n", targets[i],
                   count);
        }
    }
    // end of program
    // print a message
    // function: puts
    puts("End of program\n");
    // return success
    return 0;
}
