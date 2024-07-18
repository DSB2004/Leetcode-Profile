// zig-zag-level-traversal of binary tree
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include "binary-tree-node.cpp"
using namespace std;
class Solution
{
public:
    //  Level order traversal of a binary tree involves maintaining a temp queue that stores each level nodes  next in level to the current level of node and at each traversal all those nodes are poped out and their child node (if exist) are pushed in the queue.This continuous until the queue is empty

    // to Solve this problem of zig-zag level traversal we can modify this approach by adding a flag the justify whether to go left to right or opposite
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> temp;
        int side = 0;
        temp.push(root);
        if (root == nullptr)
            return result;

        while (!temp.empty())
        {
            vector<int> temp2;
            int size = temp.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *ref = temp.front();
                if (ref->left != nullptr)
                    temp.push(ref->left);
                if (ref->right != nullptr)
                    temp.push(ref->right);
                temp2.push_back(ref->val);
                temp.pop();
            }
            if (side == 1)
            {
                reverse(temp2.begin(), temp2.end());
            }
            side = 1 - side;
            result.push_back(temp2);
        }
        return result;
    }
};