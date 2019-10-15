#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp;
        dp.push_back("1");
        for (int i = 1; i < n; ++i)
        {
            dp.push_back(helper(dp[i-1]));
        }
        return dp[dp.size()-1];
    }

    string helper(string &bac)
    {
        string nex = "";
        int pt = 0;
        while (pt < bac.size())
        {
            // cout << "here\n";
            char tar = bac[pt];
            int count = 1;
            while (pt < bac.size() && bac[pt] == tar)
            {
                ++count;
                ++pt;
            }
            count--;
            nex += to_string(count);
            nex += tar;
        }
        return nex;
    }
};