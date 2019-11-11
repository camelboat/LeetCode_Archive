#include <iostream>

using namespace std;

//// 99.37%, 85.71
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while (left < right)
        {
            while (!isAlphanumeric(s[left])) {
                ++left;
                if (left > right) return true;
            }
            while (!isAlphanumeric(s[right])) --right;
            if (tolower(s[left]) != tolower(s[right])) return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
                   
    bool isAlphanumeric(char tar)
    {
        tar = (char)tolower(tar);
        return (tar <= 'z' && tar >= 'a') || (tar <= '9' && tar >= '0');
    }
};
