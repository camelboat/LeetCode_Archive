#include <iostream>
#include <vector>

using namespace std;

//// 57.41%, 62.16%
//// Simple traverse.
class Solution {
private:
    void swap(vector<int> &nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

public:
    void wiggleSort(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            bool is_less = i % 2 == 0 ? true : false;
            if (is_less && nums[i] > nums[i - 1]) {
                swap(nums, i, i - 1);
            }
            if (!is_less && nums[i] < nums[i - 1]) {
                swap(nums, i, i - 1);
            }
        }
    }
};


int main() {
    Solution test;
    vector<int> test_data{3, 5, 2, 1, 6, 4};
    test.wiggleSort(test_data);
    for (auto &num : test_data) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
