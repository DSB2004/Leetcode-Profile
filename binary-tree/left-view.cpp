#include <map>
#include <queue>
#include <iostream>
#include <vector>
#include "binary-tree-node-class.cpp"

using namespace std;

vector<int> printLeftView(TreeNode<int> *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    queue<pair<TreeNode<int> *, int>> temp;
    temp.push({root, 0});

    while (!temp.empty())
    {
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            auto top = temp.front();
            temp.pop();
            TreeNode<int> *node = top.first;
            int level = top.second;
            if (node->left != nullptr)
            {
                temp.push({node->left, level + 1});
            }
            if (node->right != nullptr)
            {
                temp.push({node->right, level + 1});
            }
            if (i == 0)
            {
                result.push_back(node->data);
            }
        }
    }
    return result;
}