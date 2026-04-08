#ifndef LAB10_LIB_H
#define LAB10_LIB_H

// header files
#include <stdio.h>
#include <string.h>

// global definitions
#define STR_SIZE 100

struct Album
{
    char title[STR_SIZE];
    char artist[STR_SIZE];
    int releaseYear;
    int numTracks;
};

// TODO: define your struct Track here
typedef struct Track
{
    char title[STR_SIZE];
    int duration;
    struct Track *nextTrack;
} Track;

// TODO: define your struct Album here
typedef struct newAlbum
{
    char title[STR_SIZE];
    char artist[STR_SIZE];
    int releaseYear;
    Track *firstTrack;
} Album;


// lab10-6
struct Album buildAlbum(const char *title, const char *artist, int releaseYear, int numTracks);
// lab10-7
void printAlbum(const struct Album album);
// lab10-8
void initAlbum(struct Album *album, const char *title, const char *artist, int releaseYear, int numTracks);

#endif
