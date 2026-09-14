/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>
#include <string.h>

// global definitions
#define STR_SIZE 100

// data types
    // TODO: define the enum here
typedef enum AccountType
{
    SAVINGS,
    CHECKING,
    BUSINESS
} AccountType;



    // TODO: define the struct here
typedef struct BankAccount
{
    int accountNumber;
    int routingNumber;
    char holder[STR_SIZE];
    AccountType accountType;
    double balance;
} Account;

// TODO: write your function here
void createAccount(Account *account, int accountNumber, int routingNumber, const char *holder, AccountType type, double initialBalance)
{
    account->accountNumber = accountNumber;
    account->routingNumber = routingNumber;
    strcpy(account->holder, holder);
    account->accountType = type;
    account->balance = initialBalance;
}