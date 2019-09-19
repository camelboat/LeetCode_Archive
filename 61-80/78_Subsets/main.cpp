#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> tmp;
        for (int k = 0; k <= nums.size(); ++k)
        {
            combine_helper(nums, 1, k, answer, tmp);
        }
        return answer;
    }


    void combine_helper(vector<int> nums, int start, int k, vector<vector<int>>& answer, vector<int>& tmp)
    {
        if (k == 0)
        {
            answer.emplace_back(tmp);
            return;
        }
        for (int i = start; i <= nums.size()-k+1; ++i)
        {
            // cout << "i = " << i << '\n';
            tmp.emplace_back(nums[i-1]);
            combine_helper(nums, i+1, k-1, answer, tmp);
            tmp.pop_back();
        }
    }
};