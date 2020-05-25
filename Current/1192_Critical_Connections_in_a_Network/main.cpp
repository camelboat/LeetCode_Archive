#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

//// 68.86%, 100%
class Solution {
private:
    // unordered_map<int, unordered_set<int>> bas;
    vector<vector<int>> bas;
    vector<int> visit_index;
    vector<int> lowlink;
    vector<bool> visited;
    vector<vector<int>> res;
    int index;
    void dfs(int node, int parent)
    {
        visited[node] = true;
        visit_index[node] = lowlink[node] = index;
        index++;
        for (auto child: bas[node])
        {
            if (child == parent) continue;
            if (!visited[child])
            {
                dfs(child, node);
                if (lowlink[child] > visit_index[node])
                {
                    res.emplace_back(vector<int>({child, node}));
                }
            }
            lowlink[node] = min(lowlink[node], lowlink[child]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // <node, set_of_connected_nodes>
        visit_index.assign(n, 0);
        lowlink.assign(n, 0);
        visited.assign(n, false);
        index = 0;
        bas.assign(n, vector<int>{});
        for (auto & connection : connections)
        {
            bas[connection[0]].emplace_back(connection[1]);
            bas[connection[1]].emplace_back(connection[0]);
        }
        dfs(0,-1);
        return res;
    }
};

//// 17.23%, 100%
class Solution {
private:
    unordered_map<int, unordered_set<int>> bas; // <node, set_of_connected_nodes>
    vector<int> visit_index;
    vector<int> lowlink;
    vector<bool> visited;
    vector<vector<int>> res;
    int index;
    void dfs(int node, int parent)
    {
        visited[node] = true;
        visit_index[node] = lowlink[node] = index;
        index++;
        for (auto child: bas[node])
        {
            if (child == parent) continue;
            if (!visited[child])
            {
                dfs(child, node);
                if (lowlink[child] > visit_index[node])
                {
                    res.emplace_back(vector<int>({child, node}));
                }
            }
            lowlink[node] = min(lowlink[node], lowlink[child]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visit_index.assign(n, 0);
        lowlink.assign(n, 0);
        visited.assign(n, false);
        index = 0;

        for (auto & connection : connections)
        {
            if (bas.find(connection[0]) == bas.end())
            {
                bas[connection[0]] = unordered_set<int>{connection[1]};
            }
            else bas[connection[0]].insert(connection[1]);
            if (bas.find(connection[1]) == bas.end())
            {
                bas[connection[1]] = unordered_set<int>{connection[0]};
            }
            else bas[connection[1]].insert(connection[0]);
        }
        dfs(0,-1);
        return res;
    }
};

int main() {
    int test_n = 4;
    vector<vector<int>> test_connections{{0,1},{1,2},{2,0},{1,3}};
    Solution test;
    vector<vector<int>> res = test.criticalConnections(test_n, test_connections);
    for (auto & bridge : res)
    {
        cout << bridge[0] << " " << bridge[1] << endl;
    }
    return 0;
}
