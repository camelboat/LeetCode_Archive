#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
                if (i > start && candidates[i] == candidates[i - 1]) continue;
                vector<vector<int>> answer_tmp;
                combinationSum_helper(candidates, target - candidates[i], i+1, answer_tmp);
                for (int j = 0; j < answer_tmp.size(); ++j)
                {
                    answer_tmp[j].emplace_back(candidates[i]);
                    answer.emplace_back(answer_tmp[j]);
                    // cout << "target = " << target-candidates[i] << '\n';
                    // cout << "insert = " << candidates[i] << '\n';
                }
            }
            return;
        }
        else return;
    }
};