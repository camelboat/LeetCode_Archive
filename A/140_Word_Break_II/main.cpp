#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

//// recursion with memorization, modified with official answer
class Solution {
private:
    // use map to contains wordDict
    unordered_map<int, vector<string>> bas;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // dp, dp[i] means the wordDict of s[0:i]
        vector<vector<string>> dp(s.size(), vector<string>());

        set<string> wordset(wordDict.begin(), wordDict.end());

        return word_break(s, wordset, 0);
    }

    vector<string> word_break(string s, set<string>& wordDict, int start)
    {
        if (bas.find(start) != bas.end()) return bas[start];

        vector<string> res;
        if (start == s.size()) res.emplace_back("");

        for (int end = start+1; end <= s.size(); ++end)
        {
            if (wordDict.find(s.substr(start, end-start)) != wordDict.end())
            {
                vector<string> tmp = word_break(s, wordDict, end);
                for (auto x: tmp)
                {
                    res.emplace_back(s.substr(start, end-start) + (x.compare("") ? " " : "") + x);
                }
            }
        }
        bas.insert(make_pair(start, res));
        return res;
    }
};

//// dp, cause time limits exceeded in cases s = "aaaaaaaa...baaaa...."
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // dp, dp[i] means the wordDict of s[0:i]
        vector<vector<string>> dp(s.size(), vector<string>());

        for (int i = 0; i < s.size(); ++i)
        {
            vector<string> tmp;
            for (int j = 0; j < wordDict.size(); ++j)
            {
                int tar = i - wordDict[j].size();
                if (tar == -1 && !wordDict[j].compare(s.substr(0,wordDict[j].size())))
                {
                    tmp.emplace_back(wordDict[j]);
                }
                if (tar >= 0 && !wordDict[j].compare(s.substr(tar+1,wordDict[j].size())))
                {
                    for (auto &x: dp[tar])
                    {
                        string tmp_str = x+" "+wordDict[j];
                        tmp.emplace_back(tmp_str);
                    }
                }
            }
            dp[i] = tmp;
        }
        return dp[dp.size()-1];
    }
};