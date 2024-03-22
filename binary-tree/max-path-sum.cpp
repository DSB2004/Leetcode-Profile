// ques name
#include <iostream>
#include "binary-tree-node.cpp"
using namespace std;
class Solution
{
public:
    // In this problem we are asked to return the maximum path sum (sum of node value) possible in the binary tree. To solve this we can use the approach of calculating the depth of the binary tree we instead of return the depth we can return the max path sum possible at each node.


    // backtracing approach
    int maxPathSum(TreeNode *root, int &maxPath)
    {
        if (root == nullptr)
            return 0;
        int l = 0;
        l += max(0,maxPathSum(root->left, maxPath));
        int r = 0;
        r += max(0,maxPathSum(root->right, maxPath));
        maxPath = max(maxPath, l + r + root->val);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        maxPathSum(root, maxPath);
        return maxPath;
    }

};