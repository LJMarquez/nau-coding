# Lab 8 | File Manipulation

## Task 1: header file

Produce your code in `lab8-1.c`

### Instructions

The following program results in a compilation error because the abstract data type `FILE` is undefined.
Fix the error by adding the required header file.

### Compile

```bash
gcc -Wall lab8-1.c -o lab8-1
```

## Task 2: open/close stream

Produce your code in `lab8-2.c`

### Instructions

In the following program, create a stream for reading from a file named `story.txt`.
After the reading is performed, close the stream.

### Compile

```bash
mv $UPLOADED_FILES/* .
gcc -Wall lab8-2.c -o lab8-2
```

## Task 3: open/close stream

Produce your code in `lab8-3.c`

### Instructions

In the following program, we want to append an editor's note at the end of a file named `story.txt`.
After the writing is performed, close the stream.

The program prints out the content of the file using the `printFile` function, but you can assume the function is provided (you do **not** need to implement it).

### Compile

```bash
mv $UPLOADED_FILES/* .
gcc -Wall lab8-3.c lab8-4_lib.c -o lab8-3
```

## Task 4: open/close the stream

Produce your code in `lab8-4.c`

### Instructions

In the following program, we want to append an editor's note (`newText`) _before_ the credit line, which acknowledges AI usage to produce the paragraph.
To achieve this, the program follows this process:

    1. Load the file content to the memory
        * Open the file `story.txt` for reading (`r mode`)
        * Read the entire file content into a buffer (and, as always, null-terminate the string!)
        * Close the stream
    2. Locate the place where the new text should be inserted
        * Search the file content for where the credit line string start (the `strstr` function returns the address where the string starts)
    3. Write the content in the correct order
        * Open the file for writing and overwrite the content (`w mode`, yes, delete everything and start anew!)
        * If the credit line is in the file, calculate the index by subtracting the address of the credit line by the address of the file content
        * Write the file content up to the calculated index (before the credit line)
        * Now that the cursor is right before the credit line, add the new text, then add the credit line
        * If the credit line is **not** in the file, write the entire file content, then the new text, then the credit line
        * Close the stream

The program prints out the content of the file using the `printFile` function, but you can assume the function is provided (you do **not** need to implement it).

**Requirement:** create only one pointer to store the stream (`FILE*`). Remember that you will close the read-only stream before opening the writing stream. Reuse the pointer variable!

### Compile

```bash
mv $UPLOADED_FILES/* .
gcc -Wall lab8-4.c lab8-4_lib.c -o lab8-4
```

## Task 5: test if the stream is open

Produce your code in `lab8-5.c`

### Instructions

Complete the following program so that it tests if the `file` stream failed to open. If so, print the message:

> ERROR: Could not open the file <FILENAME>

where the `<FILENAME>` is the name of the file we're trying to open.

### Compile

```bash
gcc -Wall lab8-5.c -o lab8-5
```

## Task 6: write to file

Produce your code in `lab8-6.c`

### Instructions

Write a function named `charToFile` that, given a `filename` and a string (`str`), opens the file with overwrite mode and writes each character in the string into the file in a new line.
For example, if the string is `"grapes"`, the file will contain the content

```
g
r
a
p
e
s
```

Ensure you close the stream before the function exits.

**Function prototype:**

```
void charToFile(const char* str, const char* filename);
```

**Requirement:** use the `fprintf` function to print the characters in the appropriate format.

### Compile

```bash
gcc -Wall lab8-6.c lab8-6_main.c -o lab8-6
```

## Task 7: find if a file is empty

Produce your code in `lab8-7.c`

### Instructions

Write a function named `isFileEmpty` that receives a pointer to a file name (`const char* filename`) and determines if the file is empty.
A file is empty if the first character in the file is the `EOF` character. The function returns `true` if the file is inexistent or empty, or `false` otherwise.

**Remember to close the file before returning**, otherwise, the function ends and the stream is lost open.

**Function prototype:**

```
bool isFileEmpty(const char *filename);
```

### Compile

```bash
gcc -Wall lab8-7.c lab8-7_main.c -o lab8-7
```

## Task 8: authenticate from a string in a file

Produce your code in `lab8-8.c`

### Instructions

Write a function named `authenticate` that receives two strings representing the username and the password of a given user and check if the provided information matches the credentials stored in an authenticator file (the file name is also received as an argument).
The function returns `true` if the authenticator file exists, contains the provided username and the provided password matches the stored password for that specific user.
Otherwise, the funciton returns `false`.

**Function prototypes:**

```
bool authenticate(const char* username, const char* password, const char* authFilename);
```

**Tips:**
_ assume the maximum length of username and password is `MAX_LEN`
_ use the `fscanf` function to read the formatted username and password, considering that the file is in the format `username,password` \* use the format specifier `"%49[^,],%49s\\n"` to read the formatted file. - `%49[^,],` reads _up to 49 characters or until if finds a comma_, then consumes the comma - `%49s\\n` reads \_up to 49 characters or until it finds any whitespace character (e.g., whitespace, newline, null-terminator, etc), then it consumes the newline character

### Compile

```bash
gcc -Wall lab8-8.c lab8-8_main.c -o lab8-8
```

## Task 9: spell checker from a file

Produce your code in `lab8-9.c`

### Instructions

Write a function named `spellChecker` to implement a very simple spell checker. The function takes two file names as arguments: `source`, which is a text file containing paragraphs of text, and `dictionary`, which is a file where each line contains a single correctly spelled word.
The function processes the text from the `source` file, extracts individual words, and checks if each word exists in the `dictionary`.
If a word is not found in the dictionary, it is recorded in a log file named `"misspelledWords.txt"`. The function does not return any values.

**Function prototype:**

```
void spellChecker(const char* source, const char* dictionary);
```

**Tips:**
_ create the `misspelledWords.txt` in overwrite mode
_ there may be multiple occurrences of the same word in the `misspelledWords.txt` (no need to check for repetition)
_ assume all the words in both files are lowercase (no need to convert for case insensitive comparison)
_ assume the `source` file contains only words (no punctuation or other symbols)
_ if using fgets to read each word from the dictionary, don't forget to remove the `\\n` character from the end of the string
_ don't forget to close the files

### Compile

```bash
gcc -Wall lab8-9.c lab8-9_main.c -o lab8-9
```

## Task 10: manipulating numerical data

Produce your code in `lab8-10.c`

### Instructions

Write a function named `detectAnomalies` that analyzes sensor temperature readings to identify values that are outside an acceptable range.
The function takes two file names as arguments: `sensorData`, which is a `.csv` file containing two columns (`min,max`), where each row represents the minimum and maximum temperature recorded by a sensor; and `anomalies`, which is a text file where out-of-range temperature values will be logged.
A temperature is considered out of range if:
_ it is smaller than the `MIN_TEMP`
_ it is larger than the `MAX_TEMP`
_ the minimum temperature is larger than the maximum
_ the difference between the mininum and maximum temperatures is less than 5 degrees

Whenever a temperature is out of range, it is logged in the `anomalies` file using the following format:

```
Min Temp: 9.00 (Out of range)
Max Temp: 55.00 (Out of range)
Min Temp: 35.00, Max Temp: 38.00 (Small range)
Min Temp: 48.00, Max Temp: 35.00 (Reversed range)
```

This function does not return any values.

**Function prototype:**

```
void detectAnomalies(const char* sensorData, const char* anomalies);
```

### Compile

```bash
gcc -Wall lab8-10.c lab8-10_main.c -o lab8-10
```

## Task 11: standard streams

Produce your code in `lab8-11.c`

### Instructions

The program below reads two integer numbers and calculate the integer division between them. To complete the program, follow these steps:
_ try to read two integer numbers from the standard input
_ if the reading fails, print the message `Error: invalid input format` in the standard error stream and the program ends
_ if the second number (`num2`) is zero, print the message `Error: division by zero is not allowed` in the standard error stream and the program ends
_ if no errors occur, divide `num1` by `num2` and print the result as `Result: <result>` in the standard output. Note that `<result>` is the calculate result of the integer division

**Requirement:** use `fscanf` for reading and `fprintf` for writing.

### Compile

```bash
gcc -Wall lab8-11.c -o lab8-11
```
