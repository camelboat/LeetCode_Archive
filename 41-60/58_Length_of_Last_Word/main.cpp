#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i>=0 && s[i] == ' ') --i;
        if (i == -1) return 0;
        int bac = i+1;
        for (; i >= 0; --i)
        {
            if (s[i] == ' ') return bac-i-1;
        }
        return (s.size() == 0) ? 0 : bac;
    }
};