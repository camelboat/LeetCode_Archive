#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if (nums.size() == 0) return -1;
        // if (nums.size() == 1) return nums[0] == target? 0 : -1;
        // if (nums.size() == 2)
        // {
        //     if (nums[0] == target) return 0;
        //     if (nums[1] == target) return 1;
        //     return -1;
        // }
        int fir = 0;
        int bac = nums.size();
        while (bac > fir)
        {
            int i = (bac+fir)/2;
            // cout << "i = " << i << '\n';
            // cout << "fir = " << fir << '\n';
            // cout << "bac = " << bac << '\n';
            // double num = (nums[i] < nums[0]) == (target < nums[0])
            //        ? nums[i]
            //        : target < nums[0] ? INT_MIN : INT_MAX;
            int num;
            if ((nums[i] < nums[0]) != (target < nums[0]))
            {
                if (target<nums[0]) num = INT_MIN;
                else num = INT_MAX;
            }
            else num = nums[i];
            // if (i > nums.size()-1) return -1;
            if (num < target) fir=i+1;
            else if (num > target) bac = i;
            else return i;
        }
        return -1;
    }
};

//// java version
// int search(vector<int>& nums, int target) {
//     int lo = 0, hi = nums.size();
//     while (lo < hi) {
//         int mid = (lo + hi) / 2;

//         double num = (nums[mid] < nums[0]) == (target < nums[0])
//                    ? nums[mid]
//                    : target < nums[0] ? -INFINITY : INFINITY;

//         if (num < target)
//             lo = mid + 1;
//         else if (num > target)
//             hi = mid;
//         else
//             return mid;
//     }
//     return -1;
// }