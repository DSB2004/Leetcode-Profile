// to check if the tree is balanced or not
#include <iostream>
#include "binary-tree-node.cpp"
using namespace std;
class Solution
{
public:
    int returnBalancing(TreeNode *root)
    {
        if (root != nullptr)
        {
            int l = returnBalancing(root->left);
            if (l == -1)
                return -1;
            int r = returnBalancing(root->right);
            if (r == -1)
                return -1;
            if (abs(l - r) > 1)
                return -1;
            return 1 + max(l, r);
        }
        return 0;
    }
    bool isBalanced(TreeNode *root)
    {
        return returnBalancing(root) != -1;
    }
};