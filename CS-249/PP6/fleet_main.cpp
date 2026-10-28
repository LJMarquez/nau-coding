#include "fleet_lib.h"

static void printQueue(Queue& queue)
{
    char value[MESSAGE_LEN];
    while (!queue.isEmpty())
    {
        queue.dequeue(value);
        cout << value << " -> ";
    }
    cout << "NULL" << endl;
}

int main()
{
    int choice = 1;

    while (choice != 8)
    {
        cout << "\nFleet Control System\n" << endl;
        cout << "1. Validate Delivery Path" << endl;
        cout << "2. Check Symmetric Route" << endl;
        cout << "3. Decode Drone Instructions" << endl;
        cout << "4. Evaluate Path Conditions" << endl;
        cout << "5. Reverse Delivery Routes" << endl;
        cout << "6. Rotate Delivery Schedule" << endl;
        cout << "7. Merge Delivery Routes" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Validate Delivery Path" << endl;
                Node* path = createNode("(");
                path->next = createNode("{");
                path->next->next = createNode("[");
                path->next->next->next = createNode("]");
                path->next->next->next->next = createNode("}");
                path->next->next->next->next->next = createNode(")");

                if (validateDeliveryPath(path))
                {
                    cout << "Valid delivery path" << endl;
                }
                else
                {
                    cout << "Invalid delivery path" << endl;
                }

                freeNodeList(path);
                break;
            }

            case 2:
            {
                cout << "Symmetric Route" << endl;
                Node* route = createNode("Route A");
                route->next = createNode("Route B");
                route->next->next = createNode("Route C");
                route->next->next->next = createNode("Route B");
                route->next->next->next->next = createNode("Route A");

                if (isSymmetricRoute(route))
                {
                    cout << "The route is symmetric" << endl;
                }
                else
                {
                    cout << "The route is not symmetric" << endl;
                }

                freeNodeList(route);
                break;
            }

            case 3:
            {
                cout << "Decoding Drone Instructions" << endl;
                Node* instructions = createNode("2");
                instructions->next = createNode("[");
                instructions->next->next = createNode("Hover");
                instructions->next->next->next = createNode("1");
                instructions->next->next->next->next = createNode("[");
                instructions->next->next->next->next->next = createNode("Scan");
                instructions->next->next->next->next->next->next = createNode("2");
                instructions->next->next->next->next->next->next->next = createNode("[");
                instructions->next->next->next->next->next->next->next->next = createNode("FlyTo");
                instructions->next->next->next->next->next->next->next->next->next = createNode("]");
                instructions->next->next->next->next->next->next->next->next->next->next = createNode("]");
                instructions->next->next->next->next->next->next->next->next->next->next->next = createNode("]");

                decodeInstructions(instructions);
                freeNodeList(instructions);
                break;
            }

            case 4:
            {
                cout << "Evaluating Path Conditions" << endl;
                Node* expression = createNode("6");
                expression->next = createNode("3");
                expression->next->next = createNode("+");
                expression->next->next->next = createNode("4");
                expression->next->next->next->next = createNode("*");
                expression->next->next->next->next->next = createNode("3");
                expression->next->next->next->next->next->next = createNode("/");

                cout << "Result of path evaluation: "
                     << evaluatePathConditions(expression) << endl;
                freeNodeList(expression);
                break;
            }

            case 5:
            {
                cout << "Reversing Delivery Routes" << endl;
                Queue queue;
                queue.enqueue("Point D");
                queue.enqueue("Point B");
                queue.enqueue("Point A");
                queue.enqueue("Point E");
                queue.enqueue("Point F");
                queue.enqueue("Point C");

                reverseDelivery(&queue);
                printQueue(queue);
                break;
            }

            case 6:
            {
                cout << "Rotating Delivery Schedule" << endl;
                Queue schedule;
                schedule.enqueue("Delivery 1");
                schedule.enqueue("Delivery 2");
                schedule.enqueue("Delivery 3");
                schedule.enqueue("Delivery 4");
                schedule.enqueue("Delivery 5");
                schedule.enqueue("Delivery 6");

                rotateDelivery(&schedule, 28);
                printQueue(schedule);
                break;
            }

            case 7:
            {
                cout << "Merging Delivery Routes" << endl;
                Queue q1;
                Queue q2;
                q1.enqueue("Route A1");
                q1.enqueue("Route A2");
                q1.enqueue("Route A3");
                q2.enqueue("Route B1");
                q2.enqueue("Route B2");

                Queue* merged = mergeDeliveryRoutes(&q1, &q2);
                printQueue(*merged);
                delete merged;
                break;
            }

            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option, please try again." << endl;
        }
    }

    return 0;
}
