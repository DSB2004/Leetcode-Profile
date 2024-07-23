#include <iostream>
#include "binary-tree-node.cpp"

using namespace std;
class Solution
{
public:
    TreeNode *util(TreeNode *root)
    {
        if (!root->left)
        {
            return root->right;
        }
        if (!root->right)
        {
            return root->left;
        }
        TreeNode *lastLeft = root->left;
        while (lastLeft->right)
        {
            lastLeft = lastLeft->right;
        }
        lastLeft->right = root->right;
        return root->left;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->val == key)
        {
            return util(root);
        }

        TreeNode *cur = root;

        while (cur)
        {
            if (cur->val > key)
            {
                if (cur->left && cur->left->val == key)
                {
                    cur->left = util(cur->left);
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                if (cur->right && cur->right->val == key)
                {
                    cur->right = util(cur->right);
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }

        return root;
    }
};