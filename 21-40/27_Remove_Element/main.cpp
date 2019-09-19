#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int bac = nums.size()-1;
        int fir = 0;

        while (fir <= bac)
        {
            if (nums[fir]==val)
            {
                nums[fir] = nums[bac];
                bac--;
            }
            else
            {
                fir++;
            }
        }

        return fir;
    }
};