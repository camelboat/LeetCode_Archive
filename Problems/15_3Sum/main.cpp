#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size() < 3) return answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; ++i)
        {
            // do not duplicate
            if (i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int tar = -nums[i];
                int left = i+1;
                int right = nums.size()-1;
                while (left < right)
                {
                    int tmp_sum = nums[left]+nums[right];
                    if (tmp_sum == tar)
                    {
                        answer.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                        // do not duplicate
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if (tmp_sum > tar) right--;
                    else left++;
                }
            }
        }
        return answer;
    }
};