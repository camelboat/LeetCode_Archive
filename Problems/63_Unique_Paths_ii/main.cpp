#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j]){dp[i][j] = 0; continue;}
                else if (i == 0 && j >= 1)
                {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                else if (j == 0 && i >= 1)
                {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                else if (i > 0 && j > 0)
                {
                    dp[i][j] = dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
