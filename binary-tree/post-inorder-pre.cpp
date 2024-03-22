#include <iostream>
#include <vector>
#include <stack>
#include "binary-tree-node-class.cpp"
using namespace std;
class Solution
{
public:
    vector<vector<int>> getTreeTraversal(TreeNode *root)
    {
        vector<vector<int>> result(3);
        stack<pair<TreeNode *, int>> temp;
        if (root != nullptr)
        {
            temp.push(make_pair(root, 1));
        }
        while (!temp.empty())
        {
            auto topE = temp.top();
            temp.pop();

            if (topE.second == 1) // preorder
            {
                result[1].push_back(topE.first->data);
                topE.second++;
                temp.push(topE);
                if (topE.first->left != nullptr)
                {
                    temp.push(make_pair(topE.first->left, 1));
                }
            }
            else if (topE.second == 2) // inorder
            {
                result[0].push_back(topE.first->data);
                topE.second++;
                temp.push(topE);
                if (topE.first->right != nullptr)
                {
                    temp.push(make_pair(topE.first->right, 1));
                }
            }
            else if (topE.second == 3) // postorder
            {
                result[2].push_back(topE.first->data);
            }
        }
        return result;
    }
   
};