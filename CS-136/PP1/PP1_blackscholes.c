// header files
#include <stdio.h>
#include <math.h>

// global constants
#define HALF 0.5
#define COEFF 1
#define SQRT_COEFF 2

// prototypes
double normalCDF(double zScore);

// main program
int main()
{
    // initialize the program
        // declare user input variables
    double currentStockPrice, strikePrice, riskFreeInterestRate, timeToExpire,
        sigma;
        // declare supporting variables
    double ratioStockStrike, growthRate, sumRatioGrowth, overTimeVolatility,
        expectedStockValue, expectedStrikePrice;
        // declare user output variables
    double d1factor, d2factor, d1NormalDistr, d2NormalDistr, premium;
    
        // show title
            // function: printf
    printf("\nCall Option Price Calculator (Black-Scholes Model)\n");
    printf("==================================================\n\n");
    
    // get the user input
        // print a message explaining the steps
            // function: printf
    printf("Please provide the data for Call Option Price calculation\n");
    
        // prompt for the current stock price
            // function: printf
    printf("Inform the current stock price (S):\n");
    
        // read the current stock price from the user input
            // function: scanf
    scanf("%lf", &currentStockPrice);
    
        // prompt for the strike price
            // function: printf
    printf("Inform the strike price (X):\n");
    
        // read the strike price from the user input
            // function: scanf
    scanf("%lf", &strikePrice);
    
        // prompt for the risk-free interest rate
            // function: printf
    printf("Inform the risk-free interest rate (r - a number between "
           "0.0-1.0):\n");
    
        // read the risk-free interest rate from the user input
            // function: scanf
    scanf("%lf", &riskFreeInterestRate);
    
        // prompt for the time to expiration in years
            // function: printf
    printf("Inform the time to expiration in years (T):\n");
    
        // read the time expiration from the user input
            // function: scanf
    scanf("%lf", &timeToExpire);
    
        // prompt for the volatility
            // function: printf
    printf("Inform the volatility (sigma - a number between 0.0-1.0):\n");
    
        // read the volatility from the user input
            // function: scanf
    scanf("%lf", &sigma);
    
    // process the data
        // print a message to inform the user about the processing
    printf("\nCalculating the Call Option Price...\n\n");

        // TODO: calculate the log ratio of stock price to the strike price
            // function: log
    ratioStockStrike = log(currentStockPrice / strikePrice);
    
        // TODO: calculate the expected growth rate of the stock over time
    growthRate = riskFreeInterestRate + 0.5 * (sigma * sigma);
    
        // TODO: calculate the sum of the log ratio and expected growth rate
    sumRatioGrowth = ratioStockStrike + growthRate;
    
        // TODO: calculate the volatility of the stock over time
            // function: sqrt
    overTimeVolatility = sigma * sqrt(timeToExpire);
    
        // TODO: calculate d1
    d1factor = sumRatioGrowth / overTimeVolatility;
    
        // TODO: calculate d2
            // function: sqrt
    d2factor = d1factor - overTimeVolatility;
    
        // calculate the cummulative distribution estimation for d1
            // function: normalCDF
    d1NormalDistr = normalCDF(d1factor);
    
        // calculate the cummulative distribution estimation for d2
            // function: normalCDF
    d2NormalDistr = normalCDF(d2factor);
    
        // TODO: calculate the expected value of stock if option is exercised
    expectedStockValue = currentStockPrice * d1NormalDistr;
    
        // TODO: calculate the value of strike price if option is exercised
            // function: exp
    expectedStrikePrice = strikePrice * exp(-riskFreeInterestRate * timeToExpire);

        // TODO: calculate the premium (call option price)
    premium = expectedStockValue - (expectedStrikePrice * d2NormalDistr);

    // show the results
        // print out the Black-Scholes Call Option Price
            // function: printf
    printf("Black-Scholes Call Option Price: %.2lf\n\n", premium);
    
    // end program
        // print out a message
            // function: printf
    printf("End program.\n\n");

        // return success
    return 0;
}

// supporting functions
/*
Name: normalCDF
Process: calculates the cumulative distribution function (CDF) of the standard
         normal distribution for a given probability.
Function input/parameters: zScore - the z-score value used in the cumulative
         distribution function calculation
Function output/parameters: none
Function output/returned: cummulativeResult - the estimated value of the
                          cummulative distribution
Dependencies: math.h - erf, sqrt
*/
double normalCDF(double zScore)
{
    // commulative distribution calculation
        // functions: erf, sqrt
    double cummulativeResult = HALF * (COEFF + erf(zScore / sqrt(SQRT_COEFF)));
    // return the cummulative distribution result
    return cummulativeResult;
}
