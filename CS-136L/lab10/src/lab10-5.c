/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

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

// main program
int main()
{
    struct Album album;

    // TODO: initialize each struct member here
    //    (use the member-wise initialization method)
    strcpy(album.title, "Revolver");
    strcpy(album.artist, "The Beatles");
    album.releaseYear = 1966;
    album.numTracks = 14;
    
    

    // print the data
    printf("Album: %s\n", album.title);
    printf("Artist: %s\n", album.artist);
    printf("Release Year: %d\n", album.releaseYear);
    printf("Number of Tracks: %d\n", album.numTracks);

    // return success
    return 0;
}
