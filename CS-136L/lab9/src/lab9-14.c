/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// global definitions
#define ROWS 8
#define COLS 8
#define HORIZONTAL 0
#define VERTICAL 1
#define NOT_FOUND -1

int searchWord(char grid[ROWS][COLS], const char* word, int* row, int* col)
{
    int wordLength = strlen(word);

    *row = NOT_FOUND;
    *col = NOT_FOUND;

    for(int i = 0; i < ROWS; i++) {
        int matchedLetters = 0;
        int startCol = NOT_FOUND;

        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == word[matchedLetters]) {
                if(matchedLetters == 0) {
                    startCol = j;
                }
                matchedLetters++;
                if(matchedLetters == wordLength)
                {
                    *row = i;
                    *col = startCol;
                    return HORIZONTAL;
                }
            }
            else
            {
                matchedLetters = 0;
            }
        }
    }

    for(int j = 0; j < COLS; j++) {
        int matchedLetters = 0;
        int startRow = NOT_FOUND;

        for(int i = 0; i < ROWS; i++) {
            if(grid[i][j] == word[matchedLetters]) {
                if(matchedLetters == 0) {
                    startRow = i;
                }
                matchedLetters++;
                if(matchedLetters == wordLength)
                {
                    *row = startRow;
                    *col = j;
                    return VERTICAL;
                }
            }
            else
            {
                matchedLetters = 0;
            }
        }
    }

    return NOT_FOUND;
}