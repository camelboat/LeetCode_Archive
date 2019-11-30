#include <iostream>
#include <vector>

using namespace std;

//// 62.06%, 100.00%
class Solution {
private:
    static void swap(int &a, int &b)
    {
        if (a != b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
    }

public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[cur], nums[i]);
                ++cur;
            }
        }
    }
};

//// 96.95%, 86.11%
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[cur] = nums[i];
                ++cur;
            }
        }
        for (int i = cur; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};

//// 96.95%, 88.89%
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> bas(nums.size(), 0);
        int cur = 0;
        for (auto &x: nums)
        {
            if (x != 0)
            {
                bas[cur] = x;
                cur++;
            }
        }
        nums = bas;
    }
};

//// 22.32%, 93.06%
class Solution {

public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                count++;
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        for (int i = 0; i < count; ++i)
        {
            nums.insert(nums.end(), 0);
        }
    }
};