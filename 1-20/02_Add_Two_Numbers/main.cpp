#include <iostream>
#include <cstring>


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer;
        ListNode *head;
        bool first = true;
        int parity = 0;
        while (l1 != NULL || l2 != NULL || parity != 0)
        {
            int tmp = 0;
            if (l1 != NULL) {tmp += l1->val; l1 = l1->next;}
            if (l2 != NULL) {tmp += l2->val; l2 = l2->next;}
            tmp+= parity;
            parity = tmp / 10;
            tmp = tmp % 10;
            ListNode *new_node = new ListNode(tmp);
            if (first)
            {
                answer = new_node;
                head = answer;
                first = false;
            }
            else
            {
                answer->next = new_node;
                answer = answer->next;
            }
        }
        return head;
    }
};

/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        int status = 1;
        int flag = 0;
        while (status == 1)
        {
            if ((result->val = l1->val + l2->val + flag) > 9)
            {
                result->val-=10;
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            if (l1->next == NULL || l2->next == NULL)
            {
                status = 0;
                if (l2->next != NULL)
                {
                    status = 2;
                }
                if (l1->next != NULL)
                {
                    status = 3;
                }
            }
            else
            {
                l1 = l1->next;
                l2 = l2->next;
            }
            result = result->next;
        }
        if (status == 2)
        {
            while (l2 != NULL)
            {
                if (flag == 1)
                {
                    result->val = l2->val+1;
                    flag == 0;
                }
                else
                {
                    result->val = l2->val;
                    result = result->next;
                    l2 = l2->next;
                }
            }
        }
        if (status == 3)
        {
            while (l1 != NULL)
            {
                if (flag == 1)
                {
                    result->val = l1->val+1;
                    flag == 0;
                }
                else
                {
                    result->val = l1->val;
                    result = result->next;
                    l2 = l2->next;
                }
            }
        }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
*/
