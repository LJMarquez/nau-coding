// header files
#include "mosaic_lib.h"

/**
 * Constructor: Mosaic
 * Input argument: the mural as a 2D array of integer
 * Output argument: none
 * Return: none
 * Dependencies: none
 * Description: Initializes the Mosaic object with the given matrix data
 */
Mosaic::Mosaic(const int inputMatrix[SIZE][SIZE])
{
    // copy the input matrix to the internal matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = inputMatrix[i][j];
        }
    }
}

/**
 * Method: setMatrix
 * Input argument: the mural as a 2D array of integer
 * Output argument: none
 * Return: none
 * Dependencies: none
 * Description: Loads data into the internal matrix
 */
void Mosaic::setMatrix(const int inputMatrix[SIZE][SIZE])
{
    // copy the input matrix to the internal matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = inputMatrix[i][j];
        }
    }
}

/**
 * Task 1: Reordering the Mosaic Tiles
 * Input argument: none (operates on internal matrix)
 * Output argument: none (modifies internal matrix)
 * Return: none
 * Dependencies: none
 */
void Mosaic::transpose()
{
    // TODO: Implement transpose
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

/**
 * Task 2: Realigning the Rotated Tiles
 * Input argument: none (operates on internal matrix)
 * Output argument: none (modifies internal matrix)
 * Return: none
 * Dependencies: none
 */
void Mosaic::rotate()
{
    // TODO: Implement rotate
    transpose();

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][SIZE - 1 - j];
            matrix[i][SIZE - 1 - j] = temp;
        }
    }
}

/**
 * Task 3: Restoring the Blank Spaces
 * Input argument: none (operates on internal matrix)
 * Output argument: none (modifies internal matrix)
 * Return: none
 * Dependencies: none
 */
void Mosaic::zeroMatrix()
{
    // TODO: Implement zeroMatrix
    bool firstRowZero = false;
    bool firstColumnZero = false;

    for (int j = 0; j < SIZE; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColumnZero = true;
        }
    }

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (firstColumnZero)
    {
        for (int i = 0; i < SIZE; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

/**
 * Task 4: Rotating the Mosaic Row
 * Input argument: k number of steps
 * Output argument: none (modifies internal matrix)
 * Return: none
 * Dependencies: cstdlib - rand
 */
void Mosaic::rotateRow(int k)
{
    // TODO: Implement rotateRow
    int row = rand() % SIZE;
    k %= SIZE;

    for (int step = 0; step < k; step++)
    {
        int temp = matrix[row][SIZE - 1];
        for (int j = SIZE - 1; j > 0; j--)
        {
            matrix[row][j] = matrix[row][j - 1];
        }
        matrix[row][0] = temp;
    }
}

/**
 * Task 5: Unveiling the Spiral Mural
 * Input argument: none (operates on internal matrix)
 * Output argument: none
 * Return: dynamically allocated array of integers
 * Dependencies: none
 */
int* Mosaic::spiralOrder()
{
    // TODO: Implement spiralOrder
    int* result = new int[ARRAY_SIZE];
    int index = 0;
    int top = 0;
    int bottom = SIZE - 1;
    int left = 0;
    int right = SIZE - 1;

    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            result[index++] = matrix[top][j];
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            result[index++] = matrix[i][right];
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}

/**
 * Method: printMatrix (provided)
 * Input argument: none (operates on internal matrix)
 * Output argument: none
 * Return: none
 * Dependencies: iostream - cout
 */
void Mosaic::printMatrix()
{
    using namespace std;

    // traverse the mural rows
    for (int i = 0; i < SIZE; i++)
    {
        // traverse the mural columns
        for (int j = 0; j < SIZE; j++)
        {
            // print the current row-column value
            cout.width(3);
            cout << matrix[i][j] << " ";
        }
        // break a line at the end of the row
        cout << endl;
    }
}

/**
 * Method: getElement (for testing purposes)
 * Input argument: row and column indices
 * Output argument: none
 * Return: the value at matrix[row][col]
 * Dependencies: none
 */
int Mosaic::getElement(int row, int col) const
{
    return matrix[row][col];
}
