#include <iostream>
#include "list-node.cpp"
using namespace std;

class Solution
{

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        int carry = 0;

        while (l1 || l2)
        {
            int l1_val = 0;
            int l2_val = 0;
            if (l1)
            {
                l1_val = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                l2_val = l2->val;
                l2 = l2->next;
            }

            int temp = l1_val + l2_val + carry;
            int sum = temp % 10;
            carry = temp / 10;
            ListNode *node = new ListNode(sum);
            if (!head)
            {
                head = node;
            }
            else
            {
                cur->next = node;
            }
            cur = node;
        }

        if (carry > 0)
        {
            ListNode *node = new ListNode(carry);
            cur->next = node;
        }
        return head;
    }
};