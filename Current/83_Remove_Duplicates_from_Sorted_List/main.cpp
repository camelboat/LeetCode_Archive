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
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != NULL)
        {
            // cout << "slow = " << slow->val << '\n';
            fast = slow->next;
            if (fast == NULL) break;
            while (fast->val == slow->val)
            {
                fast = fast->next;
                if (fast == NULL) break;
            }
            slow -> next = fast;
            slow = slow->next;
        }
        return tmp->next;
    }
};