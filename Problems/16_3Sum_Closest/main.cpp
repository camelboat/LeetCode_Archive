#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int tar = target - nums[i];
                int left = i+1;
                int right = nums.size()-1;
                int tmp_answer = nums[0] + nums[1] + nums[2];
                while (left < right)
                {
                    if (nums[left] + nums[right] < tar)
                    {
                        left++;
                        int tmp = nums[left-1]+nums[right]+nums[i];
                        tmp_answer = abs(tmp_answer-target) < abs(tmp-target) ? tmp_answer : tmp;
                    }
                    else if(nums[left] + nums[right] > tar)
                    {
                        right--;
                        int tmp = nums[left]+nums[right+1]+nums[i];
                        tmp_answer = abs(tmp_answer-target) < abs(tmp-target) ? tmp_answer : tmp;
                    }
                    else return target;
                }
                answer = abs(answer-target) < abs(tmp_answer-target) ? answer : tmp_answer;
            }
        }
        return answer;
    }
};