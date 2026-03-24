#include "hangman_lib.h"

int main()
{
    initializeRandom();

    // Print program title
    printf("***************************\n");
    printf("Welcome to the Hangman Game\n");
    printf("***************************\n");

    bool playAgain = true;

    while(playAgain)
    {
        bool giveup = false;
        bool won = play(&giveup);

        if(giveup)
        {
            printf("You gave up!\n");
            playAgain = false;
        }
        else
        {
            if(won)
            {
                printf("You won the round! Well done!\n");
            }
            else
            {
                printf("You lost the round!\n");
            }

            printf("Do you want to play a new round? [y|n]\n");
            char response;
            scanf(" %c\n", &response);

            while(tolower(response) != 'y' && tolower(response) != 'n')
            {
                printf("I didn't get that. Please use y to yes and n to no.\n");
                printf("Do you want to play a new round? [y|n]\n");
                scanf(" %c\n", &response);
            }

            if(tolower(response) == 'n')
            {
                playAgain = false;
            }
        }

    }

    printf("Come back another time!\n");

    return 0;
}