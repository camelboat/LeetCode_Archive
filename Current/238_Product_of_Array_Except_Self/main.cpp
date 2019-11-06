#include<iostream>
#include<vector>

using namespace std;

//// 98.23%, 56.06%
//// left and right product lists
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_products(n, 0);
        int tmp = 1;
        for (int i = 0; i < n; ++i)
        {
            left_products[i] = tmp;
            tmp *= nums[i];
        }
        tmp = 1;
        for (int i = n-1; i >= 0; --i)
        {
            left_products[i] = left_products[i] * tmp;
            tmp *= nums[i];
        }
        return left_products;
    }
};
