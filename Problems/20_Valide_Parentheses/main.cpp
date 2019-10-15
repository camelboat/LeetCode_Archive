#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bas;
        bool valid = true;
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
                case '(': bas.push('('); break;
                case '{': bas.push('{'); break;
                case '[': bas.push('['); break;
                default: valid = single_pop(s[i], bas);
            }
            if (!valid) return false;
        }
        if (bas.size() == 0) return true;
        else return false;
    }

    bool single_pop(char tar, stack<char> &bas)
    {
        if (bas.size() == 0)
        {
            return false;
        }
        else if ((bas.top()=='(' && tar == ')') ||
                (bas.top()=='{' && tar == '}') ||
                (bas.top()=='[' && tar==']'))
        {
            bas.pop();
            return true;
        }
        else
        {
            return false;
        }
    }
};