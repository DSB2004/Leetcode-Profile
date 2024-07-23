#include <iostream>
#include "binary-tree-node.cpp"

using namespace std;

class Solution
{

    void kthSmallest(TreeNode *root, int k, int &result, int &index)
    {
        if (root == nullptr)
        {
            return;
        }
        kthSmallest(root->left, k, result, index);
        index++;
        if (k == index)
        {
            result = root->val;
        }
        kthSmallest(root->right, k, result, index);
        return;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int result = root->val;
        int index = 0;
        kthSmallest(root, k, result, index);
        return result;
    }
};