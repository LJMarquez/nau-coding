/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include "lab10_lib.h"

// TODO: implement your function here
void printAlbum(const struct Album album)
{
    printf("%s - %s (%d), %d.", album.artist, album.title, album.releaseYear, album.numTracks);
}