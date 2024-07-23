#include <vector>
#include "binary-tree-node.cpp"
using namespace std;

void inorder(TreeNode *root, pair<int, int> &result, int key)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, result, key);
    if (root->val < key)
    {
        result.first = root->val;
    }
    if (root->val > key && result.second == -1)
    {
        result.second = root->val;
    }
    inorder(root->right, result, key);
    return;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> result = {-1, -1};
    inorder(root, result, key);
    return result;
}