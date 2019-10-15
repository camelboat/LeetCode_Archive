#include <iostream>
#include <stack>

using namespace std;

//// 100.00%, 36.36%
//// stack
class Solution {
private:
    string clearbackspace(string &S)
    {
        stack<char> bas;
        int cur = 0;
        while (cur < S.size())
        {
            if (S[cur] == '#')
            {
                if (!bas.empty()) bas.pop();
            }
            else bas.push(S[cur]);
            ++cur;
        }
        string S_org;
        while (!bas.empty())
        {
            S_org = bas.top() + S_org;
            bas.pop();
        }
        return S_org;
    }

public:
    bool backspaceCompare(string S, string T) {
        string S_org = clearbackspace(S);
        string T_org = clearbackspace(T);
        return !S_org.compare(T_org);
    }
};