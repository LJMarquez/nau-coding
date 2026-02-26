// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
    initializePlayer();
        // declare variable to hold the dice
    int dice[NUM_DICE];

        // declare the variable to store the user's choice
    char choice;
        // inialize the variable that stores the play
    int play = NO_PLAY;

        // print a title
    printf("\nWelcome to Simple Yahtzee!\n");
    printf("==========================\n\n");

    // begin game
        // prompt the user for the play
            // function: printf
    printf("Do you want to roll the dice (y/n): ");
        // wait for user input
            // function: getChoice
    choice = getChoice();

        // TODO 1: create a loop that runs while the user wants to continue
    while(choice != 'n')
    { 
        printf("Your roll: ");
        int dice[NUM_DICE];
        for(int i = 0; i < NUM_DICE; i++)
        {
            // TODO 2: roll the dice to fill the array of dice
            dice[i] = rollDice();
            // TODO 3: print the dice
            printf("%d", dice[i]);
            if(i < NUM_DICE - 1)
            {
                printf(", ");
            }
            else
            {
                printf(" ");
            }
        }


            // TODO 4: call the function decidePlay and store the result in
            //         the play variable
        play = decidePlay(dice);

            // TODO 5: evaluate the play variable and print the appropriate 
            //         message
        printf("You rolled ");
        if(play == YAHTZEE)
        {
            printf("a Yahtzee!\n");
        }
        else if(play == FULL_HOUSE)
        {
            printf("a Full House!\n");
        }
        else if(play == FOUR_OF_A_KIND)
        {
            printf("a Four of a Kind!\n");
        }
        else if(play == THREE_OF_A_KIND)
        {
            printf("a Three of a Kind!\n");
        }
        else if(play == L_STRAIGHT)
        {
            printf("a Large Straight!\n");
        }
        else if(play == S_STRAIGHT)
        {
            printf("a Small Straight!\n");
        }
        else
        {
            printf("no particular play.\n");
        }
        

        // prompt the user for continuing
            // function: printf
        printf("\nPlay again? (y/n): ");
        // Read the choice
            // function: getChoice
        choice = getChoice();
    
    // END OF TODO 1: loop
    }

    // End program
        // print a message
            // function: printf
    printf("\nThanks for playing Yahtzee!\n");
        // return success
    return 0;
}
