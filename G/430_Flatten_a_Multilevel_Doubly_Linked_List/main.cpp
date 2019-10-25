#include<iostream>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        return_tail(head);
        return head;
    }
    
    // flatten the linked list
    // return the tail of a head
    Node* return_tail(Node* head)
    {
        Node* tmp_next = head->next;
        if (head->child != NULL) 
        {
            head->child->prev = head;
            Node* new_next = return_tail(head->child);
            if (tmp_next != NULL) 
            {
                new_next->next = head->next;
                head->next->prev = new_next;
            }
            head->next = head->child;
            head->child = NULL;
        }
        if (tmp_next == NULL) return head;
        return return_tail(tmp_next);
    }
}; 
