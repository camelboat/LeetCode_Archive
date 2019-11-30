#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//// 100.00%, 75.00%
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; ++i) pourOneWater(heights, K);
        return heights;
    }

    static void pourOneWater(vector<int>& heights, int K)
    {
        int cur = heights[K];
        int left = INT_MAX;
        for (int i = K-1; i >= 0; --i)
        {
            if (cur < heights[i]) break;
            if (heights[i] < cur)
            {
                left = i;
                cur = heights[i];
            }
        }
        if (left < K)
        {
            heights[left]++;
            return;
        }
        cur = heights[K];
        int right = -1;
        for (int i = K+1; i < heights.size(); ++i)
        {
            if (cur < heights[i]) break;
            if (heights[i] < cur)
            {
                right = i;
                cur = heights[i];
            }
        }
        if (right > K)
        {
            heights[right]++;
            return;
        }
        heights[K]++;
    }
};