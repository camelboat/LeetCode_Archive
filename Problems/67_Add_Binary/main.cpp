#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        int len = len_a < len_b ? len_a : len_b;
        int parity = 0;
        string answer = "";
        for (int i = 0; i < len; ++i)
        {
            int tmp = (a[len_a-i-1]-'0') + (b[len_b-i-1]-'0') + parity;
            answer = to_string(tmp % 2)+answer;
            parity = tmp >= 2 ? 1 : 0;
        }
        if (len == len_a && len != len_b)
        {
            for (int i = 0; i < len_b-len_a; ++i)
            {
                int tmp = b[len_b-len_a-1-i]-'0' + parity;
                answer = to_string(tmp % 2)+answer;
                parity = tmp >= 2 ? 1 : 0;
            }
        }
        else if (len == len_b && len != len_a)
        {
            cout << "ha\n";
            for (int i = 0; i < len_a-len_b; ++i)
            {
                int tmp = a[len_a-len_b-1-i]-'0' + parity;
                answer = to_string(tmp % 2)+answer;
                parity = tmp >= 2 ? 1 : 0;
            }
        }
        if (parity == 1) answer = '1'+answer;
        return answer;
    }
};