/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab12_lib.h"

// function prototypes
Destination* createDestination(const char* name, int days);
void addDestination(Itinerary *itinerary, Destination *destination);

// main program
int main()
{
    // create the itinerary
    Itinerary itinerary = {.tripId = 500, .totalDays = 0, .firstDestination = NULL};

    // create destinations
    Destination *newDestination = createDestination("Paris", 3);
    // TODO: add destination to the itinerary
    addDestination(&itinerary, newDestination);

    newDestination = createDestination("Rome", 4);
    // TODO: add destination to the itinerary
    addDestination(&itinerary, newDestination);

    newDestination = createDestination("Berlin", 2);
    // TODO: add destination to the itinerary
    addDestination(&itinerary, newDestination);

    newDestination = createDestination("Amsterdam", 2);
    // TODO: add destination to the itinerary
    addDestination(&itinerary, newDestination);

    // print the itinerary
    printItinerary(&itinerary);

    // TODO: free the dynamically allocated memory (each destination)
    Destination *current = itinerary.firstDestination;
    while(current->nextDestination != NULL)
    {
        Destination *temp = current;
        current = current->nextDestination;
        free(temp);
    }

    // return success
    return 0;
}

// TODO: implement the createDestination function here
Destination* createDestination(const char* name, int days)
{
    Destination *newDestination = (Destination*)malloc(sizeof(Destination));
    strcpy(newDestination->name, name);
    newDestination->days = days;
    newDestination->nextDestination = NULL;
    return newDestination;
}

// TODO: implement the addDestination function here
void addDestination(Itinerary *itinerary, Destination *destination)
{
    if(itinerary->firstDestination == NULL)
    {
        itinerary->firstDestination = destination;
    }
    else
    {
        Destination *current = itinerary->firstDestination;
        while(current->nextDestination != NULL)
        {
            current = current->nextDestination;
        }
        current->nextDestination = destination;
    }

    itinerary->totalDays += destination->days;
}