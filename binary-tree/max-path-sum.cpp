// ques name
#include <iostream>
#include "binary-tree-node.cpp"
using namespace std;
class Solution
{
public:
    // To solve this problem we can use the backtracking algorithm by recursively iterating over each node checking the left and right side and calculating the max possible path at that node
    int function(TreeNode *root, int &maxPath)
    {
        if (root != nullptr)
        {
            int l = 0, r = 0;
            l = max(0, function(root->left, maxPath));
            r = max(0, function(root->right, maxPath));
            maxPath = max(maxPath, l + r + root->val);
            return root->val + max(l, r);
        }
        return 0;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        function(root, maxPath);
        return maxPath;
    }
};