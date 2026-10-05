// puzzle_main.cpp — driver program
#include "puzzle_lib.h"

int main()
{
    // Task 1: The Box Builder's Challenge
    const int NUM_BOXES = 6;
    int boxSizes[NUM_BOXES] = {1, 2, 3, 4, 5, 6};
    const int containerSize = 10;

    Container container(boxSizes, NUM_BOXES, containerSize);

    cout << endl << "The Box Builder's Challenge:" << endl;
    cout << "---------------------------------" << endl;
    cout << "Filling up a container of size "
         << container.getContainerSize() << endl;
    cout << "There are " << container.getNumBoxes()
         << " boxes of the following sizes: {";
    for (int i = 0; i < container.getNumBoxes(); i++)
    {
        cout << container.getBoxSize(i);
        if (i != container.getNumBoxes() - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    cout << "Output: ";
    if (container.fill())
    {
        cout << "Success!" << endl << endl;
    }
    else
    {
        cout << "Failure!" << endl << endl;
    }


    // Task 2: The Labyrinth Challenge
    const int MAZE_SIZE = 4;
    int row0[] = {1, 0, 0, 0};
    int row1[] = {1, 1, 1, 1};
    int row2[] = {0, 1, 0, 1};
    int row3[] = {0, 1, 1, 1};
    int* grid[] = {row0, row1, row2, row3};

    Labyrinth maze(grid, MAZE_SIZE);

    cout << "The Labyrinth Challenge:" << endl;
    cout << "-----------------------------" << endl;
    cout << "Map Size: " << maze.getSize()
         << "x" << maze.getSize()
         << " (N = " << maze.getSize() << ")" << endl << endl;
    for (int i = 0; i < maze.getSize(); i++)
    {
        for (int j = 0; j < maze.getSize(); j++)
        {
            cout << maze.getCell(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl << "Possible paths from entrance to exit:" << endl;

    maze.solve();


    // Task 3: The Financial Puzzle
    const int NUM_INVESTMENTS = 6;
    int investments[NUM_INVESTMENTS] = {100, 200, 300, 500, 700, 1000};
    const int targetSum = 1100;

    Portfolio portfolio(investments, NUM_INVESTMENTS, targetSum);

    cout << endl << "The Financial Puzzle:" << endl;
    cout << "--------------------------" << endl;
    cout << "Investment options available: {";
    for (int i = 0; i < portfolio.getNumInvestments(); i++)
    {
        cout << portfolio.getInvestment(i);
        if (i != portfolio.getNumInvestments() - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    cout << "Target sum to achieve: " << portfolio.getTarget() << endl;

    cout << "The following selected options are available:" << endl;
    portfolio.findSubsets();

    // end of program
    cout << endl << endl << "End of program" << endl;
    return 0;
}
