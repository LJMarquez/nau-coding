#include "router_lib.h"

// provided node constructors
RouterNode::RouterNode(int id)
{
    router_id = id;
    left = nullptr;
    right = nullptr;
}

QueueNode::QueueNode(RouterNode* routerPtr)
{
    router = routerPtr;
    next = nullptr;
}

// provided helper for the Rule of Three
RouterNode* Router::copyTree(const RouterNode* source)
{
    if (source == nullptr)
    {
        return nullptr;
    }

    RouterNode* node = new RouterNode(source->router_id);
    node->left = copyTree(source->left);
    node->right = copyTree(source->right);
    return node;
}

// provided helper for cleanup
void Router::deleteNodes(RouterNode* node)
{
    if (node != nullptr)
    {
        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    }
}

// provided Rule-of-Three support
Router::Router()
{
    root = nullptr;
}

Router::Router(const Router& other)
{
    root = copyTree(other.root);
}

Router& Router::operator=(const Router& other)
{
    if (this == &other)
    {
        return *this;
    }

    deleteNodes(root);
    root = copyTree(other.root);
    return *this;
}

Router::~Router()
{
    deleteNodes(root);
    root = nullptr;
}

/*
 * Student note:
 * Use router_lib.h for the exact method signatures.
 */

/**
 * Task 1: Add a New Router
 * Input argument: router_id - the identification for the new router
 * Output argument: the last unfilled position of the last level contains a new
 *                  router with id router_id
 * Return: none
 * Dependencies: Router::createRouter, Router::createQueue,
 *               Router::isEmptyQueue, Router::enqueue, Router::dequeue
 */

void Router::addRouter(int router_id)
{
    RouterNode* newRouter = createRouter(router_id);

    if(root == nullptr)
    {
        root = newRouter;
        return;
    }

    Queue queue = createQueue();
    enqueue(&queue, root);

    while(!isEmptyQueue(&queue))
    {
        RouterNode* currentRouter = dequeue(&queue);

        if(currentRouter->left == nullptr)
        {
            currentRouter->left = newRouter;
            while(!isEmptyQueue(&queue))
            {
                dequeue(&queue);
            }
            return;
        }
        enqueue(&queue, currentRouter->left);

        if(currentRouter->right == nullptr)
        {
            currentRouter->right = newRouter;
            while(!isEmptyQueue(&queue))
            {
                dequeue(&queue);
            }
            return;
        }
        enqueue(&queue, currentRouter->right);
    }
}

/**
 * Task 2: Remove a Faulty Router
 * Input argument: router_id - the identification for the target router
 * Output argument: the target router is replaced with the last router in the
 *                  network (bottommost, rightmost node)
 * Return: none
 * Dependencies: Router::createQueue, Router::isEmptyQueue,
 *               Router::enqueue, Router::dequeue
 */

void Router::removeRouter(int router_id)
{
    if(root == nullptr)
    {
        cout << "Router with ID " << router_id << " not found." << endl;
        return;
    }

    Queue queue = createQueue();
    RouterNode* targetRouter = nullptr;
    RouterNode* lastRouter = nullptr;
    RouterNode* lastParent = nullptr;
    enqueue(&queue, root);

    while(!isEmptyQueue(&queue))
    {
        RouterNode* currentRouter = dequeue(&queue);

        if(targetRouter == nullptr && currentRouter->router_id == router_id)
        {
            targetRouter = currentRouter;
        }

        if(currentRouter->left != nullptr)
        {
            lastParent = currentRouter;
            lastRouter = currentRouter->left;
            enqueue(&queue, currentRouter->left);
        }

        if(currentRouter->right != nullptr)
        {
            lastParent = currentRouter;
            lastRouter = currentRouter->right;
            enqueue(&queue, currentRouter->right);
        }
    }

    if(targetRouter == nullptr)
    {
        cout << "Router with ID " << router_id << " not found." << endl;
        return;
    }

    if(lastRouter == root)
    {
        delete root;
        root = nullptr;
    }
    else
    {
        targetRouter->router_id = lastRouter->router_id;

        if(lastParent->right == lastRouter)
        {
            lastParent->right = nullptr;
        }
        else
        {
            lastParent->left = nullptr;
        }
        delete lastRouter;
    }

    cout << "Router with ID " << router_id << " successfully removed." << endl;
}

/**
 * Task 3: Invert Router Network
 * Input argument: none
 * Output argument: the router network is inverted in place
 * Return: none
 * Dependencies: Router::invertNetwork (recursive helper)
 */

void Router::invertNetwork()
{
    invertNetwork(root);
}

/**
 * Task 4: Ensure Symmetrical Routing
 * Input argument: none
 * Output argument: none
 * Return: true if the routing is symmetric, false otherwise
 * Dependencies: Router::createQueue, Router::enqueue, Router::dequeue,
 *               Router::isEmptyQueue
 */

bool Router::isRoutingSymmetric() const
{
    if(root == nullptr)
    {
        return true;
    }

    Queue leftQueue = createQueue();
    Queue rightQueue = createQueue();
    enqueue(&leftQueue, root->left);
    enqueue(&rightQueue, root->right);

    bool symmetric = true;

    while(symmetric && !isEmptyQueue(&leftQueue) && !isEmptyQueue(&rightQueue))
    {
        RouterNode* leftRouter = dequeue(&leftQueue);
        RouterNode* rightRouter = dequeue(&rightQueue);

        if(leftRouter == nullptr || rightRouter == nullptr)
        {
            if(leftRouter != rightRouter)
            {
                symmetric = false;
            }
        }
        else if(leftRouter->router_id != rightRouter->router_id)
        {
            symmetric = false;
        }
        else
        {
            enqueue(&leftQueue, leftRouter->left);
            enqueue(&leftQueue, leftRouter->right);
            enqueue(&rightQueue, rightRouter->right);
            enqueue(&rightQueue, rightRouter->left);
        }
    }

    if(!isEmptyQueue(&leftQueue) || !isEmptyQueue(&rightQueue))
    {
        symmetric = false;
    }

    while(!isEmptyQueue(&leftQueue))
    {
        dequeue(&leftQueue);
    }

    while(!isEmptyQueue(&rightQueue))
    {
        dequeue(&rightQueue);
    }
    return symmetric;
}

/**
 * Task 5: Analyze Maximum Network Depth
 * Input argument: none
 * Output argument: none
 * Return: an integer value representing the maximum depth of the tree
 * Dependencies: Router::getMaxNetworkDepth (recursive helper)
 */

int Router::getMaxNetworkDepth() const
{
    return getMaxNetworkDepth(root);
}

/**
 * Task 6: Get a Right-Side View of the Router Network
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: Router::getRouterRightView (recursive helper)
 */

void Router::getRouterRightView() const
{
    int maxLevel = 0;
    getRouterRightView(root, 1, &maxLevel);
    cout << endl;
}

/**
 * Task 7: Identify High-Traffic Routers
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: Router::createQueue, Router::enqueue, Router::dequeue,
 *               Router::isEmptyQueue
 */

void Router::findHighTrafficRouters() const
{
    if(root == nullptr)
    {
        cout << endl;
        return;
    }

    Queue queue = createQueue();
    enqueue(&queue, root);

    while(!isEmptyQueue(&queue))
    {
        Queue nextLevel = createQueue();
        RouterNode* highestTrafficRouter = nullptr;

        while(!isEmptyQueue(&queue))
        {
            RouterNode* currentRouter = dequeue(&queue);

            if(highestTrafficRouter == nullptr || currentRouter->router_id > highestTrafficRouter->router_id)
            {
                highestTrafficRouter = currentRouter;
            }

            if(currentRouter->left != nullptr)
            {
                enqueue(&nextLevel, currentRouter->left);
            }
            if(currentRouter->right != nullptr)
            {
                enqueue(&nextLevel, currentRouter->right);
            }
        }

        cout << highestTrafficRouter->router_id << " ";
        queue = nextLevel;
    }

    cout << endl;
}

/**
 * Task 8: Show Routers in the Network
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: iostream or cstdio output
 */

void Router::printNetwork() const
{
    Queue queue = createQueue();

    if(root != nullptr)
    {
        enqueue(&queue, root);
    }

    while(!isEmptyQueue(&queue))
    {
        RouterNode* currentRouter = dequeue(&queue);
        cout << currentRouter->router_id << " ";

        if(currentRouter->left != nullptr)
        {
            enqueue(&queue, currentRouter->left);
        }
        if(currentRouter->right != nullptr)
        {
            enqueue(&queue, currentRouter->right);
        }
    }

    cout << endl;
}

/**
 * Function: invertNetwork
 * Input argument: node - a pointer to the root of a subtree
 * Output argument: none
 * Return: none
 * Dependencies: Router::invertNetwork (recursive)
 */

void Router::invertNetwork(RouterNode* node)
{
    if (node != nullptr)
    {
        RouterNode* temporary = node->left;
        node->left = node->right;
        node->right = temporary;
        invertNetwork(node->left);
        invertNetwork(node->right);
    }
}

/**
 * Function: getMaxNetworkDepth
 * Input argument: node - a pointer to the root of a subtree
 * Output argument: none
 * Return: an integer representing the maximum depth of that subtree
 * Dependencies: Router::getMaxNetworkDepth (recursive)
 */

int Router::getMaxNetworkDepth(const RouterNode* node)
{
    if(node == nullptr)
    {
        return 0;
    }

    int leftDepth = getMaxNetworkDepth(node->left);
    int rightDepth = getMaxNetworkDepth(node->right);
    int greaterDepth = leftDepth;

    if(rightDepth > greaterDepth)
    {
        greaterDepth = rightDepth;
    }

    return greaterDepth + 1;
}

/**
 * Function: getRouterRightView
 * Input argument: node - a pointer to the current subtree root
 *                 level - the current tree level
 *                 maxLevel - the deepest level printed so far
 * Output argument: none
 * Return: none
 * Dependencies: Router::getRouterRightView (recursive)
 */

void Router::getRouterRightView(const RouterNode* node, int level, int* maxLevel)
{
    if(node != nullptr)
    {
        if(level > *maxLevel)
        {
            cout << node->router_id << " ";
            *maxLevel = level;
        }

        getRouterRightView(node->right, level + 1, maxLevel);
        getRouterRightView(node->left, level + 1, maxLevel);
    }
}

/**
 * Function: createRouter
 * Input argument: router_id - the router's identification
 * Output argument: none
 * Return: a pointer to the recently created router node with no children
 * Dependencies: new
 */

RouterNode* Router::createRouter(int router_id)
{
    RouterNode* router = new RouterNode(router_id);
    return router;
}

/**
 * Function: createQueue
 * Input argument: none
 * Output argument: none
 * Return: a queue where front and rear pointers are set to nullptr
 * Dependencies: none
 */

Queue Router::createQueue()
{
    Queue queue;
    queue.front = nullptr;
    queue.rear = nullptr;
    return queue;
}

/**
 * Function: isEmptyQueue
 * Input argument: queue - a pointer to a queue
 * Output argument: none
 * Return: true if the queue is empty, false otherwise
 * Dependencies: none
 */

bool Router::isEmptyQueue(Queue* queue)
{
    return queue->front == nullptr;
}

/**
 * Function: enqueue
 * Input argument: queue - a pointer to a queue
 *                 router - a pointer to the router node to enqueue
 * Output argument: the router is added at the rear of the queue
 * Return: none
 * Dependencies: new
 */

void Router::enqueue(Queue* queue, RouterNode* router)
{
    QueueNode* newNode = new QueueNode(router);

    if(queue->rear == nullptr)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

/**
 * Function: dequeue
 * Input argument: queue - a pointer to a queue
 * Output argument: the front router is removed from the queue
 * Return: a pointer to the dequeued router node (not the queue node!)
 *         nullptr if the queue is empty
 * Dependencies: Router::isEmptyQueue
 */

RouterNode* Router::dequeue(Queue* queue)
{
    if(isEmptyQueue(queue))
    {
        return nullptr;
    }

    QueueNode* removedNode = queue->front;
    RouterNode* router = removedNode->router;
    queue->front = removedNode->next;

    if(queue->front == nullptr)
    {
        queue->rear = nullptr;
    }

    delete removedNode;
    return router;
}

/**
 * Function: clearQueue
 * Input argument: queue - a pointer to a queue
 * Output argument: all queue nodes are removed
 * Return: none
 * Dependencies: Router::isEmptyQueue, Router::dequeue
 */

void Router::clearQueue(Queue* queue)
{
    while (!isEmptyQueue(queue))
    {
        dequeue(queue);
    }
}

RouterNode* Router::getRoot() const
{
    return root;
}
