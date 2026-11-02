#include "router_lib.h"

int main()
{
    Router network;
    int option = 0;
    int router_id = 0;

    while (option != 9)
    {
        cout << "\nNetFlow: Router Traffic Management" << endl;
        cout << "1. Add a new router" << endl;
        cout << "2. Remove a faulty router" << endl;
        cout << "3. Invert the router network" << endl;
        cout << "4. Ensure symmetrical routing" << endl;
        cout << "5. Analyze maximum network depth" << endl;
        cout << "6. Get right-side view of router network" << endl;
        cout << "7. Identify high-traffic routers" << endl;
        cout << "8. Print the network" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
            case 1:
                do
                {
                    cout << "Enter router ID to add or -1 to exit: ";
                    cin >> router_id;
                    if (router_id != -1)
                    {
                        network.addRouter(router_id);
                    }
                }
                while (router_id != -1);
                break;

            case 2:
                cout << "Enter router ID to remove: ";
                cin >> router_id;
                network.removeRouter(router_id);
                break;

            case 3:
                cout << "Inverting the router network..." << endl;
                network.invertNetwork();
                if (network.getRoot() != nullptr)
                {
                    cout << "Router network inverted successfully." << endl;
                }
                else
                {
                    cout << "Network is empty" << endl;
                }
                break;

            case 4:
                if (network.isRoutingSymmetric())
                {
                    cout << "The routing is symmetrical." << endl;
                }
                else
                {
                    cout << "Imbalanced routing detected." << endl;
                }
                break;

            case 5:
                cout << "The maximum network depth is "
                     << network.getMaxNetworkDepth() << "." << endl;
                break;

            case 6:
                network.getRouterRightView();
                break;

            case 7:
                network.findHighTrafficRouters();
                break;

            case 8:
                cout << "Routers in the network: ";
                network.printNetwork();
                break;

            case 9:
                cout << "Exiting NetFlow Management System." << endl;
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}
