#ifndef FLEET_LIB_H
#define FLEET_LIB_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MESSAGE_LEN 1024

struct Node
{
    char data[MESSAGE_LEN];
    Node* next;

    Node();
    Node(const char* value);
};

class Stack
{
private:
    Node* top;

    static Node* copyList(Node* source);

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    void push(const char* value);
    bool pop(char* out);
    bool isEmpty() const;
    const char* peek() const;
    Node* getTop() const;
};

class Queue
{
private:
    Node* front;
    Node* rear;

    static Node* copyList(Node* source);
    void rebuildRear();

public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();

    void enqueue(const char* value);
    bool dequeue(char* out);
    bool isEmpty() const;
    Node* getFront() const;
    Node* getRear() const;
    void setFront(Node* node);
    void setRear(Node* node);
};

bool validateDeliveryPath(Node* routeHead);
bool isSymmetricRoute(Node* routeHead);
void decodeInstructions(Node* instructionHead);
int evaluatePathConditions(Node* expressionHead);
void reverseDelivery(Queue* queue);
void rotateDelivery(Queue* queue, int k);
Queue* mergeDeliveryRoutes(Queue* q1, Queue* q2);

Node* createNode(const char* value);
char* intToStr(int num);
void freeNodeList(Node* head);

#endif
