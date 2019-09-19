#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int tmp = 0;
        for (int i = digits.size()-1; i>=0; --i)
        {
            digits[i] = i == digits.size()-1 ? (digits[i]+1+tmp) % 10 : (digits[i]+tmp) % 10;
            if (digits[i] != 0) break;
            else
            {
                tmp = 1;
                if (i == 0) digits.insert(digits.begin(), 1);
            };
        }
        return digits;
    }
};