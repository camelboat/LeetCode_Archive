#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

//// 90.67%, 100.00%
//// count diagonal
class Solution {
private:
    set<pair<int, int>> bas;

public:
    int minAreaRect(vector<vector<int>>& points) {
        for (auto &pt: points) bas.insert(make_pair(pt[0], pt[1]));
        int ans = INT_MAX;
        // for each pair, check if it is a diagonal
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i+1; j < points.size(); ++j)
            {
                int tmp = abs((points[i][0] - points[j][0]) * (points[i][1]-points[j][1]));
                if (tmp != 0 && tmp < ans)
                {
                    // if it is a diagonal, and the potential area less than
                    // the current answer, check if the other diagonal exists
                    if (bas.find(make_pair(points[i][0], points[j][1])) != bas.end()
                        && bas.find(make_pair(points[j][0], points[i][1])) != bas.end())
                    {
                        ans = tmp;
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};