#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//// 97.53%, 100.00%
//// problem is the sorting function
//// use vector<int> freq_bas to contain f(word) >= i
//// notice that 1 <= queries[i].length, words[i].length <= 10
class Solution {
private:
    int f_implementation(const string &word)
    {
        char min = word[0];
        int res = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (min > word[i])
            {
                min = word[i];
                res = 1;
            }
            else if (min == word[i]) res++;
        }
        return res;
    }

public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer(queries.size(), 0);
        vector<int> freq_bas(11, 0); // freq_bas[i-1] is the frequency of f(word) >= i
        for (auto &word: words) freq_bas[f_implementation(word)-1]++;
        for (int i = 8; i >= 0; --i)
        {
            freq_bas[i] = freq_bas[i+1]+freq_bas[i];
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            int cur = f_implementation(queries[i]);
            answer[i] = freq_bas[cur];
        }
        return answer;
    }
};

//// 37.04%, 100.00%
//// sort words_bas first
class Solution {
private:
    int f_implementation(const string &word)
    {
        unordered_map<char, int> bas;
        char min = word[0];
        bas[min] = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (min > word[i])
            {
                min = word[i];
                bas[min] = 1;
            }
            else if (min == word[i]) bas[min]++;
        }
        return bas[min];
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer(queries.size(), 0);
        vector<int> words_bas(words.size(), 0);
        unordered_map<int, int> freq_bas;
        for (int i = 0; i < words.size(); ++i)
        {
            words_bas[i] = f_implementation(words[i]);
        }
        sort(words_bas.begin(), words_bas.end());
        for (int i = 0; i < queries.size(); ++i)
        {
            int cur = f_implementation(queries[i]);
            for (int j = words.size()-1; j >= 0; --j)
            {
                if (cur < words_bas[j]) answer[i]++;
                else break;
            }
        }
        return answer;
    }
};


//// 18.01%, 100.00%
class Solution {
private:
    int f_implementation(string word)
    {
        unordered_map<char, int> bas;
        char min = word[0];
        bas[min] = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (min > word[i])
            {
                min = word[i];
                bas[min] = 1;
            }
            else if (min == word[i])
            {
                bas[min]++;
            }
        }
        return bas[min];
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer(queries.size(), 0);
        vector<int> words_bas(words.size(), 0);
        for (int i = 0; i < words.size(); ++i)
        {
            words_bas[i] = f_implementation(words[i]);
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            int cur = f_implementation(queries[i]);
            for (int j = 0; j < words.size(); ++j)
            {
                answer[i]+= cur < words_bas[j] ? 1 : 0;
            }
        }
        return answer;
    }
};