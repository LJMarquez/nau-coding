# Lab 2 | C Basics

## Task 1: printf

Produce your code in `lab2-1.c`

### Instructions

Write a statement that prints the following message in the system's console.

> Hello World!

Make sure the cursor moves to next line after the message.

### Compile

```bash
gcc lab2-1.c -o lab2-1
```

## Task 2: scanf string

Produce your code in `lab2-2.c`

### Instructions

Declare a variable of type `char` of size `20` called `name`.
Then, read the `name` from the user input using a `scanf` function call.
Make sure your `scanf` function reads up to `19` characters only to fit the size of the string.

### Compile

```bash
gcc lab2-2.c -o lab2-2
```

## Task 3: scanf int

Produce your code in `lab2-3.c`

### Instructions

Declare a variable of type `int` called `age`.
Then, read the `age` from the user input using a `scanf` function call.

### Compile

```bash
gcc lab2-3.c -o lab2-3
```

## Task 4: printf scanf

Produce your code in `lab2-4.c`

### Instructions

Complete the program below so that it reads the user's `name` and `age` and prints the message:

> Hello \<name\>, you are \<age\> years old.

where `<name>` and `<age>` are the values informed by the user.
Consider that `name` has size `20`, holding up to `19` characters plus the null-terminator.

### Compile

```bash
gcc lab2-4.c -o lab2-4
```

## Task 5: scanf double

Produce your code in `lab2-5.c`

### Instructions

Declare a variable of type `double` called `price`.
Then, read the `price` from the user input using a `scanf` function call.

### Compile

```bash
gcc lab2-5.c -o lab2-5
```

## Task 6: stdio functions

Produce your code in `lab2-6.c`

### Instructions

Complete the program below so that it reads the name of a product (size `20` characters) and its price from the user input and prints the message:

> \<prodName\> costs USD\<price\>.

where `<prodName>` and `<price>` are the values informed by the user.
Show the `price` formatted with two decimal points and ensure that the product name fits the string.

### Compile

```bash
gcc lab2-6.c -o lab2-6
```

## Task 7: variable initialization

Produce your code in `lab2-7.c`

### Instructions

Declare a variable of type `int` named `number` and initialize it with the literal `-2`.

### Compile

```bash
gcc lab2-7.c -o lab2-7
```

## Task 8: string initialization

Produce your code in `lab2-8.c`

### Instructions

Declare a variable of type `char` of size `10` named `dayOfWeek` and initialize it with the string `"Monday"`.

### Compile

```bash
gcc lab2-8.c -o lab2-8
```

## Task 9: addition

Produce your code in `lab2-9.c`

### Instructions

Change the value of `number` to be incremented in three integers using addition operator.
For example, if `number` is `5`, it becomes `8`.

### Compile

```bash
gcc lab2-9.c -o lab2-9
```

## Task 10: subtraction

Produce your code in `lab2-10.c`

### Instructions

Change the value of `number` to be decremented in five integers using subtraction operator.
For example, if `number` is `10`, it becomes `5`.

### Compile

```bash
gcc lab2-10.c -o lab2-10
```

## Task 11: decrement

Produce your code in `lab2-11.c`

### Instructions

Change the value of `number` to be one **less** than its current value.
For example, if `number` is `10`, it becomes `9`.

Requirement: _use a decrement operator_

### Compile

```bash
gcc lab2-11.c -o lab2-11
```

## Task 12: increment

Produce your code in `lab2-12.c`

### Instructions

Change the value of `number` to be one **more** than its current value.
For example, if `number` is `10`, it becomes `11`.

Requirement: _use a increment operator_

### Compile

```bash
gcc lab2-12.c -o lab2-12
```

## Task 13: sum

Produce your code in `lab2-13.c`

### Instructions

In the program below, set the variable `sum` to the sum of `num1` and `num2`.

### Compile

```bash
gcc lab2-13.c -o lab2-13
```

## Task 14: multiplication

Produce your code in `lab2-14.c`

### Instructions

In the program below, set the variable `mult` to the multiplication of `num` and `3`.

### Compile

```bash
gcc lab2-14.c -o lab2-14
```

## Task 15: integer division

Produce your code in `lab2-15.c`

### Instructions

In the program below, set the variable `intDiv` to the integer division of `num` and `2`.

### Compile

```bash
gcc lab2-15.c -o lab2-15
```

## Task 16: remainder

Produce your code in `lab2-16.c`

### Instructions

In the program below, set the variable `remainder` to the remainder of the integer division between `num` and `4`.

### Compile

```bash
gcc lab2-16.c -o lab2-16
```

## Task 17: decimal division

Produce your code in `lab2-17.c`

### Instructions

In the program below, set the variable `div` to the division of `num` and `2.0`.

### Compile

```bash
gcc lab2-17.c -o lab2-17
```

## Task 18: printf syntax

Produce your code in `lab2-18.c`

### Instructions

The following program results in an error. Identify and fix the error so that the program works as expected.

### Compile

```bash
gcc lab2-18.c -o lab2-18
```

## Task 19: scanf syntax

Produce your code in `lab2-19.c`

### Instructions

The following program results in an unexpected behavior. Identify and fix the error so that the program works as expected.

### Compile

```bash
gcc lab2-19.c -o lab2-19
```

## Task 20: scanf syntax

Produce your code in `lab2-20.c`

### Instructions

The following program results in an unexpected behavior. Identify and fix the error so that the program works as expected.

### Compile

```bash
gcc lab2-20.c -o lab2-20
```

## Task 21: printf syntax

Produce your code in `lab2-21.c`

### Instructions

The following program results in an unexpected behavior. Identify and fix the error so that the program works as expected.

### Compile

```bash
gcc lab2-21.c -o lab2-21
```

## Task 22: printf syntax

Produce your code in `lab2-22.c`

### Instructions

Considering the program below, write statements that result in a table formatted as the following example:

```
| Student              | Grade |
|----------------------|-------|
| Mary                 | 9.3   |
| Peter                | 8.2   |
| John                 | 9.5   |
```

### Compile

```bash
gcc lab2-22.c -o lab2-22
```

## Task 23: compound interest

Produce your code in `lab2-23.c`

### Instructions

Complete the program below to calculate the compound interest of a given initial amount. The compound interest is given by the formula $CI = A - P$ where:

- $CI$ is the compound interest we want to calculate
- $A$ is the final amount after a period
- $P$ is the principal amount

The principal amount ($P$) is informed by the user. $A$ is calculated as $$A = P(1 + \frac{r}{100n})^{nt}$$ where:

- $P$ is the principal amount
- $r$ is the interest rate
- $n$ is the compounding frequency
- $t$ is the number of years

Except for $CI$ and $A$, all the other variables are initialized with values provided by the user. The interest rate is provided as a percentage (`0.0 - 100.0`); don't forget to convert it to decimal before applying the formula.

### Compile

```bash
gcc lab2-23.c -o lab2-23 -lm
```

## Task 24: header files

Produce your code in `lab2-24.c`

### Instructions

The compilation of the source code below fails because some functions are not recognized.
Resolve the issues to ensure successful compilation.

### Compile

```bash
gcc lab2-24.c -o lab2-24 -lm
```

## Task 25: basic program

Produce your code in `lab2-25.c`

### Instructions

Write a complete program that reads an integer number from the user input and prints the message:

> You typed \<number\>.

where \<number\> is the number typed by the user.
Your program must include the following:

- the necessary header files
- a main program with the following:
  - _initialization_: a title to the program and a declaration to the the necessary variable(s)
  - _user input_: a prompt for the number and a statement to read the number
  - _output_: the requested message
  - _end program_: an ending message and a success exit

Comment your code using the FSPP structure.

### Compile

```bash
gcc lab2-25.c -o lab2-25
```

## Task 26: swap program

Produce your code in `lab2-26.c`

### Instructions

Write a program that swap the contents of two variables by performing arithmetic operations with them.
Your program must include the following:

- the necessary header files
- a main program with the following:
  - _initialization_: a title to the program and a declaration to the the necessary variable(s)
  - _user input_: prompt/read statements for the `first` and `second` integer values to be swapped; show the variables before swapping as in the sample output below
  - _processing_: calculate the swap
  - _output_: the output messages as shown below
  - _end program_: an ending message and a success exit

To perform the swap between a `first` and a `second` variables, do the following:

- store the sum of both variables in the `first` variable
- store the difference between the `first` variable and the `second` variable in the `second` variable.
- store the difference between the `first` variable and the `second` variable in the `first` variable.

**Sample output:** assuming that first=5 and second=10 initially

> Before the swap
> first: 5
> second: 10
>
> After the swap
> first: 10
> second: 5

Comment your code using the FSPP structure.

### Compile

```bash
gcc lab2-26.c -o lab2-26
```
