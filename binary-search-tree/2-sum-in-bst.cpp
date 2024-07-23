#include <stack>
#include <iostream>
#include "binary-tree-node.cpp"

using namespace std;

class Solution
{
public:
    void initialiseStack(TreeNode *root, stack<TreeNode *> &front, stack<TreeNode *> &back)
    {
        TreeNode *left = root;
        while (left)
        {
            front.push(left);
            left = left->left;
        }
        TreeNode *right = root;
        while (right)
        {
            back.push(right);
            right = right->right;
        }
    }
    int getFront(stack<TreeNode *> &front)
    {
        if (front.empty())
        {
            return 0;
        }
        TreeNode *node = front.top();
        front.pop();
        TreeNode *nodeRight = node->right;
        while (nodeRight)
        {
            front.push(nodeRight);
            nodeRight = nodeRight->left;
        }
        return node->val;
    }
    int getBack(stack<TreeNode *> &back)
    {
        if (back.empty())
        {
            return 0;
        }
        TreeNode *node = back.top();
        back.pop();
        TreeNode *nodeLeft = node->left;
        while (nodeLeft)
        {
            back.push(nodeLeft);
            nodeLeft = nodeLeft->right;
        }
        return node->val;
    }

    bool KSumPair(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }
        stack<TreeNode *> front;
        stack<TreeNode *> back;
        initialiseStack(root, front, back);

        int i = getFront(front);
        int j = getBack(back);

        while (i < j && !front.empty() && !back.empty())
        {
            int sum = i + j;
            if (sum > k)
            {
                j = getBack(back);
            }
            else if (sum < k)
            {
                i = getFront(front);
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};