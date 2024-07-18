#include "binary-tree-node-class.cpp"
#include <iostream>
using namespace std;

#include <map>
#include <queue>
#include <vector>

vector<int> bottomView(TreeNode<int> *root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    map<int, int> ref;
    queue<pair<TreeNode<int> *, int>> temp;
    temp.push({root, 0});

    while (!temp.empty())
    {

        TreeNode<int> *node = temp.front().first;
        int line = temp.front().second;

        temp.pop();

        ref[line] = node->data;

        if (node->left != nullptr)
        {
            temp.push({node->left, line - 1});
        }
        if (node->right != nullptr)
        {
            temp.push({node->right, line + 1});
        }
    }
    for (auto p : ref)
    {
        result.push_back(p.second);
    }
    return result;
}
