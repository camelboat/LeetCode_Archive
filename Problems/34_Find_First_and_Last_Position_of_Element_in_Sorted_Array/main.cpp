#include <iostream>
#include <vector>

using namespace std;

//// Binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fir = 0;
        int bac = nums.size(); // use nums.size() as bac instead of nums.size()-1
        bool flag = false;     // in order to deal with nums.size()==1
        int pos;
        int mid;
        while (fir < bac)
        {
            mid = (fir+bac)/2;
            // cout << "mid = " << mid << '\n';
            if (target > nums[mid])
            {
                fir = mid+1;
            }
            else if (target < nums[mid])
            {
                bac = mid;
            }
            else
            {
                flag = true;
                pos = mid;
                break;
            }
        }
        vector<int> answer;
        if (!flag)
        {
            answer.emplace_back(-1);
            answer.emplace_back(-1);
            return answer;
        }
        else
        {
            fir = mid;
            while(nums[fir] == target)
            {
                // cout << "fir = " << fir << '\n';
                --fir;
                if (fir < 0) break;
            }
            ++fir;
            bac = mid;
            while(nums[bac] == target)
            {
                ++bac;
                if (bac > nums.size()-1) break;
            }
            --bac;
            // cout << "fir = " << fir << '\n';
            answer.emplace_back(fir);
            answer.emplace_back(bac);
            return answer;
        }
    }
};