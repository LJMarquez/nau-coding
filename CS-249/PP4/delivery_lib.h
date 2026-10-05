#ifndef DELIVERY_LIB_H
#define DELIVERY_LIB_H

// header files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

// global definitions
#define ERROR -1
#define SUCCESS 0

// enum for order categories
enum Category
{
    FOOD = 0,
    DRINKS = 1,
    DESSERTS = 2
};

// class to represent an order
class Order
{
private:
    int id;
    char clientName[50];
    Category category;
    int priority;
    int staffScore;
    char cuisine[50];
    int customerSatisfaction;

public:
    /**
     * Default constructor (needed for arrays)
     */
    Order();

    /**
     * Parameterized constructor
     */
    Order(int id, const char* clientName, Category category, int priority,
          int staffScore, const char* cuisine, int customerSatisfaction);

    // getters
    int getId() const;
    const char* getClientName() const;
    Category getCategory() const;
    int getPriority() const;
    int getStaffScore() const;
    const char* getCuisine() const;
    int getCustomerSatisfaction() const;

    /**
     * Method: print
     * Output argument: prints order details to stdout
     * Return: none
     * Dependencies: iostream
     */
    void print() const;

    /**
     * Method: equals
     * Input argument: another order to compare against
     * Return: true if all fields (except id) match, false otherwise
     * Dependencies: cstring
     */
    bool equals(const Order& other) const;

    /**
     * Method: swap
     * Input argument: another order to swap with
     * Output argument: this order and the other order are swapped
     * Return: none
     * Dependencies: none
     */
    void swap(Order& other);
};

// function prototypes
/**
 * Function: swapOrders (provided)
 * Input argument: two pointer to orders
 * Output argument: swapped orders
 * Return: none
 * Dependencies: Order::swap
 */
void swapOrders(Order* leftOrder, Order* rightOrder);

/**
 * Function: sortOrders
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: array of orders sorted by category
 * Return: none
 * Dependencies: swapOrders (provided)
 */
void sortOrders(Order orders[], int size);

/**
 * Function: findKthHighestPriority
 * Input argument: - array of orders
 *                 - an integer value representing the array size
 *                 - integer value representing k
 * Output argument: none
 * Return: integer value representing the k-th priority
 * Dependencies: mergesort
 */
int findKthHighestPriority(const Order orders[], int size, int k);

/**
 * Function: merge
 * Input argument: - array of integers
 *                 - left, middle and right indexes
 * Output argument: sorted array of integers
 * Return: none
 * Dependencies: none
 */
void merge(int arr[], int left, int mid, int right);

/**
 * Function: mergesort
 * Input argument: - array of integers
 *                 - left and right indexes
 * Output argument: sorted array of integers
 * Return: none
 * Dependencies: mergesort (recursive), merge
 */
void mergeSort(int arr[], int left, int right);

/**
 * Function: containsDuplicateOrder
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: true if there are duplicates, false otherwise
 * Dependencies: Order::equals
 */
bool containsDuplicateOrder(const Order orders[], int size);

/**
 * Function: findTriplets
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: error code when memory allocation fails; success code otherwise
 * Dependencies: quicksort
 */
int findTriplets(const Order orders[], int size);

/**
 * Function: partition
 * Input argument:  - array of integers
 *                  - left and right indexes, representing the range of the
 *                  array to partition
 * Output argument: sorted array
 * Return: the index of the pivot element after partitioning
 * Dependencies: swap
 */
int partition(int arr[], int left, int right);

/**
 * Function: quicksort
 * Input argument:  - array of integers
 *                  - left and right indexes, representing the range of the
 *                  array to partition
 * Output argument: sorted array
 * Return: none
 * Dependencies: partition, quicksort
 */
void quicksort(int arr[], int left, int right);

/**
 * Function: groupOrders
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: array of orders sorted by cuisine
 * Return: none
 * Dependencies: insertionsort, cstring
 */
void groupOrders(Order orders[], int size);

/**
 * Function: insertionsort
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: array of orders sorted by cuisine
 * Return: none
 * Dependencies: cstring
 */
void insertionsort(Order orders[], int size);

/**
 * Function: sortStaffFromOrders
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: none
 * Dependencies: none
 */
void sortStaffFromOrders(Order orders[], int size);

/**
 * Function: displayMenu (provided)
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: none
 */
void displayMenu();

/**
 * Function: readCSV (provided)
 * Input argument: filename, array of orders, a pointer to the array size
 * Output argument: filled array of orders, updated array size
 * Return: success or error code
 * Dependencies: fstream
 */
int readCSV(const char* filename, Order orders[], int* size);

/**
 * Function: printOrders (provided)
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: none
 * Dependencies: Order::print
 */
void printOrders(const Order orders[], int size);

#endif // DELIVERY_LIB_H
