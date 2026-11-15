#ifndef STOCK_MARKET_LIB_H
#define STOCK_MARKET_LIB_H

#include <iostream>

using namespace std;

const int MAX_STOCKS = 1000;
const int IDENTIFIER_SIZE = 20;

struct Stock
{
    char identifier[IDENTIFIER_SIZE];
    float performance;
};

class StockMarket
{
private:
    Stock stocks[MAX_STOCKS];
    int size;

    void upHeapify(int index);
    void downHeapify(int index);
    void swap(Stock& a, Stock& b);

public:
    StockMarket();

    bool addStock(const char* identifier, float performance);
    bool removeStock(const char* identifier);
    void viewAllStocks() const;
    void sortStocks() const;
    Stock* findKthLargest(int k) const;
    void topFreqStocks(int k) const;
};

#endif
