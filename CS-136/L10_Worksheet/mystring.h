// mystring.h
#ifndef MYSTRING_H
#define MYSTRING_H

// header files
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h> // for tolower, toupper, isalpha, isspace

// global definitions
#define MAX_STR_SIZE 255
#define ALPHABET_SIZE 26

/**
 * Function: caesarCipher
 * Input argument: 
 *      - message: a pointer to the text message
 *      - shift: the number of characters to shift
 * Output argument: each character in message is shifted by shift characters
 * Return: none
 * Dependencies:
 *      - string.h: strlen
 *      - ctype.h: toupper
 */
void caesarCipher(char *message, int shift);

/**
 * Function: uniqueChar
 * Input argument: 
 *      - message: a pointer to the text message
 * Output argument: none
 * Return: the number of unique letters in the message (case-insensitive)
 * Dependencies: 
 *      - string.h: stlen
 *      - ctype.h: tolower, isalpha
 */
int uniqueChar(const char *message);

/**
 * Function: countTotalCharacters
 * Input argument: none
 * Output argument: none
 * Return: the total number of characters typed by the user considering 
 *         multiple messages
 * Dependencies:
 *      - stdio.h: printf, scanf
 *      - string.h: strcmp, strlen
 */
int countTotalCharacters();

/**
 * Function: reverseString
 * Input argument: 
 *      - message: pointer to the text message to be reversed
 * Output argument: none
 * Return: none
 * Dependencies:
 *      - string.h: strlen
 */
void reverseString(char *message);

/**
 * Function: removeWhitespace
 * Input argument: 
 *      - message: pointer to the message from which the whitespaces are removed
 * Output argument: message without the whitespace
 * Return: none
 * Dependencies: 
 *      - string.h: strlen
 *      - ctype.h: isspace
 */
void removeWhitespace(char *message);

#endif
