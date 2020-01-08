#include <iostream>
#include <vector>

using namespace std;

//// 45.55% 93.62%
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // we only need to store the timing value for the task
        // with maximum number of instances
        // sort bas for each round
        vector<int> bas(26, 0);
        for (auto &c: tasks) bas[c-'A']++;
        sort(bas.begin(), bas.end());
        int answer = 0;
        while (bas[25] > 0)
        {
            for (int time_count = 0; time_count <= n; time_count++)
            {
                if (bas[25] == 0) break;
                if (time_count < 26 && bas[25-time_count] > 0)
                {
                    bas[25-time_count]--;
                }
                answer++;
            }
            sort(bas.begin(), bas.end());
        }
        return answer;
    }
};

int main(){
    Solution test;
    vector<char> tasks = {'A', 'A', 'B', 'B'};
    int n = 2;
    int answer = test.leastInterval(tasks, n);
    cout << "total time = " << answer << '\n';
}