# Lab 11 | Structs and Enums

## Task 1: enum definition

Produce your code in `lab11-1.h`

### Instructions

Define an enumeration named `TaskType` containing the categories `WORK`, `SCHOOL`, `PERSONAL`, `CHORES`, `SOCIAL`, and `MISCELLANEOUS`.

**Requirement:** do not use `typedef` for this problem; do not assign values to the categories (use the default).

## Task 2: enum definition

Produce your code in `lab11-2.h`

### Instructions

Define an enumeration named `Currency` containing the categories `PENNY`, `NICKEL`, `DIME`, `QUARTER`, `DOLLAR` and assign them with their value in cents (i.e., `1`, `5`, `10`, `25`, and `100`, respectively).

**Requirement:** do not use `typedef` for this problem.

## Task 3: enum declaration

Produce your code in `lab11-3.c`

### Instructions

Consider the `enum Zipcode` defined below.
In the `main` function, create a statement that declares a variable named `zipcode` and initializes it with the zipcode for the downtown area.

### Compile

```bash
gcc -Wall lab11-3.c -o lab11-3
```

## Task 4: enum usage

Produce your code in `lab11-4.c`

### Instructions

Consider the `enum Zipcode` defined below.
In the `main` function, create a `switch-case` block that evaluates the user-provided `zipcode` using the known `enum Zipcode` categories and prints one of the following messages:

- _The zipcode covers the Downtown Flagstaff and surrounding area._
- _The zipcode covers the Doney Park and surrounding area._
- _The zipcode covers the Kachina Village and surrounding area._
- _The zipcode covers the Northern Arizona University and surrounding area._
- _The zipcode covers the Bellemont and surrounding area._

If the user informs an invalid zipcode (no matching categories), the program prints the message _Unknown zipcode._

### Compile

```bash
gcc -Wall lab11-4.c -o lab11-4
```

## Task 5: length category

Produce your code in `lab11-5.c`

### Instructions

Complete the program below to allow the selection of file mode of operation based on an `enum` category.
To achieve that, define an `enum FileMode` with the categories `READ`, `OVERWRITE`, `APPEND`, and `NUM_MODES`.
Use `typedef` to rename the `enum FileMode` to `FileMode`.
Then, in the `main` function, do the following:

- create an array of strings (`char *`) of size `NUM_MODES` containing the file mode of operation for each `enum FileMode` category **in the same order** as they appear in the `enum`. For example, if `READ` is the first `enum` category, then the index `0` in the array must be `"r"`. Use `"w"` for `OVERWRITE` and `"a"` for `APPEND`.
- open a file stream with the `OVERWRITE` mode, by using the string from the array of modes in the `OVERWRITE` position
- if the file is successfully open, print the following message: \__File opened in mode '\<MODE\>'_ where \<MODE\> is the selected mode of operation from the array of modes.

### Compile

```bash
gcc -Wall lab11-5.c -o lab11-5
```

## Task 6: enum and structs

Produce your code in `lab11-6.c`

### Instructions

The program below obtains the address information from the user and print it in the following format:

> \<STREET\>, \<CITY\> - \<ST\> \<ZIP\>

where the `STREET` is the street name, `CITY` is the city name, `ST` is the two-character state's acronym, and `ZIP` is the addresses zipcode. For example:

    > _1249 S Knoles Drive, Flagstaff - AZ 86011_

Complete the program so it works as expected. To achive that, do the following:

- redefine the `enum Zipcode` to be named `Zipcode` using `typedef`
- define a `struct Address` and redefine it to be named `Address`. The struct must include as members: three arrays of characters, `street`, `city`, and `state`, the first two of size `STR_LEN` and the last one of size `STATE_LEN`; and a `Zipcode` variable to store the zipcode.
- define the prototype of a `void` function named `getZipcode` that takes in a pointer to an `Address` variable
- In the `main`:
  - create an `Address` variable to store the user-provided address
  - read the `.street`, `.city` and `.state` member values from the user input. Since `.street` an `.city` may contain spaces (e.g., _1249 S Knoles Drive_), use `fgets` to read the input. Do not forget to remove the newline character from the end of the string.
  - call the function `getZipcode` to read a valid zipcode value
- Finally, implement the function `getZipcode`. The function does the following:
  - reads an integer number from the user input
  - using a `switch-case` block, it validates the informed zipcode by matching all the known cases (i.e., `DOWNTOWN`, `DONEYPARK`, etc) without taking any action. After matching the last case, a `break;` statement ends the valid cases.
  - in the `default` case (i.e., none of the cases matches the informed zipcode), reset the provided zipcode to zero, print the message _Zipcode not recognized, please try again._ and end the case with a break.
  - repeat these steps until the user types a value that matches one of the recognized cases.

**Disclaimer:** this program does not validate the city, street, and state and does not crosscheck the zipcode with the other address data.

### Compile

```bash
gcc -Wall lab11-6.c -o lab11-6 -lm
```

## Task 7: enum and structs

Produce your code in `lab11-7.c`

### Instructions

The program below obtains weather data from a file called `weatherData.csv` and prints the data as the example below:

```
Weather Data:
25.50C with 60.00% humidity and Sunny
18.20C with 80.00% humidity and Rainy
22.00C with 50.00% humidity and Cloudy
-5.00C with 90.00% humidity and Snowy
-3.40C with 85.00% humidity and Unknown
```

Complete the program so it works as expected. To achive that, do the following:

- define an `enum WeatherCondition` with the categories `SUNNY`, `RAINY`, `CLOUDY`, `SNOWY`, and `NUM_CONDITIONS`. Use a `typedef` to rename it to `WeatherCondition`
- define a `struct Weather` and redefine it to be named `Weather`. The struct must include as members: a float variable to represent the `temperature`, a float variable to represent the `humidity`, and a `WeatherCondition` variable to represent the `condition`.
- define the prototype of a function named `getWeatherText` that takes in a `WeatherCondition` variable and returns a constant string (`char *`)
- In the `main`:
  - open the file `weatherData.csv` for reading, name the file stream variable as `file`
  - if successful, create an array of `Weather` of size `DATA_SIZE`
  - create an integer variable to store a weather condition before validation
  - read each line of the file, considering that the file is in this format: `temperature,humidity,condition` (e.g., `25.5,60,0`). Store the data in each line as one index of the `Weather` array. You can read the temperature and humidity directly into the array, however, read the condition into the integer variable for validation.
  - validate the condition by checking if it is a value between zero and less than `NUM_CONDITIONS`. If the condition is valid, \*\*cast it to `WeatherCondition` type and add it to the array. Otherwise, print the message `Invalid condition in file. Defaulting to Unknown.` and set the condition value for this entry as `NUM_CONDITIONS`.
  - after reading the entire file, close the file stream
  - print the data from each index as shown in the sampe output above. To print the condition as a text, call the `getWeatherText` function
- Finally, implement the function `getWeatherText`. The function prints a given `WeatherCondition` as a string, rather than an integer. Do the following:
  - create a `switch-case` statement that checks the `WeatherCondition` received as argument.
  - for each valid case (i.e., `SUNNY`, `RAINY`, `CLOUDY`, and `SNOWY`), return a string with the text representing the category. For example, if the condition matches `SUNNY`, return `"Sunny"`.
  - if the condition does not match any valid case, the default case is met and it returns `Unknown`.

### Compile

```bash
gcc -Wall lab11-7.c -o lab11-7 -lm
```

## Task 8: functions with enums

Produce your code in `lab11-8.c`

### Instructions

Define an `enum AccountType` with the categories `SAVINGS`, `CHECKING`, and `BUSINESS`. Use a `typedef` to redefine the `enum AccountType` to `AccountType `.
Then, define a `struct BankAccount` to represent a bank account and redefine it using `typedef` to `Account`. The member include an integer representing the `accountNumber`, an integer representing the `routingNumber`, an array of characters of size `STR_SIZE` representing the account `holder`, an `AccountType` representing the `accountType`, and a `double` variable representing the `balance`.
Finally, create a constructor function named `openAccount` that, given a pointer to a bank account and all the required account data, initializes the argument `account` with the provided data.

**Function prototype:**

```c
void createAccount(Account *account, int accountNumber, int routingNumber, const char *holder, AccountType type, double initialBalance);
```

### Compile

```bash
gcc -Wall lab11-8.c lab11-8_main.c -o lab11-8 -lm
```

## Task 9: functions with enums

Produce your code in `lab11-9.c`

### Instructions

Define an `enum DocType` with the categories `SSN`, `US_PASSPORT`, `AZ_DRIVER_LICENSE`, `CA_DRIVER_LICENSE`, and `NUM_DOCUMENT_TYPES` with default values. Use a `typedef` to redefine the `enum DocType` to `DocType `.
Create a function named `validateDocFormat` that, given a `DocType` and a constant string representing a document number, validates whether the document number is in the correct format.
The function returns `true` if the string is a valid document number or `false` otherwise. Consider that the function knows the following formats:

- `SSN`: nine numbers separated by a dash (`-`), for example: `999-88-7777` (11 characters in total)
- `US_PASSPORT` and `AZ_DRIVER_LICENSE`: one letter followed by eight numbers, for example: `A12345678` (9 characters in total)
- `CA_DRIVER_LICENSE`: one letter followed by seven numbers, for example: `B1234567` (8 characters in total)

**Function prototype:**

```c
bool validateDocFormat(DocType type, const char *docNumber);
```

**Tip:** you can use the functions `isalpha` and `isdigit` from `ctype.h` to check whether a given character is an letter or a number, respectively.

### Compile

```bash
gcc -Wall lab11-9.c lab11-9_main.c -o lab11-9 -lm
```
