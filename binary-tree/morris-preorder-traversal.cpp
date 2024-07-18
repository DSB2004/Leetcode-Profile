#include <iostream>
#include <vector>
#include "binary-tree-node.cpp"

using namespace std;

class Solution
{

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;

        TreeNode *cur = root;

        while (cur != nullptr)
        {

            if (!cur->left)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }

            else
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == cur)
                {
                    prev->right = nullptr;
                    cur = cur->right;
                }
                else if (!prev->right)
                {
                    prev->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                }
            }
        }

        return result;
    }
};
