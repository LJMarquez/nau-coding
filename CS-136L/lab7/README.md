# Lab 7 | String Manipulation

## Task 1: header file

Produce your code in `lab7-1.c`

### Instructions

The following program results in a compilation error because the function `strlen` is undefined. Fix the error by adding the required header file.

### Compile

```bash
gcc -Wall lab7-1.c -o lab7-1
```

## Task 2: length of a string

Produce your code in `lab7-2.c`

### Instructions

The program below uses the function `printCharacters` to print each character of a string in a new line. For example, `printCharacters("grapes")` prints

```
g
r
a
p
e
s
```

Write the function `printCharacters` using a `for` loop to iterate through the string.
Use the appropriate `string.h` function to identify the length of the string.

### Compile

```bash
gcc -Wall lab7-2.c -o lab7-2
```

## Task 3: length of a string

Produce your code in `lab7-3.c`

### Instructions

Write a function named `isEmpty` that receives a pointer to a string (`const char* str`) and determines if the string is empty.
The function returns `true` if the string is empty or `false` if the string is not empty.

A string is empty if:

- The pointer is `NULL` (i.e., it doesn't point to a valid string)
- The string contains no characters (i.e., the length of the string is zero)

**Function prototype:**

```
bool isEmpty(const char* str);
```

### Compile

```bash
gcc -Wall lab7-3.c lab7-3_main.c -o lab7-3
```

## Task 4: length of a string

Produce your code in `lab7-4.c`

### Instructions

Write a function named `countVowels` that receives a pointer to a string (`const char* str`) and returns the number of vowel characters (`a`, `e`, `i`, `o`, `u`) present in the string.
The function must be case-insensitive (e.g., 'A' and 'a' should both be counted as vowels).
If the string is `NULL` or empty, the function returns zero.

**Requirement:** traverse the string using a `for` loop and subscript notation (i.e., `str[]`) for string manipulation.

For example:
_ for `str = "banana"`, the function returns 3 (`aaa`)
_ for `str = "Application"`, the function returns 5 (`Aiaio`) \* for `str = ""`, the function returns 0

**Function prototype:**

```
int countVowels(const char* str);
```

### Compile

```bash
gcc -Wall lab7-4.c lab7-4_main.c -o lab7-4
```

## Task 5: length of a string

Produce your code in `lab7-5.c`

### Instructions

Write a function named `countVowels` that receives a pointer to a string (`const char* str`) and returns the number of vowel characters (`a`, `e`, `i`, `o`, `u`) present in the string.
The function must be case-insensitive (e.g., 'A' and 'a' should both be counted as vowels).
If the string is `NULL` or empty, the function returns zero.

**Requirement:** traverse the string using a `while` loop and pointer arithmetic (i.e., `*str`) for string manipulation.

For example:
_ for `str = "banana"`, the function returns 3 (`aaa`)
_ for `str = "Application"`, the function returns 5 (`Aiaio`) \* for `str = ""`, the function returns 0

**Function prototype:**

```c
int countVowels(const char* str);
```

### Compile

```bash
gcc -Wall lab7-5.c lab7-4_main.c -o lab7-5
```

## Task 6: length of a string

Produce your code in `lab7-6.c`

### Instructions

Write a function named `isPalindrome` that receives a pointer to a string (`const char* str`) and checks whether the string is a palindrome.
The function returns `true` when the string is a palindrome or `false`, otherwise. If the string is `NULL` or empty, the function returns `false`.

A palindrome is a string that reads the same forward and backward, such as _"racecar"_, _"madam"_, and _"level"_.
The function must be case-insensitive and ignore non-alphabetic characters.

**Function prototype:**

```
bool isPalindrome(const char* str);
```

**Tips:**
_ `isalpha(char c)`: function from the `ctype.h` library that returns `true` when a given character `c` is an alphabetic character (`a-z|A-z`) or `false` otherwise.
_ to detect if a string is a palindrome, start an index at the left side of the string and another at the end of the string (right side). Walk these index towards the middle of the string, comparing the next valid character in both ends. If there is a mismatch, the string is not a palindrome.

### Compile

```bash
gcc -Wall lab7-6.c lab7-6_main.c -o lab7-6
```

## Task 7: length of a string

Produce your code in `lab7-7.c`

### Instructions

The program below gets a word from the user input and replaces all occurrences of a given character in the word with a new character (both characters also informed by the user).
Complete the program so that it works as expected.

### Compile

```bash
gcc -Wall lab7-7.c -o lab7-7
```

## Task 8: string as function arguments

Produce your code in `lab7-8.c`

### Instructions

The program below gets a word from the user input and calls the function `replaceChar` to replaces all occurrences of a given character in the word with a new character (both characters also informed by the user).
Complete the program so that it works as expected.

**Provided function:** assume the function `replaceChar` is provided with the prototype below (you do **not** need to implement it).

```c
void replaceChar(char* str, char oldChar, char newChar);
```

### Compile

```bash
gcc -Wall lab7-8.c lab7-8_lib.c -o lab7-8
```

## Task 9: comparing strings

Produce your code in `lab7-9.c`

### Instructions

Write a function named `authenticate` that receives two strings representing the username and the password of a given user and check if the provided information match the stored credentials.
The function returns `true` if both username and password match or `false` otherwise.

Use the function `getCredentials` from `lab7_9_lib.h` library to obtain the stored password for the given username. If the username does not exist, `getCredentials` returns `NULL`. You do **not** need to implement this function (assume the implementation is already provided).

**Function prototypes:**

```c
char* getCredentials(const char* username);   // implementation provided
bool authenticate(const char* username, const char* password);
```

### Compile

```bash
gcc -Wall lab7-9.c lab7-9_lib.c lab7-9_main.c -o lab7-8
```

## Task 10: comparing strings

Produce your code in `lab7-10.c`

### Instructions

Write a function named `spellChecker` to implement a very simple spell checker. The function compares a `word` received as an argument with words listed in a `dictionary` of size `DICTIONARY_SIZE`.
The function returns `true` if the `word` is in the `dictionary` or `false` otherwise. The function also returs `false` if the `word` is empty.

\*\*Function prototype:

```c
bool spellChecker(const char* word);
```

### Compile

```bash
gcc -Wall lab7-10.c lab7-10_main.c -o lab7-10
```

## Task 11: string mutability

Produce your code in `lab7-11.c`

### Instructions

The following program intends to convert all the characters from a string to upercase letters. Although my program compiles without errors and warnings, the program terminates when the function is called with a `bus error` message.

According to generative AI:

    > A Bus Error is a type of runtime error that occurs when a program attempts to access memory in an invalid or misaligned way.

Fix the program so that it runs as expected.

### Compile

```bash
gcc -Wall lab7-11.c -o lab7-11
```

## Task 12: concatenating strings

Produce your code in `lab7-12.c`

### Instructions

Write a function named `appFileExtension` that takes in an array of `filenames`, the size of the array (i.e., the `fileCount`), and a string containing a `extension` for a file (e.g., `.exe` or `.pdf`).
The function traverses the array adding the `extension` to each filename. The function doesn't return any values.

**Function prototype:**

```c
void appFileExtension(char* filenames[], int fileCount, const char* extension);
```

### Compile

```bash
gcc -Wall lab7-12.c lab7-12_main.c -o lab7-12
```
