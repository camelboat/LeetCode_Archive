#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return;
        if (nums.size() == 2)
        {
            int tmp = nums[0];
            nums[0] = nums[1];
            nums[1] = tmp;
            return;
        }
        bool flag = false;
        int bac = nums.size()-2;
        while (nums[bac] >= nums[bac+1] && bac >= 1)
        {
            bac--;
        }
        if (bac == 0 && nums[0] >= nums[1])
        {
            sort(nums.begin(), nums.end());
            return;
        }
        // cout << "bac = " << bac << '\n';
        int fin = bac+1;
        while (nums[fin] > nums[bac] && fin < nums.size()-1)
        {
            fin++;
        }
        if (nums[fin] <= nums[bac]) --fin;
        // cout << "fin = " << fin << '\n';
        int tmp = nums[fin];
        nums[fin] = nums[bac];
        nums[bac] = tmp;
        sort(nums.begin()+bac+1, nums.end());
        return;
    }
};