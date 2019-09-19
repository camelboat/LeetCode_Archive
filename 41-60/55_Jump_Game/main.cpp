#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // logic
        int max = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > max) return false;
            max = max > nums[i] + i ? max : nums[i]+i;
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp, dp[i]: i is able to reach the last index
        int n = nums.size();
        bool *dp = new bool[n];
        dp[n-1] = true;
        for (int i = n-2; i >= 0; --i)
        {
            dp[i] = false;
            for (int j = 1; j <= nums[i] && i+j < n; ++j)
            {
                dp[i] = dp[i+j];
                if (dp[i]) break;
            }
        }
        return dp[0];
    }
};