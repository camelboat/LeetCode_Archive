#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool compare (const pair<string, int> a, const pair<string, int> b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        else return a.second > b.second;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // map<string, times>
        unordered_map<string, int> index;

        // insert the words into bas
        for (int i = 0; i < words.size(); ++i)
        {
            string cur = words[i];
            if (index.find(cur) == index.end()) index[cur] = 1;
            else index[cur]++;
        }

        // use a vector to get all pairs stored in index map
        vector<pair<string, int>> answer(index.begin(), index.end());

        // sort the vector according to the requirement
        sort(answer.begin(), answer.end(), compare);

        // return the first k element as the answer
        vector<string> ans;
        for (int i = 0; i < k; ++i) ans.emplace_back(answer[i].first);
        return ans;
    }
};


//// redundant method, use two maps
//class Solution {
//private:
//    struct classcomp {
//        bool operator() (const int& lhs, const int& rhs) const
//        {return lhs>rhs;}
//    };
//
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        // map<int, set of strings>
//        map<int, set<string>, classcomp> bas;
//
//        // map<string, times>
//        unordered_map<string, int> index;
//
//        // insert the words into bas
//        for (int i = 0; i < words.size(); ++i)
//        {
//            string cur = words[i];
//            if (index.find(cur) == index.end())
//            {
//                index[cur] = 1;
//                bas[1].insert(cur);
//            }
//            else
//            {
//                bas[index[cur]].erase(cur);
//                index[cur]++;
//                bas[index[cur]].insert(cur);
//            }
//        }
//
//        vector<string> answer;
//        for (auto &x : bas)
//        {
//            // cout << x.first << '\n';
//            for (auto &y : x.second)
//            {
//                // cout << y << '\n';
//                answer.emplace_back(y);
//                --k;
//                if (k == 0) return answer;
//            }
//        }
//        return answer;
//    }
//};