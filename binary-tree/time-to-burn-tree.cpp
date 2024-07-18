#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include "binary-tree-node-2.cpp"
using namespace std;

void CreateParentMap(BinaryTreeNode<int> *node, BinaryTreeNode<int> *parent,
                     int target, BinaryTreeNode<int> *&address, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &childParentMap)
{
    if (node != nullptr)
    {
        if (node->data == target)
        {
            address = node;
        }
        childParentMap[node] = parent;
        CreateParentMap(node->left, node, target, address, childParentMap);
        CreateParentMap(node->right, node, target, address, childParentMap);
    }
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    // creating a child to parent map and getting the address of the required start node
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> ref;
    BinaryTreeNode<int> *target = nullptr;

    CreateParentMap(root, nullptr, start, target, ref);

    queue<BinaryTreeNode<int> *> todo;
    unordered_set<BinaryTreeNode<int> *> ignore;

    todo.push(target);
    ignore.insert(target);
    int result = -1;

    while (!todo.empty())
    {
        int size = todo.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = todo.front();
            todo.pop();

            if (ref[front] != nullptr && ignore.find(ref[front]) == ignore.end())
            {
                ignore.insert(ref[front]);
                todo.push(ref[front]);
            }

            if (front->left != nullptr && ignore.find(front->left) == ignore.end())
            {
                ignore.insert(front->left);
                todo.push(front->left);
            }

            if (front->right != nullptr && ignore.find(front->right) == ignore.end())
            {
                ignore.insert(front->right);
                todo.push(front->right);
            }
        }
        result++;
    }
    return result;
}
