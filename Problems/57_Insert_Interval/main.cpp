#include <iostream>
#include <vector>

using namespace std;

//// sort intervals and compare to the last element of answer
class Solution {
public:
    static bool sort_compare(vector<int> a, vector<int> b) {return a[0] < b[0];}

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return intervals;
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(), sort_compare);
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

//// don't know why this is much faster than mine, they look very similar
class Solution {
public:
    static bool compinterval(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;

        sort(intervals.begin(),  intervals.end(), Solution :: compinterval);

        for(int i=intervals.size()-1; i>0; i--){
            if(intervals[i][0] <= intervals[i-1][1])
                intervals[i-1] = {min(intervals[i][0],intervals[i-1][0]), intervals[i][1]};
            else res.push_back(move(intervals[i]));

        }
        res.push_back(move(intervals[0]));
        return res;
    }
};
