#include <iostream>
#include <stack>

using namespace std;

//// stack
class Solution {
public:
    string decodeString(string s) {
        string answer;
        stack<char> bas;
        for (char i : s)
        {
            if (i == ']')
            {
                string tmp;
                while (bas.top() != '[')
                {
                    tmp = bas.top()+tmp;
                    bas.pop();
                }

                // pop '['
                bas.pop();
                string times_str;
                while (!bas.empty() && bas.top()-'0' <= 9 && bas.top()-'0' >= 0)
                {
                    times_str = bas.top() + times_str;
                    bas.pop();
                }
                int times = stoi(times_str);
                for (int i = 0; i < times; ++i)
                {
                    for (char j : tmp) bas.push(j);
                }
            }
            else bas.push(i);
        }

        while (!bas.empty())
        {
            answer = bas.top()+answer;
            bas.pop();
        }
        return answer;
    }
};