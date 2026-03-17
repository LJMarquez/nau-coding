#include "mystring.h"

void caesarCipher(char *message, int shift)
{
    int normalizedShift = shift % ALPHABET_SIZE;
    if(normalizedShift < 0)
    {
        normalizedShift += ALPHABET_SIZE;
    }

    int messageLength = strlen(message);
    for(int i = 0; i < messageLength; i++)
    {
        if(isalpha(message[i]) != 0)
        {
            char upperChar = toupper(message[i]);
            message[i] = (upperChar - 'A' + normalizedShift) % ALPHABET_SIZE + 'A';
        }
    }
}

int uniqueChar(const char *message)
{
    bool seen[ALPHABET_SIZE] = {false};
    int count = 0;

    int messageLength = strlen(message);
    for(int i = 0; i < messageLength; i++)
    {
        if(isalpha(message[i]) != 0)
        {
            char lowerChar = tolower(message[i]);
            int index = lowerChar - 'a';
            if(!seen[index])
            {
                seen[index] = true;
                count++;
            }
        }
    }
    return count;
}

int countTotalCharacters()
{
    char message[MAX_STR_SIZE];
    int totalChars = 0;
    bool keepReading = true;

    while(keepReading)
    {
        printf("Type a message (or \"quit\" to exit): ");
        int scanStatus = scanf("%254[^\n]", message);
        if(scanStatus == 1)
        {
            scanf("%*c");

            if(strcmp(message, "quit") == 0)
            {
                keepReading = false;
            }
            else
            {
                totalChars += strlen(message);
            }
        }
        else if(scanStatus == 0)
        {
            scanf("%*c");
        }
        else
        {
            keepReading = false;
        }
    }

    return totalChars;
}

void reverseString(char *message)
{
    int messageLength = strlen(message);
    for(int i = 0; i < messageLength / 2; i++)
    {
        char temp = message[i];
        message[i] = message[messageLength - 1 - i];
        message[messageLength - 1 - i] = temp;
    }
}

void removeWhitespace(char *message)
{
    int writeIndex = 0;
    for(int i = 0; message[i] != '\0'; i++)
    {
        if(!isspace(message[i]))
        {
            message[writeIndex] = message[i];
            writeIndex++;
        }
    }

    message[writeIndex] = '\0';
}