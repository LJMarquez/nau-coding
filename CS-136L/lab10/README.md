# Lab 10 | Structs

## Task 1: struct definition

Produce your code in `lab10-1.h`

### Instructions

Define a struct named `Book` containing the following members:

- an array of characters of size `STR_SIZE` to store the book `title`
- an array of characters of size `ISBN_SIZE` to store the book's `ISBN`
- an array of characters of size `STR_SIZE` to store the `author`'s name
- an integer value to store the `yearPublished`

**Requirement:** do not use `typedef` for this problem

## Task 2: struct definition

Produce your code in `lab10-2.h`

### Instructions

Define a struct named `DynamicArray` containing the following members:

- a pointer to integer to store the `array`
- an integer variable to store the `size` of the array

**Requirement:** do not use `typedef` for this problem

## Task 3: struct initialization

Produce your code in `lab10-3.c`

### Instructions

Consider the `struct Album` defined below. In the `main` function, create a statement that declares a variable named `album` and initializes the members with the following values:

- Title: "Revolver"
- Release year: 1966

**Requirement:** use the _designated initializers_ method

### Compile

```bash
gcc -Wall lab10-3.c -o lab10-3
```

## Task 4: struct initialization

Produce your code in `lab10-4.c`

### Instructions

Consider the `struct Album` defined below. In the `main` function, create a statement that declares a variable named `album` and initializes the members with the given values:

- Title: "Revolver"
- Artist: "The Beatles"
- Release year: 1966
- Number of tracks: 14

**Requirement:** use the _compound literal initialization_ method

### Compile

```bash
gcc -Wall lab10-4.c -o lab10-4
```

## Task 5: struct initialization

Produce your code in `lab10-5.c`

### Instructions

Consider the `struct Album` defined below. In the `main` function, create a statement that declares a variable named `album` and initializes the members with the given values:

- Title: "Revolver"
- Artist: "The Beatles"
- Release year: 1966
- Number of tracks: 14

**Requirement:** use the _member-wise initialization_ method

### Compile

```bash
gcc -Wall lab10-5.c -o lab10-5
```

## Task 6: struct initialization

Produce your code in `lab10-6.c`

### Instructions

We want to create a constructor function to initialize a `struct Album`.
Implement the function `buildAlbum` that takes the input data needed to initialize the struct, creates a `struct Album` variable, adds the input data to the respective struct members, and return the initialized struct variable.
Then, in the `main` function, call the function `buildAlbum` to initialize a struct Album variable named `album`.

**Function prototype:**

```c
struct Album buildAlbum(const char *title, const char *artist, int releaseYear,
    int numTracks);
```

### Compile

```bash
gcc -Wall lab10-6.c -o lab10-6 -lm
```

## Task 7: struct member access

Produce your code in `lab10-7.c`

### Instructions

Write a function named `printAlbum` that takes a `struct Album` and prints the album information in the format below.

**Sample output:**

```
The Beatles - Revolver (1966), 14.
```

**Function prototype:**

```c
void printAlbum(const struct Album album);
```

### Compile

```bash
mv $UPLOADED_FILES/* .
gcc -Wall lab10-7.c lab10-7_main.c -o lab10-7 -lm
```

## Task 8: pointer to struct

Produce your code in `lab10-8.c`

### Instructions

We want to create a constructor function to initialize a `struct Album`.
Implement the function `initAlbum` that takes a pointer to a `struct Album` and the input data needed to initialize the struct.
The function then sets each member of the `struct Album` received as argument with the provided input data. The function does not return any values.

In the `main` function, call the function `initAlbum` to initialize a the `struct Album album` variable.

**Function prototype:**

```c
void initAlbum(struct Album* album, const char *title, const char *artist,
    int releaseYear, int numTracks);
```

### Compile

```bash
gcc -Wall lab10-8.c -o lab10-8 -lm
```

## Task 9: struct with pointer

Produce your code in `lab10-9.h`

### Instructions

Define a struct named `Track` containing the following members:

- an array of characters of size `STR_SIZE` to store a song `title`
- an integer value to store the song's `duration` in seconds
- a pointer to a `struct Track` to store the next song in the album (`nextTrack`)

Using `typedef`, rename the `struct Track` to `Track`.

Then, define a struct named `Album` containing the following members:

- an array of characters of size `STR_SIZE` to store an album's `title`
- an array of characters of size `STR_SIZE` to store the `artist`
- an integer value to store the release year (`releaseYear`)
- a pointer to a `Track` variable to store the address of the first track in the album (`fistTrack`)

Using a `typedef`, rename the `struct Album` to `Album`.

## Task 10: struct manipulation

Produce your code in `lab10-10.c`

### Instructions

Assume the structs `Track` and `Album` created in the previous problem (`lab10-9`) are defined in the header file `lab10_lib.h`. The structs contain the following members:

- `Track`: `title` (array of characters), `duration` (integer), `nextTrack` (pointer to `struct Track`)
- `Album`: `title` (array of characters), `artist` (array of characters), `releaseYear` (integer), `firstTrack` (pointer to `Track`)

Complete this program below to print the three first tracks of _Revolver_ by _The Beatles_, following the sample output below.
To achieve this, do the following:

- after creating the individual tracks (provided), link the tracks in the correct order by setting the `nextTrack` member of the track to store the address of the track that should play after it. E.g., the `nextTrack` of `track1` should be `track2`
- for the `beatles` album (provided), set the `firstTrack` to the address of the first track (`track1`)
- create a pointer variable of type `Track` to store the `current` track and initialize it with the `beatles` album's first track
- create a `while` loop to traverse the linked tracks while the `current` track is a valid track
- print the `current` track with the appropriate format (see the sample output).
- move to the next track by assigning the `current` track to its `nextTrack`

When the `current` track becomes `NULL`, all the tracks have been printed (there's no `nextTrack` from there).
The loop exits and the program ends with a success code.

**Sample output:**

```
Album: Revolver
Artist: The Beatles
Release Year: 1966
Track 1: Taxman (156 seconds)
Track 2: Eleanor Rigby (131 seconds)
Track 3: I'm Only Sleeping (182 seconds)
```

### Compile

```bash
gcc -Wall lab10-10.c -o lab10-10 -lm
```

## Task 11: struct manipulation

Produce your code in `lab10-11.c`

### Instructions

Define the structs `Destination` and `Itinerary` with the following members:

- `Destination`: `name` (array of characters of size `STR_SIZE`), `days` (integer), `nextDestination` (pointer to `struct Destination`)
- `Itinerary`: `tripId` (integer), `totalDays` (integer), `firstDestination` (pointer to `Destination`)

Use `typedef` to redefine the name of these structs to `Itinerary` and `Destination`.

Then, complete the program below to build and print an itinerary with the four provided destinations.
The program also calculates and prints the trip length, by accumulating the number of days for each destination in the itinerary's `totalDays`.

Ensure the final itinerary follows the sequence in the sample output below.

**Sample output:**

```
Itinerary 500: Paris -> Rome -> Berlin -> Amsterdam
Trip length: 11 days
```

### Compile

```bash
gcc -Wall lab10-11.c -o lab10-11 -lm
```
