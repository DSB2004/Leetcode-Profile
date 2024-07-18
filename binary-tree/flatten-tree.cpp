#include <iostream>
#include "binary-tree-node.cpp"

using namespace std;

class Solution
{
public:
    void util(TreeNode *cur, TreeNode *&prev)
    {
        if (cur == nullptr)
        {
            return;
        }
        util(cur->right, prev);
        util(cur->left, prev);
        cur->right = prev;
        cur->left = nullptr;
        prev = cur;
        return;
    }
    void flatten(TreeNode *root)
    {
        TreeNode *initial = nullptr;
        util(root, initial);
    }
};