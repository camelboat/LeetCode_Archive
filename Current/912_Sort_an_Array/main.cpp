#include <iostream>
#include <vector>

using namespace std;

//// 91.97%, 55.04%
//// Quick sort.
class Solution {
private:
    void swap(vector<int> &nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int pivot = nums[(left + right) / 2];
        int partition = findPartition(nums, left, right, pivot);
        quickSort(nums, left, partition - 1);
        quickSort(nums, partition, right);
    }

    int findPartition(vector<int> &nums, int left, int right, int pivot) {
        while (left <= right) {
            while (nums[left] < pivot) {
                left++;
            }
            while (nums[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(nums, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
};


int main() {
    Solution test;
    vector<int> test_array{5, 1, 1, 2, 0, 0};
    test.sortArray(test_array);
    for (auto &num : test_array) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
