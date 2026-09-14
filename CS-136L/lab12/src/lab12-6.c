/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// TODO: write your function here
struct Album* buildAlbum(const char* title, const char* artist, int year, int tracks)
{
    struct Album* newAlbum = (struct Album*)malloc(sizeof(struct Album));

    newAlbum->releaseYear = year;
    newAlbum->numTracks = tracks;
    strcpy(newAlbum->title, title);
    strcpy(newAlbum->artist, artist);

    return newAlbum;
}