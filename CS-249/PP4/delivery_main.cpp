// header files
#include "delivery_lib.h"

// main program
int main()
{
    // declare an array of orders with a size of 15
    Order orders[15];

    // variable to hold the number of orders loaded
    int size = 0;

    // initialize orders from CSV file
    if (readCSV("orders.csv", orders, &size) != 0)
    {
        // print an error message if loading fails
        cout << "Failed to load orders from CSV." << endl;
        return ERROR;
    }

    // create a variable to hold the user's menu choice
    int choice = 0;

    // Infinite loop to keep the menu active
    while (choice != 9)
    {
        // display the menu options to the user
        displayMenu();
        // prompt the user to choose an option
        cout << "Choose an option: ";
        // read the user's choice from input
        cin >> choice;
        // choose the action based on the user's choice
        switch (choice)
        {
            // case for 1. View orders
            case 1:
                // print the orders
                printOrders(orders, size);
                // end of case
                break;
            // case for resetting orders
            case 2:
                // read the orders from file again
                readCSV("orders.csv", orders, &size);
                // print a confirmation message
                cout << "Orders reset to original." << endl;
                // end of case
                break;
            // case for sorting orders
            case 3:
                // sort the orders by category
                sortOrders(orders, size);
                // print a confirmation message
                cout << "Orders sorted by category." << endl;
                // print the orders
                printOrders(orders, size);
                // end of case
                break;
            // case for finding k-th highest priority
            case 4:
            {
                // variable to hold the user input for k
                int k;
                // prompt for k
                cout << "Enter k: ";
                // read k from input
                cin >> k;
                // get the k-th highest priority
                int kthPriority = findKthHighestPriority(orders, size, k);
                // print the result
                cout << "The " << k << "-th highest priority is " << kthPriority << endl;
                // end of case
                break;
            }
            // case for detecting duplicate orders
            case 5:
                // if there are duplicate orders
                if (containsDuplicateOrder(orders, size))
                {
                    // print message if duplicates exist
                    cout << "End of duplicated order's list." << endl;
                }
                else
                {
                    // print message if no duplicates exist
                    cout << "There are no duplicate orders to show." << endl;
                }
                // end of case
                break;
            // case for finding triplets
            case 6:
                // print a message
                cout << "Unique triplets that sum to zero:" << endl;
                // find the triplets
                findTriplets(orders, size);
                // end of case
                break;
            // case for grouping orders by cuisine
            case 7:
                // group orders by cuisine
                groupOrders(orders, size);
                // print a message
                cout << endl << "Orders sorted by cuisine:" << endl;
                // print the orders
                printOrders(orders, size);
                // end of case
                break;
            // case for sorting staff by performance
            case 8:
                // sort staff by score
                sortStaffFromOrders(orders, size);
                // end of case
                break;
            // case for exiting the program
            case 9:
                // print a message
                cout << "Exiting..." << endl;
                // end of case
                break;
            default: // Case for handling invalid options
                cout << "Invalid option, please try again." << endl;
        }
    }
    // return success
    return 0;
}
