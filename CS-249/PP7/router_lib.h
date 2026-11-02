#ifndef ROUTER_LIB_H
#define ROUTER_LIB_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct RouterNode
{
    int router_id;
    RouterNode* left;
    RouterNode* right;

    RouterNode(int id = 0);
};

struct QueueNode
{
    RouterNode* router;
    QueueNode* next;

    QueueNode(RouterNode* routerPtr = nullptr);
};

struct Queue
{
    QueueNode* front;
    QueueNode* rear;
};

class Router
{
private:
    RouterNode* root;

    static RouterNode* copyTree(const RouterNode* source);
    static void deleteNodes(RouterNode* node);
    static void invertNetwork(RouterNode* node);
    static int getMaxNetworkDepth(const RouterNode* node);
    static void getRouterRightView(const RouterNode* node, int level,
                                   int* maxLevel);

    static RouterNode* createRouter(int router_id);
    static Queue createQueue();
    static bool isEmptyQueue(Queue* queue);
    static void enqueue(Queue* queue, RouterNode* router);
    static RouterNode* dequeue(Queue* queue);
    static void clearQueue(Queue* queue);

public:
    Router();
    Router(const Router& other);
    Router& operator=(const Router& other);
    ~Router();

    void addRouter(int router_id);
    void removeRouter(int router_id);
    void invertNetwork();
    bool isRoutingSymmetric() const;
    int getMaxNetworkDepth() const;
    void getRouterRightView() const;
    void findHighTrafficRouters() const;
    void printNetwork() const;

    RouterNode* getRoot() const;
};

#endif
