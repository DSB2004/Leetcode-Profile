#include <map>
#include <queue>
#include <iostream>
#include <vector>
#include "binary-tree-node-class.cpp"

using namespace std;

vector<int> getTopView(TreeNode<int> *root)
{
    map<int, int> ref;
    queue<pair<TreeNode<int> *, int>> temp;
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    temp.push(make_pair(root, 0));

    while (!temp.empty())
    {
        TreeNode<int> *node = temp.front().first;
        int header = temp.front().second;
        temp.pop();

        if (ref.find(header) == ref.end())
        {
            ref[header] = node->data;
        }

        if (node->left != nullptr)
        {
            temp.push({node->left, header - 1});
        }
        if (node->right != nullptr)
        {
            temp.push({node->right, header + 1});
        }
    }
    for (auto a : ref)
    {
        result.push_back(a.second);
    }
    return result;
}