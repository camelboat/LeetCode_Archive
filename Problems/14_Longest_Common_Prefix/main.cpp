#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string answer = LCP(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); ++i)
        {
            answer = LCP(strs[i], answer);
            if (answer == "") break;
        }
        return answer;
    }

    string LCP(string s1, string s2)
    {
        string result = "";
        for (int i = 0; i < min(s1.size(), s2.size()); ++i)
        {
            if (s1[i] == s2[i]) result+=s1[i];
            else return result;
        }
        return result;
    }
};