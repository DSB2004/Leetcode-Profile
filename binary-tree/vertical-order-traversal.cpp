// ques name
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <climits>
#include <algorithm>
#include "binary-tree-node-class.cpp"
using namespace std;

// value left level
class Solution
{
public:
    vector<int> verticalOrderTraversal(TreeNode<int> *root)
    {

        // left      level  value
        map<int, map<int, multiset<int>>> ref;
        queue<pair<TreeNode<int> *, vector<int>>> temp;
        temp.push(make_pair(root, vector<int>{0, 0}));

        while (!temp.empty())
        {
            auto cur = temp.front();
            if (cur.first->left)
                temp.push(make_pair(root->left, vector<int>{cur.second[0] + 1, cur.second[1] - 1}));
            if (cur.first->right)
                temp.push(make_pair(root->right, vector<int>{cur.second[0] + 1, cur.second[1] + 1}));
            temp.pop();
            auto map_val = ref[cur.second[0]];
            map_val[cur.second[1]].insert(root->data);
            ref[cur.second[0]] = map_val;
        }

        vector<int> res;
        for (const auto &left_order : ref)
        {
            for (const auto &level : left_order.second)
            {
                for (const auto &value : level.second)
                {
                    res.push_back(value);
                }
            }
        }
        return res;
    }
};