#include "yahtzee_lib.h"

void initializePlayer()
{
    // initalize random number generator
    // functions: srand, time
    srand(time(NULL));
}

char getChoice()
{
    // get the player choice and validate the input
    // function: scanf, tolower
    char choice;
    while(choice != 'y' && choice != 'n')
    {
        scanf(" %c", &choice);
        choice = tolower(choice);
        if(choice != 'y' && choice != 'n')
            printf("Invalid option. Please type 'y' to play or 'n' to exit: ");
    }
    return choice;
}

int rollDice()
{
    // generate the random number and constraint within range (1-6)
    // function: rand
    return rand() % NUM_SIDES + 1;
}

void countNumber(const int dice[], int counts[])
{
    // count how many times the number appears in the dice
    for(int i = 0; i < NUM_DICE; i++)
    {
        int diceRollIndex = dice[i] - 1;
        counts[diceRollIndex] = counts[diceRollIndex] + 1;
    }
}

bool isYahtzee(const int dice[])
{
    // check if all dice have the same value
    int num = dice[0];
    bool isYahtzeeBool = true;

    for(int i = 1; i < NUM_DICE; i++)
    {
        if(dice[i] != num)
        {
            isYahtzeeBool = false;
        }
    }

    return isYahtzeeBool;
}

bool isFourOfAKind(const int counts[])
{
    // check if any number appears exactly four times
    bool isFourOfAKindBool = false;

    for(int i = 0; i < NUM_SIDES; i++)
    {
        if(counts[i] == 4)
        {
            isFourOfAKindBool = true;
        }
    }

    return isFourOfAKindBool;
}

bool hasTwoEqual(const int counts[])
{
    // check if any number appears exactly two times
    bool hasTwoEqualBool = false;

    for(int i = 0; i < NUM_SIDES; i++)
    {
        if(counts[i] == 2)
        {
            hasTwoEqualBool = true;
        }
    }

    return hasTwoEqualBool;
}

bool hasThreeEqual(const int counts[])
{
    // check if any number appears exactly three times
    bool hasThreeEqualBool = false;

    for(int i = 0; i < NUM_SIDES; i++)
    {
        if(counts[i] == 3)
        {
            hasThreeEqualBool = true;
        }
    }

    return hasThreeEqualBool;
}

bool isThreeOfAKind(const int counts[])
{
    // check if any number appears exactly three times and no number appears exactly two times
    // function: hasThreeEqual, hasTwoEqual
    if(hasThreeEqual(counts) && !hasTwoEqual(counts))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFullHouse(const int counts[])
{
    // check if any number appears exactly three times and any number appears exactly two times
    // function: hasThreeEqual, hasTwoEqual
    if(hasThreeEqual(counts) && hasTwoEqual(counts))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLargeStraight(const int counts[])
{
    // check if the dice show 1-2-3-4-5 or 2-3-4-5-6
    if((counts[0] == 1 && counts[1] == 1 && counts[2] == 1 && counts[3] == 1 && counts[4] == 1) || (counts[1] == 1 && counts[2] == 1 && counts[3] == 1 && counts[4] == 1 && counts[5] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSmallStraight(const int counts[])
{
    // check if the dice show 1-2-3-4 or 2-3-4-5 or 3-4-5-6
    if((counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1) || (counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1) || (counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1 && counts[5] >= 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int decidePlay(const int dice[])
{
    // count how many times each number appears in the dice
    // function: countNumber
    int counts[NUM_SIDES];

    for(int i = 0; i < NUM_SIDES; i++)
    {
        counts[i] = 0;
    }

    countNumber(dice, counts);

    // check if there is any play and return the appropriate value
    // functions: isYahtzee, isFullHouse, isFourOfAKind, isThreeOfAKind, isLargeStraight, isSmallStraight
    if(isYahtzee(dice))
        return YAHTZEE;
    else if(isFullHouse(counts))
        return FULL_HOUSE;
    else if(isFourOfAKind(counts))
        return FOUR_OF_A_KIND;
    else if(isThreeOfAKind(counts))
        return THREE_OF_A_KIND;
    else if(isLargeStraight(counts))
        return L_STRAIGHT;
    else if(isSmallStraight(counts))
        return S_STRAIGHT;
    else
        return NO_PLAY;
}