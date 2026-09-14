/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// global definitions
#define STR_LEN 100
#define STATE_LEN 3

// data type
enum Zipcode
{
    DOWNTOWN = 86001,
    DONEYPARK = 86004,
    KACHINA = 86005,
    NAU = 86011,
    BELLEMONT = 86015
};

// TODO: use typedef to rename the enum Zipcode to Zipcode
typedef enum Zipcode Zipcode;

// TODO: define the struct Address here
typedef struct Address
{
    char street[STR_LEN];
    char city[STR_LEN];
    char state[STATE_LEN];
    Zipcode zipcode;
} Address;

// TODO: write the function prototype here
void getZipcode(Address *address);

// main program
int main()
{
    // TODO: create a variable to store an address
    Address address;

    printf("Enter street: ");
    // TODO: read the street name from the user input
    fgets(address.street, STR_LEN, stdin);
    address.street[strcspn(address.street, "\n")] = '\0';

    printf("Enter city: ");
    // TODO: read the city name from the user input
    fgets(address.city, STR_LEN, stdin);
    address.city[strcspn(address.city, "\n")] = '\0';
    
    printf("Enter state (i.e., AZ): ");
    // TODO: read the two-digit state acronym from the user input
    scanf("%2s", address.state);
    

    printf("Enter zipcode: ");
    // TODO: read the zipcode from the user input
    getZipcode(&address);
    
    
    // show the data
    printf("Address: %s, %s - %s %d", address.street, address.city, address.state, address.zipcode);
    
    // return success
    return 0;
}

// TODO: implement the function here
void getZipcode(Address *address)
{
    int zipcode;
    int validZipcode = 0;

    while (!validZipcode)
    {
        scanf("%d", &zipcode);

        switch (zipcode)
        {
            case DOWNTOWN:
            case DONEYPARK:
            case KACHINA:
            case NAU:
            case BELLEMONT:
                validZipcode = 1;
                break;
            default:
                address->zipcode = 0;
                printf("Zipcode not recognized, please try again.\n");
                break;
        }
    }

    address->zipcode = (Zipcode)zipcode;
}