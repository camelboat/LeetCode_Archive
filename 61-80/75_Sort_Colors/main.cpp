#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_point = 0;
        int two_point = nums.size()-1;
        int search = 0;
        while (zero_point < two_point && search <= two_point)
        {
            // cout << "search = " << search << '\n';
            if (nums[search] == 0)
            {
                swap(nums[zero_point], nums[search]);
                zero_point++;
            }
            else if (nums[search] == 2)
            {
                swap(nums[two_point], nums[search]);
                two_point--;
                --search;
            }
            search++;
        }
    }

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};