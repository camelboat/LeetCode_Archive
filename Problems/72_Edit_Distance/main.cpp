#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp, dp[m][n] means the edit distance between word1[0,m-1] to word2[0,m-1]
        // should remain one line for the empty string condition
        int m = word1.size();
        int n = word2.size();
        if (m == 0) return n;
        if (n == 0) return m;

        int large = m > n ? m : n;
        vector<vector<int>> dp(m+1, vector<int>(n+1, large));
        if (word1[0] == word2[0]) dp[1][1] = 0;
        else dp[1][1] = 1;

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (word1[i-1] == word2[j-1])
                {
                    int min_val = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                    dp[i][j] = min(min_val, dp[i-1][j-1]);
                }
                else
                {
                    int min_val = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                    dp[i][j] = min(min_val, dp[i-1][j-1]+1);
                }
            }
        }
        return dp[m][n];
    }
};