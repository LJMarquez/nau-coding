#include "battleship_lib.h"

int main()
{
    char solution[SIZE][SIZE];
    char game[SIZE][SIZE];
    int upperBound = SIZE - 1;
    initializeRandom();
    printf("Battleship Game\n");
    printf("==============\n\n");
    buildBoard(solution, WATER_SOLUTION);
    buildBoard(game, HIDDEN_SHIP_GAME);
    fillBoard(solution);
    printf("Game board:\n");
    printMatrix(game);

    int row, col;
    int gameOver = 0;
    while(checkVictory(solution, game) == false && !gameOver)
    {
        printf("Enter the ROW (%d-%d) where you want to shoot or %d to give up: ", 0, upperBound, GIVE_UP);
        scanf("%d", &row);
        printf("\n");
        if(row == GIVE_UP)
        {
            gameOver = 1;
        }
        else if(row < 0 || row >= SIZE)
        {
            printf("Invalid input. Please enter a number between %d and %d.\n", 0, upperBound);
        }
        else
        {
            printf("Enter the COLUMN (%d-%d) where you want to shoot or %d to give up: ", 0, upperBound, GIVE_UP);
            scanf("%d", &col);
            printf("\n");
            if(col == GIVE_UP)
            {
                gameOver = 1;
            }
            else if(row < 0 || row >= SIZE || col < 0 || col >= SIZE)
            {
                printf("Invalid input. Please enter a number between %d and %d.\n", 0, upperBound);
            }
            else
            {
                shoot(solution, game, row, col);
                if(game[row][col] == SHIP_GAME)
                {
                    printf("Ship!\n");
                }
                else
                {
                    printf("Miss!\n");
                }
                printf("Current game board:\n");
                printMatrix(game);
            }
        }
    }

    if(checkVictory(solution, game))
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("You gave up. Here is the solution board:\n");
        printMatrix(solution);
    }
}