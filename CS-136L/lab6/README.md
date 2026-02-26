# Lab 6 | Pointers

## Task 1: pointer manipulation

Produce your code in `lab6-1.c`

### Instructions

Fill in the blanks in the code below, so that the program prints the value stored in `number` using the pointer variable.

**Sample Output:**

```
Type a number: 7
Value pointed by the pointer variable: 7
```

### Compile

```bash
gcc -Wall lab6-1.c -o lab6-1
```

## Task 2: pointer manipulation

Produce your code in `lab6-2.c`

### Instructions

Fill in the blanks in the code below, so that the value in `number` changes by assigning the pointer variable.

**Sample Output:**

```
Number: 10
```

### Compile

```bash
gcc -Wall lab6-2.c -o lab6-2
```

## Task 3: pointer manipulation

Produce your code in `lab6-3.c`

### Instructions

Fill in the blanks in the code below, so that the program prints the requested information in the comments.

**Sample Output:** this sample output is an example as there is no way to anticipate the memory address where the variables will be stored.

```
Address where ptr is stored at: 0x7ffeefbff4a0
Address stored in ptr: 0x7ffeefbff4b0
Value at the address in ptr: 5.700000
```

### Compile

```bash
gcc -Wall lab6-3.c -o lab6-3
```

## Task 4: pointer in functions

Produce your code in `lab6-4.h`

### Instructions

Write a library file that contains the prototypes for the functions described below.
Your file must include an include guard (opening and closing) and the prototypes must be listed within the guards.
Also include the `stdbool.h` header file for `bool` data types.

**Function library:**

* `printValue`: the function receives a pointer to integer and prints its value. The function does not return any values.
* `swap`: a function that takes two pointers to integer and swaps their values. The function does not return any values.
* `divide`: the function takes in two `double` values representing a dividend and a divisor as well as a pointer to double representing the quotient.
The function divides the dividend by the divisor and stores the result in the pointer to quotient.
The function returns `true` if the division is possible or `false` if the divisor is zero.

## Task 5: pointer in functions

Produce your code in `lab6-5.c`

### Instructions

Write a function that, given a pointer to an array of characters, fills in the variables `firstLetter` and `lastLetter` with the smallest and largest lowercase characters (alphabetically) present in the string.
For example, for an array of characters containing the word "backgrounds", `firstLetter = 'a'` and `lastLetter = 'u'`.
If the string is empty, the output variables receive the null terminator character (\0).

**Function prototype:**
```c
void letterRange(const char* str, int size, char* firstLetter, char* lastLetter);
```

**Tip:** to ensure the letters are lowercase, use the function `tolower()` from `ctype.h`. See the example:
```c
char upper = 'M';
char lower = tolower(upper);  // lower = 'm'
```

### Compile

```bash
gcc -Wall lab6-5.c lab6-5_main.c -o lab6-5 -lm
```

## Task 6: pointer arithmetic

Produce your code in `lab6-6.c`

### Instructions

Write a function that traverses an array of characters using pointer arithmetic and print each individual character in a new line.
For example, if `str = "banana"`, then the function prints

```
b
a
n
a
n
a
```
**Function prototype:**
```c
void printCharacters(const char* str);
```

**Tips:**
* `str` is empty if the pointer points to `NULL` or if the first character is the null terminator character (`*str = '\\0'`)
* `str++` or any equivalent increment operation, moves the pointer to the next character
* the string no longer contains characters to print when it finds the null terminator (`'\\0'`)

### Compile

```bash
gcc -Wall lab6-6_main.c lab6-6.c -o lab6-6 -lm
```

## Task 7: pointer in functions

Produce your code in `lab6-7.c`

### Instructions

Write a C function that, given a pointer to an integer, increments the value pointed by the pointer in one.

**Function prototype:**
```c
void increment(int* ptr);
```

**Tip:** to ensure the letters are lowercase, use the function `tolower()` from `ctype.h`. See the example:
```c
char upper = 'M';
char lower = tolower(upper);  // lower = 'm'
```

### Compile

```bash
gcc -Wall lab6-7.c lab6-7_main.c -o lab6-7 -lm
```

## Task 8: pointer in functions

Produce your code in `lab6-8.c`

### Instructions

Write a C function that reverses the data in a given array. For example, the array `{1, 2, 3, 4, 5}` becomes `{5, 4, 3, 2, 1}`.

**Function prototype:**
```
void reverseArray(int* arr, int size);
```

**Tip:**
* no changes are needed if the array `NULL`, or sizes 0-1
* to reverse, swap the first and last elements, than walk both ends toward the center

### Compile

```bash
gcc -Wall lab6-8.c lab6-8_main.c -o lab6-8 -lm
```

## Task 9: pointers in functions

Produce your code in `lab6-9.c`

### Instructions

Complete the code below, so that it correctly calls the function `letterRange`.

### Compile

```bash
gcc -Wall lab6-9.c lab6-5.c -o lab6-9
```

## Task 10: pointers in functions

Produce your code in `lab6-10.c`

### Instructions

Complete the code below, so that it correctly calls the function `increment`.

### Compile

```bash
gcc -Wall lab6-10.c lab6-7.c -o lab6-10
```

## Task 11: pointers in functions

Produce your code in `lab6-11.c`

### Instructions

Complete the code below, so that it correctly calls the function `reverseArray`.

### Compile

```bash
gcc -Wall lab6-8.c lab6-11.c -o lab6-11
```

## Task 12: pointers and arrays

Produce your code in `lab6-12.c`

### Instructions

Complete the code below to demonstrate the equivalence between array indexing and pointer arithmetic.

**Sample output:**
```
Index notation: 3 6 9 12 15
Pointer notation: 3 6 9 12 15
```

### Compile

```bash
gcc -Wall lab6-12.c -o lab6-12
```
