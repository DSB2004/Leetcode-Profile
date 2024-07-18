#include <iostream>
#include "binary-tree-node-2.cpp"
using namespace std;

// int intermediate(BinaryTreeNode<int> *root){

// }

void changeTree(BinaryTreeNode<int> *root)
{

    if (root == nullptr)
    {
        return;
    }

    int leftSide = 0, rightSide = 0;

    if (root->left)
    {
        leftSide = root->left->data;
    }

    if (root->right)
    {
        rightSide = root->right->data;
    }
    if (leftSide + rightSide < root->data)
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);

    root->data = max(root->data,
                     (root->left ? root->left->data : 0) +
                         (root->right ? root->right->data : 0));

    return;
}