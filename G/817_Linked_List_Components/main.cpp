#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//// 90.48%, 78.95%
//// traverse the link list
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> bas(G.begin(), G.end());
        int answer = 0;
        bool is_connected = false;
        while (head != NULL)
        {
            if (bas.find(head->val) != bas.end())
            {
                if (!is_connected)
                {
                    answer++;
                    is_connected = true;
                }
            }
            else is_connected = false;
            head = head->next;
        }
        return answer;
    }
};
