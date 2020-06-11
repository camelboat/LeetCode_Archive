#include <iostream>
#include <string>

using namespace std;

//// 31.12%, 34.78%
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int min_len = len1 < len2 ? len1 : len2;
        int max_len = len1 > len2 ? len1 : len2;
        string &min_string = len1 <= len2 ? num1 : num2;
        string &max_string = len1 > len2 ? num1 : num2;
        int comp = 0;
        int cur = 0;
        string res;
        for (int i = 0; i < min_len; ++i)
        {
            cur = (min_string[min_len-i-1]-'0') + (max_string[max_len-i-1]-'0') + comp;
            comp = cur / 10;
            cur = cur % 10;
            res = to_string(cur) + res;
        }
        for (int i = max_len - min_len - 1; i >= 0 ; --i)
        {
            cur = (max_string[i]-'0') + comp;
            comp = cur / 10;
            cur = cur % 10;
            res = to_string(cur) + res;
        }
        res = comp == 0 ? res : to_string(comp) + res;
        return res;
    }

};

int main() {
    string a = "12345";
    string b = "123456789";
    Solution test;
    cout << test.addStrings(a, b) << endl;
    return 0;
}
