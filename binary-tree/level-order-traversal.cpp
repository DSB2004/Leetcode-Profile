// Level order traversal of a binary tree
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> temp;
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
            result.push_back(temp2);
        }
        return result;
    }
};