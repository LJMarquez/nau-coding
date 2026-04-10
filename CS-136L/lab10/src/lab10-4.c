/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

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
    // TODO: initialize your struct variable here
    //    (use the compound literal initialization method)
    struct Album album =
    {
        "Revolver",
        "The Beatles",
        1966,
        14
    };



    // print the data
    printf("Album: %s\n", album.title);
    printf("Artist: %s\n", album.artist);
    printf("Release Year: %d\n", album.releaseYear);
    printf("Number of Tracks: %d\n", album.numTracks);

    // return success
    return 0;
}
