#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        // unordered_map<char, int> bas;
        vector<int> bas(128,0); //// use vector to store the remains character,
                                          //// use char's ascii value as the index
        for (int i = 0; i < t.size(); ++i) bas[t[i]]++;
        int left = 0;
        int right = 0;
        int answer_left = 0;
        int answer_len = s.size()+1;
        int remains = t.size();
        while (right < s.size())
        {
            if (bas[s[right]] > 0) remains--;
            bas[s[right]]--;
            // cout << s[right] << " = " << bas[s[right]] << '\n';
            ++right;
            while (remains == 0)
            {
                if (right - left < answer_len)
                {
                    answer_len = right - left;
                    answer_left = left;
                }
                if (bas[s[left]] >= 0) remains++;
                bas[s[left]]++;
                ++left;
            }
        }
        if (answer_len == s.size()+1) return "";
        return s.substr(answer_left, answer_len);
    }
};