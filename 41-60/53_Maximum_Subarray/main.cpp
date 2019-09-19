#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp, dp[i] max subarray end with i;

        int n = nums.size();
        int dp = nums[0];
        int answer = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (dp < 0) dp = nums[i];
            else dp+=nums[i];
            answer = dp > answer ? dp : answer;
        }
        return answer;
    }
};