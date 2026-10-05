// header files
#include <iostream>
#include "untzler_lib.h"

// main program
int main()
{
    // declare and initialize the test data
    int hiddenCodeArray[] = {7, 5, 3, 7, 15, 5, 9, 3, 9};  // Task 1
    int systemLogs[] = {8, -2, -1, 4, 7, 0, 4, 5};  // Task 2
    char scrambledMessage[] = "aabbccddeeffgghhiijj";
    char referenceMessage[] = "cajehfbcidefbghgdiaj";  // Task 3
    int criticalLog[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  // Task 4
    int rotatedData[] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};  // Task 5
    int rotatedMin[] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};  // Task 6

    // Task 1: Find the unique code
    int uniqueCode = unique_code(hiddenCodeArray, sizeof(hiddenCodeArray) /
        sizeof(hiddenCodeArray[0]));
    cout << "Dear TechnoCity Restorer, the Untzler system needs your expertise "
        "to restore order and functionality! Each step you take helps us "
        "uncover vital information and secure our city." << endl << endl;
    cout << "================================================================" << endl << endl;
    cout << "The Hidden Code in the Data Breach:" << endl << endl;
    cout << "In the chaos of the cyberattack, essential security codes have been"
        " scrambled. Your task was to identify the unique code amidst the "
        "duplicates that has been corrupted beyond recognition." << endl << endl;
    cout << "The unique code in the data breach is: " << uniqueCode << endl << endl;
    cout << "You've successfully pinpointed the unique code that will help us "
        "reestablish secure access controls. Great job!" << endl << endl;

    // Task 2: Find the balance point in the system logs
    int balancePoint = balance(systemLogs, sizeof(systemLogs) / sizeof(systemLogs[0]));
    cout << "=================================================================" << endl << endl;
    cout << "Balancing the System Logs:" << endl << endl;
    cout << "Our system logs are in disarray, and we need to find the balance"
        "point where the activity before equals the activity after. This "
        "balance point is crucial for assessing the impact of the attack and "
        "ensuring stability." << endl << endl;
    cout << "The balance point in the system logs is at index: " << balancePoint << endl << endl;
    cout << "You've found the equilibrium point, restoring balance to our logs "
        "and paving the way for further analysis." << endl << endl;

    // Task 3: Decode the scrambled message
    int isDecoded = decode(scrambledMessage, referenceMessage);
    cout << "================================================================" << endl << endl;
    if (isDecoded == true)
    {
        cout << "The scrambled message can be decoded to match the reference "
            "message." << endl << endl;
        cout << "You've successfully decoded the messages, unlocking vital "
            "information necessary for a comprehensive response to the attack."
            << endl << endl;
    }

    else {
        cout << "The scrambled message cannot be decoded to match the reference "
            "message." << endl << endl;
        cout << "You've encountered issues in decoding the messages, which may "
            "require further investigation." << endl << endl;
    }

    // Task 4: Find the maximum sum of a contiguous subarray
    int maxSum = uncover(criticalLog,
        sizeof(criticalLog) / sizeof(criticalLog[0]));
    cout << "================================================================" << endl << endl;
    cout << "Uncovering the Critical System Log:" << endl << endl;
    cout << "Among the clutter of system logs, the most significant sequence of "
        "events is hidden. Finding the maximum sum of a contiguous subarray "
        "reveals the most critical period of activity." << endl << endl;
    cout << "The maximum sum of a contiguous subarray is: " << maxSum << endl << endl;
    cout << "Congratulations! You've identified the most impactful period of "
        "activity, providing key insights into the attack's effects." << endl << endl;

    // Task 5: Search for a specific entry in a rotated sorted array
    int dataElement = 3;
    int index = navigate(rotatedData, sizeof(rotatedData) / sizeof(rotatedData[0]), dataElement);
    cout << "================================================================" << endl << endl;
    cout << "Navigating Through Rotated Data:" << endl << endl;
    cout << "A critical part of our dataset was rotated, making searches "
    "challenging. Your task was to locate a specific entry within this rotated "
    "sorted array." << endl << endl;
    if (index != NOT_FOUND)
    {
        cout << "The data element " << dataElement << " is present at index: " << index << endl << endl;
        cout << "You've successfully navigated the rotated data, retrieving "
            "crucial information from the disarrayed dataset." << endl << endl;
    }
    else
    {
        cout << "The data element " << dataElement << " is not present in the array." << endl << endl;
        cout << "The data element was not found, which may suggest further "
            "investigation is needed." << endl << endl;
    }

    // Task 6: Find the minimum value in a rotated sorted array
    int minValue = critical_minimum(rotatedMin, sizeof(rotatedMin) / sizeof(rotatedMin[0]));
    cout << "================================================================" << endl << endl;
    cout << "Finding the Critical Minimum:" << endl << endl;
    cout << "The dataset's rotation has made it necessary to find the minimum "
        "value within the rotated sorted array. This value is crucial for "
        "diagnostic purposes." << endl << endl;
    cout << "The minimum value in the rotated sorted array is: " << minValue << endl << endl;
    cout << "You've identified the minimum value, helping us understand the  "
        "rotation's impact and facilitate accurate analysis." << endl << endl;

    // return success
    return 0;
}
