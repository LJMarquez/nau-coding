#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H

// header files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>

using namespace std;

// global definitions
#define FILENAME "playlist.csv"
#define MAX_SONGS 150
#define STR_LEN 50

// enum for song genres
enum Genre
{
    POP,
    ROCK,
    JAZZ,
    CLASSICAL,
    OTHER,
    GENRE_COUNT
};

// class to represent a song (node in the linked list)
class Song
{
private:
    char title[STR_LEN];
    char artist[STR_LEN];
    Genre genre;
    Song* next;

public:
    /**
     * Default constructor
     */
    Song();

    /**
     * Parameterized constructor
     */
    Song(const char* title, const char* artist, Genre genre);

    // getters
    const char* getTitle() const;
    const char* getArtist() const;
    Genre getGenre() const;
    Song* getNext() const;

    // setter (needed for linked list manipulation)
    void setNext(Song* next);

    /**
     * Method: print
     * Input argument: genres - an array with the names of the genres
     * Output argument: prints song details to stdout
     * Return: none
     * Dependencies: iostream
     */
    void print(char* genres[]) const;

    /**
     * Method: swap
     * Input argument: another song to swap with
     * Output argument: this song and the other song have swapped data
     * Return: none
     * Dependencies: cstring
     */
    void swap(Song& other);
};

// class to represent a playlist (linked list of songs)
class Playlist
{
private:
    Song* head;

public:
    /**
     * Default constructor
     */
    Playlist();

    /**
     * Copy constructor (deep copy)
     */
    Playlist(const Playlist& other);

    /**
     * Copy assignment operator (deep copy)
     */
    Playlist& operator=(const Playlist& other);

    // NO destructor — the playlist is not automatically freed.
    // Memory must be managed manually (e.g., using removeSong).

    /**
     * Getter: getHead
     * Output argument: none
     * Return: pointer to the first song in the playlist
     * Dependencies: none
     */
    Song* getHead() const;

    /**
     * Method: createPlaylist (provided)
     * Output argument: playlist is populated from the CSV file
     * Return: true if the playlist is successfully loaded, false if errors occur
     * Dependencies: addSong, fstream, cstring
     */
    bool createPlaylist();

    /**
     * Method: play
     * Input argument: genres - an array with the names of the genres. Genres are
     *                          listed in the array according to its enum value.
     *                          For example, "Pop" is at index genres[POP]
     * Output argument: none
     * Return: none
     * Dependencies: iostream, cctype
     */
    void play(char* genres[]);

    /**
     * Method: addSong
     * Input argument: title - a string with the title of the song
     *                 artist - a string with the artist of the song
     *                 genre - a Genre enum for the genre of the song
     * Output argument: updated head of the playlist, if needed
     * Return: true if the song is successfully added, false otherwise
     * Dependencies: iostream, cstring
     */
    bool addSong(const char* title, const char* artist, Genre genre);

    /**
     * Method: removeSong
     * Input argument: title - a string with the title of the song
     * Output argument: updated head of the playlist, if needed
     * Return: true if the song is successfully removed, false otherwise
     * Dependencies: iostream, cstring
     */
    bool removeSong(const char* title);

    /**
     * Method: playShuffle
     * Input argument: genres - an array with the names of the genres. Genres are
     *                          listed in the array according to its enum value.
     *                          For example, "Pop" is at index genres[POP]
     * Output argument: none
     * Return: none
     * Dependencies: cstdlib, iostream
     */
    void playShuffle(char* genres[]);

    /**
     * Method: playByArtist
     * Input argument: artist - a string representing the artist name
     *                 genres - an array with the names of the genres. Genres are
     *                          listed in the array according to its enum value.
     *                          For example, "Pop" is at index genres[POP]
     * Output argument: none
     * Return: none
     * Dependencies: cstring, iostream
     */
    void playByArtist(const char* artist, char* genres[]);

    /**
     * Method: sortByGenre
     * Output argument: playlist sorted by genre
     * Return: void
     * Dependencies: none
     */
    void sortByGenre();

    /**
     * Method: detectCycle
     * Output argument: none
     * Return: true if the last song points to the head of the playlist,
     *         false otherwise
     * Dependencies: none
     */
    bool detectCycle();

    /**
     * Method: makePlaylistCircular
     * Output argument: playlist is configured to be circular
     * Return: void
     * Dependencies: detectCycle
     */
    void makePlaylistCircular();

    /**
     * Method: makePlaylistLinear
     * Output argument: playlist is configured to be linear (last points to null)
     * Return: void
     * Dependencies: detectCycle
     */
    void makePlaylistLinear();

    /**
     * Method: reversePlaylist
     * Output argument: playlist is reversed
     * Return: void
     * Dependencies: detectCycle
     */
    void reversePlaylist();
};

#endif // MUSIC_LIB_H
