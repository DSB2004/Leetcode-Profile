#include <iostream>
#include <queue>
#include <vector>
#include "binary-tree-node.cpp"
using namespace std;

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        if (root == nullptr)
        {
            return result;
        }

        queue<pair<TreeNode *, int>> temp;

        temp.push({root, 0});

        while (!temp.empty())
        {
            vector<int> levelWidth;
            int size = temp.size();
            int left = temp.front().second;
            int right = temp.back().second;
            result = max(result, right - left + 1);

            for (int i = 0; i < size; i++)
            {
                auto [node, index] = temp.front();
                temp.pop();
                if (node->left != nullptr)
                {
                    temp.push({node->left, 2 * index + 1});
                }
                if (node->right != nullptr)
                {
                    temp.push({node->right, 2 * index + 2});
                }
            }
        }
        return result;
    }
};
