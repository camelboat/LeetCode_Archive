#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int answer = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            // cout << i << '\n';
            if (s[i] == ')')
            {
                if (s[i-1] == '(')
                {
                    if (i == 1) dp[i] = 2;
                    else dp[i] = dp[i-2] + 2;
                }
                else
                {
                    if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                    {
                        int fir = i-dp[i-1]-1 == 0 ? 0 : dp[i-dp[i-1]-2];
                        dp[i] = dp[i-1]+fir+2;
                    }
                    else
                    {
                        dp[i] = 0;
                    }
                }
            }
            answer = answer > dp[i] ? answer : dp[i];
        }
        return answer;
    }
};