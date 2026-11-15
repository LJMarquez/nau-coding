#include "stock_market_lib.h"

int main()
{
    StockMarket market;
    int choice = 0;
    int k = 0;
    float performance = 0.0f;
    char identifier[IDENTIFIER_SIZE];

    while (choice != 7)
    {
        cout << "\nStock Market Analysis Menu:" << endl;
        cout << "1. Add Stock" << endl;
        cout << "2. Remove Stock" << endl;
        cout << "3. View All Stocks" << endl;
        cout << "4. Sort Stocks by Performance" << endl;
        cout << "5. Find Kth Largest Stock" << endl;
        cout << "6. Find Top K Frequent Stocks" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Stock Identifier: ";
                cin >> identifier;
                cout << "Enter Stock Performance: ";
                cin >> performance;

                if (market.addStock(identifier, performance))
                {
                    cout << "Stock added successfully" << endl;
                }
                else
                {
                    cout << "Market may be full. Try again later" << endl;
                }
                break;

            case 2:
                cout << "Enter Stock Identifier to Remove: ";
                cin >> identifier;

                if (market.removeStock(identifier))
                {
                    cout << "Stock removed successfully" << endl;
                }
                else
                {
                    cout << "Stock cannot be found in the current market"
                         << endl;
                }
                break;

            case 3:
                market.viewAllStocks();
                break;

            case 4:
                market.sortStocks();
                cout << "Market successfully sorted" << endl;
                break;

            case 5:
            {
                cout << "Enter value of K: ";
                cin >> k;

                Stock* kthLargest = market.findKthLargest(k);

                if (kthLargest != nullptr)
                {
                    cout << "Kth Largest Stock: Identifier: "
                         << kthLargest->identifier << ", Performance: "
                         << kthLargest->performance << endl;
                    delete kthLargest;
                }
                else
                {
                    cout << "Invalid value for K." << endl;
                }
                break;
            }

            case 6:
                cout << "Enter value of K: ";
                cin >> k;
                market.topFreqStocks(k);
                break;

            case 7:
                cout << "Come back another time!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }

    return 0;
}
