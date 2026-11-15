#include "leaderboard_lib.h"

int main()
{
    Leaderboard leaderboard;
    int option = 0;
    int score = 0;
    int k = 0;
    int low = 0;
    int high = 0;
    int student1 = 0;
    int student2 = 0;

    while (option != 9)
    {
        cout << "\n---- Leaderboard Menu ----" << endl;
        cout << "1. Add a student score" << endl;
        cout << "2. Remove a student score" << endl;
        cout << "3. Print leaderboard" << endl;
        cout << "4. Find the Kth smallest score" << endl;
        cout << "5. Calculate range sum of scores" << endl;
        cout << "6. Find common friend student" << endl;
        cout << "7. Measure academic connectivity" << endl;
        cout << "8. Identify Students Meeting Average Performance" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option (1-9): ";
        cin >> option;

        switch (option)
        {
            case 1:
                cout << "Enter student score to add: ";
                cin >> score;
                leaderboard.addStudent(score);
                cout << "Score " << score << " added to leaderboard." << endl;
                break;

            case 2:
                cout << "Enter student score to remove: ";
                cin >> score;
                leaderboard.removeStudent(score);
                cout << "Score " << score << " removed from leaderboard." << endl;
                break;

            case 3:
                cout << "Current Leaderboard:" << endl;
                leaderboard.printLeaderboard();
                cout << endl;
                break;

            case 4:
            {
                int kthScore = 0;
                cout << "Enter the value of K: ";
                cin >> k;
                kthScore = leaderboard.findKthSmallestScore(k);

                if (kthScore != -1)
                {
                    cout << "The " << k << "th smallest score is: "
                         << kthScore << endl;
                }
                else
                {
                    cout << "Invalid K value or leaderboard is empty." << endl;
                }
                break;
            }

            case 5:
                cout << "Enter low range: ";
                cin >> low;
                cout << "Enter high range: ";
                cin >> high;
                cout << "The sum of scores between " << low << " and " << high
                     << " is: " << leaderboard.rangeSumScores(low, high) << endl;
                break;

            case 6:
            {
                int commonFriend = 0;
                cout << "Enter the first student score: ";
                cin >> student1;
                cout << "Enter the second student score: ";
                cin >> student2;
                commonFriend =
                    leaderboard.findCommonFriendStudent(student1, student2);

                if (commonFriend != -1)
                {
                    cout << "The common friend student score between "
                         << student1 << " and " << student2 << " is: "
                         << commonFriend << endl;
                }
                else
                {
                    cout << "No common friend found or scores do not exist."
                         << endl;
                }
                break;
            }

            case 7:
                cout << "The length of the longest path between students is: "
                     << leaderboard.measureAcademicConnectivity() << endl;
                break;

            case 8:
                cout << "Number of students meeting average performance: "
                     << leaderboard.identifyStudentsMeetingAveragePerformance()
                     << endl;
                break;

            case 9:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }

    return 0;
}
