#include <iostream>
#include <vector>

using namespace std;

//// greedy algorithm
class Solution {
public:
    int jump(vector<int>& nums) {
        int answer = 0;
        if (nums.size() == 1) return 0;
        for (int i = 0; i < nums.size();)
        {
            int nex = i+1;
            int tmp = 0;
            for (int j = 1; j <= nums[i] && j+i < nums.size(); ++j)
            {
                if (i+j == nums.size()-1) return ++answer;
                if (nums[j+i] + j > tmp)
                {
                    tmp = nums[j+i] + j;
                    nex = i+j;
                }

            }
            answer++;
            i = nex;
        }
        return answer;
    }
};

//// dp, time limit exceeded
class Solution {
public:
    int jump(vector<int>& nums) {
        // dp, dp[i] is the minimum number of jumps to nums[i]
        int n = nums.size();
        vector<int> dp(n, n);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            // cout << "i = " << i << '\n';
            for (int j = nums[i]+i < n-1 ? nums[i]+i : n-1 ; j >= i; --j)
            {
                // cout << "j = " << j << '\n';
                dp[j] = dp[j] < (dp[i]+1) ? dp[j] : dp[i]+1;
                if (j == n-1) return dp[n-1];
            }
        }
        return dp[n-1];
    }
};