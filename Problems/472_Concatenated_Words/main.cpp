#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> bas;
        vector<string> answer;

        // sort the words according to their length from shortest to longest
        // so that if a word is concatenated, it will only contain the words before it
        sort(words.begin(), words.end(), [](const string &l, const string &r){return l.size() < r.size();});
        for (auto &word: words)
        {
            if (word.size() == 0) continue;
            if (is_con(words, word, bas)) answer.emplace_back(word);
            bas.insert(word);
        }
        return answer;
    }

    bool is_con(vector<string>& words, string s, set<string> &bas)
    {
        if (bas.find(s) != bas.end()) return true;
        for (int i = 0; i < s.size(); ++i)
        {
            if (bas.find(s.substr(0,i))!= bas.end() && is_con(words, s.substr(i), bas)) return true;
        }
        return false;
    }
};

