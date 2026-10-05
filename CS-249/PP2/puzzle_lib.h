#ifndef PUZZLE_LIB_H
#define PUZZLE_LIB_H

#include <iostream>
#include <cstring>

using namespace std;

// ========================== Container (Task 1) ==========================
// Represents a container that must be filled exactly by a subset of boxes.
// Uses recursive backtracking to determine if a valid combination exists.
//
// MEMORY MANAGEMENT (Rule of Three):
// This class manages a single dynamically allocated array (boxSizes).
// Because we use 'new' to allocate memory, we must implement:
//   1. Destructor        - to free the allocated memory (delete[])
//   2. Copy Constructor  - to create a deep copy when a new object is
//                          initialized from an existing one
//   3. Copy Assignment   - to create a deep copy when an existing object
//                          is assigned from another (must also free old memory)
//
// DATA MEMBERS:
//   - boxSizes (int*)     : dynamically allocated array of box sizes
//   - numBoxes (int)      : number of elements in boxSizes
//   - containerSize (int) : target capacity to fill exactly
//
class Container
{
public:
    /**
     * Method: Container (constructor)
     * Arguments: - an array of box sizes
     *            - the number of boxes in the array
     *            - the capacity of the container
     * Return: none
     * Dependencies: none
     */
    Container(const int* sizes, int count, int capacity);

    /**
     * Method: Container (copy constructor)
     * Arguments: - a reference to another Container to copy from
     * Return: none
     * Dependencies: none
     */
    Container(const Container& other);

    /**
     * Method: operator= (copy assignment)
     * Arguments: - a reference to another Container to copy from
     * Return: a reference to this Container
     * Dependencies: none
     */
    Container& operator=(const Container& other);

    /**
     * Method: ~Container (destructor)
     * Arguments: none
     * Return: none
     * Dependencies: none
     */
    ~Container();

    /**
     * Method: fill (Task 1)
     * Arguments: none
     * Return: true if a combination of box sizes is equal to the container size
     *         false otherwise
     * Dependencies: fill (recursive, private)
     */
    bool fill();

    /**
     * Method: getContainerSize
     * Arguments: none
     * Return: the container size
     * Dependencies: none
     */
    int getContainerSize() const;

    /**
     * Method: getNumBoxes
     * Arguments: none
     * Return: the number of boxes
     * Dependencies: none
     */
    int getNumBoxes() const;

    /**
     * Method: getBoxSize
     * Arguments: - the index of the box
     * Return: the size of the box at the given index
     * Dependencies: none
     */
    int getBoxSize(int index) const;

private:
    int* boxSizes;
    int numBoxes;
    int containerSize;

    /**
     * Method: fill (private recursive helper)
     * Arguments: - the remaining space to fill in the container
     *            - the current index in the boxSizes array
     * Return: true if a combination from index onward fills remaining exactly
     *         false otherwise
     * Dependencies: fill (recursive)
     */
    bool fill(int remaining, int index);
};

// ========================== Labyrinth (Task 2) ==========================
// Represents a maze grid. Uses recursive backtracking to find and print
// all paths from the top-left corner to the bottom-right corner.
//
// MEMORY MANAGEMENT (Rule of Three):
// This class manages THREE dynamically allocated structures:
//   - grid (int**)    : 2D array requiring allocation of row pointers,
//                       then each individual row
//   - visited (bool**): 2D array with same structure as grid
//   - path (char*)    : 1D array to store the current path string
//
// For 2D arrays, allocation requires two steps:
//   1. Allocate the array of row pointers: new int*[size]
//   2. Allocate each row individually: new int[size] for each row
//
// Deallocation must happen in reverse order:
//   1. Delete each row: delete[] grid[i] for each row
//   2. Delete the array of pointers: delete[] grid
//
// DATA MEMBERS:
//   - grid (int**)     : 2D maze where OPEN_CELL=1, BLOCKED_CELL=0
//   - visited (bool**) : 2D array tracking visited cells during search
//   - path (char*)     : buffer storing direction characters (D,R,U,L)
//   - size (int)       : dimension of the square maze (size x size)
//
class Labyrinth
{
public:
    static const int OPEN_CELL = 1;
    static const int BLOCKED_CELL = 0;

    /**
     * Method: Labyrinth (constructor)
     * Arguments: - a 2D array (int**) representing the maze grid
     *            - the maze dimension (size x size)
     * Return: none
     * Dependencies: none
     */
    Labyrinth(int** sourceGrid, int mazeSize);

    /**
     * Method: Labyrinth (copy constructor)
     * Arguments: - a reference to another Labyrinth to copy from
     * Return: none
     * Dependencies: none
     */
    Labyrinth(const Labyrinth& other);

    /**
     * Method: operator= (copy assignment)
     * Arguments: - a reference to another Labyrinth to copy from
     * Return: a reference to this Labyrinth
     * Dependencies: none
     */
    Labyrinth& operator=(const Labyrinth& other);

    /**
     * Method: ~Labyrinth (destructor)
     * Arguments: none
     * Return: none
     * Dependencies: none
     */
    ~Labyrinth();

    /**
     * Method: solve (Task 2)
     * Arguments: none
     * Return: none
     * Dependencies: resetVisited, solve (recursive, private)
     */
    void solve();

    /**
     * Method: getSize
     * Arguments: none
     * Return: the maze dimension
     * Dependencies: none
     */
    int getSize() const;

    /**
     * Method: getCell
     * Arguments: - the row index
     *            - the column index
     * Return: the value of the cell at the given position
     * Dependencies: none
     */
    int getCell(int row, int col) const;

private:
    int** grid;
    bool** visited;
    char* path;
    int size;

    /**
     * Method: solve (private recursive helper)
     * Arguments: - the current row position in the maze
     *            - the current column position in the maze
     *            - the current length of the path being built
     * Return: none
     * Dependencies: isSafe, printPath, solve (recursive)
     */
    void solve(int row, int col, int pathIndex);

    /**
     * Method: isSafe (provided)
     * Arguments: - the row position to check
     *            - the column position to check
     * Return: true if the position is within bounds, open, and not visited
     *         false otherwise
     * Dependencies: none
     */
    bool isSafe(int row, int col);

    /**
     * Method: printPath (provided)
     * Arguments: - the length of the path to print
     * Return: none
     * Dependencies: none
     */
    void printPath(int length);

    /**
     * Method: resetVisited
     * Arguments: none
     * Return: none
     * Dependencies: none
     */
    void resetVisited();
};

// ========================== Portfolio (Task 3) ==========================
// Represents a set of investment options. Uses recursive backtracking to
// find and print all subsets that sum to the target value.
//
// MEMORY MANAGEMENT (Rule of Three):
// This class manages TWO dynamically allocated 1D arrays:
//   - investments (int*)    : stores the available investment values
//   - currentSubset (int*)  : working buffer for the current subset
//                             being built during backtracking
//
// Both arrays have the same size (numInvestments), since the maximum
// possible subset includes all investments.
//
// DATA MEMBERS:
//   - investments (int*)    : array of investment values to choose from
//   - numInvestments (int)  : number of available investments
//   - target (int)          : the sum that subsets must achieve
//   - currentSubset (int*)  : buffer for building subsets during recursion
//
class Portfolio
{
public:
    /**
     * Method: Portfolio (constructor)
     * Arguments: - an array of investment values
     *            - the number of investments in the array
     *            - the target sum the investments must achieve
     * Return: none
     * Dependencies: none
     */
    Portfolio(const int* options, int count, int targetSum);

    /**
     * Method: Portfolio (copy constructor)
     * Arguments: - a reference to another Portfolio to copy from
     * Return: none
     * Dependencies: none
     */
    Portfolio(const Portfolio& other);

    /**
     * Method: operator= (copy assignment)
     * Arguments: - a reference to another Portfolio to copy from
     * Return: a reference to this Portfolio
     * Dependencies: none
     */
    Portfolio& operator=(const Portfolio& other);

    /**
     * Method: ~Portfolio (destructor)
     * Arguments: none
     * Return: none
     * Dependencies: none
     */
    ~Portfolio();

    /**
     * Method: findSubsets (Task 3)
     * Arguments: none
     * Return: none
     * Dependencies: findSubsets (recursive, private)
     */
    void findSubsets();

    /**
     * Method: getTarget
     * Arguments: none
     * Return: the target sum
     * Dependencies: none
     */
    int getTarget() const;

    /**
     * Method: getNumInvestments
     * Arguments: none
     * Return: the number of investment options
     * Dependencies: none
     */
    int getNumInvestments() const;

    /**
     * Method: getInvestment
     * Arguments: - the index of the investment
     * Return: the value of the investment at the given index
     * Dependencies: none
     */
    int getInvestment(int index) const;

private:
    int* investments;
    int numInvestments;
    int target;
    int* currentSubset;

    /**
     * Method: findSubsets (private recursive helper)
     * Arguments: - the index for the next considered investment
     *            - the current sum of selected investments
     *            - the number of investments in the current subset
     * Return: none
     * Dependencies: findSubsets (recursive), printSubset
     */
    void findSubsets(int index, int currentSum, int subsetIndex);

    /**
     * Method: printSubset (provided)
     * Arguments: - the number of elements in the current subset to print
     * Return: none
     * Dependencies: none
     */
    void printSubset(int length);
};

#endif // PUZZLE_LIB_H
