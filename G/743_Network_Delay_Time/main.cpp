#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

//// 13.84%, 20.00%
//// DFS
class Solution {
private:
    unordered_map<int, vector<int>> bas; // stone ind in stones->set of ind of stone with same row or col

public:
    int removeStones(vector<vector<int>>& stones) {

        // save reference based on stones' index
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = i; j < stones.size(); ++j)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    bas[i].emplace_back(j);
                    bas[j].emplace_back(i);
                }
            }
        }
        vector<bool> visited(stones.size(), false);

        // for every stone in stones, if not visited,
        // use it as the start point and find the connected
        // component
        int answer = 0;
        for (int s = 0; s < stones.size(); ++s)
        {
            if (visited[s] == false)
            {
                int num = 1;
                visited[s] = true;
                stack<int> stack_stone;
                stack_stone.push(s);
                while (!stack_stone.empty())
                {
                    int tmp = stack_stone.top();
                    stack_stone.pop();
                    // push all stone in the same row/col into stack
                    // mark them as visited
                    for (auto &n: bas[tmp])
                    {
                        if (!visited[n])
                        {
                            visited[n] = true;
                            stack_stone.push(n);
                            num++;
                        }
                    }
                }
                answer+=num-1;
            }
        }
        return answer;
    }
};