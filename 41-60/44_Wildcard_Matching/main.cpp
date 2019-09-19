#include <iostream>
#include <string>
#include <vector>

using namespace std;

//// iterator

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int star = -1;
        int last_match = 0;
        while (i < s.size())
        {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?'))
            {
                i++; j++; continue;
            }
            if (p[j] == '*')
            {
                last_match = i;
                star = j++;
                continue;
            }
            if (star != -1) // but also not match
            {
                i = ++last_match;
                j = star+1;
                continue;
            }
            return false;
        }
        while (j < p.size() && p[j] == '*') j++;
        return j == p.size();
    }
};




//// dp

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j-1] != '*')
                {
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
                else
                {
                    dp[i][j] = dp[i][j-1] || (i && dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};