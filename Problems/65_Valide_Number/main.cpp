#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        while (s[i] == ' ') ++i;

        if (s[i] == '+' || s[i] == '-') ++i;

        int dig_n = 0;
        int pt_n = 0;
        while (s[i] - '0' <= 9 && s[i] - '0' >= 0 || s[i] == '.')
        {
            s[i] == '.' ? pt_n++ : dig_n++;
            ++i;
        }
        if (dig_n == 0 || pt_n > 1) return false;

        if (s[i] == 'e')
        {
            ++i;
            if (s[i] == '+' || s[i] == '-') ++i;
            dig_n = 0;
            while (s[i] - '0' <= 9 && s[i] - '0' >= 0)
            {
                dig_n++;
                ++i;
            }
            if (dig_n == 0) return false;
        }
        while (s[i] == ' ') ++i;

        return s[i] == 0;

    }
};