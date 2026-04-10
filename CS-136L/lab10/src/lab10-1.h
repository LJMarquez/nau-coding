/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// global definitions
#define STR_SIZE 100
#define ISBN_SIZE 13

// TODO: define your struct here
struct Book
{
    char title[STR_SIZE];
    char ISBN[ISBN_SIZE];
    char author[STR_SIZE];
    int yearsPublished;
};