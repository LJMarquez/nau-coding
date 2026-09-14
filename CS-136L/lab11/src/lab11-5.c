/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// TODO: define your enum here
typedef enum FileMode
{
    READ,
    OVERWRITE,
    APPEND,
    NUM_MODES
} FileMode;

// main program
int main()
{
    const char* fileName = "myfile.txt";

    // TODO: create an array with the mode of operations in the enum order
    char *modes[NUM_MODES] = {"r", "w", "a"};
    
    // TODO: open the file stream with the given mode
    FILE *file = fopen(fileName, modes[OVERWRITE]);

    // if the stream is open
    if(file != NULL)
    {
        // TODO: inform the user
        printf("File opened in mode '%s'", modes[OVERWRITE]);

    }

    // close the file stream
    fclose(file);

    // return success
    return 0;
}
