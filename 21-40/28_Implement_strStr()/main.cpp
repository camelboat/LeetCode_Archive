#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        int nes = needle.size();
        for (int i = 0; i <= (haystack.size()-needle.size()); ++i)
        {
            bool com = true;
            for (int j = 0; j < nes; ++j)
            {
                // cout << "here\n";
                if (haystack[j+i] != needle[j]) com = false;
            }
            if (com) return i;
        }
        return -1;
    }

};