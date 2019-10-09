#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> answer;
        int n = nums.size();
        if (n == 0)
        {
            if (lower == upper) answer.emplace_back(to_string(lower));
            else answer.emplace_back(to_string(lower)+"->"+to_string(upper));
            return answer;
        }

        // calculate the start index and end index
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i < n-1 && nums[i] >= lower && nums[i+1] != -2147483648)
            {
                start = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > upper)
            {
                end = i-1;
                break;
            }
            if (nums[i] == 2147483647)
            {
                end = i;
                break;
            }
        }
        if (upper >= nums[n-1] && nums[n-1] != 2147483647) end = n-1;

        // first
        if (nums[start] != -2147483648)
        {
            if (lower < nums[start]-1)
            {
                answer.emplace_back(to_string(lower)+"->"+to_string(nums[start]-1));
            }
            if (lower == nums[start]-1) answer.emplace_back(to_string(lower));
        }

        // middle
        for (int i = start; i < end; ++i)
        {
            if (nums[i]+1 >= nums[i+1]) continue;
            if (nums[i]+2 == nums[i+1]) answer.emplace_back(to_string(nums[i]+1));
            else answer.emplace_back(to_string(nums[i]+1)+"->"+to_string(nums[i+1]-1));
        }

        // last
        if (nums[end] != 2147483647)
        {
            if (upper > nums[end]+1)
            {
                answer.emplace_back(to_string(nums[end]+1)+"->"+to_string(upper));
            }
            if (upper == nums[end]+1)
            {
                answer.emplace_back(to_string(upper));
            }
        }
        return answer;
    }
};