#include "stock_market_lib.h"

/*
 * Student note:
 * Use stock_market_lib.h for the exact function and method signatures.
 * Any method intentionally left without a definition in this template is
 * student work and should be implemented here using the declarations in the
 * header file.
 */
StockMarket::StockMarket()
{
    size = 0;
}


/**
 * Task 1: Add a New Stock
 * Input arguments: identifier - a string representing the stock identifier
 *                  performance - a float representing the stock performance
 * Output argument: the market may be updated
 * Return: true if the stock is successfully added or false otherwise
 * Dependencies: upHeapify
 */
bool StockMarket::addStock(const char* identifier, float performance)
{
    if(size == MAX_STOCKS)
    {
        return false;
    }

    int i = 0;

    while(identifier[i] != '\0' && i < IDENTIFIER_SIZE - 1)
    {
        stocks[size].identifier[i] = identifier[i];
        i++;
    }

    stocks[size].identifier[i] = '\0';
    stocks[size].performance = performance;

    size++;
    upHeapify(size - 1);

    return true;
}



/**
 * Task 2: Remove a Stock
 * Input arguments: identifier - a string representing the stock identifier
 * Output argument: the market may be updated
 * Return: true if the stock is successfully removed or false otherwise
 * Dependencies: downHeapify
 */
bool StockMarket::removeStock(const char* identifier)
{
    bool found = false;

    if(size == 0)
    {
        return found;
    }

    int i = 0;
    while(!found && i < size)
    {
        int j = 0;

        while(identifier[j] == stocks[i].identifier[j] && identifier[j] != '\0')
        {
            j++;
        }

        if(identifier[j] == '\0' && stocks[i].identifier[j] == '\0')
        {
            found = true;
            stocks[i] = stocks[size - 1];
            size--;
            if(i < size)
            {
                downHeapify(i);
            }
        }
        else
        {
            i++;
        }
    }

    return found;
}



/**
 * Task 3: View All Stocks
 * Output argument: prints all stocks currently in the market
 * Return: none
 * Dependencies: stream output
 */
void StockMarket::viewAllStocks() const
{
    cout << "Stocks in the market:" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Identifier: " << stocks[i].identifier << ", Performance: " << stocks[i].performance << endl;
    }
}



/**
 * Task 4: Sort Stocks by Performance
 * Output argument: prints stocks in ascending order of performance
 * Return: none
 * Dependencies: downHeapify, swap, viewAllStocks
 */
void StockMarket::sortStocks() const
{
    StockMarket temp = *this;
    int initialSize = temp.size;

    while(temp.size > 1)
    {
        temp.swap(temp.stocks[0], temp.stocks[temp.size - 1]);
        temp.size--;
        temp.downHeapify(0);
    }

    temp.size = initialSize;
    temp.viewAllStocks();
}



/**
 * Task 5: Identify the Kth Largest Stock
 * Input argument: k - the order statistic to find
 * Output argument: none
 * Return: pointer to the kth largest stock or nullptr if k is invalid
 * Dependencies: removeStock
 */
Stock* StockMarket::findKthLargest(int k) const
{
    if(k <= 0 || k > size)
    {
        return nullptr;
    }
    else
    {
        Stock kthLargest = stocks[k - 1];

        cout << "Kth Largest Stock: Identifier: " << kthLargest.identifier << ", Performance: " << kthLargest.performance;
        return new Stock(kthLargest);
    }
}



/**
 * Task 6: Find the Top K Most Frequent Stocks
 * Input argument: k - the number of unique performance values to show
 * Output argument: prints the requested frequency summary
 * Return: none
 * Dependencies: stream output
 */
void StockMarket::topFreqStocks(int k) const
{
    if(size > 0)
    {
        float performanceList[size];
        int occurrenceList[size];
        performanceList[0] = stocks[0].performance;
        occurrenceList[0] = 1;
        int performanceListIndex = 0;
        for(int i = 1; i < size; i++)
        {
            if(stocks[i].performance == stocks[i - 1].performance)
            {
                occurrenceList[performanceListIndex] += 1;
            }
            else
            {
                performanceListIndex++;
                performanceList[performanceListIndex] = stocks[i].performance;
                occurrenceList[performanceListIndex] = 1;
            }
        }
        
        int stocksToPrint;
        
        if(k > performanceListIndex + 1)
        {
            cout << "There is not enough performances." << endl;
            cout << "Showing the top " << performanceListIndex + 1 << "frequent stocks based on performance:" << endl;
            stocksToPrint = performanceListIndex + 1;
        }
        else
        {
            cout << "Top " << k << "frequent stocks based on performance:" << endl;
            stocksToPrint = k;
        }
        
        for(int i = 0; i < stocksToPrint; i++)
        {
            cout << "Performance: " << performanceList[i] << " (Occurrences: " << occurrenceList[i] << ")" << endl;
        }
    }
}



/**
 * Function: upHeapify
 * Input argument: index - index of the node to repair upward
 * Output argument: the market heap may be updated
 * Return: none
 * Dependencies: swap, upHeapify
 */
void StockMarket::upHeapify(int index)
{
    if(stocks[index].performance > stocks[(index - 1)/2].performance && index > 0)
    {
        swap(stocks[index], stocks[(index - 1)/2]);
        upHeapify((index - 1)/2);
    }
}



/**
 * Function: downHeapify
 * Input argument: index - index of the node to repair downward
 * Output argument: the market heap may be updated
 * Return: none
 * Dependencies: swap, downHeapify
 */
void StockMarket::downHeapify(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if(stocks[index].performance < stocks[left].performance || stocks[index].performance < stocks[right].performance)
    {
        if(stocks[left].performance < stocks[right].performance && left < size)
        {
            swap(stocks[index], stocks[left]);
            downHeapify(left);
        }
        else
        {
            if(right < size)
            {
                swap(stocks[index], stocks[right]);
                downHeapify(right);
            }
        }
    }
}



/**
 * Function: swap
 * Input arguments: a, b - references to two stocks
 * Output argument: the stocks are exchanged
 * Return: none
 * Dependencies: none
 */
void StockMarket::swap(Stock& a, Stock& b)
{
    Stock temp = a;
    a = b;
    b = temp;
}