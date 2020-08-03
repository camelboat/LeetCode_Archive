#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//// 55.38%, 5.00%
//// BFS (or level-order traversal)
class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> levels;
        queue<pair<Node*, int>> node_queue;
        node_queue.push(make_pair(root, 0));
        while (!node_queue.empty()) {
            pair<Node*, int> node = node_queue.front();
            node_queue.pop();
            if (node.first == nullptr) continue;
            if (levels.size() <= node.second) {
                levels.emplace_back(vector<Node*>{node.first});
            } else {
                levels[node.second].emplace_back(node.first);
            }
            node_queue.push(make_pair(node.first->left, node.second+1));
            node_queue.push(make_pair(node.first->right, node.second+1));
        }
        for (vector<Node*> &level: levels) {
            for (int i = 0; i < level.size()-1; ++i) {
                level[i]->next = level[i+1];
            }
        }
        return root;
    }
};

int main() {
    return 0;
}
