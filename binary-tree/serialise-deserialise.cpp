#include <queue>
#include <string>
#include <sstream>
#include "binary-tree-node.cpp"
using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        string result = "";
        queue<TreeNode *> temp;
        temp.push(root);
        while (!temp.empty())
        {
            int size = temp.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = temp.front();
                temp.pop();
                if (top != nullptr)
                {
                    result += to_string(top->val) + ',';
                    temp.push(top->left);
                    temp.push(top->right);
                }
                else
                {
                    result += '#,';
                }
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }

        stringstream level_order(data);
        string val;
        queue<TreeNode *> temp;

        getline(level_order, val, ',');
        TreeNode *root = new TreeNode(stoi(val));
        temp.push(root);

        while (!temp.empty())
        {
            TreeNode *top = temp.front();
            temp.pop();
            getline(level_order, val, ',');
            if (val != "#")
            {
                top->left = new TreeNode(stoi(val));
                temp.push(top->left);
            }
            getline(level_order, val, ',');
            if (val != "#")
            {
                top->right = new TreeNode(stoi(val));
                temp.push(top->right);
            }
        }
        return root;
    }
};
