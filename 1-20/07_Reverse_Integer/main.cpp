#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
        {
            return 0;
        }
        int negative_flag = x < 0 ? 1 : 0;
        x = x < 0 ? (unsigned)x : x;
        string x_str = to_string(x);
        string answer = "";
        for (int i = x_str.size()-1; i >= 0 ; --i) {
            answer += x_str[i];
        }
        if (answer[0] == '0')
        {
            answer.erase(0,1);
        }
        long answer_num = stol(answer);
        answer_num = negative_flag ? -answer_num : answer_num;
        if (answer_num > 2147483647 || answer_num < -2147483648)
        {
            answer_num = 0;
        }
        return answer_num;
    }
};