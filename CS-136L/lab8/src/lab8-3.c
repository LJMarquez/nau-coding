/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// function prototypes
void printFile(const char* filename);

// main program
int main()
{
    // create the new text
    char* newText = "\n\nNew adventures await, filled with unexpected twists, "
                    "daring encounters, and perhaps even more trolls with a "
                    "taste for the extraordinary!";

    // TODO: declare a pointer to a stream initially set to NULL
    

    // TODO: open the file "story.txt" for reading
    

    // if the file was successfully opened
    if (file != NULL)
    {
        // TODO: write the newText to the end of the file
            // function: fputs
        

        // TODO: close the stream
        
    }
    // file couldn't be opened
    else
    {
        // inform the user
        printf("Error: Could not open file 'story.txt'.\n");
    }
    
    // print the file
    printFile("story.txt");
    
    // end program
    return 0;
}
