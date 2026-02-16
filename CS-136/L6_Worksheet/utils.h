// inclusion guard
#ifndef UTILS_H
#define UTILS_H

// header files
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// constant macros
#define BASE 10

// prototype functions
int countFactors(int n); 
bool isMultiple(int a, int b);
void printTriangle(int size);
int countDigits(int n);
int getPositiveNumber();
char getYNOption();

#endif