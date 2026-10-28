#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool is_empty()
{
    return false;
}

Node* Queue::deque()
{
    if(is_empty())
    {
        std::cout << "Queue is empty";
        return nullptr;
    }

    Node* temp = head;

    head = head->next;

    return temp;
}

int main()
{
    std::cout << "Hello, World!\n";
    return 0;
}