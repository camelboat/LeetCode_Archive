#include <iostream>
#include <stack>
#include <unordered_set>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//// 9.70%, 7.80%
//// Store parents (bad solution)
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        map < TreeNode * , TreeNode * > parent_dict;
        findPath(root, p, q, parent_dict);
        parent_dict[root] = nullptr;
        unordered_set < TreeNode * > p_parents;
        while (p) {
            p_parents.insert(p);
            p = parent_dict[p];
        }
        while (p_parents.find(q) == p_parents.end()) {
            q = parent_dict[q];
        }
        return q;

    }

    void findPath(TreeNode *root, TreeNode *p, TreeNode *q, map<TreeNode *, TreeNode *> &parent_dict) {
        stack < TreeNode * > node_stack;
        node_stack.push(root);
        unordered_set < TreeNode * > is_seen;
        while (!node_stack.empty() && (is_seen.find(p) == is_seen.end() || is_seen.find(q) == is_seen.end())) {
            TreeNode *node = node_stack.top();
            node_stack.pop();
            if (node == nullptr) continue;
            if (node == p) is_seen.insert(p);
            if (node == q) is_seen.insert(q);
            parent_dict[node->left] = node;
            parent_dict[node->right] = node;
            node_stack.push(node->left);
            node_stack.push(node->right);
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
