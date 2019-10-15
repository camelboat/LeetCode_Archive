#include <iostream>
#include <string>
#include <math.h>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int size = str.size();
        int negative_flag = 0;
        while (str[i] == ' ')
        {
            ++i;
        }
        if (str[i] == '-')
        {
            negative_flag = 1;
            ++i;
        }
        else if (str[i] == '+')
        {
            ++i;
        }
        if (!isdigit(str[i]))
        {
            return 0;
        }
        while (str[i] == '0')
        {
            ++i;
        }

        long int answer = 0;
        int digits = 0;
        int start = i;
        // cout << "i" << i << endl;
        while (isdigit(str[i]))
        {
            ++i;
            ++digits;
        }
        if (digits > 15)
        {
            if (negative_flag)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
        int end = i-1;
        // cout << "i" << i << endl;
        // cout << "negative flag" << negative_flag << endl;

        for (int j = end; j >= start ; --j) {
            answer += (str[j]-'0') * pow(10, end-j);
            // cout << "digit" << str[j] << endl;
            // cout << "pow" << pow(10, end - j) << endl;
            if (answer >= INT_MAX && !negative_flag)
            {
                return INT_MAX;
            }
            else if (answer > INT_MAX && negative_flag)
            {
                return INT_MIN;
            }
        }
        if (negative_flag)
        {
            answer = -answer;
        }
        return answer;
    }
};