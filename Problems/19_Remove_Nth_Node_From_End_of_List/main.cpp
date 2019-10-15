#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fir = new ListNode(0);
        fir->next = head;
        ListNode* end = fir;
        ListNode* tar = fir;

        for (int i = 0; i < n; ++i)
        {
            end = end->next;
        }

        while (end -> next != NULL)
        {
            end = end->next;
            tar = tar->next;
        }
        if (tar->next == head)
        {
            head = head->next;
            return head;
        }

        tar->next = tar->next->next;
        return head;
    }
};