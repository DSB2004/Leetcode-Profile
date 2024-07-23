#include <iostream>
#include <stack>
#include "binary-tree-node.cpp"

using namespace std;

class Solution
{
public:
    void initialiseStack(TreeNode *root, stack<TreeNode *> &front)
    {
        TreeNode *left = root;
        while (left)
        {
            front.push(left);
            left = left->left;
        }
    }
    TreeNode *getFront(stack<TreeNode *> &front)
    {
        if (front.empty())
        {
            return nullptr;
        }
        TreeNode *node = front.top();
        front.pop();
        TreeNode *nodeRight = node->right;
        while (nodeRight)
        {
            front.push(nodeRight);
            nodeRight = nodeRight->left;
        }
        return node;
    }
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> ref;
        initialiseStack(root, ref);
        TreeNode *prev = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *cur = getFront(ref);

        while (cur)
        {
            if (prev && prev->val > cur->val)
            {
                if (!first)
                {
                    first = prev;
                }
                second = cur;
            }
            prev = cur;
            cur = getFront(ref);
        }
        if (first && second)
        {
            swap(first->val, second->val);
        }
        return;
    }
};