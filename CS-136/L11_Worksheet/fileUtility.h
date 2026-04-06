// fileUtility.h
#ifndef FILEUTILITY_H
#define FILEUTILITY_H

// header files
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// global definitions
    // constanst for splitEvenOdd
#define PRODUCT_FILENAME "product.tsv"
#define EVEN_FILENAME "even.csv"
#define ODD_FILENAME "odd.csv"
    // constants for readProduct
        // maximum number of products
#define MAX_ARRAY_SIZE 100
        // maximum length of the product name
#define MAX_STRING_SIZE 50
        // maximum length of a line from the file
#define MAX_LINE_LENGTH 1024
    // constants for getAvgRatingPerYear
#define MAX_YEAR 2016
#define MIN_YEAR 2006
#define YEAR_INDEX 3
#define RATING_INDEX 5
#define MOVIES_INPUT_FILENAME "imdb.csv"
#define MOVIES_OUTPUT_FILENAME "average_rating_year.csv"

typedef enum ProductCategory
{
    PRODUCE,
    DAIRY,
    MEAT,
    BAKERY,
    FROZEN,
    BEVERAGES,
    SNACKS,
    CANNED_GOODS,
    PANTRY,
    CONDIMENTS,
    OTHER,
    LEN_CATEGORY
}
ProductCategory;

/**
 * Function: splitEvenOdd
 * Input argument:
 *      - numbers: an array of integers
 *      - size: the number of elements in the array
 * Output argument: none
 * Return: true if the files are successfully created, false otherwise
 * Dependencies:
 *      - stdio.h - fopen, perror, fprintf, fclose
 */
bool splitEvenOdd(int *numbers, int size);

/**
 * Function: readProduct
 * Input argument:
 *      - filename: the name of the file to read from
 *      - productNames: an array of strings to store the product names
 *      - productPrices: an array of floats to store the product prices
 *      - productCategories: an array of strings to store the product categories
 *      - maxSize: the maximum number of products that the arrays can hold
 * Output argument: none
 * Return: true if the split was successfull, false otherwise
 * Dependencies:
 *      - stdio.h - fopen, perror, fscanf, fclose
 *      - string.h - strcpy
 */
int readProduct(const char *filename, 
    char productNames[MAX_ARRAY_SIZE][MAX_STRING_SIZE], 
    float productPrices[MAX_ARRAY_SIZE], 
    ProductCategory productCategories[MAX_ARRAY_SIZE]);

/**
 * Function: getAvgRatingPerYear
 * Input argument:
 *      - inputFilename: the name of the CSV file to read from
 *      - outputFilename: the name of the file to save the average ratings per year
 * Output argument: none
 * Return: true if the output file is generated successfully, false otherwise
 * Dependencies:
 *      - stdio.h - fopen, perror, fclose, fgets, fprintf, printf
 *      - string.h  - strtok
 *      - stdlib.h - atoi, atof
 */
bool getAvgRatingPerYear(const char *inputFilename, const char *outputFilename);

#endif