#include "leaderboard_lib.h"

/*
 * Student note:
 * Use leaderboard_lib.h for the exact function and method signatures.
 * Any function intentionally left without a definition in this template is
 * student work and should be implemented here using the declarations in the
 * header file.
 */

TreeNode::TreeNode()
{
    score = 0;
    left = nullptr;
    right = nullptr;
    height = 1;
}

TreeNode::TreeNode(int value)
{
    score = value;
    left = nullptr;
    right = nullptr;
    height = 1;
}

Leaderboard::Leaderboard()
{
    root = nullptr;
}

Leaderboard::Leaderboard(const Leaderboard& other)
{
    root = cloneSubtree(other.root);
}

Leaderboard& Leaderboard::operator=(const Leaderboard& other)
{
    if (this != &other)
    {
        freeSubtree(root);
        root = cloneSubtree(other.root);
    }

    return *this;
}

Leaderboard::~Leaderboard()
{
    freeSubtree(root);
}

TreeNode* Leaderboard::cloneSubtree(TreeNode* node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    TreeNode* copy = new TreeNode(node->score);
    copy->height = node->height;
    copy->left = cloneSubtree(node->left);
    copy->right = cloneSubtree(node->right);
    return copy;
}

void Leaderboard::freeSubtree(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    freeSubtree(node->left);
    freeSubtree(node->right);
    delete node;
}

/**
* Task 2: Add a New Student
* Input argument: score - the score to add to the leaderboard
* Output argument: leaderboard tree may be updated
* Return: none
* Dependencies: private recursive addStudent helper, AVL helpers
*/
TreeNode* addStudent(TreeNode* node, int score)
{
    
}

/**
* Task 3: Remove a Student
* Input argument: score - the score to remove from the leaderboard
* Output argument: leaderboard tree may be updated
* Return: none
* Dependencies: private recursive removeStudent helper, AVL helpers
*/


/**
* Task 4: Print the Leaderboard
* Output argument: prints the leaderboard in ascending order
* Return: none
* Dependencies: private recursive print helper
*/


/**
* Task 5: Find the Kth Smallest Score
* Input argument: k - order statistic to locate
* Output argument: none
* Return: the kth smallest score or -1 if not found
* Dependencies: private recursive findKthSmallest helper
*/
int Leaderboard::findKthSmallestScore(int k) const
{
    int count = 0;
    int result = -1;
    findKthSmallest(root, k, count, result);
    return result;
}

/**
* Task 6: Calculate the Range Sum of Scores
* Input argument: low, high - inclusive score bounds
* Output argument: none
* Return: sum of scores in the range
* Dependencies: private recursive rangeSumScores helper
*/


/**
* Task 7: Find the Common Friend Student
* Input argument: student1, student2 - scores to compare
* Output argument: none
* Return: score of the common friend student or -1 if not found
* Dependencies: private recursive findCommonFriendStudent helper
*/


/**
* Task 8: Measure Academic Connectivity
* Output argument: none
* Return: longest path length in edges
* Dependencies: private recursive connectivity helper
*/


/**
* Task 9: Identify Students Meeting Average Performance
* Output argument: none
* Return: number of students whose score equals the integer average
*         of their subtree
* Dependencies: countSubtree, recursive average-performance helper
*/


int Leaderboard::height(TreeNode* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    return node->height;
}

/**
* Task 2: Add a new student
* Input argument: node - a pointer to the root of the leaderboard
*                 score - the score to add to the leaderboard
* Output argument: none
* Return: a pointer to the root of the leaderboard
* Dependencies: rightRotate, leftRotate, maxHeight, height, getBalance,
*               addStudent (recursive)
*/



/**
* Task 3: Remove a student
* Input argument: node - a pointer to the root of the leaderboard
*                 score - the score to remove from the leaderboard
* Output argument: none
* Return: a pointer to the root of the leaderboard
* Dependencies: rightRotate, leftRotate, maxHeight, height, getBalance,
*               removeStudent (recursive)
*/



/**
* Task 4: Print leaderboard
* Input argument: node - a pointer to the root of the leaderboard
* Output argument: none
* Return: none
* Dependencies: printLeaderboard (recursive)
*/



/**
* Task 5: Find the kth smallest score
* Input argument: node - a pointer to the root of the leaderboard
*                 k - integer value indicating the order of the smallest
*                     element to be found
*                 count - reference to the number of visited nodes
*                 result - reference to the integer representing the kth
*                          smallest score (or -1 if not found)
* Output argument: count and result are updated
* Return: none
* Dependencies: findKthSmallest (recursive)
*/



/**
* Task 6: Calculate the range sum of scores
* Input argument: node - a pointer to the root of the leaderboard
*                 low, high - integer values to delimit the range
* Output argument: none
* Return: the sum of the scores in the range
* Dependencies: rangeSumScores (recursive)
*/



/**
* Task 7: Find common friend student
* Input argument: node - a pointer to the root of the leaderboard
*                 student1, student2 - integer values with student scores
* Output argument: none
* Return: score of the common friend student
* Dependencies: findCommonFriendStudent (recursive)
*/



/**
 * Task 8: Measure academic connectivity
 * Input argument: node - a pointer to the root of the leaderboard
 *                 diameter - reference to the longest path found so far
 * Output argument: diameter may be updated
 * Return: height-like value used by the recursive connectivity calculation
 * Dependencies: measureAcademicConnectivity (recursive)
 */



/**
 * Function: countSubtree
 * Input argument: node - a pointer to the root of the subtree
 *                 sum - reference to the sum of the scores in the subtree
 *                 count - reference to the number of nodes in the subtree
 * Output argument: sum and count contain the accumulated values
 * Return: none
 * Dependencies: countSubtree (recursive)
 */



/**
 * Task 9: Identify students meeting average performance
 * Input argument: node - a pointer to the root of the leaderboard
 * Output argument: none
 * Return: number of students meeting the average performance
 * Dependencies: countSubtree, identifyStudentsMeetingAveragePerformance
 */



/**
* Function: maxHeight
* Input argument: left - the height of the left subtree of a node
*                 right - the height of the right subtree of a node
* Output argument: none
* Return: integer value representing the maximum of left and right values
* Dependencies: none
*/



/**
* Function: getBalance
* Input argument: node - a node in an AVL tree
* Output argument: none
* Return: the difference between the heights of the left and right children
* Dependencies: none
*/



/**
* Function: rightRotate
* Input argument: unbalancedNode - the unbalanced node to rotate in an AVL tree
* Output argument: the height of rotated nodes are updated
* Return: the new root of the rotated subtree
* Dependencies: maxHeight, height
*/



/**
* Function: leftRotate
* Input argument: unbalancedNode - the unbalanced node to rotate in an AVL tree
* Output argument: the height of rotated nodes are updated
* Return: the new root of the rotated subtree
* Dependencies: maxHeight, height
*/
