// ques name
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include "binary-tree-node-class.cpp"
using namespace std;
class Solution
{
public:
    bool isLeaf(TreeNode<int> *root)
    {
        return root->left == nullptr && root->right == nullptr;
    }
    void leftBorder(TreeNode<int> *root, vector<int> &res)
    {
        TreeNode<int> *temp = root->left;
        while (temp)
        {
            if (!isLeaf(temp))
            {
                res.push_back(temp->data);
            }
            if (temp->left)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    void addLeaf(TreeNode<int> *root, vector<int> &res)
    {
        if (root)
        {
            if (isLeaf(root))
            {
                res.push_back(root->data);
                return;
            }
            return addLeaf(root->left, res);
            return addLeaf(root->right, res);
        }
    }
    void rightBorder(TreeNode<int> *root, vector<int> &res)
    {
        TreeNode<int> *temp = root->right;
        vector<int> tempArray;
        while (temp)
        {
            if (!isLeaf(temp))
            {
                tempArray.push_back(temp->data);
            }
            if (temp->right)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        for (int i = tempArray.size() - 1; i >= 0; i--)
        {
            res.push_back(tempArray[i]);
        }
    }
    vector<int> traverseBoundary(TreeNode<int> *root)
    {
        vector<int> result;
        if (root)
        {
            result.push_back(root->data);
            leftBorder(root, result);
            addLeaf(root, result);
            rightBorder(root, result);
        }
        return result;
    }
};