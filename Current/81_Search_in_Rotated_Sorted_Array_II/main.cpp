#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left <= right)
        {
            //// at least a half is in order
            mid = (left + right) / 2;
            // cout << "left = " << left << '\n';
            // cout << "right = " << right << '\n';
            // cout << "mid = " << mid << '\n';

            if (nums[mid] == target) return true;

            //// left side in order
            if (nums[left] < nums[mid])
            {
                if (target >= nums[left] && target < nums[mid]) right = mid-1;
                else left = mid+1;
            }
                //// left side till mide are all equal
            else if (nums[left] == nums[mid]) left++;

                //// right side in order
            else if (nums[mid] <= nums[right])
            {
                if (target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};