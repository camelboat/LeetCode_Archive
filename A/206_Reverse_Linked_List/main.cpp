#include<iostream>
#include<stack>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//// 98.88%, 55.72%
//// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }  
};

//// 98.88%, 22.90%
//// stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        stack<ListNode*> bas;
        while (head != NULL)
        {
            bas.push(head);
            head = head->next;
        }
        head = bas.top();
        bas.pop();
        ListNode* first = head;
        while (!bas.empty())
        {
            head->next = bas.top();
            bas.pop();
            head = head->next;
        }
        head->next = NULL;
        return first;
    }
};

