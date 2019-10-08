#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

//// DAQ topology sorting
/*
 * 1. compute the in-degree of all nodes
 * 2. enqueue all in-degree 0 nodes into a queue
 * 3. While queue is not empty:
 *  a. Dequeue a node v from the queue and visit it
 *  b. decrement in-degrees of node v's neighbors
 *  c. if any neighbor's in-degree bcomes 0, place it in the queue
 */

//// refer from https://leetcode.com/problems/alien-dictionary/discuss/378324/C%2B%2B-solution-with-Topological-sorting
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // BFS and topological sorting.
        if (words.size() == 0) return "";
        unordered_map<char, int> indegree;
        for (auto& word : words) {
            for (int i = 0; i < word.size(); i++) {
                indegree[word[i]] = 0;  // set to 0.
            }
        }
        // Create graph.
        unordered_map<char, unordered_set<char>> graph;
        for (int i = 0; i < words.size() - 1; i++) {
            string curr = words[i], next = words[i + 1];    // compare adjacent words.
            int len = min(curr.size(), next.size());
            for (int j = 0; j < len; j++) { // loop thru both words.
                if (curr[j] != next[j]) {   // haven't seen letter before.
                    unordered_set<char> set = graph[curr[j]];
                    if (set.find(next[j]) == set.end()) { // check if next letter doesn't already form an edge in graph.
                        graph[curr[j]].insert(next[j]); //  add edge to graph
                        indegree[next[j]]++; // add indegree of next node.
                    }
                    break;  // end loop once the first mismatch has been found. subsequent mismatches don't give us any more clues.
                }
            }
        }
		// Do topological sorting.
        queue<char> queue;
        string result = "";
        for (auto& node : indegree) {
            if (node.second == 0) queue.push(node.first);   // add letters with indegree 0 to queue.
        }
        while (!queue.empty()) {
            char u = queue.front(); queue.pop();
            result += u;
            if (graph[u].size() != 0) { // loop thru its adjacency list.
                for (auto& v : graph[u]) {   // remove all incoming edges to node v.
                    indegree[v]--;
                    if (indegree[v] == 0) queue.push(v);
                }
            }
        }
		// check for a cycle.
        return result.size() == indegree.size() ? result : "";
    }
};


//// my same version
//class Solution {
//public:
//    string alienOrder(vector<string>& words) {
//        if (words.size() == 0) return "";
//        string answer = "";
//        unordered_map<char, int> indegree;
//        for (auto &word: words)
//        {
//            for (auto &letter: word) indegree[letter] = 0;
//        }
//
//        unordered_map<char, unordered_set<char>> bas;
//        for (int i = 1; i < words.size(); ++i)
//        {
//            string cur = words[i-1];
//            for (int j = 0; j < min(words[i].size(), cur.size()); ++j)
//            {
//                // cout << "cur = " << cur << '\n';
//                if (cur[j] != words[i][j])
//                {
//                    unordered_set<char> cur_set = bas[cur[j]];
//                    if (cur_set.find(words[i][j]) == cur_set.end())
//                    {
//                        bas[cur[j]].insert(words[i][j]);
//                        indegree[words[i][j]]++;
//                    }
//                    break;
//                }
//            }
//        }
//
//        // for (auto &x: bas)
//        // {
//        //     cout << x.first << " ";
//        //     for (auto &y: x.second) cout << y << " ";
//        //     cout <<  '\n';
//        // }
//
//
//        queue<char> topo;
//        for (auto &x: indegree)
//        {
//            if (x.second == 0) topo.push(x.first);
//        }
//
//        while (!topo.empty())
//        {
//            char tmp = topo.front();
//            topo.pop();
//            answer+=tmp;
//            if (bas[tmp].size() != 0)
//            {
//                for (auto &y : bas[tmp])
//                {
//                    indegree[y]--;
//                    if (indegree[y] == 0) topo.push(y);
//                }
//            }
//        }
//        return answer.size() == indegree.size() ? answer : "";
//    }
//};

