/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
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
    // TODO: initialize a zipcode variable here
    enum Zipcode zipcode = DOWNTOWN;

    // print the zipcode
    printf("Zipcode for Downtown area: %d\n", zipcode);
    
    // return success
    return 0;
}
