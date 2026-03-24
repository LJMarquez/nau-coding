// include guard
#ifndef HANGMAN_LIB_H
#define HANGMAN_LIB_H

// header files
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// global constants
#define LEN_FRUITS 104
#define ATTEMPTS 6
#define MAX_FRUIT_SIZE 25
extern const char* FRUITS[LEN_FRUITS];

// function prototypes
/**
 * Function initializeRandom: this function intends to initialize the random generator number based on your operating system's current time. This initialization should happen only once in the program. You have this function implemented in The Yahtzee problems!
**/
void initializeRandom();

/**
 * Function getSecretWord: this function takes an array of characters named secretWord[] as an output argument. It randomly generates an index between zero and the length of the array of FRUITS. Then, it selects the appropriate secret word from FRUITS based on the generated index and copies the fruit name into the output parameter secretWord[]. For example, if the randomly generated index is 0 and FRUITS[0] = "banana", then the secretWord[] receives "banana". The function returns an integer value that indicates the length of the selected secret word. For example, if the selected word is "banana", the function returns 6.
**/
int getSecretWord(char secretWord[]);

/**
 * Function buildOutputArray: this function takes the size of the secret word (length of the word plus an additional index for the null terminator) and an outputArray, which is the same size as the secret word, and fills in the output array with underscores. The output array contains one underscore character for each position, except for the last one, which contains the null terminator. For example, if the size is 5, the output array will be {'_', '_', '_', '_', '\0'}. The function doesn't return any values.
**/
void buildOutputArray(int size, char outputArray[]);

/**
 * Function buildAttemptArray: this function takes a pointer to an array with 7 indexes (i.e., size ATTEMPTS + 1) to store the user's incorrect guesses. The attempts array is initialized with stars ('*') in each position, except for the last one, which receives the null terminator '\0'. The stars represent that no guesses have been made yet. The function doesn't return any values.
**/
void buildAttemptArray(char attempts[]);

/**
 * Function checkGuess: given a single character representing the user's guess, and a secret word as a constant pointer to char, this function returns true if the guess is a letter that exists in the secret word. Otherwise, it returns false.
**/
bool checkGuess(char guess, const char secretWord[]);

/**
 * Function fillOutputArray: given a single character that represents the user's guess, a secret word as a constant pointer to char, and the outputArray, this function verifies whether each letter in the secret word is the user's guess. If it is, it replaces the underscore '_' in the output array with the guess. For example, if the user guesses 'u' and the secret word is 'yuzu', then the output array should become {'_', 'u', '_', 'u', '\0'}. The function returns true if any underscore is replaced with the guessed letter. It returns false if the guessed letter was already filled (i.e., the user made a repeated guess).
**/
bool fillOutputArray(char guess, const char secretWord[], char outputArray[]);

/**
 * Function fillAttemptsArray: this function takes in a single character that represents the user's guess, and an array of characters that represents the array of attempts. It replaces the next star character ('*') in the attempts array with a letter that represents an incorrect guess from the user. For example, if the secret word is "yuzu" and the first user's guess is 'a', the attempts array should become {'a', '*', '*', '*', '*', '*', '\0'}. The function returns true if at least one star is replaced with the guessed letter. It returns false if the guessed letter already exists in the attempts array (i.e., the user made a repeated guess).
**/
bool fillAttemptsArray(char guess, char attempts[]);

/**
 * Function checkVictory: given a constant representing the outputArray (i.e., an array filled with underscores or correct guesses) and the length of the outputArray, this function checks whether the output array is filled with letters only (no underscores). The function returns false if there is at least one underscore in the output array. Otherwise, it returns true.
**/
bool checkVictory(const char outputArray[]);

/**
 * Function checkDefeat: given a constant pointer to an array of characters that stores the attempts, this function checks whether the attempts array is filled with letters only (no stars). The function returns false if there is at least one star ('*') in the attempts array. Otherwise, it returns true.
**/
bool checkDefeat(const char attempts[]);

/**
 * Function play: this function controls the game. It receives a pointer to a boolean variable called giveup, which is set to true if the user gives up the game or false, otherwise. Your function must do the following (make sure you use the appropriate functions for each step):
 * generates a random secret word.
 * declares all the necessary variables, including but not limited to an array of characters of size MAX_FRUIT_SIZE to store the secret word; an array of characters to store the attempts array; and an array of characters of the same length as the secret word to store the outputArray. Make sure the attempts and output arrays are correctly initialized.
 * asks for the user to guess
 * for each guess, the function decides whether the letter is in the secret word
 *      if the guess is in the secret word, the function fills in the output array, prints it, and checks if the user won. If the user wins, set the output parameter giveup to false, and the function returns true.
 *      if the guess is not in the secret word, the function fills in the attempts array, prints it, and checks if the user has lost. If the user loses, set the output parameter giveup to false, print out the secret word, and the function returns false.
 * Repeat from step 3 while the user doesn't win, lose, or give up
**/
bool play(bool *giveup);

#endif