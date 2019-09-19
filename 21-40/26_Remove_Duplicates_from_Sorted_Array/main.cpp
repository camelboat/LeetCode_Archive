#include <iostream>
#include <vector>

using namespace std;

static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

//// fast and low pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        // int compare = nums[0];
        int answer = 1;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            // if (nums[i] == nums[i+1])
            // {
            //     // nums.erase(nums.begin() + i);
            //     nums[i] = nums[i+1];
            //     --i;
            // }
            if (nums[i] != nums[j])
            {
                ++i;
                nums[i] = nums[j];
                answer++;
            }
        }
        return answer;
    }
};