#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//// unordered_set + trick
class Solution {
public:
    // keep in mind that the result can only be in the range of 1 to nums.size()+1
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> bas;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0) bas.insert(nums[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!bas.count(i)) return i;
        }
        return nums.size()+1;
    }
};


//// Sort
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // scan once to find both max and min
        sort(nums.begin(), nums.end());
        int answer = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (answer == nums[i]) answer++;
        }
        return answer;
    }
};
 */