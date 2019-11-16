#include <iostream>
#include <vector>
#include <climits>

using namespace std;


//// 90.07%, 92.16%
//// dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        if (amount == 0) return 0;
        for (int i = 0; i <= amount; ++i)
        {
            int tmp = INT_MAX;
            for (auto &coin : coins)
            {
                if (i-coin >= 0)
                {
                    if (i-coin == 0)
                    {
                        tmp = 1; break;
                    }
                    else if (dp[i-coin] != -1) tmp = tmp < (dp[i-coin]+1) ? tmp : (dp[i-coin]+1);
                }
            }
            dp[i] = tmp == INT_MAX ? -1 : tmp;
        }
        return dp[amount];
    }
};