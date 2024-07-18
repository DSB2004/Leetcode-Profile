#include <iostream>
#include "binary-tree-node.cpp"

TreeNode*insertionInBST(TreeNode *root, int val)
{
    TreeNode*newNode = new TreeNode(val);
    if (!root)
    {
        return newNode;
    }
    TreeNode *cur = root;
    while (cur)
    {
        if (cur->val > val)
        {
            if (cur->left)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = newNode;
                break;
            }
        }
        else 
        {
            if (cur->right)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = newNode;
                break;
            }
        }
    }
    return root;
}