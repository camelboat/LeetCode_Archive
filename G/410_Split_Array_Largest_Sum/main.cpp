#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


//// 22.53%, 20.00%
//// dp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // dp, dp[i][j] = largest sum from nums[0:i] among j subarrays
        vector<vector<long int>> dp(n+1, vector<long int>(m+1, INT_MAX));
        dp[0][0] = 0;
        vector<long int> sum_bas(n+1, 0);
        for (int i = 1; i <= n; ++i) sum_bas[i] = sum_bas[i-1]+nums[i-1];
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                for (int k = 0; k < i; ++k)
                {
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum_bas[i]-sum_bas[k]));
                }
            }
        }
        return dp[n][m];
    }
};