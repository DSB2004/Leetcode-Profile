
#include <iostream>
#include "binary-tree-node-2.cpp"
#include <string>
#include <vector>

using namespace std;

class Solution
{

    bool isLeaf(BinaryTreeNode<int> *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
    void getPath(BinaryTreeNode<int> *node, string &preOrder, vector<string> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        preOrder += to_string(node->data) + " ";

        if (isLeaf(node))
        {
            result.push_back(preOrder);
        }
        else
        {
            getPath(node->left, preOrder, result);
            getPath(node->right, preOrder, result);
        }
        preOrder.pop_back();
    }
    vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
    {
        string preOrder = "";
        vector<string> result;
        getPath(root, preOrder, result);
        return result;
    }
};