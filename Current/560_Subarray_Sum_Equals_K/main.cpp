#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//// 90.27%, 60.00%
//// hashmap, see official solution approach #4
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> bas;
        bas[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum+=nums[i];
            if (bas.find(sum-k) != bas.end())
            {
                count+=bas[sum-k];
            }
            if (bas.find(sum) != bas.end())
            {
                bas[sum]++;
            }
            else bas[sum] = 1;
        }
        return count;
    }
};

//// 5.04%, 93.33%
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // dp, dp[i], sum of array[0:i]
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int answer = 0;
        if (nums[0] == k) answer++;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = dp[i-1] + nums[i];
            if (dp[i] == k) answer++;
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if(dp[j] - dp[i-1] == k) answer++;
            }
        }
        return answer;
    }
};