#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

//// backward tracking


//// recursion with referene optimization
/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        combinationSum_helper(candidates, target, 0, answer);
        return answer;
    }

    void combinationSum_helper(vector<int>& candidates, int target, int start, vector<vector<int>> &answer)
    {
        // cout << "target = " << target << '\n';
        if (target == 0)
        {
            vector<int> res;
            answer.emplace_back(res);
            return;
        }
        else if (target > 0)
        {
            for (int i = start; i < candidates.size(); ++i)
            {
                vector<vector<int>> answer_tmp;
                combinationSum_helper(candidates, target - candidates[i], i, answer_tmp);
                for (int j = 0; j < answer_tmp.size(); ++j)
                {
                    answer_tmp[j].emplace_back(candidates[i]);
                    answer.emplace_back(answer_tmp[j]);
                }
            }
            return;
        }
        else
        {
            return;
        }
    }
};
 */

//// recursion
/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum_helper(candidates, target, 0);
    }

    vector<vector<int>> combinationSum_helper(vector<int>& candidates, int target, int start)
    {
        // cout << "target = " << target << '\n';
        if (target == 0)
        {
            vector<vector<int>> answer;
            vector<int> res;
            answer.emplace_back(res);
            return answer;
        }
        else if (target > 0)
        {
            vector<vector<int>> answer;
            for (int i = start; i < candidates.size(); ++i)
            {
                vector<vector<int>> answer_tmp = combinationSum_helper(candidates, target - candidates[i], i);
                for (int j = 0; j < answer_tmp.size(); ++j)
                {
                    answer_tmp[j].emplace_back(candidates[i]);
                    answer.emplace_back(answer_tmp[j]);
                }
            }
            return answer;
        }
        else
        {
            vector<vector<int>> answer;
            return answer;
        }
    }
};
 */



//// dp
/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // dp[i] all combinations of numbers in candidates to sum to target
        // dp[i]+= candidate if i=candidate
        // dp[i] = dp[i-candidates] +  candidates

        vector<vector<vector<int>>> dp;
        vector<vector<int>> dp0;
        dp.emplace_back(dp0);
        for (int i = 1; i <= target; ++i)
        {
            vector<vector<int>> tmp;
            for (int j = 0; j < candidates.size(); ++j)
            {
                if (i == candidates[j])
                {
                    vector<int> single;
                    single.emplace_back(candidates[j]);
                    tmp.emplace_back(single);
                    // cout << "insert " << tmp[0][0] << '\n';
                }
                if (i > candidates[j])
                {
                    int tar_tmp = i-candidates[j];
                    for (int k = 0; k < dp[tar_tmp].size(); ++k)
                    {
                        vector<int> update = dp[tar_tmp][k];
                        update.emplace_back(candidates[j]);
                        tmp.emplace_back(update);
                    }
                }
            }
            dp.emplace_back(tmp);
        }

        // remove the duplicate
        // cout << "answer size is " << dp[target].size() << '\n';
        for (int i = 0; i < dp[target].size(); ++i)
        {
            sort(dp[target][i].begin(), dp[target][i].end());
        }
        vector<vector<int>>::iterator it = unique(dp[target].begin(), dp[target].end());
        dp[target].resize(distance(dp[target].begin(), it));

        unordered_set<string> base;
        vector<int> choice;
        for (int i = 0; i < dp[target].size(); ++i)
        {
            string tmp = "";
            for (int j = 0; j < dp[target][i].size(); ++j)
            {
                tmp+=to_string(dp[target][i][j]);
            }
            // cout << "string is " << tmp << '\n';
            if (base.find(tmp) == base.end())
            {
                base.insert(tmp);
                choice.emplace_back(i);
            }
        }
        // for (const std::string& x: base) std::cout << x << '\n';

        vector<vector<int>> answer;
        for (int i = 0; i < choice.size(); ++i)
        {
            answer.emplace_back(dp[target][choice[i]]);
        }


        // for (int i = 0; i <= target; ++i)
        // {
        //     cout << "target = " << i << '\n';
        //     for (int j = 0; j < dp[i].size(); ++j)
        //     {
        //         for (int k = 0; k < dp[i][j].size(); ++k)
        //         {
        //             cout << dp[i][j][k];
        //         }
        //         cout << '\n';
        //     }
        // }
        // return dp[target];
        return answer;
    }
};
 */