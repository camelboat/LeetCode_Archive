#include <iostream>

class Solution {
public:
    static bool sort_compare(vector<int> a, vector<int> b) {return a[0] < b[0];}
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return intervals;
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(), Solution::sort_compare);
        answer.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            int n = answer.size()-1;
            if (answer[n][1] < intervals[i][0]) answer.emplace_back(intervals[i]);
            else if (intervals[i][1] > answer[n][1]) answer[n][1] = intervals[i][1];
        }
        return answer;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return intervals;
        vector<vector<int>> answer;
        answer.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            judge_merge(answer, intervals[i]);
        }
        int n = answer.size();
        for (int i = 1; i < n; ++i)
        {
            judge_merge(answer, answer[i]);
        }
        for (int i = 1; i < answer.size(); ++i)
        {
            judge_merge(answer, answer[i]);
        }
        std::vector<vector<int>>::iterator it;
        it = std::unique (answer.begin(), answer.end());
        answer.resize( std::distance(answer.begin(),it) );
        return answer;
    }

    void judge_merge(vector<vector<int>>& answer, vector<int>& tar)
    {
        int merge_flag = false;
        for (int i = 0; i < answer.size(); ++i)
        {
            if (((answer[i][0] - tar[1])*(answer[i][1]-tar[0]) <= 0) ||
                (answer[i][0] < tar[0] && answer[i][1] > tar[1]) ||
                (answer[i][0] > tar[0] && answer[i][1] < tar[1]))
            {
                merge(answer, tar, i);
                merge_flag = true;
            }
        }
        if (!merge_flag) answer.emplace_back(tar);
    }

    void merge(vector<vector<int>>& answer, vector<int>& tar, int index)
    {
        int min = answer[index][0] < tar[0] ? answer[index][0] : tar[0];
        int max = answer[index][1] > tar[1] ? answer[index][1] : tar[1];
        answer[index][0] = min;
        answer[index][1] = max;
    }
};
