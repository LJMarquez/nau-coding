/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdlib.h>

// global definitions
#define STR_SIZE 100

// data types
struct Album
{
    char title[STR_SIZE];
    char artist[STR_SIZE];
    int releaseYear;
    int numTracks;
};

// TODO: write your statement here
struct Album *album = (struct Album *)malloc(sizeof(struct Album));