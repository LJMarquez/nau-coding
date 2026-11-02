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

/**
 * Task 2: Remove a Faulty Router
 * Input argument: router_id - the identification for the target router
 * Output argument: the target router is replaced with the last router in the
 *                  network (bottommost, rightmost node)
 * Return: none
 * Dependencies: Router::createQueue, Router::isEmptyQueue,
 *               Router::enqueue, Router::dequeue
 */

/**
 * Task 3: Invert Router Network
 * Input argument: none
 * Output argument: the router network is inverted in place
 * Return: none
 * Dependencies: Router::invertNetwork (recursive helper)
 */

/**
 * Task 4: Ensure Symmetrical Routing
 * Input argument: none
 * Output argument: none
 * Return: true if the routing is symmetric, false otherwise
 * Dependencies: Router::createQueue, Router::enqueue, Router::dequeue,
 *               Router::isEmptyQueue
 */

/**
 * Task 5: Analyze Maximum Network Depth
 * Input argument: none
 * Output argument: none
 * Return: an integer value representing the maximum depth of the tree
 * Dependencies: Router::getMaxNetworkDepth (recursive helper)
 */

/**
 * Task 6: Get a Right-Side View of the Router Network
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: Router::getRouterRightView (recursive helper)
 */

/**
 * Task 7: Identify High-Traffic Routers
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: Router::createQueue, Router::enqueue, Router::dequeue,
 *               Router::isEmptyQueue
 */

/**
 * Task 8: Show Routers in the Network
 * Input argument: none
 * Output argument: none
 * Return: none
 * Dependencies: iostream or cstdio output
 */

/**
 * Function: invertNetwork
 * Input argument: node - a pointer to the root of a subtree
 * Output argument: none
 * Return: none
 * Dependencies: Router::invertNetwork (recursive)
 */

/**
 * Function: getMaxNetworkDepth
 * Input argument: node - a pointer to the root of a subtree
 * Output argument: none
 * Return: an integer representing the maximum depth of that subtree
 * Dependencies: Router::getMaxNetworkDepth (recursive)
 */

/**
 * Function: getRouterRightView
 * Input argument: node - a pointer to the current subtree root
 *                 level - the current tree level
 *                 maxLevel - the deepest level printed so far
 * Output argument: none
 * Return: none
 * Dependencies: Router::getRouterRightView (recursive)
 */

/**
 * Function: createRouter
 * Input argument: router_id - the router's identification
 * Output argument: none
 * Return: a pointer to the recently created router node with no children
 * Dependencies: new
 */

/**
 * Function: createQueue
 * Input argument: none
 * Output argument: none
 * Return: a queue where front and rear pointers are set to nullptr
 * Dependencies: none
 */

/**
 * Function: isEmptyQueue
 * Input argument: queue - a pointer to a queue
 * Output argument: none
 * Return: true if the queue is empty, false otherwise
 * Dependencies: none
 */

/**
 * Function: enqueue
 * Input argument: queue - a pointer to a queue
 *                 router - a pointer to the router node to enqueue
 * Output argument: the router is added at the rear of the queue
 * Return: none
 * Dependencies: new
 */

/**
 * Function: dequeue
 * Input argument: queue - a pointer to a queue
 * Output argument: the front router is removed from the queue
 * Return: a pointer to the dequeued router node (not the queue node!)
 *         nullptr if the queue is empty
 * Dependencies: Router::isEmptyQueue
 */

/**
 * Function: clearQueue
 * Input argument: queue - a pointer to a queue
 * Output argument: all queue nodes are removed
 * Return: none
 * Dependencies: Router::isEmptyQueue, Router::dequeue
 */

RouterNode* Router::getRoot() const
{
    return root;
}
