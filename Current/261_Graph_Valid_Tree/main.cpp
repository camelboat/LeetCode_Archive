#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

//// 59.42%, 62.27%
//// Graph+DFS.
class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n - 1) return false;
        if (edges.size() == 0 && n == 1) return true;
        unordered_map<int, vector<int>> graph;
        for (auto &edge: edges) {
            if (graph.find(edge[0]) == graph.end()) {
                graph[edge[0]] = vector<int>{edge[1]};
            } else {
                graph[edge[0]].emplace_back(edge[1]);
            }
            if (graph.find(edge[1]) == graph.end()) {
                graph[edge[1]] = vector<int>{edge[0]};
            } else {
                graph[edge[1]].emplace_back(edge[0]);
            }
        }
        unordered_map<int, int> parents;
        parents[edges[0][0]] = -1;
        stack<int> node_stack;
        node_stack.push(edges[0][0]);
        while (!node_stack.empty()) {
            int cur_node = node_stack.top();
            node_stack.pop();
            for (auto &neighbour: graph[cur_node]) {
                if (neighbour == parents[cur_node]) continue;
                if (parents.find(neighbour) != parents.end()) return false;
                parents[neighbour] = cur_node;
                node_stack.push(neighbour);
            }
        }
        return parents.size() == n;
    }
};


int main() {
    Solution test;
    vector<vector<int>> test_data{{0, 1},
                                  {0, 2},
                                  {0, 3},
                                  {1, 4}};
    cout << test.validTree(5, test_data) << '\n';
    return 0;
}
