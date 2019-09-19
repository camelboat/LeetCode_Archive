#include <iostream>

//// Should use recursion


//// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int length = 0;
        ListNode* pt = head;
        ListNode* answer;
        while (pt != NULL)
        {
            length++;
            pt = pt->next;
        }
        if (length == 0 || length == 1)
        {
            return head;
        }
        else if (length % 2 == 0)
        {
            pt = head;
            answer = head->next;
            for (int i = 0; i < length; i+=2)
            {
                // cout << "switch " << pt->val << " and " << pt->next->val << '\n';
                ListNode *tmp = pt->next->next;
                swapNode(pt, pt->next);
                if (tmp != NULL)
                {
                    pt->next = pt->next->next;
                }
                pt = tmp;
                // cout << "pt is " << pt->val << '\n';
                // cout << "now pt next is " << pt->next->val << '\n';
            }
        }
        else if (length %2 == 1)
        {
            pt = head;
            answer = head->next;
            for (int i = 0; i < length-1; i+=2)
            {
                ListNode *tmp = pt->next->next;
                // cout << "tmp is " << tmp->val << '\n';
                swapNode(pt, pt->next);
                if (tmp->next != NULL)
                {
                    pt->next = pt->next->next;
                }
                pt = tmp;
                // cout << "pt is " << pt->val << '\n';
            }
        }
        return answer;
    }

    void swapNode(ListNode *l1, ListNode *l2)
    {
        ListNode *tmp = l2->next;
        l2->next = l1;
        l1->next = tmp;
        // cout << "switch " << l1->val << " and " << l2->val << '\n';
    }
};


/* java version of recursion
public ListNode swapPairs(ListNode head) {
    if ((head == null)||(head.next == null))
        return head;
    ListNode n = head.next;
    head.next = swapPairs(head.next.next);
    n.next = head;
    return n;
}
*/