// delivery_lib.cpp
#include "delivery_lib.h"

// ========================== Order Class Methods ==========================

/**
 * Default constructor (needed for arrays)
 */
Order::Order()
{
    // initialize all fields to default values
    id = 0;
    clientName[0] = '\0';
    category = FOOD;
    priority = 0;
    staffScore = 0;
    cuisine[0] = '\0';
    customerSatisfaction = 0;
}

/**
 * Parameterized constructor
 */
Order::Order(int id, const char* clientName, Category category, int priority,
             int staffScore, const char* cuisine, int customerSatisfaction)
{
    // TODO: set the id
    this->id = id;
    // TODO: copy the client name (use strncpy)
    strncpy(this->clientName, clientName, sizeof(this->clientName) - 1);
    this->clientName[sizeof(this->clientName) - 1] = '\0';
    // TODO: set the category
    this->category = category;
    // TODO: set the priority
    this->priority = priority;
    // TODO: set the staff score
    this->staffScore = staffScore;
    // TODO: copy the cuisine (use strncpy)
    strncpy(this->cuisine, cuisine, sizeof(this->cuisine) - 1);
    this->cuisine[sizeof(this->cuisine) - 1] = '\0';
    // TODO: set the customer satisfaction
    this->customerSatisfaction = customerSatisfaction;
}

// getters
int Order::getId() const { return id; }
const char* Order::getClientName() const { return clientName; }
Category Order::getCategory() const { return category; }
int Order::getPriority() const { return priority; }
int Order::getStaffScore() const { return staffScore; }
const char* Order::getCuisine() const { return cuisine; }
int Order::getCustomerSatisfaction() const { return customerSatisfaction; }

/**
 * Method: print
 * Output argument: prints order details to stdout
 * Return: none
 * Dependencies: iostream
 */
void Order::print() const
{
    // print details of this order
    cout << "Order #" << id << " - " << clientName
         << ", Category: " << category
         << ", Priority: " << priority
         << ", Staff Score: " << staffScore
         << ",Cuisine: " << cuisine
         << ", Customer Satisfaction Score: " << customerSatisfaction << endl;
}

/**
 * Method: equals
 * Input argument: another order to compare against
 * Return: true if all fields (except id) match, false otherwise
 * Dependencies: cstring
 */
bool Order::equals(const Order& other) const
{
    // compare all fields except id
    return strcmp(clientName, other.clientName) == 0 &&
           category == other.category &&
           priority == other.priority &&
           staffScore == other.staffScore &&
           strcmp(cuisine, other.cuisine) == 0 &&
           customerSatisfaction == other.customerSatisfaction;
}

/**
 * Method: swap
 * Input argument: another order to swap with
 * Output argument: this order and the other order are swapped
 * Return: none
 * Dependencies: none
 */
void Order::swap(Order& other)
{
    // temporary order receives this order
    Order temp = *this;
    // this order is set to the other order
    *this = other;
    // the other order is set to the temporary variable
    other = temp;
}

// ========================== Free Functions ==========================

/**
 * Function: swapOrders (provided)
 * Input argument: two pointer to orders
 * Output argument: swapped orders
 * Return: none
 * Dependencies: Order::swap
 */
void swapOrders(Order* leftOrder, Order* rightOrder)
{
    // delegate to the Order swap method
    leftOrder->swap(*rightOrder);
}

/**
 * Function: sortOrders
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: array of orders sorted by category
 * Return: none
 * Dependencies: swapOrders (provided)
 */
void sortOrders(Order orders[], int size)
{
    // TODO: set food, drink and dessert indexes
    int foodIndex = 0;
    int drinkIndex = 0;
    int dessertIndex = size - 1;
    // TODO: flag for invalid categories
    bool invalidCategory = false;

    // TODO: while the index for drinks hasn't met the desserts
    while(drinkIndex <= dessertIndex)
    {
        // TODO: if the order at the drink position is food
        if(orders[drinkIndex].getCategory() == FOOD)
        {
            // TODO: swap the food and drink positions (use swapOrders)
            swapOrders(&orders[drinkIndex], &orders[foodIndex]);
            // TODO: increment food and drink indexes (both are placed)
            foodIndex++;
            drinkIndex++;
        }
        // TODO: otherwise, if the order at the drink position is a drink
        else if(orders[drinkIndex].getCategory() == DRINKS)
        {
            // TODO: it is in the correct place, increment the drink index
            drinkIndex++;
        // TODO: otherwise, if the order at the drink position is a dessert
        }
        else if(orders[drinkIndex].getCategory() == DESSERTS)
        {
            // TODO: swap drink and dessert position (use swapOrders)
            swapOrders(&orders[drinkIndex], &orders[dessertIndex]);
            // TODO: decrement the dessert index (dessert is placed)
            dessertIndex--;
        }
        // TODO: otherwise, category is invalid
        else
        {
            // TODO: print a message
            cout << "Invalid Category";
            // TODO: mark invalid category found
            invalidCategory = true;
            // TODO: move to the next item
            drinkIndex++;
        }
    }

    // TODO: if there is an invalid category
    if(invalidCategory)
    {
        // TODO: print a message
        cout << "Invalid category found in the orders.";
    }

}

/**
 * Function: findKthHighestPriority
 * Input argument: - array of orders
 *                 - an integer value representing the array size
 *                 - integer value representing k
 * Output argument: none
 * Return: integer value representing the k-th priority or an error code
 * Dependencies: mergesort
 */
int findKthHighestPriority(const Order orders[], int size, int k)
{
    // TODO: if the array is empty or k is invalid
    if(orders == nullptr || size <= 0 || k < 1)
    {
        // TODO: return error code
        return ERROR;
    }

    // TODO: allocate memory for the array of priorities
    int* priorities = new int[size];

    // TODO: traverse the array of orders
    for(int i = 0; i < size; i++)
    {
        // TODO: copy the current priority to the array of priorities
        priorities[i] = orders[i].getPriority();
    }

    // TODO: sort the priorities (use mergeSort)
    mergeSort(priorities, 0, size - 1);

    // TODO: create a variable to count the unique priorities
    int uniquePriorities = 0;
    // TODO: create a variable to hold the last priority
    int lastPriority = 0;
    // TODO: create a variable to hold the value of the kth priority
    int kthPriority = ERROR;

    // TODO: traverse the array of priorities backwards
    for(int i = size - 1; i >= 0; i--)
    {
        // TODO: if the current priority is not the same as the last priority
        if(i == size - 1 || priorities[i] != lastPriority)
        {
            // TODO: count a unique value
            uniquePriorities++;
            // TODO: update the value of the last priority
            lastPriority = priorities[i];

            // TODO: if we found the kth priority
            if(uniquePriorities == k)
            {
                // TODO: set the kth priority to the current value
                kthPriority = priorities[i];
                // TODO: free the array of priorities (use delete[])
                delete[] priorities;
                // TODO: return the k-th highest unique priority
                return kthPriority;
            }
        }
    }

    // TODO: free memory before returning error (use delete[])
    delete[] priorities;
    // TODO: return error if got here without returning
    return ERROR;
}

/**
 * Function: merge
 * Input argument: - array of integers
 *                 - left, middle and right indexes
 * Output argument: sorted array of integers
 * Return: none
 * Dependencies: none
 */
void merge(int arr[], int left, int mid, int right)
{
    // TODO: set the boundaries for left and right arrays
    int leftBound = mid - left + 1;
    int rightBound = right - mid;

    // TODO: allocate the left array (use new)
    int* leftArray = new int[leftBound];

    // TODO: allocate the right array (use new)
    int* rightArray = new int[rightBound];

    // TODO: traverse the subarray to the left
    for(int i = 0; i < leftBound; i++)
    {
        // TODO: copy the values to the left buffer
        leftArray[i] = arr[left + i];
    }

    // TODO: traverse the subarray to the right
    for(int i = 0; i < rightBound; i++)
    {
        // TODO: copy the values to the right buffer
        rightArray[i] = arr[mid + 1 + i];
    }

    // TODO: start the indexes to control the positions for each array
    int leftIndex = 0;
    int rightIndex = 0;
    int arrayIndex = left;

    // TODO: while both buffers still have elements
    while(leftIndex < leftBound && rightIndex < rightBound)
    {
        // TODO: if data in the left buffer is less/equal to data in the right buffer
        if(leftArray[leftIndex] <= rightArray[rightIndex])
        {
            // TODO: array in the current position is set to the left buffer
            arr[arrayIndex] = leftArray[leftIndex];
            // TODO: increment the index for the left buffer
            leftIndex++;
        }
        // TODO: otherwise
        else
        {
            // TODO: array in the current position is set to the right buffer
            arr[arrayIndex] = rightArray[rightIndex];
            // TODO: increment the index for the right buffer
            rightIndex++;
        }
        // TODO: increment the array index
        arrayIndex++;
    }

    // TODO: while it is not the end of the left buffer
    while(leftIndex < leftBound)
    {
        // TODO: copy the remainder elements to the array
        arr[arrayIndex] = leftArray[leftIndex];
        // TODO: increment the index for left buffer
        leftIndex++;
        // TODO: increment the index for the array
        arrayIndex++;
    }

    // TODO: while it is not the end of the right buffer
    while(rightIndex < rightBound)
    {
        // TODO: copy the remainder elements to the array
        arr[arrayIndex] = rightArray[rightIndex];
        // TODO: increment the index for the right buffer
        rightIndex++;
        // TODO: increment the index for the array
        arrayIndex++;
    }

    // TODO: free the left buffer (use delete[])
    delete[] leftArray;
    // TODO: free the right buffer (use delete[])
    delete[] rightArray;
}

/**
 * Function: mergesort
 * Input argument: - array of integers
 *                 - left and right indexes
 * Output argument: sorted array of integers
 * Return: none
 * Dependencies: mergesort (recursive), merge
 */
void mergeSort(int arr[], int left, int right)
{
    // TODO: if the search space is not empty
    if(left < right)
    {
        // TODO: calculate the middle element
        int mid = left + (right - left) / 2;
        // TODO: sort the array to the left (recursive call)
        mergeSort(arr, left, mid);
        // TODO: sort the array to the right (recursive call)
        mergeSort(arr, mid + 1, right);
        // TODO: merge left and right arrays
        merge(arr, left, mid, right);
    }

}

/**
 * Function: containsDuplicateOrder
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: true if there are duplicates, false otherwise
 * Dependencies: Order::equals
 */
bool containsDuplicateOrder(const Order orders[], int size)
{
    // TODO: if there is not enough orders
    if(size < 2)
    {
        // TODO: there are no duplicates, return false
        return false;
    }

    // TODO: assume there are no duplicate orders
    bool duplicateOrders = false;

    // TODO: traverse the array selecting one key order at a time
    for(int i = 0; i < size; i++)
    {
        // TODO: for each element, compare to all the other indexes
        for(int j = i + 1; j < size; j++)
        {
            // TODO: if key order is equal to the compared order (use equals)
            if(orders[i].equals(orders[j]))
            {
                // TODO: print the duplicate order
                cout << "Duplicate found: ";
                orders[i].print();
                // TODO: set found to true
                duplicateOrders = true;
            }
        }
    }

    // TODO: return whether duplicates are found
    return duplicateOrders;
}

/**
 * Function: findTriplets
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: error code when memory allocation fails; success code otherwise
 * Dependencies: quicksort
 */
int findTriplets(const Order orders[], int size)
{
    // TODO: allocate an array to store the scores (use new)
    int* scores = new int[size];

    // TODO: traverse the array of orders
    for(int i = 0; i < size; i++)
    {
        // TODO: fill the current score with the customer satisfaction scores
        scores[i] = orders[i].getCustomerSatisfaction();
    }

    // TODO: sort the scores array (use quicksort)
    quicksort(scores, 0, size - 1);

    // TODO: traverse the array up to the second to last element
    for(int i = 0; i < size - 1; i++)
    {
        // TODO: assume a value is not a duplicate
        bool isDuplicate = false;
        // TODO: if it is not the first value and the score is equal to its previous
        if(i != 0 && scores[i] == scores[i - 1])
        {
            // TODO: set the duplicate to true
            isDuplicate = true;
        }

        // TODO: if the value is not a duplicate
        if(!isDuplicate)
        {
            // TODO: set the left index starting at next index
            int leftindex = i + 1;
            // TODO: set the right index starting at the end
            int rightIndex = size - 1;

            // TODO: while left doesn't meet right
            while(leftindex < rightIndex)
            {
                // TODO: sum the current score with data at left and right indexes
                int sum = scores[i] + scores[leftindex] + scores[rightIndex];
                // TODO: if the sum is zero
                if(sum == 0)
                {
                    // TODO: it is a triplet, print a message
                    cout << "Triplet found: [" << scores[i] << ", " << scores[leftindex] << ", " << scores[rightIndex] << "]" << endl;
                    // TODO: while the next left index is a duplicate
                    while(leftindex + 1 < rightIndex && scores[leftindex] == scores[leftindex + 1])
                    {
                        // TODO: skip the next index
                        leftindex++;
                    }
                    // TODO: while the right index is a duplicate
                    while(rightIndex - 1 > leftindex && scores[rightIndex] == scores[rightIndex - 1])
                    {
                        // TODO: skip the right index
                        rightIndex--;
                    }
                    // TODO: move the left and right indexes
                    leftindex++;
                    rightIndex--;
                }
                // TODO: otherwise, if sum is too small (less than 0)
                else if(sum < 0)
                {
                    // TODO: increment left to make the sum bigger
                    leftindex++;
                }
                // TODO: otherwise, the sum is too high (greater than 0)
                else
                {
                    // TODO: decrement right to make the sum smaller
                    rightIndex--;
                }
            }
        }
    }

    // TODO: free the array of scores (use delete[])
    delete[] scores;
    // TODO: return a success code
    return SUCCESS;
}

/**
 * Function: partition
 * Input argument:  - array of integers
 *                  - left and right indexes, representing the range of the
 *                  array to partition
 * Output argument: array partitioned at the pivot value
 * Return: the index of the pivot element after partitioning
 * Dependencies: none
 */
int partition(int arr[], int left, int right)
{
    // TODO: choose the last element as the pivot
    int pivot = arr[right];

    // TODO: create an index for the smaller element
    int smallerIndex = left - 1;
    // TODO: traverse the array from left to right indexes
    for(int i = left; i < right; i++)
    {
        // TODO: if the current element is smaller than or equal to the pivot
        if(arr[i] <= pivot)
        {
            // TODO: increment the index for the smaller element
            smallerIndex++;
            // TODO: swap the smaller element with the larger element
            int temp = arr[smallerIndex];
            arr[smallerIndex] = arr[i];
            arr[i] = temp;
        }
    }

    // TODO: swap the pivot element with the element at index i + 1
    int temp = arr[smallerIndex + 1];
    arr[smallerIndex + 1] = arr[right];
    arr[right] = temp;

    // TODO: return the pivot position
    return smallerIndex + 1;
}

/**
 * Function: quicksort
 * Input argument:  - array of integers
 *                  - left and right indexes, representing the range of the
 *                  array to partition
 * Output argument: sorted array
 * Return: none
 * Dependencies: partition, quicksort
 */
void quicksort(int arr[], int left, int right)
{
    // TODO: if the search space is not empty
    if(left < right)
    {
        // TODO: partition the array and get the pivot index
        int pivotIndex = partition(arr, left, right);
        // TODO: recursively sort the array to the left
        quicksort(arr, left, pivotIndex - 1);
        // TODO: recursively sort the array to the right
        quicksort(arr, pivotIndex + 1, right);
    }

}

/**
 * Function: groupOrders
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: array of orders sorted by cuisine
 * Return: none
 * Dependencies: insertionsort, cstring
 */
void groupOrders(Order orders[], int size)
{
    // TODO: sort the orders by cuisine (use insertionsort)
    insertionsort(orders, size);

    // TODO: create an array to store whether each order was visited (use new)
    bool* visited = new bool[size];
    // TODO: traverse the array of visited
    for(int i = 0; i < size; i++)
    {
        // TODO: assume the current position is not visited at first
        visited[i] = false;
    }

    // TODO: print an initial message
    cout << "Grouped Orders by Cuisine:\n";
    // TODO: traverse the array of orders
    for(int i = 0; i < size; i++)
    {
        // TODO: if the current order is not visited
        if(!visited[i])
        {
            // TODO: print cuisine name
            cout << orders[i].getCuisine() << ":\n";
            // TODO: mark as visited
            visited[i] = true;
            orders[i].print();
            // TODO: traverse the array of orders starting at the next from key order
            for(int j = i + 1; j < size; j++)
            {
                // TODO: if the order is not visited and it is equal to the key order
                if(!visited[j] && strcmp(orders[i].getCuisine(), orders[j].getCuisine()) == 0)
                {
                    // TODO: print the order
                    orders[j].print();
                    // TODO: mark as visited
                    visited[j] = true;
                }
            }
            // TODO: cosmetic
            cout << "\n";
        }
    }

    // TODO: free the visited array (use delete[])
    delete[] visited;
}

/**
 * Function: insertionsort
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: array of orders sorted by cuisine
 * Return: none
 * Dependencies: cstring
 */
void insertionsort(Order orders[], int size)
{
    // TODO: traverse the array starting at index 1
    for(int i = 1; i < size; i++)
    {
        // TODO: store the current order in a temporary variable
        Order currentOrder = orders[i];

        // TODO: start an index to traverse the sorted sub-array backwards
        int j = i - 1;

        // TODO: while there are elements to compare and the cuisine is different
        //   from the current order's cuisine
        while(j >= 0 && strcmp(orders[j].getCuisine(), currentOrder.getCuisine()) > 0)
        {
            // TODO: shift orders to the right
            orders[j + 1] = orders[j];
            // TODO: move to the next order (backwards)
            j--;
        }

        // TODO: insert the current order into its correct position
        orders[j + 1] = currentOrder;
    }

}

/**
 * Function: sortStaffFromOrders
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: none
 * Dependencies: none
 */
void sortStaffFromOrders(Order orders[], int size)
{
    // TODO: create arrays to hold staff names and scores (use new)
    char** names = new char*[size];
    int* scores = new int[size];

    // TODO: traverse the array of names and scores
    for(int i = 0; i < size; i++)
    {
        // TODO: copy them to the newly created arrays
        names[i] = new char[strlen(orders[i].getClientName()) + 1];
        strcpy(names[i], orders[i].getClientName());
        scores[i] = orders[i].getStaffScore();
    }

    // TODO: traverse the arrays
    for(int i = 0; i < size - 1; i++)
    {
        // TODO: set the maximum index to the key index
        int maxIndex = i;
        // TODO: traverse the array starting at current index + 1
        for(int j = i + 1; j < size; j++)
        {
            // TODO: if the current score is greater than the key score
            if(scores[j] > scores[maxIndex])
            {
                // TODO: update the maximum index
                maxIndex = j;
            }
        }
        // TODO: swap the key score with the maximum score
        int tempScore = scores[i];
        scores[i] = scores[maxIndex];
        scores[maxIndex] = tempScore;
        // TODO: swap the key name with the corresponding maximum score's name
        char* tempName = names[i];
        names[i] = names[maxIndex];
        names[maxIndex] = tempName;
    }

    // TODO: traverse the arrays
    for(int i = 0; i < size; i++)
    {
        // TODO: print the staff and their score
        cout << names[i] << ": " << scores[i] << "\n";
        delete[] names[i];
    }

    // TODO: free the dynamically allocated arrays (use delete[])
    delete[] names;
    delete[] scores;
}

/**
 * Function: displayMenu (provided)
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: none
 */
void displayMenu()
{
    // print the title of the order management system
    cout << endl << "QuickBite Order Management System" << endl;
    // print the option to view orders
    cout << "1. View Orders" << endl;
    // print the option to reset orders to the original state
    cout << "2. Reset Orders to Original" << endl;
    // print the option to sort orders by category
    cout << "3. Sort Orders by Category" << endl;
    // print the option to find the k-th highest priority order
    cout << "4. Find k-th Highest Priority" << endl;
    // print the option to detect duplicate orders
    cout << "5. Detect Duplicate Orders" << endl;
    // print the option to find route triplets among orders
    cout << "6. Find Customer Service Score Triplets" << endl;
    // print the option to group orders by cuisine
    cout << "7. Sort and Group Orders by Cuisine" << endl;
    // print the option to sort staff by performance
    cout << "8. Print Staff by Performance" << endl;
    // print the option to exit the program
    cout << "9. Exit" << endl;
}

/**
 * Function: readCSV (provided)
 * Input argument: filename, array of orders, a pointer to the array size
 * Output argument: filled array of orders, updated array size
 * Return: success or error code
 * Dependencies: fstream
 */
int readCSV(const char* filename, Order orders[], int* size)
{
    // open the file for reading
    ifstream file(filename);
    // if the file is not open
    if (!file.is_open())
    {
        // print the error
        cerr << "Failed to open file" << endl;
        // return the error code
        return ERROR;
    }

    // start an index at 0
    int i = 0;
    // temporary variables for parsing
    int id, categoryInt, priority, staffScore, customerSatisfaction;
    char clientName[50], cuisine[50];
    char comma;

    // while there's data to read in the file
    while (file >> id)
    {
        file >> comma; // consume comma after id
        file.getline(clientName, 50, ',');
        file >> categoryInt >> comma;
        file >> priority >> comma;
        file >> staffScore >> comma;
        file.getline(cuisine, 50, ',');
        file >> customerSatisfaction;

        // construct the order using the parameterized constructor
        orders[i] = Order(id, clientName, (Category)categoryInt, priority,
                          staffScore, cuisine, customerSatisfaction);

        // increment the index
        i++;
    }
    // set the size pointer to index
    *size = i;
    // close the file
    file.close();
    // return success
    return SUCCESS;
}

/**
 * Function: printOrders (provided)
 * Input argument: array of orders, an integer value representing the array size
 * Output argument: none
 * Return: none
 * Dependencies: Order::print
 */
void printOrders(const Order orders[], int size)
{
    // traverse the array
    for (int i = 0; i < size; i++)
    {
        // print details of each order using the Order print method
        orders[i].print();
    }
}