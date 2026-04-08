/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// global definitions
#define STR_SIZE 100

// TODO: define your struct Track here
typedef struct Track
{
    char title[STR_SIZE];
    int duration;
    struct Track *nextTrack;
} Track;


// TODO: define your struct Album here
typedef struct Album
{
    char title[STR_SIZE];
    char artist[STR_SIZE];
    int releaseYear;
    Track *firstTrack;
} Album;
