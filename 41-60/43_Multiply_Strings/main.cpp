#include <iostream>
#include <string>

using namespace std;

//// vertical addition
class Solution {
public:
    string multiply(string num1, string num2) {
        if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0')) return "0";
        int max_size = num1.size()+num2.size();
        int *bas = new int [max_size] {};
        bas[0] = 0;
        for (int i = num1.size()-1; i >= 0; --i)
        {
            for (int j = num2.size()-1; j >= 0; --j)
            {
                int tmp = (num1[i]-'0')*(num2[j]-'0') + bas[i+j+1];
                bas[i+j+1]=tmp%10;
                bas[i+j]+=tmp/10;
            }
        }
        string answer;
        for (int i = max_size-1; i >= 1; --i)
        {
            answer = to_string(bas[i]) + answer;
        }
        bas[0]+=bas[1]/10;
        if (bas[0] != 0) answer = to_string(bas[0]) + answer;
        return answer;
    }
};