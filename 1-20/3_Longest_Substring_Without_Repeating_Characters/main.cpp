#include <unordered_map>
#include <string>
#include <iostream>

static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

typedef std::unordered_map<char,int> stringmap;

using namespace std;

class Solution {
public:
    unsigned int current_length;
    int lengthOfLongestSubstring(string s) {
        unsigned long string_length = s.length();
        current_length = 0;
        unsigned int max_length = 0;
        for (unsigned int loc = 0; loc < string_length; loc++)
        {
            lengthjudge(s, loc);
            max_length = max_length > current_length?max_length:current_length;
            current_length = 0;
        }
        return max_length;
    }

    void lengthjudge(string s, unsigned int loc)
    {
        stringmap current_string;
        char current_char = s[loc];
        unsigned long total_length = s.length();
        while (current_string.find(current_char) == current_string.end()
               && loc < total_length)
        {
            current_length++;
            pair<char, int> current_pair (current_char, 1);
            current_string.insert(current_pair);
            loc++;
            current_char = s[loc];
        }
    }
};