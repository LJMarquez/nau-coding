#include "hangman_lib.h"

const char *FRUITS[LEN_FRUITS] = {"abiu", "acai", "acerola", "akebi", "ackee", "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry", "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel", "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut", "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian", "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin", "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia", "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit", "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo", "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe", "galia", "melon", "honeydew", "watermelon", "mulberry", "nance", "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya", "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum", "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate", "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant", "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry", "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};

void initializeRandom()
{
    srand(time(NULL));
}

int getSecretWord(char secretWord[])
{
    int randomIndex = rand() % LEN_FRUITS;
    strcpy(secretWord, FRUITS[randomIndex]);

    return strlen(secretWord);
}

void buildOutputArray(int size, char outputArray[])
{
    for(int i = 0; i < size - 1; i++)
    {
        outputArray[i] = '_';
    }
    outputArray[size - 1] = '\0';
}

void buildAttemptArray(char attempts[])
{
    for(int i = 0; i < ATTEMPTS; i++)
    {
        attempts[i] = '*';
    }
    attempts[ATTEMPTS] = '\0';
}

bool checkGuess(char guess, const char secretWord[])
{
    for(int i = 0; secretWord[i] != '\0'; i++)
    {
        if(guess == secretWord[i])
        {
            return true;
        }
    }

    return false;
}

bool fillOutputArray(char guess, const char secretWord[], char outputArray[])
{
    bool isFilled = false;
    for(int i = 0; secretWord[i] != '\0'; i++)
    {
        if(guess == secretWord[i])
        {
            if(outputArray[i] == '_')
            {
                outputArray[i] = guess;
                isFilled = true;
            }
        }
    }

    return isFilled;
}

bool fillAttemptsArray(char guess, char attempts[])
{
    for(int i = 0; attempts[i] != '\0'; i++)
    {
        if(attempts[i] == guess)
        {
            return false;
        }
    }

    for(int i = 0; attempts[i] != '\0'; i++)
    {
        if(attempts[i] == '*')
        {
            attempts[i] = guess;
            return true;
        }
    }

    return false;
}

bool checkVictory(const char outputArray[])
{
    for(int i = 0; outputArray[i] != '\0'; i++)
    {
        if(outputArray[i] == '_')
        {
            return false;
        }
    }

    return true;
}

bool checkDefeat(const char attempts[])
{
    for(int i = 0; attempts[i] != '\0'; i++)
    {
        if(attempts[i] == '*')
        {
            return false;
        }
    }

    return true;
}

bool play(bool *giveup)
{
    *giveup = false;

    char secretWord[MAX_FRUIT_SIZE];
    getSecretWord(secretWord);

    char outputArray[MAX_FRUIT_SIZE];
    buildOutputArray(strlen(secretWord) + 1, outputArray);

    char attempts[ATTEMPTS + 1];
    buildAttemptArray(attempts);

    char guess;

    printf("Which letter? (0 to exit the game):\n");
    scanf(" %c", &guess);

    while(guess != '0' && !checkVictory(outputArray) && !checkDefeat(attempts))
    {
        if(checkGuess(guess, secretWord))
        {
            fillOutputArray(guess, secretWord, outputArray);
            printf("%s\n", outputArray);
        }
        else
        {
            fillAttemptsArray(guess, attempts);
            printf("The letter doesn't exist in the word.\n");
            printf("Mistakes: %s\n", attempts);
        }

        if(checkDefeat(attempts))
        {
            printf("The secret word was: %s\n", secretWord);
        }
        else if(!checkVictory(outputArray))
        {
            printf("Which letter? (0 to exit the game):\n");
            scanf(" %c", &guess);
        }
    }

    if(guess == '0')
    {
        *giveup = true;
        return false;
    }

    return checkVictory(outputArray);
}