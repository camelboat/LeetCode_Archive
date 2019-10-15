#include <iostream>
#include <vector>

using namespace std;

//// equation
class Solution {
public:
    int uniquePaths(int m, int n) {
        // equation
        int N = m+n-2;
        int k = m-1;

        // calculate C(N, k);
        long answer = 1;
        for (int i = 1; i <= k; ++i)
        {
            answer = answer * (N-k+i) / i;
        }
        return answer;
    }
};

//// dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp
        vector<vector<int>> dp;
        for (int i = 0; i < m; ++i)
        {
            vector<int> tmp;
            for (int j = 0; j < n; ++j)
            {
                tmp.emplace_back(0);
            }
            dp.emplace_back(tmp);
        }
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j >= 1)
                {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                else if (j == 0 && i >= 1)
                {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                else
                {
                    for (int k = 0; k < j; ++k)
                    {
                        dp[i][j]+=dp[i-1][k];
                    }
                    for (int k = 0; k < i; ++k)
                    {
                        dp[i][j]+=dp[k][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};