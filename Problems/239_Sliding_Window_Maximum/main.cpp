#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        if (nums.size() == 0) return answer;
        priority_queue<pair<int, int>> bas; // <val, index>
        for (int i = 0; i < nums.size(); ++i)
        {
            // pop the element that is not in the window
            while (!bas.empty() && bas.top().second <= i-k) bas.pop();

            // insert the new element to the window
            bas.push(make_pair(nums[i], i));

            // add to answer if the window size is equal to k
            if (i >= k-1) answer.emplace_back(bas.top().first);
        }
        return answer;
    }
};

