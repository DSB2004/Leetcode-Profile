#include <stack>
#include "binary-tree-node.cpp"

using namespace std;

class BSTIterator
{
public:
    stack<TreeNode *> stack_space;

    BSTIterator(TreeNode *root)
    {
        if (root)
        {
            TreeNode *cur = root;
            while (cur)
            {
                stack_space.push(cur);
                cur = cur->left;
            }
        }
    }

    int next()
    {
        if (!stack_space.empty())
        {
            TreeNode *next = stack_space.top();
            TreeNode *rightSide = next->right;
            while (rightSide)
            {
                stack_space.push(rightSide);
                rightSide = rightSide->left;
            }

            return next->val;
        }
    }

    bool hasNext()
    {
        return stack_space.empty();
    }
};