/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// global definitions
const char* dictionary[] = {"apple", "banana", "grape", "orange", "melon", "cherry", "peach", "strawberry"};
const int DICTIONARY_SIZE = sizeof(dictionary) / sizeof(dictionary[0]);

// TODO: write the spellChecker function here
bool spellChecker(const char* word)
{
    for(int i = 0; i < DICTIONARY_SIZE; i++)
    {
        if(word == dictionary[i])
        {
            return true;
        }
        
    }
    return false;
}
