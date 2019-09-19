#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int answer = 1;
        int i = 0;
        int tmp = 1;
        int tar = nums[0];
        int start = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == tar)
            {
                tmp++;
                answer++;
            }
            else if (nums[i] != tar)
            {
                tmp = 1;
                answer++;
                tar = nums[i];
            }
            if (tmp > 2)
            {
                for (int j = i+1; j < nums.size(); ++j)
                {
                    swap(nums[j-1], nums[j]);
                }
                --i;
                --n;
                --answer;
                --tmp;
            }
        }
        return answer;
    }

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};