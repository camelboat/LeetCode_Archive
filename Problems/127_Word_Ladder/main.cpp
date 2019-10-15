#include <iostream>
#include <string>
#include<vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

//// correct BFS, note that in combo_dict, we should store
//// something like <*ot, ["hot", "lot"]>, but not the opposite
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // length of the words
        int len = beginWord.size();

        // visited list
        map<string, bool> visited;
        visited[beginWord] = true;

        // generate a word path list for all
        unordered_map<string, vector<string>> combo_dict;
        for(int i = 0; i < wordList.size(); ++i)
        {
            string cur = wordList[i];
            for (int j = 0; j < len; ++j)
            {
                string tmp = cur.substr(0, j) + "*" + cur.substr(j+1);
                if (combo_dict.find(tmp) == combo_dict.end())
                {
                    vector<string> cur_combo;
                    cur_combo.emplace_back(cur);
                    combo_dict[tmp] = cur_combo;
                }
                else combo_dict[tmp].emplace_back(cur);
            }
        }

        // queue for BSF
        queue<pair<string, int>> bas;
        bas.push(make_pair(beginWord, 1));
        while (!bas.empty())
        {
            pair<string, int> cur = bas.front();
            bas.pop();
            string cur_str = cur.first;
            int cur_level = cur.second;
            for (int j = 0; j < len; ++j)
            {
                string tmp_compare = cur_str.substr(0, j)+"*"+cur_str.substr(j+1);
                for (auto &x: combo_dict[tmp_compare])
                {
                    if (!endWord.compare(x)) return cur_level+1;
                    if (visited.find(x) == visited.end())
                    {
                        visited[x] = true;
                        bas.push(make_pair(x, cur_level+1));
                    }
                }
            }
        }
        return 0;
    }
};


//// slow version, wrong setup of combo_dict
//class Solution {
//public:
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//        // length of the words
//        int len = beginWord.size();
//
//        // visited list
//        map<string, bool> visited;
//        visited[beginWord] = true;
//
//        // generate a word path list for all
//        unordered_map<string, vector<string>> combo_dict;
//        for(int i = 0; i < wordList.size(); ++i)
//        {
//            string cur = wordList[i];
//            vector<string> cur_combo;
//            for (int j = 0; j < len; ++j)
//            {
//                string tmp = cur.substr(0, j) + "*" + cur.substr(j+1);
//                cur_combo.push_back(tmp);
//            }
//            combo_dict[cur] = cur_combo;
//        }
//
//        // queue for BSF
//        queue<pair<string, int>> bas;
//        bas.push(make_pair(beginWord, 1));
//        while (!bas.empty())
//        {
//            pair<string, int> cur = bas.front();
//            bas.pop();
//            string cur_str = cur.first;
//            int cur_level = cur.second;
//            for (int j = 0; j < len; ++j)
//            {
//                string tmp_compare = cur_str.substr(0, j)+"*"+cur_str.substr(j+1);
//                for (auto &x: combo_dict)
//                {
//                    for (int k = 0; k < x.second.size(); ++k)
//                    {
//                        if (!tmp_compare.compare(x.second[k]))
//                        {
//                            if (!endWord.compare(x.first))
//                            {
//                                return cur_level+1;
//                            }
//                            if (visited.find(x.first) == visited.end())
//                            {
//                                visited[x.first] = true;
//                                bas.push(make_pair(x.first, cur_level+1));
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        return 0;
//    }
//};