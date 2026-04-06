// include guards
#ifndef LAB8_LIB_H
#define LAB8_LIB_H

// header files
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// global definitions
#define MAX_WORD_LENGTH 50

// function prototypes
// lab8-6
void charToFile(const char *str, const char *filename);
// lab8-7
bool isFileEmpty(const char *filename);
// lab8-8
bool authenticate(const char *username, const char *password, const char *authFilename);
// lab8-9
void spellChecker(const char *source, const char *dictionary);
// lab8-10
void detectAnomalies(const char *sensorData, const char *anomalies);

// end LAB8_LIB_H
#endif
