/**
 * Driver: Austin Squier
 * Navigator: Leo Marquez
 **/

// header file
#include <stdio.h>
#include <math.h>

// main program
int main()
{
    // initialization
        // TODO: declare variables to store CI, P, A, r, n, and t
        //  (use more meaningful names)
    double compoundInterest, principalAmount, finalAmount, interestRate, compoundingFrequency;
    int years;
    
    // user input
        // TODO: prompt and read variables in this order: P, r, n, t 
        //  (include the FSPP comments)
    
    // user input
        // prompt for principal amount
    printf("Type principal amount: ");

        // read principal amount
    scanf("%lf", &principalAmount);

        // prompt for interest rate
    printf("Type interest rate: ");

        // read interest rate
    scanf("%lf", &interestRate);
    
        // prompt for compounding frequency
    printf("Type compounding frequency: ");

        // read compounding frequency
    scanf("%lf", &compoundingFrequency);

        // prompt for years
    printf("Type years: ");

        // read years
    scanf("%d", &years);

        // processing
            // TODO: calculate the final amount (A)
    finalAmount = principalAmount * pow((1 + (interestRate / (100 * compoundingFrequency))), compoundingFrequency * years);
    
            // TODO: calculate the compound interest (CI)
    compoundInterest = finalAmount - principalAmount;
    
    // output
        // print the final amount
    printf("he final amount (A) is: $%.2lf\n", finalAmount);
        // print the final compound interest
    printf("The compound interest (CI) is: $%.2lf\n", compoundInterest);

    // end program
        // return success
    return 0;
}
