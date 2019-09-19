#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//// modified from 46_permutations

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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

        unordered_set<int> bas;
        for (int i = start; i < nums.size(); ++i)
        {
            if (bas.find(nums[i]) == bas.end())
            {
                bas.insert(nums[i]);
                swap(nums, start, i);
                permute_helper(nums, start+1, answer);
                swap(nums, start, i);
            }
        }
    }

    void swap(vector<int>& nums, int start, int tar)
    {
        int tmp = nums[start];
        nums[start] = nums[tar];
        nums[tar] = tmp;
    }
};