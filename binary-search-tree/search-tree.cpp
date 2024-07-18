#include <iostream>
#include "binary-tree-node.cpp"
using namespace std;

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *cur = root;
        while (cur && cur->val != val)
        {
            cur->val > val ? cur = cur->left : cur = cur->right;
        }

        return cur;
    }
};