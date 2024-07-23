#include <iostream>
#include <climits>

#include "binary-tree-node.cpp"

using namespace std;

struct NodeStats
{
    int size;
    int min;
    int max;
    NodeStats(int size, int max, int min) : size(size), min(min),
                                            max(max) {}
};

NodeStats checkSize(TreeNode *node)
{
    if (!node)
    {
        return NodeStats(0, INT_MIN, INT_MAX);
    }
    NodeStats left = checkSize(node->left);
    NodeStats right = checkSize(node->right);

    if (left.max < node->val && node->val < right.min)
    {
        return NodeStats(1 + left.size + right.size, max(node->val, right.max), min(node->val, left.min));
    }
    return NodeStats(max(left.size, right.size), INT_MAX, INT_MIN);
}

int largestBST(TreeNode *root)
{
    return checkSize(root).size;
}