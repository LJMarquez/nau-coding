// header files
#include "mystring.h"

int main()
{
    // Test caesarCipher
        // print a title
            // function: puts
    puts("\nFunction: caesarCipher");
    puts("======================");
        // create a message
    char message1[MAX_STR_SIZE] = "Hello, World!";
        // define a number of shifts
    int shift = 3;
        // print the original message
            // function: printf
    printf("Original message: %s\n", message1);
        // TODO: encode the message
            // function: caesarCipher
    caesarCipher(message1, shift);
    


        // print the encoded message
            // function: printf
    printf("Caesar Cipher (shift %d): %s\n", shift, message1);
        // TODO: decode the message
            // function: caesarCipher
    caesarCipher(message1, -shift);
    
    

        // print the decoded message
            // function: printf
    printf("Caesar Cipher (shift %d): %s\n\n", -shift, message1);

    // Test uniqueChar
        // print a title
            // function: puts
    puts("Function: uniqueChar");
    puts("====================");
        // create a message
    const char *message2 = "Hi there! This is a test message.";
        // create a variable to store the unique count
    int uniqueCount;
        // TODO: count the unique characters
            // function: uniqueChar
    uniqueCount = uniqueChar(message2);



        // print the n
    printf("The message: \"%s\" contains %d unique letters.\n\n", message2, 
        uniqueCount);

    // Test countTotalCharacters
        // print a title
            // function: puts
    puts("Function: countTotalCharacters");
    puts("==============================");
        // create the function to store the total number of characters
    int totalChars;
        // TODO: count the total number of characters
            // function: countTotalCharacters
    totalChars = countTotalCharacters();
    

        // print the result
            // function: printf
    printf("You typed a total of %d characters.\n\n", totalChars);

    // Test reverseString
        // print a title
            // function: puts
    puts("Function: reverseString");
    puts("=======================");
        // define the string to reverse
    char message3[MAX_STR_SIZE] = "Reverse this string!";
        // print the original message
            // function: printf
    printf("Original message: %s\n", message3);
        // TODO: reverse the message
            // function: reverseString
    reverseString(message3);



        // print the reversed message
            // function: printf
    printf("Reversed message: %s\n\n", message3);

    // Test removeWhitespace
        // print a title
            // function: puts
    puts("Function: removeWhitespace");
    puts("==========================");
        // create a message with whitespaces
    char message4[MAX_STR_SIZE] = "  Remove    all   the   spaces!   ";
        // print the original message
            // function: printf
    printf("Original message: \"%s\"\n", message4);
        // TODO: remove the whitespaces
            // function: removeWhitespace
    removeWhitespace(message4);
    

        // print the cleaned message
            // function: printf
    printf("Message without whitespace: \"%s\"\n\n", message4);

    // end program
        // print a message
            // function: puts
    puts("End of program\n");
        // return success
    return 0;
}
