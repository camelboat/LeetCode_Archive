#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int x_origin = x;
        if (x < 0 || x%10 == 0 && x!=0)
        {
            return false;
        }
        int x_compare = 0;
        int digits = floor(log10(x)) + 1;
        int half = floor(digits / 2);

        // int last_half = x_origin;
        // for (int i = 0; i < digits - half; ++i)
        // {
        //     last_half += (floor)(last_half / pow(10, digits-i-1)) * pow(10, digits-i-1);
        // }

        int last_half = 0;
        int x_tmp = x_origin;
        for (int i = 0; i < half; ++i)
        {
            last_half = last_half*10 + x_tmp % 10;
            // cout << "x_tmp" << x_tmp << endl;
            x_tmp = x_tmp / 10;
        }

        // cout << digits << endl;
        // int tmp = 0;
        // for (int i = 0; i < half; ++i) {
        //     tmp = (floor)(x / pow(10, digits - i - 1));
        //     // cout << "tmp" << tmp << endl;
        //     x -= tmp * pow(10, digits-i-1);
        //     x_compare += tmp * pow(10, i);
        // }

        cout << last_half << endl;
        cout << x_tmp << endl;
        return (last_half == x_tmp || last_half == x_tmp / 10);
    }
};