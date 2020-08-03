#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if (res.size() < cur.second) {
                res.emplace_back(vector<int>{cur.first->val});
            } else {
                res[cur.second-1].emplace_back(cur.first->val);
            }
            if (cur.first->left != nullptr) {
                q.push(make_pair(cur.first->left, cur.second+1));
            }
            if (cur.first->right != nullptr) {
                q.push(make_pair(cur.first->right, cur.second+1));
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
