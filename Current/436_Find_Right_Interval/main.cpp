#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> starts;
    int findRightInterval_helper(int end) {
        int left = 0;
        int right = starts.size();
        if (end > starts[starts.size()-1][0]) return -1;
        while(left < right) {
            int mid = (left+right) / 2;
            if (end < starts[mid][0]) right = mid;
            else if (end > starts[mid][0]) left = mid+1;
            else return starts[mid][1];
        }
        return starts[right][1];
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // store <start point, index> in a vector and sort it
        for (int i = 0; i < intervals.size(); ++i) {
            starts.push_back(vector<int>{intervals[i][0],i});
        }
        sort(starts.begin(), starts.end());
        // for each interval, compare end point to the start point

        // for (auto &start: starts){
        //     cout << start[0] << " " << start[1] << '\n';
        // }

        vector<int> ans;
        for (auto &interval: intervals) {
            ans.push_back(findRightInterval_helper(interval[1]));
        }
        return ans;
    }
};


int main() {
    Solution test;
    vector<vector<int>> input = {{1,4},{2,3},{3,4}};
    vector<int> ans = test.findRightInterval(input);
    vector<int> expected_answer{-1,2,-1};
    assert(ans == expected_answer);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
