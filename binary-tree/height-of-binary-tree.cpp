// ques name
#include <iostream>
#include "binary-tree-node.cpp"

using namespace std;
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root != nullptr)
        {

            int l = 0;
            l += maxDepth(root->left);
            int r = 0;
            r += maxDepth(root->right);
            return 1 + max(l, r);
        }
        return 0;
    }
};