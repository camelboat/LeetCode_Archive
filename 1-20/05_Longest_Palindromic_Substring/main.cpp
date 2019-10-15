#include <iostream>
#include <string>

using namespace std;

// dynamic programming
// store all sub-problems' results

// Manacher's Algorithm?

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 0)
        {
            return "";
        }
        string answer = s.substr(0,1);
        int start = 0;

        // use dp[i][j] to indicate whether s[i:j] is a palindromic string
        int dp[length][length];
        for (int i = 0; i < length; ++i)
        {
            for (int j = 0; j < length; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int i = length-1; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if(j - i == 1 && s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                }
                if (dp[i][j] == 1 && j-i+1 >= answer.size())
                {
                    if (j-i+1 == answer.size() && i < start)
                    {
                        answer = s.substr(i,j-i+1);
                        start = i;
                    }
                    else if (j-i+1 > answer.size())
                    {
                        answer = s.substr(i, j-i+1);
                        start = i;
                    }
                }
            }
        }
        return answer;
    }
};