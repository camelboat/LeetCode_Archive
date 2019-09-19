#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = height.size();
        int left = 0;
        int right = m-1;
        int answer = (m-1) * min(height[left], height[right]);
        while (left < right)
        {
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            answer = max(answer, (right-left) * min(height[left], height[right]));
        }
        return answer;
    }
};