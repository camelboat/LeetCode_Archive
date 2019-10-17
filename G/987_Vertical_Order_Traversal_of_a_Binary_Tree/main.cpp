#include <iostream>
#include <vector>
#include <climits>
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

//// can optimize memory usage by applying map<row, map<col, set>

//// 91.90%, 11.11%
//// store the position
class Solution {
private:
    vector <vector<int>> bas;

    static bool mysort(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] != b[1]) return a[1] < b[1];
        if (a[2] != b[2]) return a[2] < b[2];
        return a[0] < b[0];
    }

public:
    vector <vector<int>> verticalTraversal(TreeNode *root)
    {
        traverse(root, 0, 0);
        sort(bas.begin(), bas.end(), mysort);
        vector <vector<int>> answer;
        int col = INT_MIN;
        vector<int> col_vals;
        for (auto &pos: bas)
        {
            if (col != pos[1])
            {
                col = pos[1];
                if (!col_vals.empty()) answer.emplace_back(col_vals);
                col_vals = vector<int>();
            }
            col_vals.emplace_back(pos[0]);
        }
        answer.emplace_back(col_vals);
        return answer;
    }

    void traverse(TreeNode *root, int row, int col)
    {
        if (root == NULL) return;
        vector<int> tmp(3, 0);
        tmp[0] = root->val;
        tmp[1] = row;
        tmp[2] = col;
        bas.emplace_back(tmp);
        traverse(root->left, row - 1, col + 1);
        traverse(root->right, row + 1, col + 1);
    }
};
