/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

#include <string.h>
#include "lab10_lib.h"

// main program
int main()
{
    // input data
    char* title = "Revolver";
    char* artist = "The Beatles";
    int year = 1966;
    int tracks = 14;

    // create the struct to be initialized
    struct Album album;

    // TODO: call the function initAlbum to initialize the struct
    initAlbum(&album, title, artist, year, tracks);
    

    // print the data
    printf("Album: %s\n", album.title);
    printf("Artist: %s\n", album.artist);
    printf("Release Year: %d\n", album.releaseYear);
    printf("Number of Tracks: %d\n", album.numTracks);
    // return success
    return 0;
}

// function implementation
void initAlbum(struct Album* album, const char *title, const char *artist, int releaseYear, int numTracks)
{
    // TODO: implement your function here
    strcpy(album->title, title);
    strcpy(album->artist, artist);
    album->releaseYear = releaseYear;
    album->numTracks = numTracks;
}
