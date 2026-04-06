/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// global definitions
#define MAX_FILE_SIZE 10000
#define CREDIT_LINE "\n(This paragraph was created with AI-generated content.)"

// function prototypes
void printFile(const char* filename);

// main program
int main()
{
    // create a buffer to store file content
    char fileContent[MAX_FILE_SIZE];
    // define the new text
    char* newText = "\nNew adventures await, filled with unexpected twists, "
                    "daring encounters, and perhaps even more trolls with a "
                    "taste for the extraordinary!\n";
    
    // TODO: open the file as read-only
    

    // TODO: check if the stream opening fails
    
    {
        // print a message
        printf("Error: Could not open file 'story.txt'.\n");
        // end the program with an error code
        return 1;
    }

    // read the ENTIRE file into the buffer
        // size_t is just a large unsigned integer type
        // function: fread
    size_t bytesRead = fread(fileContent, 1, MAX_FILE_SIZE - 1, file);
    // null-terminate the content
    fileContent[bytesRead] = '\0';
    // TODO: close the stream
    fclose(file);

    // locate the AI credit line
        // function: strstr
    char *credit = strstr(fileContent, CREDIT_LINE);

    // TODO: open file for writing (overwrite mode)
    

    // TODO: check if the stream opening fails
    
    {
        // print a message
        printf("Error: Could not open file 'story.txt'.\n");
        // end the program with an error code
        return 1;
    }

    // if the strstr found the location of the credit line
    if (credit != NULL)
    {
        // calculate the index where the credit line starts
        size_t index = credit - fileContent;

        // write everything before the credit line
        fwrite(fileContent, 1, index, file);

        // TODO: insert the editor's note (newText)
            // function: fputs
        

        // TODO: write the credit line (credit)
            // function: fputs
        
    }
    // the credit line is not in the text
    else
    {
        // TODO: write the content in the buffer to the file (buffer)
            // function: fputs
        
        // TODO: write the new text at the end of the file (newText)
            // function: fputs
        
        // TODO: add the content in the constants at the end (CREDIT_LINE)
            // function: fputs
        
    }
    // TODO: close the stream
    
    // print the file
    printFile("story.txt");
    // return success
    return 0;
}
