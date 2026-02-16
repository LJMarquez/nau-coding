// header files
#include "utils.h"

// function definitions
int countFactors(int n)
{
    int factors = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors++;
        }
    }
    return factors;
}

bool isMultiple(int a, int b)
{
    if (a % b == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void printTriangle(int size)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int countDigits(int n)
{
    int digits = 0;
    while (n > 0)
    {
        n /= BASE;
        digits++;
    }
    return digits;
}

int getPositiveNumber()
{
    int n = -1;
    while (n <= 0)
    {
        printf("Enter a positive number: ");
        scanf("%d", &n);
    }
    return n;
}

char getYNOption()
{
    char userInput;
    while(userInput != 'Y' && userInput != 'N')
    {
        printf("Enter Y|N: ");
        scanf(" %c", &userInput);
        userInput = toupper(userInput);
    }
    return userInput;
}