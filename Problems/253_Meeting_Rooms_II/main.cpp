#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:

    static bool compare_first (vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), compare_first);
        // for (int i = 0; i < intervals.size(); ++i)
        // {
        //     for (int j = 0; j < intervals[0].size(); ++j)
        //     {
        //         cout << intervals[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        priority_queue<int, vector<int>, greater<int>> bas;
        bas.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            int stop = intervals[i][1];
            if (bas.top() > intervals[i][0])
            {
                bas.push(intervals[i][1]);
            }
            else
            {
                bas.pop();
                bas.push(intervals[i][1]);
            }
        }
        return bas.size();
    }
};