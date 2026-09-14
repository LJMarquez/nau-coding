/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

#include <stdio.h>

// data types
enum Zipcode
{
    DOWNTOWN = 86001,
    DONEYPARK = 86004,
    KACHINA = 86005,
    NAU = 86011,
    BELLEMONT = 86015
};

// main program
int main()
{
    // variable to store user input
    int zipcode;

    // prompt user for input
    printf("Enter a zipcode: ");
    scanf("%d", &zipcode);

    // TODO: determine the area based on the zipcode
    switch(zipcode)
    {
        case DOWNTOWN:
            printf("The zipcode covers the Downtown Flagstaff and surrounding area.\n");
            break;
        case DONEYPARK:
            printf("The zipcode covers the Doney Park and surrounding area.\n");
            break;
        case KACHINA:
            printf("The zipcode covers the Kachina Village and surrounding area.\n");
            break;
        case NAU:
            printf("The zipcode covers the Northern Arizona University and surrounding area.\n");
            break;
        case BELLEMONT:
            printf("The zipcode covers the Bellemont and surrounding area.\n");
            break;
        default:
            printf("Unknown zipcode.\n");
            break;
    }
    

    // return success
    return 0;
}
