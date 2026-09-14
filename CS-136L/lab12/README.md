# Lab 12 | Dynamic Memory Allocation

## Task 1: malloc - basic type

Produce your code in `lab12-1.c`

### Instructions

Write a single statement that dynamically allocates an array of 10 integers using `malloc` function.

## Task 2: calloc - basic type

Produce your code in `lab12-2.c`

### Instructions

Write a single statement that dynamically allocates an array of 10 integers using `calloc` function.

## Task 3: malloc - struct type

Produce your code in `lab12-3.c`

### Instructions

Consider the `struct Album` below. Write a single statement that dynamically allocates a `struct Album` using `malloc` function.

## Task 4: calloc - struct type

Produce your code in `lab12-4.c`

### Instructions

Consider the `struct Album` below. Write a single statement that dynamically allocates a `struct Album` using `calloc` function.

## Task 5: deallocation

Produce your code in `lab12-5.c`

### Instructions

In the program below, dynamically allocate memory for a `double` variable, assign the value `3.14` to it, print the value, and deallocate the memory after use.

**Sample output:**

> Value: 3.14

### Compile

```bash
gcc -Wall lab12-5.c -o lab12-5
```

## Task 6: constructor function

Produce your code in `lab12-6.c`

### Instructions

Considering the `struct Album` below, create a function that, given the values representing the `title`, `artist`, `releaseYear`, and `numTracks`, creates and return a `struct Album` variable, filled in with the given data.

**Function prototype:**

```c
struct Album\* buildAlbum(const char\* title, const char\* artist, int year, int tracks);
```

### Compile

```bash
gcc -Wall lab12-6.c lab12-6_main.c -o lab12-6 -lm
```

## Task 7: realloc

Produce your code in `lab12-7.c`

### Instructions

In the program below, demonstrate the use of `realloc` function to modify the size of an array. Do the following:

- Dynamically allocate memory for an array of 3 integers and store its address at a pointer variable named `fives`
- Initialize the array with the values 0, 5, and 10
- After printing the array, use `realloc` to resize the array to hold 5 integers
- Initialize the new elements with 15 and 20
- After printing, deallocate the memory for the array

### Compile

```bash
gcc -Wall lab12-7.c -o lab12-7 -lm
```

## Task 8: memory allocation in functions

Produce your code in `lab12-8.c`

### Instructions

Write a function named `buildSquares` that dynamically allocates an array of `n` integers and stores the first `n` square numbers.
The function returns the pointer to the array or `NULL` if the memory allocation fails.

**Example:** for `n = 6`, the function returns an array with the following values: `0, 1, 4, 9, 16, 25`

**Function prototype:**

```c
int *buildSquares(int n);
```

### Compile

```bash
gcc -Wall lab12-8.c lab12-8_main.c -o lab12-8 -lm
```

## Task 9: memory allocation in functions

Produce your code in `lab12-9.c`

### Instructions

Write a function named `duplicateString` that returns a dynamically allocated copy of a string given as argument.

**Tips:**

- use the `strcpy` to copy the given string to the new variable
- when allocating the memory to the new variable, remember to include the space for the null terminator

**Function prototype:**

```c
char* duplicateString(const char* str);
```

### Compile

```bash
gcc -Wall lab12-9.c lab12-9_main.c -o lab12-9 -lm
```

## Task 10: memory allocation - 2D arrays

Produce your code in `lab12-10.c`

### Instructions

In the program below, dynamically allocate a 2D array (`matrix`) of integers with `m` rows and `n` columns, where `m` and `n` are given by the user.
Fill it with a number representing the sum of its row and column indexes (e.g., index `(0,3)` receives `0 + 3 = 3`).

After printing the `matrix`, deallocate the 2D array.

### Compile

```bash
gcc -Wall lab12-10.c -o lab12-10 -lm
```

## Task 11: linked lists

Produce your code in `lab12-11.c`

### Instructions

Assume the structs `Track` and `Album` are defined in the header file `lab12_lib.h`. The structs contain the following members:

- `Track`: `title` (array of characters), `duration` (integer), `nextTrack` (pointer to `struct Track`)
- `Album`: `title` (array of characters), `artist` (array of characters), `releaseYear` (integer), `firstTrack` (pointer to `Track`)

Complete the program below to print the tracks of _Revolver_ by _The Beatles_, following the sample output below.
To achieve this, do the following:

- implement the constructor function `createTrack`. Given a title and a duration, the fuction allocates memory for a `Track`, initialize its members with the given values and returns the address of the newly created `Track`.
- implement the function `addTrack`. Given the address of an `Album` and the address of a `Track`, the function adds the given `Track` as the **last** track in the album. Follow this process:
  - if the album currently does not have any tracks (`.firstTrack` is `NULL`), assign the given track as the album's first track
  - if the album contains one or more tracks, initialize a pointer to `Track` with the album's first Track (this is the current `Track`)
  - traverse the tracks by moving the current track to the next track, until you find the last track (you know you reached the last track when `current->nexTrack` is equal to `NULL`)
  - attach the given track as the `.nextTrack` of the last track
  - the function doesn't return any values

In main:

- link the tracks in the correct order by calling the `addTrack` function for each newly created track
- after printing the album, traverse the tracks to deallocate the dynamically allocated memory:
  - initialize a pointer to Track to store the album's first track (this is your current track)
  - while there are tracks to deallocate (the current track is not `NULL`), store the next of the current track in a `Track` pointer (so that you know where the next track is)
  - free the current track
  - assign the current track with the next track you stored

When the loop exits, all the tracks were deallocated and the program ends successfully.

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
gcc -Wall lab12-11.c lab12-11_lib.c -o lab12-11 -lm
```

## Task 12: linked lists

Produce your code in `lab12-12.c`

### Instructions

Assume the structs `Destination` and `Itinerary` are defined in the header file `lab12_lib.h`. The structs contain the following members:

- `Destination`: `name` (array of characters of size `STR_SIZE`), `days` (integer), `nextDestination` (pointer to `struct Destination`)
- `Itinerary`: `tripId` (integer), `totalDays` (integer), `firstDestination` (pointer to `Destination`)

Complete the program below to build and print an itinerary with the four provided destinations. Do the following:

- implement the constructor function `createDestination`. Given a destination name and a number of days, the fuction allocates memory for a `Destination`, initialize its members with the given values and returns the address of the newly created `Destination`.
- implement the function `addDestination`
  - given the address of an `Itinerary` and the address of a `Destination`, the function adds the given `Destination` as the **last** destination in the itinerary
  - the function updates the trip length, by accumulating the number of days for the added destination in the itinerary's `totalDays`
- the function doesn't return any values

In main:

    * link the destinations in the correct order by calling the `addDestintaion` for each newly created destination
    * after printing the itinerary, traverse the tracks to deallocate the dynamically allocated memory
    * the program ends with a success code

**Sample output:**

```
Itinerary 500: Paris -> Rome -> Berlin -> Amsterdam
Trip length: 11 days
```

### Compile

```bash
gcc -Wall lab12-12.c lab12-12_lib.c -o lab12-12 -lm
```
