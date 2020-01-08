#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//// 97.91%, 93,94%
//// ?
 class Solution {
 public:
     int findKthLargest(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());
         return nums[nums.size()-k];
     }
 };

//// 79.56%, 60.61%
//// quicksort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return nums[quickselect(0, n-1, n-k, nums)];
    }

    int quickselect(int left, int right, int k, vector<int>& nums)
    {
        if (left == right) return left;
        int pivot_index = rand() % (right-left) + left;
        pivot_index = partition(left, right, pivot_index, nums);
        if (k == pivot_index) return pivot_index;
        else if (k < pivot_index) return quickselect(left, pivot_index-1, k, nums);
        return quickselect(pivot_index+1, right, k, nums);
    }

    int partition(int left, int right, int pivot_index, vector<int>& nums)
    {
        int pivot = nums[pivot_index];
        swap(pivot_index, right, nums);
        int store_index = left;
        for (int i = left; i <= right; ++i)
        {
            if (nums[i] < pivot)
            {
                swap(store_index, i, nums);
                store_index++;
            }
        }
        swap(store_index, right, nums);
        return store_index;
    }

    void swap(int a, int b, vector<int>& nums)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};

