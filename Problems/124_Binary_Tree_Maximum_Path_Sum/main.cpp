#include <iostream>
#include <climits>

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
class Solution {
private:
    // priority_queue<int> bas;
    int max; // max has nothing to do with the node
public:
    int maxPathSum(TreeNode* root) {
        max = INT_MIN;
        maxPathSum_helper(root);
        return max;
    }

    //// return the value of max path passing through root
    int maxPathSum_helper(TreeNode* root)
    {
        int left_val = 0;
        int right_val = 0;
        int val = root->val;
        if (root->left != NULL)
        {
            int tmp = maxPathSum_helper(root->left);
            left_val = tmp > 0 ? tmp : 0;
        }
        if (root->right != NULL)
        {
            int tmp = maxPathSum_helper(root->right);
            right_val = tmp > 0 ? tmp : 0;
        }

        //// update the max value if now the path should change its start node
        //// so that now root is the highest node of the path we want
        max = max > val + left_val + right_val ? max : val + left_val + right_val;
        return left_val > right_val ? val + left_val : val + right_val;
    }
};