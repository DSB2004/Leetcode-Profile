#include <iostream>
#include "linked-list-node.cpp"
using namespace std;

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}