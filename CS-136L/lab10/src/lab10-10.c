/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>
#include "lab10_lib.h"

// main program
int main()
{
    // create tracks without a nextTrack (NULL)
    Track track1 = {.title = "Taxman", .duration = 156, .nextTrack = NULL};
    Track track2 = {.title = "Eleanor Rigby", .duration = 131, .nextTrack = NULL};
    Track track3 = {.title = "I'm Only Sleeping", .duration = 182, .nextTrack = NULL};

    // TODO: link track2 as the next track after track1
    track1.nextTrack = &track2;

    // TODO: link track3 as the next track after track2
    track2.nextTrack = &track3;

    // create an album without the first track (NULL)
    Album beatles = {.title = "Revolver", .artist = "The Beatles", .releaseYear = 1966, .firstTrack = NULL};

    // TODO: link track1 as the first track of the album
    beatles.firstTrack = &track1;

    // print album information
    printf("Album: %s\n", beatles.title);
    printf("Artist: %s\n", beatles.artist);
    printf("Release Year: %d\n", beatles.releaseYear);

    // create a variable to store the track number
    int trackNumber = 1;

    // TODO: create a pointer to the current track, set it to the first track
    Track *currentTrackPtr = beatles.firstTrack;
    
    // TODO: traverse the tracks while there is a next track
    while(currentTrackPtr != NULL)
    {
        // TODO: print the current track
        printf("Track %d: %s (%d seconds)\n", trackNumber, currentTrackPtr->title, currentTrackPtr->duration);
        
        // TODO: move the current track to the next track
        currentTrackPtr = currentTrackPtr->nextTrack;
        
        // increment the track number
        trackNumber++;
    }

    // return success
    return 0;
}
