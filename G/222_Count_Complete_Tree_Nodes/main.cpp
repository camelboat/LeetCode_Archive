#include <iostream>
#include <cmath>

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

//// 92.25%, 100.00%
//// binary search for last layer
//// binary search for a specific node
class Solution {
private:
    bool check_exist(TreeNode* root, int depth, int ind)
    {
        TreeNode* cur = root;
        int node_tmp = pow(2, depth-1);
        for (int i = 1; i < depth; ++i)
        {
            int dir = ind > node_tmp / 2-1 ? 1 : 0;
            node_tmp = node_tmp / 2;
            ind = ind % node_tmp;
            if (dir == 0) cur = cur->left;
            if (dir == 1) cur = cur->right;
        }
        return cur != NULL;
    }

public:
    int countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            cur=cur->left;
            depth++;
        }

        // binary search the last layer
        int left = 0;
        int right = pow(2, depth-1);
        while (left < right)
        {
            int mid = (left+right) / 2;
            if (check_exist(root, depth, mid)) left = mid+1;
            else right = mid;
        }
        return pow(2, depth-1) + left-1;
    }
};


//// Linear search
 class Solution {
 public:
     int countNodes(TreeNode* root) {
         if (root == NULL) return 0;
         int left = countNodes(root->left);
         int right = countNodes(root->right);
         return left+right+1;
     }
 };