/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// global definitions
#define STR_SIZE 100

// TODO: define the struct Destination
typedef struct Destination
{
    char name[STR_SIZE];
    int days;
    struct Destination *nextDestination;
} Destination;

// TODO: define the struct Itinerary
typedef struct Itinerary
{
    int tripId;
    int totalDays;
    Destination *firstDestination;
} Itinerary;



// main program
int main()
{
    // create destinations without a nextDestination (NULL)
    Destination paris = {.name = "Paris", .days = 3, .nextDestination = NULL};
    Destination rome = {.name = "Rome", .days = 4, .nextDestination = NULL};
    Destination berlin = {.name = "Berlin", .days = 2, .nextDestination = NULL};
    Destination amsterdam = {.name = "Amsterdam", .days = 2, .nextDestination = NULL};

    // TODO: link Rome as the next destination after Paris
    paris.nextDestination = &rome;

    // TODO: link Berlin as the next destination after Rome
    rome.nextDestination = &berlin;

    // TODO: link Amsterdam as the next destination after Berlin
    berlin.nextDestination = &amsterdam;

    // create an itinerary
    Itinerary itinerary = {.tripId = 500, .totalDays = 0, .firstDestination = NULL};

    // print the itinerary
    printf("Itinerary %d: ", itinerary.tripId);

    // TODO: link Paris as the first destination of the itinerary
    itinerary.firstDestination = &paris;

    // TODO: create a pointer to destination, set it to the itinerary's first destination
    Destination *destinationPtr = itinerary.firstDestination;

    // TODO: traverse the destinations while there is still a new destination
    while(destinationPtr != NULL)
    {
        // TODO: accumulate the number of days in the current destination to 
        //  the itinerary's total number of days
        itinerary.totalDays += destinationPtr->days;        

        // TODO: print the current destination's name
        printf("%s", destinationPtr->name);

        // TODO: if the current destination has a next destination (the nextDestination is not NULL)
        if(destinationPtr->nextDestination != NULL)
        {
            printf(" -> ");
        }

        // TODO: move the current destination to its next destination
        destinationPtr = destinationPtr->nextDestination;
    }

    // TODO: print the itinerary's total number of days
    printf("\nTrip length: %d days", itinerary.totalDays);

    // return success
    return 0;
}
