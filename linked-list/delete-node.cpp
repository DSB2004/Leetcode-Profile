#include <iostream>
#include "list-node.cpp"
using namespace std;
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *nextNode = node->next;

        node->val = nextNode->val;
        node->next = nextNode->next;
    }
};