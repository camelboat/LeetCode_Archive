#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//// 98.15%, 90.83%
//// optimal dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        int answer = 0;
        int dp = INT_MIN;
        for (int i = day-2; i >= 0; --i)
        {
            dp = dp > prices[i+1] ? dp : prices[i+1];
            int tmp = dp - prices[i];
            answer = tmp > answer ? tmp: answer;
        }
        return answer;
    }
};


//// 65.87%, 83.49%
//// dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        vector<int> dp(day, INT_MIN); // dp[i]: maximum in [i:day-1]
        for (int i = day-2; i >= 0; --i)
        {
            dp[i] = dp[i+1] > prices[i+1] ? dp[i+1] : prices[i+1];
        }
        int answer = 0;
        for (int i = 0; i < day-1; ++i)
        {
            int tmp = dp[i] - prices[i];
            answer = tmp > answer ? tmp : answer;
        }
        return answer;
    }
};


//// 5.92%, 46.79%
//// brute-force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        int answer = 0;
        for (int i = 0; i < day; ++i)
        {
            for (int j = i+1; j < day; ++j)
            {
                int tmp = prices[j] - prices[i];
                answer = answer > tmp ? answer : tmp;
            }
        }
        return answer;
    }
};
