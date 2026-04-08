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
    //    (use the designated initializers method)
    struct Album album =
    {
        .title = "Revolver",
        .releaseYear = 1966,
    };
    
    

    // print the data
    printf("Album: %s\n", album.title);
    printf("Release Year: %d\n", album.releaseYear);
    
    // return success
    return 0;
}
