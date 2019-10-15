#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//// 98.43%, 100.00%
class Solution {
private:
    vector<TreeNode*> answer;

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(), to_delete.end());
        unordered_set<int> bas(to_delete.begin(), to_delete.end());
        if (!delNodes_helper(root, bas)) answer.emplace_back(root);
        return answer;
    }

    bool delNodes_helper(TreeNode* root, unordered_set<int>& bas)
    {
        if (root == NULL) return false;
        if (delNodes_helper(root->left, bas)) root->left = NULL;
        if (delNodes_helper(root->right, bas)) root->right = NULL;
        if (bas.find(root->val) != bas.end())
        {
            if (root->left != NULL) answer.emplace_back(root->left);
            if (root->right != NULL) answer.emplace_back(root->right);
            return true;
        }
        return false;
    }

};