#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *last = tmp;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL)
        {
            slow = last->next;
            fast = slow;
            while (fast->val == slow->val)
            {
                fast = fast->next;
                if (fast == NULL) break;
            }
            if (fast != slow->next) last->next = fast;
            else last = last->next;
            if (fast == NULL) break;
        }
        return tmp->next;
    }
};