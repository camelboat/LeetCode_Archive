#include<iostream>
#include<vector>
#include<priority_queue>

using namespace std;

//// 12.71%, 100.00%
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> bas(sticks.begin(), sticks.end());
        int answer = 0;
        while (bas.size()>1)
        {
            int first = bas.top();
            bas.pop();
            int second = bas.top();
            bas.pop();
            int new_stick = first+second;
            answer+=new_stick;
            bas.push(new_stick);
        }
        return answer;
    }
};
