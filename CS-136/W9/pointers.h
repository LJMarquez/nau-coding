// pointers.h
#ifndef POINTERS_H
#define POINTERS_H

// header files
#include <stdbool.h>

// global definitions
#define MAX_ARR_SIZE 100

typedef enum
{
    SUCCESS = 0,
    ZERODIVISION = -1,
    OUTOFBOUNDS = -2,
    NOTFOUND = -3
}
ErrorCode;

/**
 * Function: findRange
 * Input argument: 
 *      - arr: an array of integers
 *      - size: the number of elements in the array
 * Output argument: 
 *      - min: pointer to the minimum value
 *      - max: pointer to the maximum value
 * Return: true if the range can be determined, false if the array is empty
 */
bool findRange(int arr[], int size, int *min, int *max);

/**
 * Function: safeDivision
 * Input argument:
 *      - numerator: the numerator for the division
 *      - denominator: the denominator for the division
 * Output argument: 
 *      - errorCode: pointer to store the error code
 * Return: the result of the division, or 0.0 if an error occurs
 */
float safeDivision(int numerator, int denominator, ErrorCode *errorCode);

/**
 * Function: fillInArray
 * Input argument:
 *      - arr: an array of integers
 * Output argument: 
 *      - size: pointer to the number of elements in the array
 * Return: none
 */
void fillInArray(int arr[], int *size);

/**
 * Function: searchNeighbors
 * Input argument:
 *      - arr: an array of integers
 *      - size: the number of elements in the array
 *      - target: the target value to search for
 * Output argument: 
 *      - left: pointer to the left neighbor of the target or NOTFOUND
 *      - right: pointer to the right neighbor of the target or NOTFOUND
 * Return: the index of the target if found, otherwise returns NOTFOUND
 */
int searchNeighbors(int arr[], int size, int target, int *left, int *right);

/**
 * Function: isUnique
 * Input argument:
 *      - arr: an array of integers
 *      - size: the number of elements in the array
 *      - target: the target value to search for
 * Output argument: 
 *      - count: pointer to store the number of occurrences of the target value
 * Return: true if the target is unique, false if it is repeated
 */
bool isUnique(int arr[], int size, int target, int *count);

#endif // POINTERS_H
