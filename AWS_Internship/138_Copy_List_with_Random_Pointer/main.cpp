#include <iostream>
#include <map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


//// based on LeetCode solution
//// use map to memorize which node has
//// already been copied to solve the
//// random pointer issue

class Solution {
    map<Node*, Node*> bas;
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        if (bas.find(head) != bas.end()) return bas[head];
        Node *tmp = new Node(head->val, NULL, NULL);
        bas[head] = tmp;
        tmp->next = copyRandomList(head->next);
        tmp->random = copyRandomList(head->random);
        return tmp;
    }
};