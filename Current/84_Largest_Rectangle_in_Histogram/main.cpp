#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//// stack solution, refer to LeetCode official solution, good question
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> bas;
        bas.push(-1);
        int answer = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (bas.top() != -1 && heights[bas.top()] >= heights[i])
            {
                int top_tmp = bas.top();
                bas.pop();
                int tmp = heights[top_tmp] * (i-bas.top()-1);
                answer = answer > tmp ? answer : tmp;
            }
            bas.push(i);
        }
        while (bas.top() != -1)
        {
            int top_tmp = bas.top();
            bas.pop();
            int tmp = heights[top_tmp]*(heights.size()-bas.top()-1);
            answer = answer > tmp ? answer : tmp;
        }
        return answer;
    }
};