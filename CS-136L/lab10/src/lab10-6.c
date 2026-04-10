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

    // TODO: call the function buildAlbum to create a struct
    struct Album album = buildAlbum(title, artist, year, tracks);
    

    // print the data
    printf("Album: %s\n", album.title);
    printf("Artist: %s\n", album.artist);
    printf("Release Year: %d\n", album.releaseYear);
    printf("Number of Tracks: %d\n", album.numTracks);
    // return success
    return 0;
}

// function implementation
struct Album buildAlbum(const char *title, const char *artist, int releaseYear, int numTracks)
{
    // TODO: implement your function here
    struct Album album;
    strcpy(album.title, title);
    strcpy(album.artist, artist);
    album.releaseYear = releaseYear;
    album.numTracks = numTracks;

    return album;
}
