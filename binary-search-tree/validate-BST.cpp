#include <iostream>
#include "binary-tree-node.cpp"
#include "binary-tree-node-2.cpp"
using namespace std;
class Solution
{
public:
    bool isValidBST(TreeNode *node, long min, long max)
    {
        if (!node)
        {
            return true;
        }
        if (node->val >= max || node->val <= min)
        {
            return false;
        }
        return isValidBST(node->left, min, node->val) && isValidBST(node->right, node->val, max);
    }
    bool isValidBST(TreeNode *root)
    {

        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool validateBST(BinaryTreeNode<int> *root, int min, int max)
    {
        if (!root)
        {
            return true;
        }
        if (root->data >= max || root->data <= min)
        {
            return false;
        }
        return root->data < max && root->data > min && validateBST(root->left, min, root->data) && validateBST(root->right, root->data, max);
    }
    bool validateBST(BinaryTreeNode<int> *root)
    {

        validateBST(root, INT_MIN, INT_MAX);
    }
};