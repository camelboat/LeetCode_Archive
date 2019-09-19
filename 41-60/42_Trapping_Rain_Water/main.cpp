#include <iostream>
#include <vector>

using namespace std;

//// first think about the question, what value do I need to calculate
//// then think about the algorithm

//// think about dp and stack

class Solution {
public:
    int trap(vector<int>& height) {
        // dp, dp_lef[i] is the max wall left to i, dp_rig[i] is the max wall right to i

        if (height.size() < 2) return 0;
        int *dp_lef = new int [height.size()];
        int *dp_rig = new int [height.size()];
        dp_lef[0] = 0;
        dp_rig[height.size()-1] = 0;

        for (int i = 1; i < height.size(); ++i)
        {
            dp_lef[i] = dp_lef[i-1] > height[i-1] ? dp_lef[i-1] : height[i-1];
        }
        for (int i = height.size()-2; i > 0; --i)
        {
            dp_rig[i] = dp_rig[i+1] > height[i+1] ? dp_rig[i+1] : height[i+1];
        }

        int answer = 0;
        for (int i = 1; i < height.size()-1; ++i)
        {
            if (dp_lef[i] > height[i] && dp_rig[i] > height[i])
            {
                answer+= dp_lef[i] < dp_rig[i] ? (dp_lef[i] - height[i]) : (dp_rig[i] - height[i]);
            }
        }

        return answer;


        // stack
    }
};