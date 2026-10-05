// puzzle_lib_students.cpp — student implementation file
#include "puzzle_lib.h"

// ========================== Container ==========================

/**
 * Constructor: Container
 * Allocates a dynamic array for boxSizes and copies the values from sizes.
 * Sets numBoxes and containerSize from the parameters.
 */
Container::Container(const int* sizes, int count, int capacity)
{
    // Store the number of boxes from the count parameter
    numBoxes = count;
    // Store the container capacity from the capacity parameter
    containerSize = capacity;
    // Allocate a new dynamic array to hold the box sizes
    boxSizes = new int[numBoxes];
    // Loop through each box index
    for (int i = 0; i < numBoxes; i++)
    {
        // Copy each box size from the source array to our array
        boxSizes[i] = sizes[i];
    }
}

/**
 * Copy Constructor: Container
 * Creates a deep copy of the other Container.
 */
Container::Container(const Container& other)
{
    // Copy the number of boxes from the other Container
    numBoxes = other.numBoxes;
    // Copy the container size from the other Container
    containerSize = other.containerSize;
    // Allocate a new dynamic array (deep copy, not sharing memory)
    boxSizes = new int[numBoxes];
    // Loop through each box index
    for (int i = 0; i < numBoxes; i++)
    {
        // Copy each box size from the other Container's array
        boxSizes[i] = other.boxSizes[i];
    }
}

/**
 * Copy Assignment: Container
 * Assigns a deep copy of the other Container to this one.
 */
Container& Container::operator=(const Container& other)
{
    // Check for self-assignment (e.g., c = c) to avoid deleting our own data
    if (this != &other)
    {
        // Free the old dynamic array to prevent memory leak
        delete[] boxSizes;

        // Copy the number of boxes from the other Container
        numBoxes = other.numBoxes;
        // Copy the container size from the other Container
        containerSize = other.containerSize;
        // Allocate a new dynamic array for the copied data
        boxSizes = new int[numBoxes];
        // Loop through each box index
        for (int i = 0; i < numBoxes; i++)
        {
            // Copy each box size from the other Container's array
            boxSizes[i] = other.boxSizes[i];
        }
    }
    // Return a reference to this object (allows chaining: a = b = c)
    return *this;
}

/**
 * Destructor: Container
 * Deallocates the boxSizes array.
 */
Container::~Container()
{
    // Free the dynamically allocated array to prevent memory leak
    delete[] boxSizes;
}

/**
 * Method: fill (public)
 * Entry point for the backtracking algorithm.
 * Returns true if a subset of boxes exactly fills the container.
 */
bool Container::fill()
{
    return fill(containerSize, 0);
}

/**
 * Method: fill (private recursive helper)
 * Arguments: - remaining: the space left to fill in the container
 *            - index: the current position in the boxSizes array
 * Return: true if a combination from index onward fills 'remaining' exactly
 *         false otherwise
 * Dependencies: fill (recursive)
 */
bool Container::fill(int remaining, int index)
{
    // TODO: Implement recursive backtracking
    // Base cases:
    //   - If remaining == 0, we filled the container exactly (success)
    //   - If index >= numBoxes or remaining < 0, no solution on this path
    if (remaining == 0)
    {
        return true;
    }
    if (index >= numBoxes || remaining < 0)
    {
        return false;
    }
    // Recursive cases:
    //   - Choice 1: take boxSizes[index] (subtract from remaining, advance index)
    //   - Choice 2: skip boxSizes[index] (keep remaining, advance index)
    if (fill(remaining - boxSizes[index], index + 1))
    {
        return true;
    }
    return fill(remaining, index + 1);
}

int Container::getContainerSize() const
{
    return containerSize;
}

int Container::getNumBoxes() const
{
    return numBoxes;
}

int Container::getBoxSize(int index) const
{
    return boxSizes[index];
}

// ========================== Labyrinth ==========================

/**
 * Constructor: Labyrinth
 * Allocates dynamic 2D arrays for grid and visited, and a path buffer.
 * Copies the source grid values.
 */
Labyrinth::Labyrinth(int** sourceGrid, int mazeSize)
{
    // Store the maze dimension
    size = mazeSize;

    // Allocate array of row pointers for the grid (first dimension)
    grid = new int*[size];
    // Loop through each row
    for (int i = 0; i < size; i++)
    {
        // Allocate each row of the grid (second dimension)
        grid[i] = new int[size];
        // Loop through each column in this row
        for (int j = 0; j < size; j++)
        {
            // Copy each cell value from the source grid
            grid[i][j] = sourceGrid[i][j];
        }
    }

    // Allocate array of row pointers for the visited array (first dimension)
    visited = new bool*[size];
    // Loop through each row
    for (int i = 0; i < size; i++)
    {
        // Allocate each row of visited (second dimension)
        visited[i] = new bool[size];
        // Loop through each column in this row
        for (int j = 0; j < size; j++)
        {
            // Initialize all cells as not visited
            visited[i][j] = false;
        }
    }

    // Allocate path buffer (max path length is size*size moves, +1 for null terminator)
    path = new char[size * size + 1];
}

/**
 * Copy Constructor: Labyrinth
 * Creates a deep copy of all dynamic members.
 */
Labyrinth::Labyrinth(const Labyrinth& other)
{
    // Copy the maze dimension from the other Labyrinth
    size = other.size;

    // Allocate array of row pointers for the grid (first dimension)
    grid = new int*[size];
    // Loop through each row
    for (int i = 0; i < size; i++)
    {
        // Allocate each row of the grid (second dimension)
        grid[i] = new int[size];
        // Loop through each column in this row
        for (int j = 0; j < size; j++)
        {
            // Copy each cell value from the other Labyrinth's grid
            grid[i][j] = other.grid[i][j];
        }
    }

    // Allocate array of row pointers for the visited array (first dimension)
    visited = new bool*[size];
    // Loop through each row
    for (int i = 0; i < size; i++)
    {
        // Allocate each row of visited (second dimension)
        visited[i] = new bool[size];
        // Loop through each column in this row
        for (int j = 0; j < size; j++)
        {
            // Copy each visited status from the other Labyrinth
            visited[i][j] = other.visited[i][j];
        }
    }

    // Allocate path buffer with same size
    path = new char[size * size + 1];
    // Loop through each character in the path buffer
    for (int i = 0; i < size * size + 1; i++)
    {
        // Copy each character from the other Labyrinth's path
        path[i] = other.path[i];
    }
}

/**
 * Copy Assignment: Labyrinth
 * Assigns a deep copy of the other Labyrinth to this one.
 */
Labyrinth& Labyrinth::operator=(const Labyrinth& other)
{
    // Check for self-assignment to avoid deleting our own data
    if (this != &other)
    {
        // Free old memory: delete each row of grid and visited
        for (int i = 0; i < size; i++)
        {
            // Delete this row of the grid
            delete[] grid[i];
            // Delete this row of the visited array
            delete[] visited[i];
        }
        // Delete the array of row pointers for grid
        delete[] grid;
        // Delete the array of row pointers for visited
        delete[] visited;
        // Delete the old path buffer
        delete[] path;

        // Copy the maze dimension from the other Labyrinth
        size = other.size;

        // Allocate new array of row pointers for grid
        grid = new int*[size];
        // Loop through each row
        for (int i = 0; i < size; i++)
        {
            // Allocate each row of the grid
            grid[i] = new int[size];
            // Loop through each column
            for (int j = 0; j < size; j++)
            {
                // Copy each cell value from the other Labyrinth's grid
                grid[i][j] = other.grid[i][j];
            }
        }

        // Allocate new array of row pointers for visited
        visited = new bool*[size];
        // Loop through each row
        for (int i = 0; i < size; i++)
        {
            // Allocate each row of visited
            visited[i] = new bool[size];
            // Loop through each column
            for (int j = 0; j < size; j++)
            {
                // Copy each visited status from the other Labyrinth
                visited[i][j] = other.visited[i][j];
            }
        }

        // Allocate new path buffer
        path = new char[size * size + 1];
        // Loop through each character in the path buffer
        for (int i = 0; i < size * size + 1; i++)
        {
            // Copy each character from the other Labyrinth's path
            path[i] = other.path[i];
        }
    }
    // Return a reference to this object (allows chaining: a = b = c)
    return *this;
}

/**
 * Destructor: Labyrinth
 * Deallocates all dynamic members.
 */
Labyrinth::~Labyrinth()
{
    // Loop through each row to delete individual rows
    for (int i = 0; i < size; i++)
    {
        // Delete this row of the grid
        delete[] grid[i];
        // Delete this row of the visited array
        delete[] visited[i];
    }
    // Delete the array of row pointers for grid
    delete[] grid;
    // Delete the array of row pointers for visited
    delete[] visited;
    // Delete the path buffer
    delete[] path;
}

/**
 * Method: solve (public)
 * Resets visited array and starts the recursive search from (0,0).
 */
void Labyrinth::solve()
{
    // TODO: Implement solve
    // - Call resetVisited() to clear the visited array
    // - Call the private solve(0, 0, 0) to begin backtracking
    resetVisited();
    solve(0, 0, 0);
}

/**
 * Method: solve (private recursive helper)
 * Arguments: - row, col: current position in the maze
 *            - pathIndex: current length of the path being built
 * Explores D, R, U, L directions, marking and unmarking visited cells.
 * Prints the path when the exit (size-1, size-1) is reached.
 * Dependencies: isSafe, printPath, solve (recursive)
 */
void Labyrinth::solve(int row, int col, int pathIndex)
{
    // TODO: Implement recursive backtracking
    // - If !isSafe(row, col), return
    // - If at exit (row == size-1 && col == size-1), call printPath and return
    // - Mark visited[row][col] = true
    // - Try D: set path[pathIndex] = 'D', recurse with (row+1, col)
    // - Try R: set path[pathIndex] = 'R', recurse with (row, col+1)
    // - Try U: set path[pathIndex] = 'U', recurse with (row-1, col)
    // - Try L: set path[pathIndex] = 'L', recurse with (row, col-1)
    // - Backtrack: visited[row][col] = false
    if (!isSafe(row, col))
    {
        return;
    }
    if (row == size - 1 && col == size - 1)
    {
        printPath(pathIndex);
        return;
    }
    visited[row][col] = true;

    path[pathIndex] = 'D';
    solve(row + 1, col, pathIndex + 1);
    path[pathIndex] = 'R';
    solve(row, col + 1, pathIndex + 1);
    path[pathIndex] = 'U';
    solve(row - 1, col, pathIndex + 1);
    path[pathIndex] = 'L';
    solve(row, col - 1, pathIndex + 1);

    visited[row][col] = false;
}

/**
 * Method: resetVisited
 * Zeros out all entries in the visited array.
 */
void Labyrinth::resetVisited()
{
    // TODO: Implement resetVisited
    // - Traverse visited[i][j] and set each to false
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            visited[i][j] = false;
        }
    }
}

// PROVIDED: checks if (row,col) is within bounds, open, and not visited
bool Labyrinth::isSafe(int row, int col)
{
    return (row >= 0
         && row < size
         && col >= 0
         && col < size
         && grid[row][col] == OPEN_CELL
         && !visited[row][col]);
}

// PROVIDED: prints the path buffer up to the given length
void Labyrinth::printPath(int length)
{
    path[length] = '\0';
    cout << path << endl;
}

int Labyrinth::getSize() const
{
    return size;
}

int Labyrinth::getCell(int row, int col) const
{
    return grid[row][col];
}

// ========================== Portfolio ==========================

/**
 * Constructor: Portfolio
 * Allocates dynamic arrays for investments and currentSubset.
 * Copies the investment values from options.
 */
Portfolio::Portfolio(const int* options, int count, int targetSum)
{
    // Store the number of investment options
    numInvestments = count;
    // Store the target sum to achieve
    target = targetSum;

    // Allocate a new dynamic array for the investment values
    investments = new int[numInvestments];
    // Loop through each investment index
    for (int i = 0; i < numInvestments; i++)
    {
        // Copy each investment value from the source array
        investments[i] = options[i];
    }

    // Allocate array to hold the current subset during backtracking
    currentSubset = new int[numInvestments];
}

/**
 * Copy Constructor: Portfolio
 * Creates a deep copy of both dynamic arrays.
 */
Portfolio::Portfolio(const Portfolio& other)
{
    // Copy the number of investments from the other Portfolio
    numInvestments = other.numInvestments;
    // Copy the target sum from the other Portfolio
    target = other.target;

    // Allocate a new dynamic array for investments (deep copy)
    investments = new int[numInvestments];
    // Loop through each investment index
    for (int i = 0; i < numInvestments; i++)
    {
        // Copy each investment value from the other Portfolio
        investments[i] = other.investments[i];
    }

    // Allocate a new dynamic array for currentSubset (deep copy)
    currentSubset = new int[numInvestments];
    // Loop through each index
    for (int i = 0; i < numInvestments; i++)
    {
        // Copy each value from the other Portfolio's currentSubset
        currentSubset[i] = other.currentSubset[i];
    }
}

/**
 * Copy Assignment: Portfolio
 * Assigns a deep copy of the other Portfolio to this one.
 */
Portfolio& Portfolio::operator=(const Portfolio& other)
{
    // Check for self-assignment to avoid deleting our own data
    if (this != &other)
    {
        // Free the old investments array to prevent memory leak
        delete[] investments;
        // Free the old currentSubset array to prevent memory leak
        delete[] currentSubset;

        // Copy the number of investments from the other Portfolio
        numInvestments = other.numInvestments;
        // Copy the target sum from the other Portfolio
        target = other.target;

        // Allocate a new dynamic array for investments
        investments = new int[numInvestments];
        // Loop through each investment index
        for (int i = 0; i < numInvestments; i++)
        {
            // Copy each investment value from the other Portfolio
            investments[i] = other.investments[i];
        }

        // Allocate a new dynamic array for currentSubset
        currentSubset = new int[numInvestments];
        // Loop through each index
        for (int i = 0; i < numInvestments; i++)
        {
            // Copy each value from the other Portfolio's currentSubset
            currentSubset[i] = other.currentSubset[i];
        }
    }
    // Return a reference to this object (allows chaining: a = b = c)
    return *this;
}

/**
 * Destructor: Portfolio
 * Deallocates both dynamic arrays.
 */
Portfolio::~Portfolio()
{
    // Free the dynamically allocated investments array
    delete[] investments;
    // Free the dynamically allocated currentSubset array
    delete[] currentSubset;
}

/**
 * Method: findSubsets (public)
 * Entry point for the subset-sum backtracking algorithm.
 */
void Portfolio::findSubsets()
{
    findSubsets(0, 0, 0);
}

/**
 * Method: findSubsets (private recursive helper)
 * Arguments: - index: the next investment to consider
 *            - currentSum: the running total of selected investments
 *            - subsetIndex: the number of investments selected so far
 * Finds all subsets of investments that sum to target.
 * Dependencies: findSubsets (recursive), printSubset
 */
void Portfolio::findSubsets(int index, int currentSum, int subsetIndex)
{
    // TODO: Implement recursive backtracking
    // Base cases:
    //   - If currentSum == target, call printSubset(subsetIndex) and return
    //   - If index >= numInvestments or currentSum > target, return
    // Recursive cases:
    //   - Include: set currentSubset[subsetIndex] = investments[index],
    //     recurse with (index+1, currentSum + investments[index], subsetIndex+1)
    //   - Exclude: recurse with (index+1, currentSum, subsetIndex)
    if (currentSum == target)
    {
        printSubset(subsetIndex);
        return;
    }
    if (index >= numInvestments || currentSum > target)
    {
        return;
    }

    currentSubset[subsetIndex] = investments[index];
    findSubsets(index + 1, currentSum + investments[index], subsetIndex + 1);
    findSubsets(index + 1, currentSum, subsetIndex);
}

// PROVIDED: prints the currentSubset buffer up to the given length
void Portfolio::printSubset(int length)
{
    cout << "{";
    for (int i = 0; i < length; i++)
    {
        cout << currentSubset[i];
        if (i + 1 < length)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int Portfolio::getTarget() const
{
    return target;
}

int Portfolio::getNumInvestments() const
{
    return numInvestments;
}

int Portfolio::getInvestment(int index) const
{
    return investments[index];
}
