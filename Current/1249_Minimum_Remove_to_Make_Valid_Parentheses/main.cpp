#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

//// with speedUp, 80.88%, 100.00%
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> bas;
        for (int i = 0; i < s.length(); ++i)
        {
            char cur = s[i];
            if (cur == '(') bas.push(i);
            else if (cur == ')')
            {
                if (!bas.empty()) bas.pop();
                else s[i] = ' ';
            }
        }
        while (!bas.empty())
        {
            s[bas.top()] = ' ';
            bas.pop();
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};

//// 55.07%, 100%
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> res = vector<char>(s.length(), '@');
        stack<int> bas;
        for (int i = 0; i < s.length(); ++i)
        {
            char cur = s[i];
            if (cur <= 'z' && cur >= 'a')
            {
                res[i] = cur;
            }
            else if (cur == '(')
            {
                bas.push(i);
            }
            else if (cur == ')')
            {
                if (!bas.empty())
                {
                    int tmp = bas.top();
                    bas.pop();
                    res[tmp] = '(';
                    res[i] = ')';
                }
            }
        }
        string result;
        for (auto &cur : res)
        {
            if (cur != '@') result+=cur;
        }
        return result;
    }
};

int main() {
    Solution test;
    string test_s = "lee(t(c)o)de)";
    string result = test.minRemoveToMakeValid(test_s);
    cout << result << endl;
    return 0;
}
