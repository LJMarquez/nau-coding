# Lab 9 | Two-Dimensional Array

## Task 1: array declaration

Produce your code in `lab9-1.c`

### Instructions

Write a single statement that declares an _uninitialized_ 2D array of integers of dimensions 5 x 10.

## Task 2: array declaration

Produce your code in `lab9-2.c`

### Instructions

Write a single statement that declares an _uninitialized_ 2D array of strings that holds 100 strings with maximum of 255 characters.

## Task 3: array initialization

Produce your code in `lab9-3.c`

### Instructions

Write a single statement that declares an _uninitialized_ 1D _constant_ array that holds 100 pointers to string literals.

## Task 4: array initialization

Produce your code in `lab9-4.c`

### Instructions

Write a **single** statement that declares a 2D array of integers of dimensions 3 x 2 and initilizes each index as follows:

```
1 2
5 7
9 3
```

## Task 5: array initialization

Produce your code in `lab9-5.c`

### Instructions

In the program below, initialize the array `alphabet` so that row `UPPER` contains the uppercase letters (A-Z), and row `LOWER` contains the lowercase letters (a-z).

**Tip:** remember that characters are integer values, therefore `'a' + 0 = 'a'`, `'A' + 1 = 'B'`, and so on.

### Compile

```bash
gcc -Wall lab9-5.c -o lab9-5 -lm
```

## Task 6: array direct access

Produce your code in `lab9-6.c`

### Instructions

In the program below, write a `printf` statement that prints the value stored at index (0,1) of `numbers`.

**Sample output**: (assuming index (0,1) stores 30)

```
value at index (0,1): 30
```

### Compile

```bash
gcc -Wall lab9-6.c -o lab9-6 -lm
```

## Task 7: array direct access

Produce your code in `lab9-7.c`

### Instructions

Fill in the blanks in the program below, so it allows the user to change the value at a given row and column to a value of their choice.

**Sample output**: (invalid row)

```
Original array:
10 20 30
40 50 60
70 80 90
Enter a row (0-2): 5
Invalid row! Please enter a value between 0 and 2.
```

**Sample output**: (invalid column)

```
Original array:
10 20 30
40 50 60
70 80 90
Enter a row (0-2): 1
Enter a column (0-2): 5
Invalid column! Please enter a value between 0 and 2.
```

**Sample output**: (valid index)

```
Original table:
10  20  30
40  50  60
70  80  90

Enter a row (0-2): 1
Enter a column (0-2): 2
Enter a new value: 99

Updated table:
10  20  30
40  50  99
70  80  90
```

### Compile

```bash
gcc -Wall lab9-7.c -o lab9-7 -lm
```

## Task 8: array traversal

Produce your code in `lab9-8.c`

### Instructions

Write a program that reads 9 integers from the user input into a 2D array of dimensions 3 x 3 and prints them in reverse order.

**Sample output**:

```
Type a number: 10
Type a number: 20
Type a number: 30
Type a number: 40
Type a number: 50
Type a number: 60
Type a number: 70
Type a number: 80
Type a number: 90

Original table:
10 20 30
40 50 60
70 80 90

Reversed table:
90 80 70
60 50 40
30 20 10
```

### Compile

```bash
gcc -Wall lab9-8.c -o lab9-8 -lm
```

## Task 9: array traversal

Produce your code in `lab9-9.c`

### Instructions

Write a function named `printTriangle` that, given a 2D _squared_ matrix and the number of rows, prints the left-aligned lower triangular matrix, i.e., the values in the main diagonal and lower indexes, ignoring the indexes above than the main diagonal.
The function only prints the matrix for a valid value of `rows`, which must be a number between `1` and `MAX_SIZE` (both inclusive). If `rows` is invalid, the function prints `ERROR: Invalid dimensions.`

**Sample outptu:** assume that `rows = 3` and the 2D array is

```
0 1 1
1 1 0
1 0 1
```

the function prints:

```
0
1 1
1 0 1
```

**Tip:** a _squared_ matrix has the same number of rows and columns.

### Compile

```bash
mv $UPLOADED_FILES/* .
gcc -Wall lab9-9.c lab9-9_invalid_lower.c -o lab9-9_invalid_lower -lm
gcc -Wall lab9-9.c lab9-9_invalid_upper.c -o lab9-9_invalid_upper -lm
gcc -Wall lab9-9.c lab9-9_large.c -o lab9-9_large -lm
gcc -Wall lab9-9.c lab9-9_valid.c -o lab9-9_valid -lm
```

## Task 10: array traversal

Produce your code in `lab9-10.c`

### Instructions

Pascal's Triangle is a triangular array of numbers where each number is the sum of the two directly above it, starting with 1 at the top. For example, for `rows = 5`, the Pascal's Triangle `triangle` is

```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

In a Pascal's Triangle, each row starts and ends with a `1`. Any remainder indexes are calculated by the sum of the two values above it (previous row, same column and its predecessor).
For example, `triangle[4][1] = 4` because the number above it is `3` and its predecessor is `1` (`1 + 3 = 4`). Likewise, `triangle[4][2] = 6` because the number above it is `3` and its predecessor is `3` (`3 + 3 = 6`).

Write a function named `generatePascalTriangle` that takes a matrix of integers and a valid number of rows and fills in the matrix with the Pascal triangle value. The function ingores indexes that do not belong to the triangle form.
The function does not return any values.

### Compile

```bash
gcc -Wall lab9-10.c lab9-10_main.c -o lab9-10 -lm
```

## Task 11: arrays in functions

Produce your code in `lab9-11.c`

### Instructions

Write a C function named `findLargestPerRow` that takes a 2D array of integers, its number of rows, and a 1D array to store the largest number from each row. The function does not return a value; instead, it fills the provided 1D array with the largest values from each row.

**Function prototype:**

```c
void findLargestPerRow(int data[][MAX_SIZE], int rows, int cols, int largestPerRow[]);
```

**Sample Output:** for the input 2D array (`data`)

```
3,  5,  7,  2
9,  1,  4,  8
6, 10,  2,  3
```

the output 1D array (`largestPerRow`) is

```
{7, 9, 10}
```

### Compile

```bash
gcc -Wall lab9-11.c lab9-11_main.c -o lab9-11 -lm
```

## Task 12: arrays in functions

Produce your code in `lab9-12.c`

### Instructions

Write a function named `countPerfectSquares` that counts the number of perfect squares (numbers like `1, 4, 9, 16, 25, ...`) in a 2D array.
A perfect square is a positive number that is the result of an integer multiplied by itself (i.e., n^2 for some integer n)).

**Function prototype:**

```c
int countPerfectSquares(int data[][MAX_SIZE], int rows, int cols);
```

### Compile

```bash
gcc -Wall lab9-12.c lab9-12_main.c -o lab9-12 -lm
```

## Task 13: sizeof

Produce your code in `lab9-13.c`

### Instructions

In the function below, calculate the size of the 2D array using the `sizeof` operator.

### Compile

```bash
gcc -Wall lab9-13.c -o lab9-13 -lm
```

## Task 14: arrays in functions

Produce your code in `lab9-14.c`

### Instructions

Write a C function named `searchWord` that simulates a word search puzzle by searching for the `word` in the `grid`. The word can be found in a vertical or horizontal direction. Assume the word will always read from left to right or from top to bottom. Also assume that both grid and word include only valid, uppercase characters.
For example, the word `CAT` can be in the grid as

```
C A T
```

or

```
C
A
T
```

The function takes a 2D array representing the `grid`, a constant pointer to character representing the `word`, and two pointers to integer representing the row and column of the first character when the word is found.
The function returns a constant that indicates whether the word is found in the `HORIZONTAL` or `VERTICAL` direction, or `NOT_FOUND` if the word is not in the grid, in which case `row` and `col` are also set to `NOT_FOUND`.

**Function prototype:**

```c
int searchWord(char grid[ROWS][COLS], const char* word, int* row, int* col);
```

### Compile

```bash
gcc -Wall lab9-14.c lab9-14_main.c -o lab9-14 -lm
```
