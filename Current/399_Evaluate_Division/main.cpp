#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    double
    dfs(vector<string> &querie, map<string, vector<pair<string, double>>> &graph, unordered_set<string> &is_seen) {
        cout << "dfs at querie " << querie[0] << " " << querie[1] << '\n';
        if (querie[0] == querie[1]) {
            cout << "return 1" << '\n';
            return 1;
        }
        is_seen.insert(querie[0]);
        for (auto &neighbour: graph[querie[0]]) {
            vector<string> next_querie{neighbour.first, querie[1]};
            double tmp;
            if (is_seen.find(neighbour.first) == is_seen.end()) {
                cout << "neighbour.second " << neighbour.second << '\n';
                tmp = dfs(next_querie, graph, is_seen);
                if (tmp != -1) {
                    cout << "return " << tmp * neighbour.second << '\n';
                    return tmp * neighbour.second;
                }
            }
        }
        return -1;
    }

public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> equation = equations[i];
            if (graph.find(equation[0]) == graph.end()) {
                graph[equation[0]] = vector<pair<string, double>>{make_pair(equation[1], values[i])};
            } else {
                graph[equation[0]].emplace_back(make_pair(equation[1], values[i]));
            }
            if (graph.find(equation[1]) == graph.end()) {
                graph[equation[1]] = vector<pair<string, double>>{make_pair(equation[0], 1 / values[i])};
            } else {
                graph[equation[1]].emplace_back(make_pair(equation[0], 1 / values[i]));
            }
        }
        vector<double> ans;
        for (auto &querie: queries) {
            if (graph.find(querie[0]) != graph.end() && graph.find(querie[1]) != graph.end()) {
                unordered_set<string> is_seen;
                cout << "at querie " << querie[0] << " " << querie[1] << '\n';
                double tmp = dfs(querie, graph, is_seen);
                cout << "ans = " << tmp << '\n';
                ans.emplace_back(tmp);
            } else ans.emplace_back(-1);
        }
        return ans;
    }
};


int main() {
    Solution test;
    vector<vector<string>> equations{{"x1", "x2"},
                                     {"x2", "x3"},
                                     {"x3", "x4"},
                                     {"x4", "x5"}};
    vector<double> values{3.0, 4.0, 5.0, 6.0};
    vector<vector<string>> queries{{"x1", "x5"},
                                   {"x5", "x2"},
                                   {"x2", "x4"},
                                   {"x2", "x2"},
                                   {"x2", "x9"},
                                   {"x9", "x9"}};
    vector<double> ans = test.calcEquation(equations, values, queries);
    for (auto &num: ans) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
