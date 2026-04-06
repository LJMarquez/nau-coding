// header files
#include "fileUtility.h"

// main program
int main()
{
    // initialization
        // create an array with names of categories
    char *categoryNames[LEN_CATEGORY] = {"Produce", "Dairy", "Meat", "Bakery",
        "Frozen", "Beverages", "Snacks", "Canned Goods", "Pantry", "Condiments",
        "Other"};

    // Test splitEvenOdd
        // print a title
            // function: puts
    puts("\nFunction: splitEvenOdd");
    puts("========================");
        // create an array of numbers
    int numbers[] = {10, 15, 22, 33, 42, 51, 60, 73, 88, 97};
        // get the size of the array
    int size = sizeof(numbers) / sizeof(numbers[0]);
        // print the initial array
            // function: puts
    printf("The array of numbers to split: ");
        // traverse the array
    for(int i = 0; i < size; i++)
    {
        // print the current number
            // function: printf
        printf("%d ", numbers[i]);
    }
        // cosmetic
            // function: printf
    printf("\n");
        // create a variable to hold the return
    bool success = false;
        // TODO: split the array of numbers into even and odd files
            // function: splitEvenOdd
    success = splitEvenOdd(numbers, size);

        // if the split succeeded
    if(success)
    {
        // print a confirmation message
            // function: puts
        puts("Even and odd numbers have been successfully split into "
             "even.csv and odd.csv.\n");
    }
        // otherwise
    else
    {
        // print a confirmation message
            // function: puts
        puts("Failed to split even and odd numbers.\n");
    }

    // Test readProductPrice
        // print a title
            // function: puts
    puts("\nFunction: readProductPrice");
    puts("============================");
        // create the arrays to hold names, prices, and category
    char productNames[MAX_ARRAY_SIZE][MAX_STRING_SIZE];
    float productPrices[MAX_ARRAY_SIZE];
    ProductCategory productCategories[MAX_ARRAY_SIZE];
        // create a variable to store the result
    int productCount;
        // TODO: read the product information
            // function: readProduct
    productCount = readProduct(PRODUCT_FILENAME, productNames, productPrices, productCategories);

        // if the reading returned a products count
    if(productCount > 0)
    {
        // print the product counts
            // function: puts
        puts("\nProducts read from the file:");
        // traverse the arrays
        for(int i = 0; i < productCount; i++)
        {
            // get the category code
            ProductCategory category = productCategories[i];
            // print the current product, price, category
                // function: printf
            printf("Product: %s, Price: %.2f, Category: %s\n", productNames[i], 
                productPrices[i], categoryNames[category]);
        }
    }
    // otherwise, something went wrong
    else
    {
        // print a message
            // function: printf
        printf(
            "\nFailed to read products from the file or the file is empty.\n");
    }

    // Test getAvgRatingPerYear
        // print a title
            // function: puts
    puts("\nFunction: getAvgRatingPerYear");
    puts("===============================");

        // TODO: calculate the rating per year from the file
            // function: getAvgRatingPerYear
    success = getAvgRatingPerYear(MOVIES_INPUT_FILENAME, MOVIES_OUTPUT_FILENAME);

        // if the calculation is successful
    if(success)
    {
        // print a message
            // function: printf
        printf("\nAverage ratings per year have been calculated and saved to"
               "%s\n\n",
            MOVIES_OUTPUT_FILENAME);
    }
        // otherwise, something went wrong
    else
    {
        // print a message
            // function: puts
        puts("\nFailed to calculate average ratings per year.\n");
    }

    // end program
        // print a message
            // function: puts
    puts("End of program\n");
        // return success
    return 0;
}
