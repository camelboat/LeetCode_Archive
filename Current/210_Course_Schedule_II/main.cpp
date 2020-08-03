#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

//// 55.66%, 5.18%
//// Topological sorting, directed graph, good question
//// can optimize buy using white/gray/black to indicate node's status instead of using set
class Solution {
private:
    struct Node {
        int val;
        vector<Node*> next;
        Node(int new_val) : val(new_val), next() {}
        Node() : val(-1), next() {}
    };

    bool is_cycle = false;

    void dfs(Node* node, stack<int>& ans, unordered_set<int>& in_answer, unordered_set<int>& is_visited) {
        if (is_cycle) return;
        is_visited.insert(node->val);
        for (auto& neighbour: node->next) {
            if (in_answer.find(neighbour->val) == in_answer.end() && is_visited.find(neighbour->val) == is_visited.end()) dfs(neighbour, ans, in_answer, is_visited);
            else if (is_visited.find(neighbour->val) != is_visited.end() && in_answer.find(neighbour->val) == in_answer.end()) {
                is_cycle = true;
                return;
            }
        }
        if (in_answer.find(node->val) == in_answer.end()) {
            ans.push(node->val);
            in_answer.insert(node->val);
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, Node*> is_seen;
        for (vector<int>& course_pair: prerequisites) {
            if (is_seen.find(course_pair[0]) == is_seen.end()) {
                is_seen[course_pair[0]] = new Node(course_pair[0]);
            }
            if (is_seen.find(course_pair[1]) == is_seen.end()) {
                is_seen[course_pair[1]] = new Node(course_pair[1]);
            }
            is_seen[course_pair[1]]->next.emplace_back(is_seen[course_pair[0]]);
        }
        stack<int> ans;
        unordered_set<int> in_answer;
        unordered_set<int> is_visited;

        for (int i = 0; i < numCourses; ++i) {
            if (in_answer.find(i) == in_answer.end()) {
                if (is_seen.find(i) != is_seen.end() && is_visited.find(i) == is_visited.end()) dfs(is_seen[i], ans, in_answer, is_visited);
                else {
                    if (in_answer.find(i) == in_answer.end()) {
                        ans.push(i);
                        in_answer.insert(i);
                    }

                }
            }
        }

        if (is_cycle) return vector<int>();

        vector<int> submit;
        while (!ans.empty()) {
            submit.emplace_back(ans.top());
            ans.pop();
        }
        return submit;
    }
};


int main() {
    Solution test;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = test.findOrder(numCourses, prerequisites);
    for (auto& num : ans) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}
