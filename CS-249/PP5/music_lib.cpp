// header files
#include "music_lib.h"
#include <sstream>

// ========================== Song Class Methods (provided) ==========================

/**
 * Default constructor
 */
Song::Song()
{
    title[0] = '\0';
    artist[0] = '\0';
    genre = POP;
    next = NULL;
}

/**
 * Parameterized constructor
 */
Song::Song(const char* title, const char* artist, Genre genre)
{
    strncpy(this->title, title, STR_LEN - 1);
    this->title[STR_LEN - 1] = '\0';
    strncpy(this->artist, artist, STR_LEN - 1);
    this->artist[STR_LEN - 1] = '\0';
    this->genre = genre;
    this->next = NULL;
}

// getters
const char* Song::getTitle() const { return title; }
const char* Song::getArtist() const { return artist; }
Genre Song::getGenre() const { return genre; }
Song* Song::getNext() const { return next; }

// setter
void Song::setNext(Song* next) { this->next = next; }

/**
 * Method: print
 * Input argument: genres - an array with the names of the genres
 * Output argument: prints song details to stdout
 * Return: none
 * Dependencies: iostream
 */
void Song::print(char* genres[]) const
{
    cout << "Playing '" << title << "' by '" << artist
         << "' (Genre: " << genres[genre] << ")..." << endl;
}

/**
 * Method: swap
 * Input argument: another song to swap with
 * Output argument: this song and the other song have swapped data
 * Return: none
 * Dependencies: cstring
 */
void Song::swap(Song& other)
{
    // swap titles
    char tempTitle[STR_LEN];
    strncpy(tempTitle, title, STR_LEN);
    strncpy(title, other.title, STR_LEN);
    strncpy(other.title, tempTitle, STR_LEN);

    // swap artists
    char tempArtist[STR_LEN];
    strncpy(tempArtist, artist, STR_LEN);
    strncpy(artist, other.artist, STR_LEN);
    strncpy(other.artist, tempArtist, STR_LEN);

    // swap genres
    Genre tempGenre = genre;
    genre = other.genre;
    other.genre = tempGenre;
}

// ========================== Playlist Class Methods (provided) ==========================

/**
 * Default constructor
 */
Playlist::Playlist()
{
    head = NULL;
}

/**
 * Copy constructor (deep copy)
 * Creates an independent copy of the other playlist.
 * If the source playlist is circular, the copy will also be circular.
 */
Playlist::Playlist(const Playlist& other)
{
    // initialize the head to NULL
    head = NULL;

    // if the other playlist is empty
    if (other.head == NULL)
    {
        // nothing to copy
        return;
    }

    // determine if the other playlist is circular
    Song* tail = other.head;
    while (tail->getNext() != NULL && tail->getNext() != other.head)
    {
        tail = tail->getNext();
    }
    bool isCircular = (tail->getNext() == other.head);

    // deep copy all nodes from the other playlist
    Song* current = other.head;
    Song* newTail = NULL;

    while(current != NULL)
    {
        if(current == other.head && newTail != NULL)
        {
            break;
        }
        // create a new song with the same data
        Song* newSong = new Song(current->getTitle(),
                                 current->getArtist(),
                                 current->getGenre());
        // if this is the first node
        if (head == NULL)
        {
            // set it as the head
            head = newSong;
        }
        else
        {
            // link the previous node to this one
            newTail->setNext(newSong);
        }
        // update the tail to the new node
        newTail = newSong;
        // move to the next node in the other playlist
        current = current->getNext();
    }

    // if the source was circular, make the copy circular too
    if (isCircular && newTail != NULL)
    {
        newTail->setNext(head);
    }
}

/**
 * Copy assignment operator (deep copy)
 * Frees the current playlist and creates an independent copy of the other.
 * If the source playlist is circular, the copy will also be circular.
 */
Playlist& Playlist::operator=(const Playlist& other)
{
    // check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    // free the existing playlist
    if (head != NULL)
    {
        // break the cycle if the list is circular
        Song* t = head;
        while (t->getNext() != NULL && t->getNext() != head)
        {
            t = t->getNext();
        }
        if (t->getNext() == head)
        {
            t->setNext(NULL);
        }

        // delete all nodes
        Song* current = head;
        while (current != NULL)
        {
            Song* next = current->getNext();
            delete current;
            current = next;
        }
        head = NULL;
    }

    // deep copy from the other playlist
    if (other.head != NULL)
    {
        // determine if the other playlist is circular
        Song* tail = other.head;
        while (tail->getNext() != NULL && tail->getNext() != other.head)
        {
            tail = tail->getNext();
        }
        bool isCircular = (tail->getNext() == other.head);

        // copy all nodes
        Song* current = other.head;
        Song* newTail = NULL;

        while(current != NULL)
        {
            if(current == other.head && newTail != NULL)
            {
                break;
            }
            Song* newSong = new Song(current->getTitle(),
                                     current->getArtist(),
                                     current->getGenre());
            if (head == NULL)
            {
                head = newSong;
            }
            else
            {
                newTail->setNext(newSong);
            }
            newTail = newSong;
            current = current->getNext();
        }

        // if the source was circular, make the copy circular too
        if (isCircular && newTail != NULL)
        {
            newTail->setNext(head);
        }
    }

    return *this;
}

// getter
Song* Playlist::getHead() const { return head; }

// ========================== Provided Methods ==========================

/**
 * Method: createPlaylist (provided)
 * Output argument: playlist is populated from the CSV file
 * Return: true if the playlist is successfully loaded, false if errors occur
 * Dependencies: addSong, fstream, cstring
 */
bool Playlist::createPlaylist()
{
    // open the file
    ifstream file(FILENAME);
    // if the file could not be opened
    if (!file.is_open())
    {
        // print a message
        cout << "Could not open file " << FILENAME << endl;
        // end the method with an error code
        return false;
    }

    // create a variable to hold each line
    string line;

    // read and discard the header line
    if (!getline(file, line))
    {
        // close the file
        file.close();
        // file is empty, return false
        return false;
    }

    // while there is another line to read
    while (getline(file, line))
    {
        // create a string stream to parse the line
        stringstream ss(line);
        // create variables to hold the parsed data
        string token;
        char title[100];
        char artist[100];
        int genre;

        // parse the title
        if (getline(ss, token, ','))
        {
            strncpy(title, token.c_str(), 99);
            title[99] = '\0';
        }
        // parse the artist
        if (getline(ss, token, ','))
        {
            strncpy(artist, token.c_str(), 99);
            artist[99] = '\0';
        }
        // parse the genre
        if (getline(ss, token, ','))
        {
            genre = atoi(token.c_str());
        }

        // add the song to the playlist casting Genre to the correct enum
        addSong(title, artist, (Genre)genre);
    }
    // close the file
    file.close();
    // return success
    return true;
}

// ========================== Student Tasks ==========================

/**
 * Task 1: Play the Playlist
 * Input argument: genres - an array with the names of the genres. Genres are
 *                          listed in the array according to its enum value.
 *                          For example, "Pop" is at index genres[POP]
 * Output argument: none
 * Return: none
 * Dependencies: iostream, cctype
 */
void Playlist::play(char* genres[])
{
    // TODO: implement this method
    if(head == NULL)
    {
        cout << "Nothing to be played right now. Add songs to continue." << endl;
    }
    else
    {
        Song* current = head;
        int count = 0;

        while(current != NULL)
        {
            current->print(genres);
            current = current->getNext();
            count++;

            if(count == MAX_SONGS && current != NULL)
            {
                char choice;
                cout << "Are you still listening [Y|N]? ";
                cin >> choice;
                choice = (char)tolower(choice);

                while(choice != 'y' && choice != 'n')
                {
                    cout << "I didn't get that. Please type Y to continue listening or N to stop: ";
                    cin >> choice;
                    choice = (char)tolower(choice);
                }

                if(choice == 'n')
                {
                    return;
                }
                count = 0;
            }
        }
    }
}

/**
 * Task 2: Adding a New Song to the Playlist
 * Input argument: title - a string with the title of the song
 *                 artist - a string with the artist of the song
 *                 genre - a Genre enum for the genre of the song
 * Output argument: updated head of the playlist, if needed
 * Return: true if the song is successfully added, false otherwise
 * Dependencies: iostream, cstring
 */
bool Playlist::addSong(const char* title, const char* artist, Genre genre)
{
    // TODO: implement this method
    Song* newSong = new Song(title, artist, genre);

    if(head == NULL)
    {
        head = newSong;
        return true;
    }

    Song* current = head;
    while(current->getNext() != NULL && current->getNext() != head)
    {
        current = current->getNext();
    }

    if(current->getNext() == head)
    {
        newSong->setNext(head);
    }
    current->setNext(newSong);

    return true;
}

/**
 * Task 3: Removing a Song from the Playlist
 * Input argument: title - a string with the title of the song
 * Output argument: updated head of the playlist, if needed
 * Return: true if the song is successfully removed, false otherwise
 * Dependencies: iostream, cstring
 */
bool Playlist::removeSong(const char* title)
{
    // TODO: implement this method
    if(head == NULL)
    {
        return false;
    }

    if(strcmp(head->getTitle(), title) == 0)
    {
        if(head->getNext() == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Song* tail = head;
            while(tail->getNext() != NULL && tail->getNext() != head)
            {
                tail = tail->getNext();
            }
            Song* removed = head;
            head = head->getNext();
            if(tail->getNext() == removed)
            {
                tail->setNext(head);
            }
            delete removed;
        }
        return true;
    }

    Song* previous = head;
    Song* current = head->getNext();
    while(current != NULL && current != head)
    {
        if(strcmp(current->getTitle(), title) == 0)
        {
            previous->setNext(current->getNext());
            delete current;
            return true;
        }
        previous = current;
        current = current->getNext();
    }

    return false;
}

/**
 * Task 4: Shuffle Play
 * Input argument: genres - an array with the names of the genres. Genres are
 *                          listed in the array according to its enum value.
 *                          For example, "Pop" is at index genres[POP]
 * Output argument: none
 * Return: none
 * Dependencies: cstdlib, iostream
 */
void Playlist::playShuffle(char* genres[])
{
    // TODO: implement this method
    if(head == NULL)
    {
        cout << "Nothing to be played right now. Add songs to continue." << endl;
        return;
    }

    int count = 0;
    Song* current = head->getNext();
    count = 1;
    while(current != NULL && current != head)
    {
        count++;
        current = current->getNext();
    }

    Song** songs = new Song*[count];
    current = head;
    for(int index = 0; index < count; index++)
    {
        songs[index] = current;
        current = current->getNext();
    }

    for(int index = count - 1; index > 0; index--)
    {
        int randomIndex = rand() % (index + 1);
        Song* temp = songs[index];
        songs[index] = songs[randomIndex];
        songs[randomIndex] = temp;
    }

    for(int index = 0; index < count; index++)
    {
        songs[index]->print(genres);
    }

    delete[] songs;
}

/**
 * Task 5: Play Songs by Artist
 * Input argument: artist - a string representing the artist name
 *                 genres - an array with the names of the genres. Genres are
 *                          listed in the array according to its enum value.
 *                          For example, "Pop" is at index genres[POP]
 * Output argument: none
 * Return: none
 * Dependencies: cstring, iostream
 */
void Playlist::playByArtist(const char* artist, char* genres[])
{
    // TODO: implement this method
    bool found = false;
    Song* current = head;
    while(current != NULL)
    {
        if(strcmp(current->getArtist(), artist) == 0)
        {
            current->print(genres);
            found = true;
        }
        current = current->getNext();
        if(current == head)
        {
            break;
        }
    }

    if(!found)
    {
        cout << "Nothing to be played by " << artist
             << " right now. Add songs to continue." << endl;
    }
}

/**
 * Task 6: Sorting the Playlist by Genre
 * Output argument: playlist sorted by genre
 * Return: void
 * Dependencies: none
 */
void Playlist::sortByGenre()
{
    // TODO: implement this method
    if(head == NULL)
    {
        cout << "It is quiet here. Add songs to continue." << endl;
        return;
    }

    bool circular = detectCycle();
    if(circular)
    {
        makePlaylistLinear();
    }

    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        Song* current = head;
        while(current->getNext() != NULL)
        {
            Song* next = current->getNext();
            if(current->getGenre() > next->getGenre())
            {
                current->swap(*next);
                swapped = true;
            }
            current = next;
        }
    }

    cout << "Playlist will play by genre from here on!" << endl;
}

/**
 * Task 7: Detecting a Cycle in the Playlist
 * Output argument: none
 * Return: true if the last song points to the head of the playlist,
 *         false otherwise
 * Dependencies: none
 */
bool Playlist::detectCycle()
{
    // TODO: implement this method
    Song* slow = head;
    Song* fast = head;
    while(fast != NULL && fast->getNext() != NULL)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

/**
 * Task 8: Play Non-Stop
 * Output argument: playlist is configured to be circular
 * Return: void
 * Dependencies: detectCycle
 */
void Playlist::makePlaylistCircular()
{
    // TODO: implement this method
    if(head == NULL)
    {
        cout << "It is quiet here. Add songs to continue." << endl;
        return;
    }

    if(detectCycle())
    {
        cout << "Music is already playing continuously!" << endl;
        return;
    }

    Song* tail = head;
    while(tail->getNext() != NULL)
    {
        tail = tail->getNext();
    }
    tail->setNext(head);
    cout << "Music will play continuously from here on!" << endl;
}

/**
 * Task 9: Play Up to the End
 * Output argument: playlist is configured to be linear (last points to null)
 * Return: void
 * Dependencies: detectCycle
 */
void Playlist::makePlaylistLinear()
{
    // TODO: implement this method
    if(head == NULL)
    {
        cout << "It is quiet here. Add songs to continue." << endl;
        return;
    }

    if(!detectCycle())
    {
        cout << "Music is already playing up to the last song!" << endl;
        return;
    }

    Song* tail = head;
    while(tail->getNext() != head)
    {
        tail = tail->getNext();
    }
    tail->setNext(NULL);
    cout << "Music will stop playing when the playlist is over!" << endl;
}

/**
 * Task 10: Reversing the Playlist
 * Output argument: playlist is reversed
 * Return: void
 * Dependencies: detectCycle
 */
void Playlist::reversePlaylist()
{
    // TODO: implement this method
    if(head == NULL)
    {
        cout << "It is quiet here. Add songs to continue." << endl;
        return;
    }

    if(detectCycle())
    {
        Song* tail = head;
        while(tail->getNext() != head)
        {
            tail = tail->getNext();
        }
        tail->setNext(NULL);
    }

    Song* previous = NULL;
    Song* current = head;
    while(current != NULL)
    {
        Song* next = current->getNext();
        current->setNext(previous);
        previous = current;
        current = next;
    }
    head = previous;
    cout << "Playlist reversed." << endl;
}
