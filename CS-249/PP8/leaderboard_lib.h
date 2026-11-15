#ifndef LEADERBOARD_LIB_H
#define LEADERBOARD_LIB_H

#include <iostream>

using namespace std;

struct TreeNode
{
    int score;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode();
    TreeNode(int value);
};

class Leaderboard
{
private:
    TreeNode* root;

    TreeNode* cloneSubtree(TreeNode* node) const;
    void freeSubtree(TreeNode* node);

    TreeNode* addStudent(TreeNode* node, int score);
    TreeNode* removeStudent(TreeNode* node, int score);
    void printLeaderboard(TreeNode* node) const;
    void findKthSmallest(
        TreeNode* node,
        int k,
        int& count,
        int& result
    ) const;
    int rangeSumScores(TreeNode* node, int low, int high) const;
    int findCommonFriendStudent(
        TreeNode* node,
        int student1,
        int student2
    ) const;
    void countSubtree(TreeNode* node, int& sum, int& count) const;
    int identifyStudentsMeetingAveragePerformance(TreeNode* node) const;
    int measureAcademicConnectivity(TreeNode* node, int& diameter) const;

    int height(TreeNode* node) const;
    int maxHeight(int left, int right) const;
    int getBalance(TreeNode* node) const;
    TreeNode* rightRotate(TreeNode* unbalancedNode);
    TreeNode* leftRotate(TreeNode* unbalancedNode);

public:
    Leaderboard();
    Leaderboard(const Leaderboard& other);
    Leaderboard& operator=(const Leaderboard& other);
    ~Leaderboard();

    void addStudent(int score);
    void removeStudent(int score);
    void printLeaderboard() const;
    int findKthSmallestScore(int k) const;
    int rangeSumScores(int low, int high) const;
    int findCommonFriendStudent(int student1, int student2) const;
    int measureAcademicConnectivity() const;
    int identifyStudentsMeetingAveragePerformance() const;
};

#endif
