// to find the diameter of a binary tree (longest path between two nodes)
#include <iostream>
#include "binary-tree-node.cpp"
using namespace std;
class Solution
{
public:
    // brute force: To calculate the diameter of the tree , we can simply just calculate the left and right height of a root and return the sum as the longest path passing from that node

    int calculateMaxHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = 0, r = 0;
        l += calculateMaxHeight(root->left);
        r += calculateMaxHeight(root->right);
        return 1 + max(l, r);
    }

    void setHeight(TreeNode *root, int &val)
    {
        if (root == nullptr)
            return;
        int l = calculateMaxHeight(root->left);
        int r = calculateMaxHeight(root->right);
        val = max(val, l + r);
        setHeight(root->left, val);
        setHeight(root->right, val);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxVal = INT_MIN;
        setHeight(root, maxVal);
        return maxVal;
    }

    // (Optimised solution): In the above solution, the time complexity is O(N^2) since at each each node we are running the height function which has an overrall complexity. of O(N). So, to optimised this solution, we can directly check the Diameter of tree will calculating the max height of tree.
    
    int depthOfTree(TreeNode *root, int &val)
    {
        if (root == nullptr)
            return;
        int l = 0;
        l += depthOfTree(root->left, val);
        int r = 0;
        r += depthOfTree(root->right, val);
        val = max(val, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxVal = INT_MIN;
        depthOfTree(root, maxVal);
        return maxVal;
    }
};