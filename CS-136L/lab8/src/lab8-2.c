/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// main program
int main()
{
    // TODO: declare a pointer to a stream initially set to NULL
    

    // TODO: open the file "story.txt" for reading
    

    // if the stream was successfully opened
    if (file != NULL)
    {
        // read the first character
        char ch = fgetc(file);
        // while there is data in the file
        while (ch != EOF)
        {
            // print each character to the system's output
            putchar(ch);
            // read the next character
            ch = fgetc(file);
        }
        // TODO: close the stream
        
    }
    // file couldn't be opened
    else
    {
        // inform the user
        printf("Error: Could not open file 'story.txt'.\n");
    }

    // end program
    return 0;
}
