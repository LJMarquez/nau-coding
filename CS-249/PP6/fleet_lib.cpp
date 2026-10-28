#include "fleet_lib.h"

static void copyValue(char* destination, const char* source)
{
    if (source == NULL)
    {
        destination[0] = '\0';
        return;
    }

    strncpy(destination, source, MESSAGE_LEN - 1);
    destination[MESSAGE_LEN - 1] = '\0';
}

// provided Node constructors
Node::Node()
{
    data[0] = '\0';
    next = NULL;
}

Node::Node(const char* value)
{
    copyValue(data, value);
    next = NULL;
}

// helper used by the Rule of Three
Node* Stack::copyList(Node* source)
{
    if (source == NULL)
    {
        return NULL;
    }

    Node* headCopy = NULL;
    Node* tailCopy = NULL;

    while (source != NULL)
    {
        Node* newNode = new Node(source->data);
        if (headCopy == NULL)
        {
            headCopy = newNode;
        }
        else
        {
            tailCopy->next = newNode;
        }
        tailCopy = newNode;
        source = source->next;
    }

    return headCopy;
}

// helper used by the Rule of Three
Node* Queue::copyList(Node* source)
{
    if (source == NULL)
    {
        return NULL;
    }

    Node* headCopy = NULL;
    Node* tailCopy = NULL;

    while (source != NULL)
    {
        Node* newNode = new Node(source->data);
        if (headCopy == NULL)
        {
            headCopy = newNode;
        }
        else
        {
            tailCopy->next = newNode;
        }
        tailCopy = newNode;
        source = source->next;
    }

    return headCopy;
}

// helper used by the Rule of Three
void Queue::rebuildRear()
{
    rear = front;
    while (rear != NULL && rear->next != NULL)
    {
        rear = rear->next;
    }
}

// provided Rule-of-Three support for Stack
Stack::Stack()
{
    top = NULL;
}

Stack::Stack(const Stack& other)
{
    top = copyList(other.top);
}

Stack& Stack::operator=(const Stack& other)
{
    if (this == &other)
    {
        return *this;
    }

    while (top != NULL)
    {
        Node* nextNode = top->next;
        delete top;
        top = nextNode;
    }

    top = copyList(other.top);
    return *this;
}

Stack::~Stack()
{
    while (top != NULL)
    {
        Node* nextNode = top->next;
        delete top;
        top = nextNode;
    }
}

// provided Rule-of-Three support for Queue
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::Queue(const Queue& other)
{
    front = copyList(other.front);
    rebuildRear();
}

Queue& Queue::operator=(const Queue& other)
{
    if (this == &other)
    {
        return *this;
    }

    while (front != NULL)
    {
        Node* nextNode = front->next;
        delete front;
        front = nextNode;
    }

    front = copyList(other.front);
    rebuildRear();
    return *this;
}

Queue::~Queue()
{
    while (front != NULL)
    {
        Node* nextNode = front->next;
        delete front;
        front = nextNode;
    }
    rear = NULL;
}

/**
 * Task 1: Validate Delivery Path
 * Input argument: routeHead - a pointer to the head node of a linked list
 *                  representing the delivery route
 * Output argument: none
 * Return: true if the path is valid, false otherwise
 * Dependencies: Stack constructor, push, pop
 */
bool validateDeliveryPath(Node* routeHead)
{
    // TODO: implement this function
    Stack bracketStack;
    Node* currentNode = routeHead;

    while(currentNode != NULL)
    {
        if(strcmp(currentNode->data, "(") == 0 ||
            strcmp(currentNode->data, "{") == 0 ||
            strcmp(currentNode->data, "[") == 0)
        {
            bracketStack.push(currentNode->data);
        }
        else
        {
            char openingBracket[MESSAGE_LEN];
            bool popped = bracketStack.pop(openingBracket);
            bool matchingBracket = false;

            if(popped)
            {
                if(strcmp(openingBracket, "(") == 0 &&
                    strcmp(currentNode->data, ")") == 0)
                {
                    matchingBracket = true;
                }
                else if(strcmp(openingBracket, "{") == 0 && strcmp(currentNode->data, "}") == 0)
                {
                    matchingBracket = true;
                }
                else if (strcmp(openingBracket, "[") == 0 && strcmp(currentNode->data, "]") == 0)
                {
                    matchingBracket = true;
                }
            }

            if(!matchingBracket)
            {
                return false;
            }
        }

        currentNode = currentNode->next;
    }

    return bracketStack.isEmpty();
}

/**
 * Task 2: Symmetric Route
 * Input argument: routeHead - a pointer to the head node of a linked list
 *                  representing the delivery route
 * Output argument: none
 * Return: true if the delivery route is symmetric, false otherwise
 * Dependencies: Stack constructor, push, pop
 *               cstring - strcmp
 */
bool isSymmetricRoute(Node* routeHead)
{
    // TODO: implement this function
    Stack routeStack;
    Node* currentNode = routeHead;

    while(currentNode != NULL)
    {
        routeStack.push(currentNode->data);
        currentNode = currentNode->next;
    }

    currentNode = routeHead;
    while(currentNode != NULL)
    {
        char reverseValue[MESSAGE_LEN];
        routeStack.pop(reverseValue);

        if(strcmp(currentNode->data, reverseValue) != 0)
        {
            return false;
        }

        currentNode = currentNode->next;
    }

    return true;
}

/**
 * Task 3: Decoding Drone Instructions
 * Input argument: instructionHead - a pointer to the head node of a linked
 *                  list containing encoded drone instructions
 * Output argument: none
 * Return: none
 * Dependencies: Stack constructor, push, pop, isEmpty
 *               cstdlib - atoi
 *               cstring - strcmp, strcat, strcpy
 */
void decodeInstructions(Node* instructionHead)
{
    // TODO: implement this function
    Stack instructionStack;
    Node* currentNode = instructionHead;

    while(currentNode != NULL)
    {
        if(strcmp(currentNode->data, "]") == 0)
        {
            char decodedPart[MESSAGE_LEN];
            char stackValue[MESSAGE_LEN];
            decodedPart[0] = '\0';

            instructionStack.pop(stackValue);
            while(strcmp(stackValue, "[") != 0)
            {
                char combinedPart[MESSAGE_LEN];
                strcpy(combinedPart, stackValue);
                strcat(combinedPart, decodedPart);
                strcpy(decodedPart, combinedPart);
                instructionStack.pop(stackValue);
            }

            char repeatValue[MESSAGE_LEN];
            instructionStack.pop(repeatValue);
            int repeatCount = atoi(repeatValue);
            char repeatedPart[MESSAGE_LEN];
            repeatedPart[0] = '\0';

            int repeatIndex = 0;
            while(repeatIndex < repeatCount)
            {
                strcat(repeatedPart, decodedPart);
                repeatIndex++;
            }

            instructionStack.push(repeatedPart);
        }
        else
        {
            instructionStack.push(currentNode->data);
        }

        currentNode = currentNode->next;
    }

    char decodedInstructions[MESSAGE_LEN];
    char stackValue[MESSAGE_LEN];
    decodedInstructions[0] = '\0';

    while(!instructionStack.isEmpty())
    {
        instructionStack.pop(stackValue);
        char combinedPart[MESSAGE_LEN];
        strcpy(combinedPart, stackValue);
        strcat(combinedPart, decodedInstructions);
        strcpy(decodedInstructions, combinedPart);
    }

    cout << decodedInstructions << endl;
}

/**
 * Task 4: Evaluate Delivery Paths
 * Input argument: expressionHead - a pointer to the head node of a linked list
 *                 representing a Reverse Polish Notation expression
 * Output argument: none
 * Return: integer value representing the result of the evaluated expression
 * Dependencies: Stack constructor, push, pop, intToStr
 *               cstdlib - atoi
 */
int evaluatePathConditions(Node* expressionHead)
{
    // TODO: implement this function
    Stack valueStack;
    Node* currentNode = expressionHead;

    while(currentNode != NULL)
    {
        bool isOperator = strcmp(currentNode->data, "+") == 0 || strcmp(currentNode->data, "-") == 0 || strcmp(currentNode->data, "*") == 0 || strcmp(currentNode->data, "/") == 0;

        if(!isOperator)
        {
            valueStack.push(currentNode->data);
        }
        else
        {
            char rightValue[MESSAGE_LEN];
            char leftValue[MESSAGE_LEN];
            valueStack.pop(rightValue);
            valueStack.pop(leftValue);

            int rightNumber = atoi(rightValue);
            int leftNumber = atoi(leftValue);
            int calculatedValue = 0;

            if(strcmp(currentNode->data, "+") == 0)
            {
                calculatedValue = leftNumber + rightNumber;
            }
            else if(strcmp(currentNode->data, "-") == 0)
            {
                calculatedValue = leftNumber - rightNumber;
            }
            else if(strcmp(currentNode->data, "*") == 0)
            {
                calculatedValue = leftNumber * rightNumber;
            }
            else
            {
                calculatedValue = leftNumber / rightNumber;
            }

            char* calculatedText = intToStr(calculatedValue);
            valueStack.push(calculatedText);
            delete[] calculatedText;
        }

        currentNode = currentNode->next;
    }

    char result[MESSAGE_LEN];
    result[0] = '\0';
    valueStack.pop(result);
    return atoi(result);
}

/**
 * Task 5: Reversing Delivery Routes
 * Input argument: queue - a pointer to a Queue representing the list of
 *                  deliveries
 * Output argument: reversed delivery list
 * Return: none
 * Dependencies: Stack constructor, push, pop, enqueue, dequeue, isEmpty,
 *               isEmpty
 */
void reverseDelivery(Queue* queue)
{
    // TODO: implement this function
    Stack deliveryStack;
    char deliveryPoint[MESSAGE_LEN];

    while(!queue->isEmpty())
    {
        queue->dequeue(deliveryPoint);
        deliveryStack.push(deliveryPoint);
    }

    while(!deliveryStack.isEmpty())
    {
        deliveryStack.pop(deliveryPoint);
        queue->enqueue(deliveryPoint);
    }
}

/**
 * Task 6: Rotating Delivery Schedules
 * Input argument: queue - a pointer to a Queue representing the list of
 *                  deliveries
 *                 k - an integer indicating the number of positions to rotate
 * Output argument: rotated queue
 * Return: none
 * Dependencies: isEmpty
 */
void rotateDelivery(Queue* queue, int k)
{
    // TODO: implement this function
    if(queue == NULL || queue->isEmpty())
    {
        return;
    }

    int itemCount = 0;
    Node* currentNode = queue->getFront();
    while(currentNode != NULL)
    {
        itemCount++;
        currentNode = currentNode->next;
    }

    int rotationCount = k % itemCount;
    if(rotationCount < 0)
    {
        rotationCount += itemCount;
    }

    int itemsToMove = itemCount - rotationCount;
    char deliveryPoint[MESSAGE_LEN];
    int moveIndex = 0;
    while(moveIndex < itemsToMove)
    {
        queue->dequeue(deliveryPoint);
        queue->enqueue(deliveryPoint);
        moveIndex++;
    }
}

/**
 * Task 7: Merging Delivery Routes
 * Input argument: q1 - a pointer to the first Queue representing a
 *                 delivery route
 *                 q2 - a pointer to the second Queue representing a
 *                 delivery route
 * Output argument: none
 * Return: a pointer to a new Queue containing the merged elements
 * Dependencies: Queue constructor, dequeue, enqueue, isEmpty
 */
Queue* mergeDeliveryRoutes(Queue* q1, Queue* q2)
{
    // TODO: implement this function
    Queue* mergedQueue = new Queue;
    char deliveryPoint[MESSAGE_LEN];

    while(q1 != NULL && !q1->isEmpty())
    {
        q1->dequeue(deliveryPoint);
        mergedQueue->enqueue(deliveryPoint);
    }

    while(q2 != NULL && !q2->isEmpty())
    {
        q2->dequeue(deliveryPoint);
        mergedQueue->enqueue(deliveryPoint);
    }

    return mergedQueue;
}

// Stack & Queue implementations
/**
 * Function: createStack
 * Input argument: none
 * Output argument: none
 * Return: a Stack initialized for use
 * Dependencies: none
 */
void Stack::push(const char* value)
{
    // TODO: implement this method
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

/**
 * Function: pop
 * Input argument: out - a character array to receive the popped string
 * Output argument: stack's top element is removed
 * Return: true if a value was popped, false if the stack is empty
 * Dependencies: isEmpty
 */
bool Stack::pop(char* out)
{
    // TODO: implement this method
    if(isEmpty())
    {
        return false;
    }

    Node* removedNode = top;
    strcpy(out, removedNode->data);
    top = removedNode->next;
    delete removedNode;
    return true;
}

/**
 * Function: isEmptyStack
 * Input argument: none
 * Output argument: none
 * Return: true if the stack is empty, false otherwise
 * Dependencies: none
 */
bool Stack::isEmpty() const
{
    // TODO: implement this method
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Function: peek
 * Input argument: none
 * Output argument: none
 * Return: a pointer to the string at the top of the stack,
 *         NULL if the stack is empty
 * Dependencies: none
 */
const char* Stack::peek() const
{
    // TODO: implement this method
    if(isEmpty())
    {
        return NULL;
    }

    return top->data;
}

/**
 * Function: getTop
 * Input argument: none
 * Output argument: none
 * Return: a pointer to the top node in the stack
 * Dependencies: none
 */
Node* Stack::getTop() const
{
    return top;
}

/**
 * Function: createQueue
 * Input argument: none
 * Output argument: none
 * Return: a Queue initialized for use
 * Dependencies: none
 */
void Queue::enqueue(const char* value)
{
    // TODO: implement this method
    Node* newNode = new Node(value);

    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

/**
 * Function: dequeue
 * Input argument: out - a character array to receive the dequeued string
 * Output argument: queue's front element is removed
 * Return: true if a value was dequeued, false if the queue is empty
 * Dependencies: isEmpty
 */
bool Queue::dequeue(char* out)
{
    // TODO: implement this method
    if(isEmpty())
    {
        return false;
    }

    Node* removedNode = front;
    strcpy(out, removedNode->data);
    front = removedNode->next;
    delete removedNode;

    if(front == NULL)
    {
        rear = NULL;
    }

    return true;
}

/**
 * Function: isEmptyQueue
 * Input argument: none
 * Output argument: none
 * Return: true if the queue is empty, false otherwise
 * Dependencies: none
 */
bool Queue::isEmpty() const
{
    // TODO: implement this method
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Function: getFront
 * Input argument: none
 * Output argument: none
 * Return: a pointer to the front node in the queue
 * Dependencies: none
 */
Node* Queue::getFront() const
{
    return front;
}

/**
 * Function: getRear
 * Input argument: none
 * Output argument: none
 * Return: a pointer to the rear node in the queue
 * Dependencies: none
 */
Node* Queue::getRear() const
{
    return rear;
}

/**
 * Function: setFront
 * Input argument: node - a pointer to the node to store as the new front
 * Output argument: the queue front is updated
 * Return: none
 * Dependencies: none
 */
void Queue::setFront(Node* node)
{
    front = node;
}

/**
 * Function: setRear
 * Input argument: node - a pointer to the node to store as the new rear
 * Output argument: the queue rear is updated
 * Return: none
 * Dependencies: none
 */
void Queue::setRear(Node* node)
{
    rear = node;
}

/**
 * Function: createNode (provided)
 * Input argument: value - a pointer to a string to be stored in the new node
 * Output argument: none
 * Return: a pointer to a newly allocated Node with the given value
 * Dependencies: new
 */
Node* createNode(const char* value)
{
    return new Node(value);
}

/**
 * Function: intToStr (provided)
 * Input argument: num - an integer value to be converted to a string
 * Output argument: none
 * Return: a pointer to a dynamically allocated string representing the integer
 * Dependencies: new
 */
char* intToStr(int num)
{
    char buffer[MESSAGE_LEN];
    snprintf(buffer, MESSAGE_LEN, "%d", num);

    char* result = new char[strlen(buffer) + 1];
    strcpy(result, buffer);
    return result;
}

/**
 * Function: freeNodeList (provided)
 * Input argument: head - a pointer to the first node in a linked list
 * Output argument: linked list memory is released
 * Return: none
 * Dependencies: delete
 */
void freeNodeList(Node* head)
{
    while (head != NULL)
    {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}
