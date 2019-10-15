#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (!digits.compare(""))
        {
            return vector<string>{};
        }

        vector<string> answer;
        vector<vector<string>> base;
        base.emplace_back('0');
        base.emplace_back('1');
        base.emplace_back(vector<string>{"a", "b", "c"});
        base.emplace_back(vector<string>{"d", "e", "f"});
        base.emplace_back(vector<string>{"g", "h", "i"});
        base.emplace_back(vector<string>{"j", "k", "l"});
        base.emplace_back(vector<string>{"m", "n", "o"});
        base.emplace_back(vector<string>{"p", "q", "r", "s"});
        base.emplace_back(vector<string>{"t", "u", "v"});
        base.emplace_back(vector<string>{"w", "x", "y", "z"});

        return lc_helper(digits, base);
    }

    vector<string> lc_helper(string digits, vector<vector<string>> &base)
    {
        if (digits.size() == 1)
        {
            vector<string> answer;
            for (int i = 0; i < base[digits[0]-'0'].size(); ++i)
            {
                answer.emplace_back(base[digits[0]-'0'][i]);
            }
            return answer;
        }
        else
        {
            vector<string> answer;
            vector<string> ans_right = lc_helper(digits.substr(1, digits.size()-1), base);
            for (int i = 0; i < base[digits[0]-'0'].size(); ++i)
            {
                for (int j = 0; j < ans_right.size(); ++j)
                {
                    answer.emplace_back(base[digits[0]-'0'][i] + ans_right[j]);
                }
            }
            return answer;
        }
    }
};