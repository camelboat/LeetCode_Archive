#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int fir;
        if (l1->val < l2->val)
        {
            fir = l1->val;
            p1 = p1->next;
        }
        else
        {
            fir = l2->val;
            p2 = p2->next;
        }
        ListNode *ans = new ListNode(fir);
        ListNode *answer = ans;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                ListNode *tmp = new ListNode(p1->val);
                ans->next = tmp;
                ans = tmp;
                p1 = p1->next;
            }
            else
            {
                ListNode *tmp = new ListNode(p2->val);
                ans->next = tmp;
                ans = tmp;
                p2 = p2->next;
            }
        }
        while (p1 != NULL)
        {
            ListNode *tmp = new ListNode(p1->val);
            ans->next = tmp;
            ans = tmp;
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            ListNode *tmp = new ListNode(p2->val);
            ans->next = tmp;
            ans = tmp;
            p2 = p2->next;
        }
        return answer;
    }
};