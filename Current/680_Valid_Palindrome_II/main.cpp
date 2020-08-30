#include <iostream>

using namespace std;

//// 80.27%, 66.60%
//// Greedy
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while (s[i] == s[j] && i < j) {
            ++i;
            --j;
        }
        return totalValidPalindrome(s, i+1, j) || totalValidPalindrome(s, i, j-1);
    }

    bool totalValidPalindrome(string& s, int i , int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    Solution test;
    string input_a = "aba";
    string input_b = "yd";
    string input_c = "aettem";
    assert(test.validPalindrome(input_a));
    assert(test.validPalindrome(input_b));
    assert(!test.validPalindrome(input_c));
    return 0;
}
