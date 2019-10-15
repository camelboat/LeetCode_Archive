#include <iostream>


//// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL)
    {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int count = 0;
        ListNode *pt = head;
        while (pt != NULL)
        {
            count++;
            pt = pt->next;
        }
        if (count < k) return head;

        pt = head;
        ListNode *pre = new ListNode(0);
        for (int i = 0; i < (int) count / k; ++i)
        {
            if (i == 0) head = reverseOneGroup(pt, k);
            else pre->next = reverseOneGroup(pt, k);
            pre = pt;
            pt = pt->next;
        }

        return head;
    }

    ListNode *reverseOneGroup(ListNode *head, int k)
    {
        ListNode *pt = head;
        for (int i = 0; i < k; ++i)
        {
            pt = pt->next;
        }
        ListNode *bac = pt;
        ListNode *pre = bac;
        ListNode *next;
        pt = head;
        for (int i = 0; i < k; ++i)
        {
            next = pt->next;
            pt->next = pre;
            // cout << "now flip " << pt->val << '\n';
            pre = pt;
            // cout << "now pre is " << pre->val << '\n';
            pt = next;
        }
        return pre;
    }
};