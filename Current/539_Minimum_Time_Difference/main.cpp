#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

//// 98.19%, 80.00%
//// convert into minutes
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> time(n, 0);
        for (int i = 0; i < n; ++i)
        {
            time[i] = timestr2int(timePoints[i]);
        }
        sort(time.begin(), time.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            int tmp = diff(time[i], time[(i+1)%n]);
            ans = ans < tmp ? ans : tmp;
        }
        return ans;
    }

    static int diff(const int &first, const int &second)
    {
        int diff = abs(dec2min(first) - dec2min(second));
        return diff < 1440 - diff ? diff : 1440 - diff;
    }

    static int timestr2int(const string &time)
    {
        int ans = 0;
        ans+=time[4]-'0';
        ans+=(time[3]-'0') * 10;
        ans+=(time[1]-'0') * 100;
        ans+=(time[0]-'0') * 1000;
        return ans;
    }

    static int dec2min(const int &inttime)
    {
        return (inttime / 100) * 60 + inttime % 100;
    }
};