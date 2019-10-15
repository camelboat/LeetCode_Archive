#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* it = head;
        if (head == NULL || head->next == NULL) return head;
        int length = 0;
        while (it->next != NULL)
        {
            length++;
            it = it->next;
        }
        length++;
        it->next = head;
        k = length - k%length - 1;
        it = head;
        for (int i = 0; i < k; ++i)
        {
            it = it->next;
        }
        ListNode* tar = it->next;
        it->next = NULL;
        return tar;
    }
};