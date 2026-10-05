// header files
#include "untzler_lib.h"

/**
 * Task 1: Uncovering the Unique Code
 * Input argument: array as a 1D array of integers, size as an integer
 * Output argument: none
 * Return: the unique integer that appears only once in the array
 * Dependencies: none
 */
int unique_code(int array[], int size)
{
    // traverse the array
    for (int i = 0; i < size; i++)
    {
        // declare the counter variable
        int count = 0;
        // TODO

        // given the current value in the array, traverse to count
        for (int j = 0; j < size; j++)
        {
            // if the current element is equal to the element we are counting
            if (array[j] == array[i])
            // TODO
            count++;
        }

        // if the count is 1, this is the unique element

        // TODO
        if(count == 1)
        {
            return array[i];
        }

    }

    // if no unique element is found, return not found
    return NOT_FOUND;
}

/**
 * Task 2: Balancing the Array
 * Input argument: array as a 1D array of integers, size as an integer
 * Output argument: none
 * Return: the index where the sum of elements on the left equals the sum on the right
 * Dependencies: none
 */
int balance(int array[], int size)
{
    // initialize total and left sums to 0
    int total = 0;
    int left_sum = 0;

    // TODO

    // calculate the total sum of the array
        // traverse the array
    for (int i = 0; i < size; i++)
    {
        // add the current element to the total sum

        // TODO
        total += array[i];

    }

    // find the balance point where left and right sums are equal
        // traverse the array
    for (int i = 0; i < size; i++)
    {
        // subtract the current element from the total sum to get the right sum
        int right_sum = total - left_sum - array[i];
        // TODO

        // if the left and right sums are equal
        if(left_sum == right_sum)
        {
            return i;
        }
        // TODO

        // add the current element to the left sum
        left_sum += array[i];
        // TODO

    }

    // if no balance point is found, return not found
    return NOT_FOUND;
}

/**
 * Task 3: Decoding the Scrambled Message
 * Input argument: scrambled_message as a string, reference_message as a string
 * Output argument: none
 * Return: boolean value indicating if the messages are anagrams
 * Dependencies: none
 */
bool decode(const char *scrambled_message, const char *reference_message)
{
    // initialize an array to count character occurrences, set all counts to 0
    int char_count[CHARACTERS] = {0};
    // TODO

    // count characters in the scrambled message
        // traverse the scrambled message
    for(int i = 0; i < (int)strlen(scrambled_message); i++)
    {
        char_count[(int)scrambled_message[i]]++;
    }

    // TODO

    // subtract counts using the reference message
        // traverse the reference message
    for(int i = 0; i < (int)strlen(reference_message); i++)
    {
        char_count[(int)reference_message[i]]--;
    }

    // TODO

    // check if all counts are zero
        // traverse the array
    for(int i = 0; i < CHARACTERS; i++)
    {
        if(char_count[i] != 0)
        {
            return false;
        }
    }

    // TODO

    // if the loop doesn't return, the message is an anagram
    return true;
}

/**
 * Task 4: Uncovering the Maximum Sequence
 * Input argument: array as a 1D array of integers, size as an integer
 * Output argument: none
 * Return: the maximum sum of a contiguous subarray
 * Dependencies: none
 */
int uncover(int array[], int size)
{
    // initialize max_sum and current_sum with the first element
    int max_sum = array[0];
    int current_sum = array[0];

    // TODO

    // traverse the array starting at the second element
    for (int i = 1; i < size; i++)
    {
        // if the current sum is positive
        if(current_sum > 0)
        {
            // add the current element to the sum
            current_sum += array[i];
        }
        else
        // if it is zero or negative
        {
            // replace the current sum with the current element
            current_sum = array[i];
        }

        // TODO

        // if the current sum is greater than the maximum sum so far
        if(current_sum > max_sum)
        {
            // update the maximum sum to the current sum
           max_sum = current_sum; 
        }

        // TODO

    }

    // return the maximum sum found
    return max_sum; // TODO: change this return value
}

/**
 * Task 5: Navigating the Rotated Array
 * Input argument: array as a 1D array of integers, size as an integer, data_element as an integer
 * Output argument: none
 * Return: the index of the data_element in the rotated sorted array
 * Dependencies: none
 */
int navigate(int array[], int size, int data_element)
{
    // initialize left and right pointers for binary search
    int left =  0;
    int right = size - 1;
    // TODO

    // perform binary search in the rotated array
        // while the array is not empty
    while(left <= right)
    {
    // TODO: implement the binary search loop
    //   - calculate the middle index
        int middle = left + (right - left) / 2;

    //   - if the middle matches the data, return the index
        if(array[middle] == data_element)
        {
            return middle;
        }
    //   - check which side is sorted
    //       - if the left side is sorted
        if(array[left] <= array[middle])
        {
    //           - if the element is in the left side, adjust right pointer
            if(data_element >= array[left] && data_element < array[middle])
            {
                right = middle - 1;
            }
    //           - otherwise, adjust left pointer
            else
            {
                left = middle + 1;
            }
        }
    //       - if the right side is sorted
        else
        {
    //           - if the element is in the right side, adjust left pointer
            if(data_element > array[middle] && data_element <= array[right])
            {
                left = middle + 1;
            }
    //           - otherwise, adjust right pointer
            else
            {
                right = middle - 1;
            }
        }
    }

    // if element is not found, return
    return NOT_FOUND;
}

/**
 * Task 6: Finding the Critical Minimum
 * Input argument: array as a 1D array of integers, size as an integer
 * Output argument: none
 * Return: the minimum value in a rotated sorted array
 * Dependencies: none
 */
int critical_minimum(int array[], int size)
{
    // initialize left and right pointers for binary search
    int left =  0;
    int right = size - 1;
    // TODO

    // perform binary search in the rotated array
        // while the array is not empty
    while(left <= right)
    {
    // TODO: implement the binary search loop
    //   - calculate the middle index
    int middle = left + (right - left) / 2;
    //   - if the middle element is greater than the rightmost element
    if(array[middle] > array[right])
    {
    //       - adjust left pointer to search the right side
        left = middle + 1;
    }
    //   - otherwise
    else
    {
    //       - adjust right pointer to search the left side
        right = middle;
    }
    }

    // return the minimum element found
    return array[left]; // TODO: change this return value
}
