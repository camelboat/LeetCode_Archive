#include <iostream>
#include <vector>

using namespace std;

//// 86.91%, 57.95%
//// Recursive binary search.
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        return findPeakElementHelper(nums, 0, nums.size() - 1);
    }

    int findPeakElementHelper(vector<int> &nums, int left, int right) {
        if (left == right) return left;
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return findPeakElementHelper(nums, left, mid);
        } else {
            return findPeakElementHelper(nums, mid + 1, right);
        }
    }
};


int main() {
    Solution test;
    vector<int> test_data{1, 2, 1, 3, 5, 6, 4};
    // Note that it returns index instead of value.
    cout << test.findPeakElement(test_data) << '\n';
    return 0;
}
