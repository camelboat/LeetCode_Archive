#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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


//// recursion version
class Solution {
private:
    int max_level;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (root == NULL) return answer; // map<level, members>
        max_level = -1;
        traverse(root, answer, 0);
        for (int i = 0; i <= max_level; ++i)
        {
            if (i % 2 == 1) reverse(answer[i].begin(), answer[i].end());
        }
        return answer;
    }

    void traverse(TreeNode* root, vector<vector<int>> &bas, int level)
    {
        if (root != NULL)
        {
            if (max_level < level)
            {
                vector<int> tmp;
                tmp.emplace_back(root->val);
                bas.emplace_back(tmp);
                max_level = level;
            }
            else bas[level].emplace_back(root->val);
            traverse(root->left, bas, level+1);
            traverse(root->right, bas, level+1);
        }
    }
};