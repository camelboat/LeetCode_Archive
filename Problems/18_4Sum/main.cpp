#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        if (nums.size() < 4) return answer;

        sort(nums.begin(), nums.end());

        // notice where to end
        for (int j = 0; j < nums.size()-3; ++j)
        {
            // do not duplicate
            if (j == 0 || (j > 0 && nums[j] != nums[j-1]))
            {
                for (int i = j+1; i < nums.size()-2; ++i)
                {
                    // do not duplicate
                    if (i == j+1 || nums[i] != nums[i-1])
                    {
                        int tar = target-nums[i]-nums[j];
                        int left = i+1;
                        int right = nums.size()-1;
                        while (left < right)
                        {
                            int tmp_sum = nums[left]+nums[right];
                            if (tmp_sum == tar)
                            {
                                answer.emplace_back(vector<int>{nums[j], nums[i], nums[left], nums[right]});
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
            }

        }
        return answer;
    }
};