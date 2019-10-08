#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // store courses whose prerequisites is vector[i].first
        vector<vector<int>> graph(numCourses, vector<int>());

        // store the number of prerequisites for each course
        map<int, int> in_bas;

        for (auto &cur : prerequisites)
        {
            graph[cur[1]].emplace_back(cur[0]);
            if (in_bas.find(cur[0]) == in_bas.end()) in_bas[cur[0]] = 1;
            else in_bas[cur[0]]++;
        }

        // BFS
        queue<int> bas;

        // push all course whose in node number is 0 to the queue
        for (int i = 0; i < numCourses; ++i)
        {
            if (in_bas.find(i) == in_bas.end()) bas.push(i);
        }

        while (!bas.empty())
        {
            int cur = bas.front();
            bas.pop();

            // for the currement course, minus 1 to the in number
            // for each of courses whose prerequisites is it;
            // if the in number is 0, push it to the queue
            for (auto &x: graph[cur])
            {
                in_bas[x]--;
                if (in_bas[x] == 0) bas.push(x);
                // if push all x to the queue, there will be loop problem
            }
        }

        for (auto &x: in_bas)
        {
            if (x.second != 0) return false;
        }
        return true;
    }
};