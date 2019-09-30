#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//// space optimized
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // use map to store <char, pair<first ind, last ind>>
        unordered_map<char, pair<int, int>> bas;
        for (int i = 0; i < S.size(); ++i)
        {
            if (bas.find(S[i]) == bas.end()) bas[S[i]] = make_pair(i, i);
            else bas[S[i]].second = i;
        }
        vector<int> answer;
        int start = -1;
        int cur = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (i == bas[S[i]].first) cur++;
            if (i == bas[S[i]].second) cur--;
            if (cur == 0)
            {
                answer.emplace_back(i-start);
                start = i;
            }
        }
        return answer;
    }
};





//// original answer
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, pair<int, int>> bas;
        for (int i = 0; i < S.size(); ++i)
        {
            if (bas.find(S[i]) == bas.end()) bas[S[i]] = make_pair(i, i);
            else bas[S[i]].second = i;
        }

        vector<int> answer;
        vector<int> res(S.size(), 0);
        int start = -1;
        for (int i = 0; i < S.size(); ++i)
        {
            if (i != 0) res[i] = res[i-1];
            if (i == bas[S[i]].first) res[i]++;
            if (i == bas[S[i]].second) res[i]--;
            if (res[i] == 0)
            {
                answer.emplace_back(i-start);
                start = i;
            }
        }
        return answer;
    }
};

