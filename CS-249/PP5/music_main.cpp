#include "music_lib.h"

int main()
{
    // seed a random number generator
    srand(time(NULL));
    // variable to store user menu choice
    int choice = 0;
    // arrays to store song title and artist name
    char title[50], artist[50];
    // variable to store genre choice
    int genre;
    // array of genre names
    char* genres[] = {(char*)"Pop", (char*)"Rock", (char*)"Jazz",
                      (char*)"Classical", (char*)"Other"};
    // create an initial playlist
        // declare a playlist object
    Playlist playlist;
        // create an initial playlist
    if (!playlist.createPlaylist())
    {
        // print a message if something went wrong
        cout << "Something went wrong. Please give it another try." << endl;
        // exit with an error code
        return 1;
    }
        // print an initial message
    cout << "\nTuneStream Music Player\n" << endl;
    cout << "Initial playlist created with 20 songs!" << endl;

    // Infinite loop to keep the program running
    while (choice != 10)
    {
        // print the menu options for the user
        cout << "\n1. Play" << endl;
        cout << "2. Shuffle play" << endl;
        cout << "3. Play by Artist" << endl;
        cout << "4. Add a song to the playlist" << endl;
        cout << "5. Remove a song by name" << endl;
        cout << "6. Sort by Genre" << endl;
        cout << "7. Set to Continuous Play Mode" << endl;
        cout << "8. Set to Single Execution Play Mode" << endl;
        cout << "9. Reverse Playlist" << endl;
        cout << "10. Exit" << endl;

        // prompt user for choice
        cout << "Choose an option: ";

        // read the user's choice
        cin >> choice;

        // switch case to handle different menu options
        switch (choice)
        {
            // case for playing the songs
            case 1:
                // play the songs
                playlist.play(genres);
                // end of case
                break;

            // case for shuffling play
            case 2:
                // play songs in the shuffle mode
                playlist.playShuffle(genres);
                // exit the case
                break;

            // case for searching by artist
            case 3:
                // prompt for artist name
                cout << "Enter artist name to search: ";
                // read the artist name from user
                cin.ignore();
                cin.getline(artist, 50);
                // play by artist
                playlist.playByArtist(artist, genres);
                // exit the case
                break;

            // case for adding a song
            case 4:
                // prompt for song title
                cout << "Enter song title: ";
                // read the song title from user
                cin.ignore();
                cin.getline(title, 50);
                // prompt for artist name
                cout << "Enter artist: ";
                // read the artist name from user
                cin.getline(artist, 50);
                // prompt for genre
                cout << "Enter genre (0: POP, 1: ROCK, 2: JAZZ, 3: CLASSICAL, "
                        "4: OTHER): ";
                // read the genre from user
                cin >> genre;

                // try to add a new song
                if (playlist.addSong(title, artist, (Genre)genre))
                {
                    // print a confirmation message if successfully
                    cout << "Song added successfully!" << endl << endl;
                }
                // exit the case
                break;

            // case for removing a song
            case 5:
                // prompt for song title to remove
                cout << "Enter song title to remove: ";
                // read the song title from user
                cin.ignore();
                cin.getline(title, 50);
                // try to remove the song
                if (playlist.removeSong(title))
                {
                    cout << "Song removed successfully" << endl << endl;
                }
                // exit the case
                break;

            // case for sorting by genre
            case 6:
                // sort the list by genre
                playlist.sortByGenre();
                // exit the case
                break;

            // case for making the playlist circular
            case 7:
                // make the playlist circular
                playlist.makePlaylistCircular();
                // exit case
                break;

            // case for making the playlist singly linked
            case 8:
                // set the playlist for single execution
                playlist.makePlaylistLinear();
                // exit the case
                break;

            // Case for reversing the playlist
            case 9:
                // Call method to reverse the playlist
                playlist.reversePlaylist();

                // Confirmation message
                cout << "Playlist reversed." << endl;
                break; // Exit the case

            // Case for exiting the program
            case 10:
                // Message indicating exit
                cout << "Exiting..." << endl;

                return 0; // Exit the program

            // Default case for invalid option
            default:
                cout << "Invalid option, please try again." << endl;
        }
    }

    // Return statement for main function (not reached due to infinite loop)
    return 0;
}
