/**
 * Driver: Leo Marquez
 * Navigator: Austin Squier
 **/

// header file
#include <stdio.h>

// global constants
#define MAX_NAME_LENGTH 21
// main program
int main()
{
    // initialization
        // declare variables for the students
    char student1[MAX_NAME_LENGTH], student2[MAX_NAME_LENGTH], 
        student3[MAX_NAME_LENGTH];
        // declare variables for the grades
    float grade1, grade2, grade3;

    // user input
        // prompt for student1 name
    printf("Enter the first student's name: ");
        // read student1 name
    scanf("%20s", student1);
        // prompt for student1 grade
    printf("Enter the first student's grade: ");
        // read student2 grade
    scanf("%f", &grade1);

        // prompt for student2 name
    printf("Enter the second student's name: ");
        // read student2 name
    scanf("%20s", student2);
        // prompt for student2 grade
    printf("Enter the second student's grade: ");
        // read student2 grade
    scanf("%f", &grade2);

        // prompt for student3 name
    printf("Enter the third student's name: ");
        // read student3 name
    scanf("%20s", student3);
        // prompt for student3 grade
    printf("Enter the third student's grade: ");
        // read student3 grade
    scanf("%f", &grade3);

        // output
            // TODO: print the table
    printf("| Student              | Grade |\n");
    printf("|----------------------|-------|\n");
    printf("| %s                 | %.1lf   |\n", student1, grade1);
    printf("| %s                | %.1lf   |\n", student2, grade2);
    printf("| %s                 | %.1lf   |\n", student3, grade3);
    
    // end program
        // return success
    return 0;
}
