// using inorder and postorder

#include <vector>
#include <unordered_map>
#include "binary-tree-node.cpp"

using namespace std;

class Solution
{
public:
    TreeNode *util(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> ref,
                   int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd)
    {
        if (postOrderStart > postOrderEnd || inOrderStart > inOrderEnd)
        {
            return nullptr;
        }
        int nodeVal = postorder[postOrderEnd];
        TreeNode *node = new TreeNode(nodeVal);
        int nodePos = ref.at(nodeVal); // in inorder

        int leftTreeSize = nodePos - inOrderStart;

        node->left = util(inorder, postorder, ref, inOrderStart, nodePos-1,
                          postOrderStart, postOrderStart + leftTreeSize - 1);
        node->right = util(inorder, postorder, ref, nodePos + 1, inOrderEnd,
                           postOrderStart + leftTreeSize + 1, postOrderEnd - 1);
        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> ref;
        for (int i = 0; i < inorder.size(); i++)
        {
            ref[inorder[i]] = i;
        }
        return util(inorder, postorder, ref,
                    0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};