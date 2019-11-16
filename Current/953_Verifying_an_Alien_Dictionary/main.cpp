#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//// 97.22%, 53.85%
class Solution {
private:
    unordered_map<char, int> bas;

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i)
        {
            bas[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i)
        {
            if (!compare_two_words(words[i], words[i+1])) return false;
        }
        return true;
    }

    bool compare_two_words(string a, string b)
    {
        int size_min = a.size() < b.size() ? a.size() : b.size();
        for (int i = 0; i < size_min; ++i)
        {
            if (a[i] != b[i]) return bas[a[i]] < bas[b[i]];
        }
        return a.size() < b.size();
    }
};