// to construct a BST from a preorder traversal

#include <iostream>
#include "binary-tree-node.cpp"
#include <vector>
#include <stack>
using namespace std;

TreeNode *util(vector<int> preorder, int &index, int limit)
{
    if (index == preorder.size() || preorder[index] > limit)
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(preorder[index++]);
    node->left = util(preorder, index, node->val);
    node->right = util(preorder, index, limit);
    return node;
}


TreeNode *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.empty())
        return nullptr;

    TreeNode *root = new TreeNode(preorder.front());
    stack<pair<TreeNode *, int>> ref;
    ref.push(make_pair(root, INT_MAX));
    int index = 0;
    while (index < preorder.size() - 1 && !ref.empty())
    {
        index++;
        TreeNode *child = new TreeNode(preorder[index]);
        while (!ref.empty())
        {
            auto top = ref.top();
            TreeNode *parent = top.first;
            int right_limit = top.second;
            int left_limit = parent->val;

            if (preorder[index] < left_limit && !parent->left)
            {
                parent->left = child;
                ref.push({child, left_limit});
                break;
            }
            else if (preorder[index] > left_limit && preorder[index] < right_limit && !parent->right)
            {
                parent->right = child;
                ref.push({child, right_limit});
                break;
            }
            else
            {
                ref.pop();
            }
        }
    }
    return root;
}
