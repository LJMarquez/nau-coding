/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files

// main program
int main()
{
    // open a stream in write mode
    FILE *file = fopen("example.txt", "w");
    // if the stream is open
    if (file)
    {
        // write into the file connected to the stream
        fprintf(file, "Hello, File ADT!\n");
        // close the stream
        fclose(file);
    }
    // return success
    return 0;
}
