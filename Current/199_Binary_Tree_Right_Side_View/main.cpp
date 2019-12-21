#include <vector>

using namespace std;


///// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//// 100.00%, 100.00%
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        helper(root, 0, answer);
        return answer;
    }

    void helper(TreeNode* root, int level, vector<int> &answer)
    {
        if (root == nullptr) return;
        if (level >= answer.size()) answer.emplace_back(root->val);
        else answer[level] = root->val;
        helper(root->left, level+1, answer);
        helper(root->right, level+1, answer);
    }
};