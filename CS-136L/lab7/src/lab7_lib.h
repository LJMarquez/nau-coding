// include guards
#ifndef LAB7_LIB_H
#define LAB7_LIB_H

// header files
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// global definitions
    // maximum number of files
#define MAX_FILES 5
    // maximum length for each filename
#define MAX_LENGTH 100

// function prototypes
    // lab7-3
bool isEmpty(const char* str);
    // lab7-4 and lab7-5
int countVowels(const char* str);
    // lab7-6
bool isPalindrome(const char* str);
    // lab7-10
bool spellChecker(const char* word);
    // lab7-12
void appFileExtension(char* filenames[], int fileCount, const char* extension);

// end LAB7_LIB_H
#endif
