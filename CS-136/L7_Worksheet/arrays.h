#ifndef ARRAYS_H
#define ARRAYS_H

// header files
#include <stdio.h>

// global definitions
#define SIZE 10
#define NOT_FOUND -1

/**
 * Name: findMin
 * Process: function to find the minimum value in an array of integers
 * Function input/parameters: array of integers, size of the array
 * Function output/parameters: none
 * Function output/returned: minimum value in the array
 * Dependencies: none
 **/
int findMin(int array[], int size);

/**
 * Name: findAvg
 * Process: function to find the average of elements in an array of doubles
 * Function input/parameters: array of double, size of the array
 * Function output/parameters: none
 * Function output/returned: average value in the array
 * Dependencies: none
 **/
double findAvg(double array[], int size);

/**
 * Name: searchLetter
 * Process: function to search for a character in an array
 * Function input/parameters: array of characters
 * Function output/parameters: none
 * Function output/returned: the index of the first occurrence of letter
 * Dependencies: none
 **/
int searchLetter(char array[], char letter);

/**
 * Name: searchLetter
 * Process: function to merge two sorted arrays into one sorted array
 * Function input/parameters: two arrays of integer, and their size
 * Function output/parameters: output array with the merged array
 * Function output/returned: none
 * Dependencies: none
 **/
void merge(int array1[], int array2[], int size, int output[]);

/**
 * Name: dotProduct
 * Process: function to calculate the dot product of two integer arrays
 * Function input/parameters: two arrays of integer, and their size
 * Function output/parameters: none
 * Function output/returned: the calculated dot product
 * Dependencies: none
 **/
int dotProduct(int array1[], int array2[], int size);

#endif
