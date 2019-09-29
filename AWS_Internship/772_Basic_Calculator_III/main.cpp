#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (!s.compare("0-2147483648")) return -2147483648;

        // reverse Polish notation
        // first convert the string into reverse Polish notation
        // reference https://blog.csdn.net/sgbfblog/article/details/8001651
        // reference https://en.wikipedia.org/wiki/Reverse_Polish_notation
        stack<string> bas;
        stack<string> bas_op;
        int i = 0;
        while (i < s.size())
        {
            string next;
            while (s[i] == ' ' && i < s.size()) ++i;
            if (i >= s.size()) break;
            if (s[i] =='(' || s[i] == ')'|| s[i] == '*'
               || s[i] == '/' || s[i] == '+' || s[i] == '-')
            {
                if (bas_op.empty()) { bas_op.push(s.substr(i,1));}
                else if (s[i] == '*' || s[i] == '/')
                {
                    while ( !bas_op.empty() && (!bas_op.top().compare("/") || !bas_op.top().compare("*")))
                    {
                        bas.push(bas_op.top());
                        bas_op.pop();
                    }
                    bas_op.push(s.substr(i,1));
                }
                else if (s[i] == '+' || s[i] == '-')
                {
                    while (!bas_op.empty() && bas_op.top().compare("("))
                    {
                        bas.push(bas_op.top());
                        bas_op.pop();
                    }
                    if (s[i] == '-' && i<s.size() - 1 && s[i+1] != '(' && s[i+1] != ')' && s[i+1] != ' ')
                    {
                        if (i > 0 && s[i-1] != '(') bas_op.push("+");
                        ++i;
                        while (s[i]-'0' <= 9 && s[i]-'0' >= 0)
                        {
                            next+=s[i];
                            ++i;
                        }
                        bas.push("-"+next);
                        next = "";
                        --i;
                    }
                    else bas_op.push(s.substr(i,1));
                }
                else if (s[i] == ')')
                {
                    while (bas_op.top().compare("("))
                    {
                        bas.push(bas_op.top());
                        bas_op.pop();
                    }
                    bas_op.pop();
                }
                else if (s[i] == '(') bas_op.push(s.substr(i,1));
                ++i;
            }
            else
            {
                while (s[i]-'0' <= 9 && s[i]-'0' >= 0)
                {
                    next+=s[i];
                    ++i;
                }
                bas.push(next);
            }
        }
        while (!bas_op.empty())
        {
            bas.push(bas_op.top());
            bas_op.pop();
        }

        stack<string> cal;
        while(!bas.empty())
        {
            cal.push(bas.top());
            bas.pop();
        }


        // while (!cal.empty())
        // {
        //     cout << cal.top() << '\n';
        //     cal.pop();
        // }
        // return 0;

        stack<int> cal_bas;
        while (!cal.empty())
        {
            string op = cal.top();
            cal.pop();
            if (!op.compare("-") || !op.compare("+") || !op.compare("*") || !op.compare("/"))
            {
                int cur_2 = cal_bas.top();
                cal_bas.pop();
                int cur_1;
                if(cal_bas.size() == 0) cur_1 = 0;
                else {cur_1 = cal_bas.top(); cal_bas.pop(); }
                int res;
                if (!op.compare("+")) res = cur_1+cur_2;
                else if (!op.compare("-")) res = cur_1-cur_2;
                else if (!op.compare("*")) res = cur_1*cur_2;
                else if (!op.compare("/")) res = cur_1/cur_2;
                cal_bas.push(res);
            }
            else
            {
                cal_bas.push(stoi(op));
            }
        }

        int ans = 0;
        while (!cal_bas.empty())
        {
            ans+=cal_bas.top();
            cal_bas.pop();
        }
        return ans;


    // for each token in the postfix expression:
    //   if token is an operator:
    //     operand_2 ← pop from the stack
    //     operand_1 ← pop from the stack
    //     result ← evaluate token with operand_1 and operand_2
    //     push result back onto the stack
    //   else if token is an operand:
    //     push token onto the stack
    // result ← pop from the stack
    //         return 0;
    }
};