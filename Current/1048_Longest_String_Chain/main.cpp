#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//// 80.65%, 100.00%
//// sort words by length in map
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int answer = 1;
        map<int, map<string, int>> bas;
        for (auto &word: words)
        {
            bas[word.size()][word] = 1;
        }
        for (auto &x: bas)
        {
            for (auto &word: x.second)
            {
                if (bas.find(x.first) != bas.end())
                {
                    for (auto &longerword: bas[x.first+1])
                    {
                        if (aisbpred(word.first, longerword.first))
                        {
                            longerword.second = longerword.second > word.second+1 ? longerword.second : word.second + 1;
                            answer = answer > longerword.second ? answer : longerword.second;
                        }
                    }
                }
            }
        }
        return answer;
    }

    static bool aisbpred(string a, string b)
    {
        if (a.size() != b.size()-1) return false;
        int diffnum = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (diffnum == 0)
            {
                if (a[i] != b[i])
                {
                    diffnum++;
                    --i;
                }
            }
            else if (diffnum == 1)
            {
                if (a[i] != b[i+1]){
                    return false;
                }
            }
        }
        return true;
    }

};