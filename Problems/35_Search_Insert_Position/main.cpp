#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();
        int fir = 0;
        int bac = nums.size(); // use bac = nums.size() instead of nums.size()-1
        int mid;
        while (fir < bac)
        {
            mid = (fir+bac)/2;
            // cout << "mid = " << mid << '\n';
            if (target > nums[mid])
            {
                fir = mid+1;
            }
            else if (target < nums[mid])
            {
                bac = mid;
            }
            else
            {
                return mid;
            }
        }
        // if (target > nums[mid]) return mid+1;
        // else if (target < nums[mid]) return mid;
        // return mid;
        return fir;
    }
};