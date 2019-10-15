#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//// 100.00%, 20.00%
class Solution {
private:
    vector<vector<string>> bas;
    void readdata(string &S)
    {
        int ind = 0;
        while (ind < S.size())
        {
            if (S[ind] == '{')
            {
                string tmp;
                vector<string> tmp_line;
                ind++;
                while (S[ind] != '}')
                {
                    if (S[ind] != ',') tmp+=S[ind];
                    else
                    {
                        tmp_line.emplace_back(tmp);
                        tmp = "";
                    }
                    ind++;
                }
                tmp_line.emplace_back(tmp);
                bas.emplace_back(tmp_line);
                ind++;
            }
            else
            {
                string tmp;
                vector<string> tmp_line;
                while (S[ind] != '{' && ind < S.size())
                {
                    tmp+=S[ind];
                    ind++;
                }
                tmp_line.emplace_back(tmp);
                bas.emplace_back(tmp_line);
            }
        }
    }

public:
    vector<string> expand(string S) {
        readdata(S);
        vector<vector<string>> answer(bas.size(), vector<string>());
        answer[0] = bas[0];
        for (int i = 1; i < bas.size(); ++i)
        {
            for (auto &x: answer[i-1])
            {
                for (auto &y: bas[i])
                {
                    answer[i].emplace_back(x+y);
                }
            }
        }
        sort(answer[answer.size()-1].begin(), answer[answer.size()-1].end());
        return answer[answer.size()-1];
    }
};