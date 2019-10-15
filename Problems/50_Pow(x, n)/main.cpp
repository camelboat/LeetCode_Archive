#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (x == -1)
        {
            if (n % 2 == 0) return 1;
            else return -1;
        }
        if (n == -2147483648) return 0;
        
        if (n > 0) return myPow_helper(x, n);
        else return 1/myPow_helper(x,-n);
    }
    
    double myPow_helper(double x, int n)
    {
        if (n == 0) return 1;
        if (n % 2 == 0)
        {
            double tmp = myPow_helper(x, n/2);
            return tmp * tmp;
        }
        if (n % 2 != 0)
        {
            double tmp = myPow_helper(x, (n-1)/2);
            return tmp * tmp * x;
        }
        return -1;
    }
};