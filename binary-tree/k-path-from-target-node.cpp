#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include "binary-tree-node.cpp"
#include <unordered_set>

using namespace std;

class Solution
{
public:
    void CreateParentMap(TreeNode *node, TreeNode *parent, unordered_map<TreeNode *, TreeNode *> &childParentMap)
    {
        if (node != nullptr)
        {
            childParentMap[node] = parent;
            CreateParentMap(node->left, node, childParentMap);
            CreateParentMap(node->right, node, childParentMap);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (root == nullptr)
        {
            return {};
        }
        unordered_map<TreeNode *, TreeNode *> ref; // c->p
        CreateParentMap(root, nullptr, ref);

        queue<TreeNode *> level;
        unordered_set<TreeNode *> ignore;

        level.push(target);
        ignore.insert(target);
        int pathDis = 0;

        while (pathDis < k && !level.empty())
        {
            int size = level.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *top = level.front();
                if ((ref[top] != nullptr) && ignore.find(ref[top]) == ignore.end())
                {
                    level.push(ref[top]);
                    ignore.insert(ref[top]);
                }
                if ((top->left != nullptr) && ignore.find(top->left) == ignore.end())
                {
                    level.push(top->left);
                    ignore.insert(top->left);
                }
                if ((top->right != nullptr) && ignore.find(top->left) == ignore.end())
                {
                    level.push(top->right);
                    ignore.insert(top->right);
                }
            }
        }

        vector<int> result;
        while (!level.empty())
        {
            TreeNode *front = level.front();
            result.push_back(front->val);
            level.pop();
        }
        return result;
    }
};