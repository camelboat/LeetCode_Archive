#include <iostream>

//// Just Fibonacci Array

class Solution {
public:
    int climbStairs(int n) {
        // dp
        if (n == 0 || n == 1) return 1;
        long tmp_0 = 1;
        long tmp_1 = 2;
        long tmp;
        for (int i = 2; i < n; ++i)
        {
            tmp = tmp_1;
            tmp_1 = tmp_0 + tmp_1;
            tmp_0 = tmp;
        }
        return tmp_1;
    }
};


