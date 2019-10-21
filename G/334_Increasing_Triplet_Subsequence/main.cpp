#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//// 97.18%, 58.82%
//// store the position of next searching head
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        int next_ind = INT_MAX;
        for (int i = 0; i < nums.size()-2;)
        {
            int tmp = next_ind;
            if (increasingTriplet_helper(nums, i, next_ind)) return true;
            if (next_ind == INT_MAX || tmp == next_ind) return false;
            i = next_ind;
        }
        return false;
    }

    bool increasingTriplet_helper(vector<int>& nums, int start, int &next_ind)
    {
        int fir = nums[start];
        int sec = INT_MAX;
        int next = fir;
        for (int i = start+1; i < nums.size(); ++i)
        {
            int x = nums[i];
            if (x > sec) return true;
            else if (x > fir && x < sec) sec = x;
            else if (x <= fir && x <= next)
            {
                next_ind = i;
                next = x;
            }
        }
        return false;
    }
};

//// 9.13%, 94.12%
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (increasingTriplet_helper(nums, i)) return true;
        }
        return false;
    }

    bool increasingTriplet_helper(vector<int>& nums, int start)
    {
        int fir = nums[start];
        int sec = INT_MAX;
        for (int i = start+1; i < nums.size(); ++i)
        {
            int x = nums[i];
            if (x > sec) return true;
            else if (x > fir && x < sec) sec = x;
        }
        return false;
    }

};