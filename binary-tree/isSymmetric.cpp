
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "binary-tree-node.cpp"
#include <queue>
using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        queue<TreeNode *> temp;
        temp.push(root->left);
        temp.push(root->right);

        while (!temp.empty())
        {
            TreeNode *leftSide = temp.front();
            temp.pop();
            TreeNode *rightSide = temp.front();
            temp.pop();

            if (!leftSide && !rightSide)
            {
                continue;
            }
            if (!leftSide || !rightSide)
            {
                return false;
            }
            if (leftSide->val != rightSide->val)
            {
                return false;
            }
            
            temp.push(leftSide->left);
            temp.push(rightSide->right);
            temp.push(leftSide->right);
            temp.push(rightSide->left);
        }
        return true;
    }
};