#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


//// optimized version
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> bas;
        vector<vector<string>> answer;
        for (int i = 0; i < strs.size(); ++i)
        {
            string strs_org = strs[i];
            sort(strs[i].begin(), strs[i].end());
            pair(bas, strs[i], strs_org);
        }

        for (auto& x: bas)
        {
            vector<string> tmp;
            for (int j = 0; j < x.second.size(); ++j)
            {
                tmp.emplace_back(x.second[j]);
            }
            answer.emplace_back(tmp);
        }

        return answer;
    }

    void pair(unordered_map<string, vector<string>>& bas, string &tar, string &org)
    {
        // if (bas.size() == 0) return;
        string tmp;
        if (tar.size() == 0) tmp = "@";
        else tmp = tar;

        bas[tar].emplace_back(org);
    }
};

//// slow version
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> bas;
        vector<vector<string>> answer;
        for (int i = 0; i < strs.size(); ++i)
        {
            string strs_org = strs[i];
            sort(strs[i].begin(), strs[i].end());
            int index = pair(bas, strs[i]);
            if (index != -1)
            {
                answer[index].emplace_back(strs_org);
            }
            else
            {
                string tmp;
                if (strs[i].size() == 0) tmp = "@";
                else tmp = strs[i];
                bas.emplace_back(tmp);
                vector<string> answer_tmp;
                if (strs[i].size() == 0) answer_tmp.emplace_back("");
                else answer_tmp.emplace_back(strs_org);
                answer.emplace_back(answer_tmp);
            }
        }
        return answer;
    }

    int pair(vector<string>& bas, string &tar)
    {
        if (bas.size() == 0) return -1;
        string tmp;
        if (tar.size() == 0) tmp = "@";
        else tmp = tar;

        for (int i = 0; i < bas.size(); ++i)
        {
            if (tmp == bas[i]) return i;
        }
        return -1;
    }
};