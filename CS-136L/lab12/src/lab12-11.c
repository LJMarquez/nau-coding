/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab12_lib.h"

// function prototypes
Track* createTrack(const char* title, int duration);
void addTrack(Album *album, Track *track);

// main program
int main()
{
    // create the album
    Album beatles;
    strcpy(beatles.title, "Revolver");
    strcpy(beatles.artist, "The Beatles");
    beatles.releaseYear = 1966;
    // initially, the album doesn't contain any tracks
    beatles.firstTrack = NULL;

    // create tracks
    struct Track *track1 = createTrack("Taxman", 156);
    struct Track *track2 = createTrack("Eleanor Rigby", 131);
    struct Track *track3 = createTrack("I'm Only Sleeping", 182);

    // TODO: add tracks
        // function: addTrack
    addTrack(&beatles, track1);
    addTrack(&beatles, track2);
    addTrack(&beatles, track3);


    // print the album details and tracks
    printAlbum(&beatles);

    // deallocate the memory for the tracks
        // TODO: initialize a pointer to the album's first track
    Track *currentTrack = beatles.firstTrack;
    
        // TODO: while there are tracks in the album
    while(currentTrack->nextTrack != NULL)
    {
            // TODO: store the next of the current track in a Track pointer
        Track *nextTrack = currentTrack->nextTrack;
            // TODO: free the current track
        free(currentTrack);
            // TODO: set the current track to the next track (stored in the pointer)
        *currentTrack = *nextTrack;
    }

    // return success
    return 0;
}

Track* createTrack(const char* title, int duration)
{
    // TODO: implement the createTrack function here
    Track *track = (Track *)malloc(sizeof(Track));
    strcpy(track->title, title);
    track->duration = duration;
}


void addTrack(Album *album, Track *track)
{
    // TODO: implement the addTrack function here
    if(album->firstTrack == NULL)
    {
        album->firstTrack = track;
    }
    else
    {
        Track *currentTrack = album->firstTrack;
        while(currentTrack->nextTrack != NULL)
        {
            currentTrack = currentTrack->nextTrack;
        }
        currentTrack->nextTrack = track;
    }
}
