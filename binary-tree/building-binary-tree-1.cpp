// using preorder and inorder

#include <vector>
#include <unordered_map>
#include "binary-tree-node.cpp"

using namespace std;
class Solution
{
public:
    TreeNode *buildTreeHelper(const vector<int> &preorder, const vector<int> &inorder,
                              int preOrderStart, int preOrderEnd,
                              int inOrderStart, int inOrderEnd,
                              const unordered_map<int, int> &ref)
    {
        if (preOrderStart > preOrderEnd || inOrderStart > inOrderEnd)
        {
            return nullptr;
        }

        int rootVal = preorder[preOrderStart];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = ref.at(rootVal);
        int leftSize = rootIndex - inOrderStart;

        root->left = buildTreeHelper(preorder, inorder, preOrderStart + 1, preOrderStart + leftSize,
                                     inOrderStart, rootIndex - 1, ref);
        root->right = buildTreeHelper(preorder, inorder, preOrderStart + leftSize + 1, preOrderEnd,
                                      rootIndex + 1, inOrderEnd, ref);
        return root;
    }

    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder)
    {
        unordered_map<int, int> ref;
        for (int i = 0; i < inorder.size(); ++i)
        {
            ref[inorder[i]] = i;
        };
    }
};