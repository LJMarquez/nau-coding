# Lab 3 | Flow Control

## Task 1: if

Produce your code in `lab3-1.c`

### Instructions

Complete the program so that it prints `Positive` if the number informed by the user is greater than zero.

### Compile

```bash
gcc lab3-1.c -o lab3-1
```

## Task 2: if

Produce your code in `lab3-2.c`

### Instructions

Complete the program so that it prints `Even` if the number informed by the user is divisible by 2.

### Compile

```bash
gcc lab3-2.c -o lab3-2
```

## Task 3: if

Produce your code in `lab3-3.c`

### Instructions

Complete the program so that it calculates the average between number1 and number 2 only if the numbers informed by the user are within the range [0,100], inclusive.

### Compile

```bash
gcc lab3-3.c -o lab3-3
```

## Task 4: if-else

Produce your code in `lab3-4.c`

### Instructions

Define a constant named PWD with the value `4812`.
Then, complete the program so that it prints `Access Granted` if the password matches the `PWD` constant.
Otherwise, print `Access Denied`.

### Compile

```bash
gcc lab3-4.c -o lab3-4
```

## Task 5: if-else if-else

Produce your code in `lab3-5.c`

### Instructions

Define three constants named `RED`, `YELLOW`, `GREEN` with the values `0`, `1` and `2`, respectively.
Then, write a `main` program that prompt and reads a number from the user input (`0`, `1` or `2`) and print one of the messages below:

- `Stop!` if the user input is the integer equivalent to `RED` (zero)
- `Slow down and prepare to stop!` if the user input is the integer equivalent to `YELLOW` (one)
- `Proceed with caution!` if the user input is the integer equivalent to `GREEN` (two)
- `Invalid traffic light indication.` if any other case

**Requirement:** use `if-else if-else` for conditions; use macros (`#define`) for constant definition

### Compile

```bash
gcc lab3-5.c -o lab3-5
```

## Task 6: switch-case

Produce your code in `lab3-6.c`

### Instructions

Define three constants named `RED`, `YELLOW`, `GREEN` with the values `0`, `1` and `2`, respectively.
Then, write a `main` program that prompt and reads a number from the user input (`0`, `1` or `2`) and print one of the messages below:

- `Stop!` if the user input is the integer equivalent to `RED` (zero)
- `Slow down and prepare to stop!` if the user input is the integer equivalent to `YELLOW` (one)
- `Proceed with caution!` if the user input is the integer equivalent to `GREEN` (two)
- `Invalid traffic light indication.` if any other case

**Requirement:** use `switch-case` for conditions; use macros (`#define`) for constant definition

### Compile

```bash
gcc lab3-6.c -o lab3-6
```

## Task 7: for

Produce your code in `lab3-7.c`

### Instructions

Write a program using a `for` loop to print the multiplication table of a number entered by the user.

Sample output: assuming the user entered `5`

```
5 x 0 = 0
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50
```

### Compile

```bash
gcc lab3-7.c -o lab3-7
```

## Task 8: for

Produce your code in `lab3-8.c`

### Instructions

Write a program using a `for` loop and the appropriate conditional statements to calculate and print the factorial of a number entered by the user.
Note: `0! = 1` and there are no factorial of negative numbers.

Sample output: assuming the user entered `5`

```
5! = 5 x 4 x 3 x 2 x 1 = 120
```

Sample output: assuming the user entered `0`

```
0! = 1
```

Sample output: assuming the user entered `-5`

```
The factorial of a negative number is undefined.
```

### Compile

```bash
gcc lab3-8.c -o lab3-8
```

## Task 9: for

Produce your code in `lab3-9.c`

### Instructions

Write a program using a `for` loop to calculate and print the sum of the first `n` natural numbers, where `n` is provided by the user.

Sample output: assuming the user entered `5`

```
1 + 2 + 3 + 4 + 5 = 15
```

Sample output: assuming the user entered `0`

```
0 is not a natural number.
```

Sample output: assuming the user entered `-5`

```
-5 is not a natural number.
```

**Disclaimer:** `0` (zero) may be considered a natural number in some definitions, but this is being intentially ignored in this assignment.

### Compile

```bash
gcc lab3-9.c -o lab3-9
```

## Task 10: while

Produce your code in `lab3-10.c`

### Instructions

Write a program using a `while` loop to read numbers from the user until a negative number is entered.

Sample output:

```
Type a number: 5
Type a number: 20
Type a number: 3
Type a number: 0
Type a number: -6
Thanks for playing.
```

### Compile

```bash
gcc lab3-10.c -o lab3-10
```

## Task 11: while

Produce your code in `lab3-11.c`

### Instructions

Write a program using a `while` loop where the user has to guess a single digit number (0-9).
The loop should continue until the user guesses correctly. Notify the user if the guess is invalid.

Sample output: assuming the secret number is `5`

```
Guess the number: 0
Guess the number: 8
Guess the number: 3
Guess the number: 10
Invalid. The number has one digit only.
Guess the number: 5
You found it!
```

### Compile

```bash
gcc lab3-11.c -o lab3-11
```

## Task 12: do-while

Produce your code in `lab3-12.c`

### Instructions

Write a program using a `do-while` loop to read numbers from the user until a negative number is entered.

Sample output:

```
Type a number: 5
Type a number: 20
Type a number: 3
Type a number: 0
Type a number: -6
Thanks for playing.
```

### Compile

```bash
gcc lab3-12.c -o lab3-12
```

## Task 13: do-while

Produce your code in `lab3-13.c`

### Instructions

Write a program using a `do-while` loop where the user has to guess a single digit number (0-9).
The loop should continue until the user guesses correctly. Notify the user if the guess is invalid.

Sample output: assuming the secret number is `5`

```
Guess the number: 0
Guess the number: 8
Guess the number: 3
Guess the number: 10
Invalid. The number has one digit only.
Guess the number: 5
You found it!
```

### Compile

```bash
gcc lab3-13.c -o lab3-13
```

## Task 14: loop-conditionals

Produce your code in `lab3-14.c`

### Instructions

Write a C program that interacts with the user to collect a positive integer `nTerm` and display the nth terms of the Fibonacci series.

Your program must:

- Print a title to the program: `Fibonacci Calculator`
- Declare the necessary variables
- Prompt and read the necessary user input: `nTerm`, representing the number of terms to show
- Check the validity of user input: `nTerm` must be `1` or greater
- If the user input is invalid, end the program with a message
- If the user input is valid, calculate and display `nTerm` terms of the Fibonacci sequence
- End the program with a message

**The Fibonacci Sequence**

The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones. The two first terms are 0 and 1.

```
F(0) = 0
F(1) = 1
F(2) = 0 + 1 = 1
F(3) = 1 + 1 = 2
F(4) = 1 + 2 = 3
F(5) = 2 + 3 = 5
...
```

Therefore, an example of a Fibonacci Sequence is `0, 1, 1, 2, 3, 5, 8, 13, 21, ...`

To solve this problem, you will need to store the two initial terms and sum them up to calculate the next term. Repeat this process `nTerm`times! Don't forget to update the two terms after calculating each new term, as you have new preceding terms.

For example, if your preceding terms are `fib1` and `fib2`, then the new term is caculated as

```
newTerm = fib1 + fib2;
```

Then, `fib1` must be updated to store the value in `fib2` and `fib2` must be updated to store the value in the `newTerm` to keep them with the two most recent terms.

**Sampe ouptut:** Invalid input

```
Fibonacci Calculator
====================
Type the number of terms: -5
Invalid. The number must be equal to or greater than 1.
End of program.
```

**Sampe ouptut:** Valid input

```
Fibonacci Calculator
====================
Type the number of terms: 5
Fibonacci Sequence with 5 terms: 0, 1, 1, 2, 3,
End of program.
```

### Compile

```bash
gcc lab3-14.c -o lab3-14
```
