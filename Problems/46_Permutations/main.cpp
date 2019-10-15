#include <iostream>
#include <vector>

using namespace std;

//// recursion

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        permute_helper(nums, 0, answer);
        return answer;
    }

    void permute_helper(vector<int>& nums, int start, vector<vector<int>> &answer)
    {
        if (start == nums.size())
        {
            answer.emplace_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i)
        {
            swap(nums, start, i);
            permute_helper(nums, start+1, answer);
            swap(nums, start, i);
        }
    }

    void swap(vector<int>& nums, int start, int tar)
    {
        int tmp = nums[start];
        nums[start] = nums[tar];
        nums[tar] = tmp;
    }
};

