#include <iostream>
#include <vector>

using namespace std;

//// backtracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> tmp;
        combine_helper(n, 1, k, answer, tmp);
        return answer;
    }

    void combine_helper(int n, int start, int k, vector<vector<int>>& answer, vector<int>& tmp)
    {
        if (k == 0)
        {
            answer.emplace_back(tmp);
            return;
        }
        for (int i = start; i <= n-k+1; ++i)
        {
            // cout << "i = " << i << '\n';
            tmp.emplace_back(i);
            combine_helper(n, i+1, k-1, answer, tmp);
            tmp.pop_back();
        }
    }
};

//// slow recursion
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        combine_helper(n, 1, k, answer);
        return answer;
    }

    void combine_helper(int n, int start, int k, vector<vector<int>>& answer)
    {
        if (k == 1)
        {
            for (int i = start; i <= n; ++i)
            {
                // cout << i << '\n';
                vector<int> tmp;
                tmp.emplace_back(i);
                answer.emplace_back(tmp);
            }
        }
        else
        {
            for (int i = start; i <= n-k+1; ++i)
            {
                vector<vector<int>> tmp;
                combine_helper(n, i+1, k-1, tmp);
                for (int j = 0; j < tmp.size(); ++j)
                {
                    tmp[j].emplace_back(i);
                }
                answer.reserve(answer.size() + tmp.size());
                answer.insert(answer.end(), tmp.begin(), tmp.end());
            }
        }
    }
};