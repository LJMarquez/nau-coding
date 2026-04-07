#include "battleship_lib.h"

void initializeRandom()
{
    srand(time(NULL));
}

void printMatrix(const char matrix[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void buildBoard(char board[SIZE][SIZE], char character)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = character;
        }
    }
}

bool isWater(const char solution[SIZE][SIZE], int row, int col)
{
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE)
    {
        return false;
    }
    return solution[row][col] == WATER_SOLUTION;
}

void placeShipHorizontal(char solution[SIZE][SIZE], int shipLength)
{
    int row, col;
    bool placed = false;

    while(placed == false)
    {
        row = rand() % SIZE;
        col = rand() %(SIZE - shipLength + 1);

        bool canPlace = true;
        for(int i = 0; i < shipLength; i++)
        {
            if(isWater(solution, row, col + i) == false)
            {
                canPlace = false;
            }
        }

        if(canPlace)
        {
            for(int i = 0; i < shipLength; i++)
            {
                solution[row][col + i] = '0' + shipLength;
            }
            placed = true;
        }
    }
}

void placeShipVertical(char solution[SIZE][SIZE], int shipLength)
{
    int row, col;
    bool placed = false;

    while(placed == false)
    {
        row = rand() %(SIZE - shipLength + 1);
        col = rand() % SIZE;

        bool canPlace = true;
        for(int i = 0; i < shipLength; i++)
        {
            if(isWater(solution, row + i, col) == false)
            {
                canPlace = false;
            }
        }

        if(canPlace)
        {
            for(int i = 0; i < shipLength; i++)
            {
                solution[row + i][col] = '0' + shipLength;
            }
            placed = true;
        }
    }
}

void fillBoard(char solution[SIZE][SIZE])
{
    for(int i = 0; i < 1; i++)
    {
        int orientation = rand() % 2;
        if(orientation == 0)
        {
            placeShipHorizontal(solution, 5);
        }
        else
        {
            placeShipVertical(solution, 5);
        }
    }
    for(int i = 0; i < 2; i++)
    {
        int orientation = rand() % 2;
        if(orientation == 0)
        {
            placeShipHorizontal(solution, 4);
        }
        else
        {
            placeShipVertical(solution, 4);
        }
    }
    for(int i = 0; i < 2; i++)
    {
        int orientation = rand() % 2;
        if(orientation == 0)
        {
            placeShipHorizontal(solution, 3);
        }
        else
        {
            placeShipVertical(solution, 3);
        }
    }
    for(int i = 0; i < 1; i++)
    {
        int orientation = rand() % 2;
        if(orientation == 0)
        {
            placeShipHorizontal(solution, 3);
        }
        else
        {
            placeShipVertical(solution, 3);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        int orientation = rand() % 2;
        if(orientation == 0)
        {
            placeShipHorizontal(solution, 2);
        }
        else
        {
            placeShipVertical(solution, 2);
        }
    }
}

void shoot(const char solution[SIZE][SIZE], char game[SIZE][SIZE], int row, int col)
{
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE)
    {
        if(isWater(solution, row, col))
        {
            game[row][col] = WATER_GAME;
        }
        else
        {
            game[row][col] = SHIP_GAME;
        }
    }
}

bool checkVictory(const char solution[SIZE][SIZE], const char game[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(solution[i][j] != WATER_SOLUTION && game[i][j] != SHIP_GAME)
            {
                return false;
            }
        }
    }
    return true;
}