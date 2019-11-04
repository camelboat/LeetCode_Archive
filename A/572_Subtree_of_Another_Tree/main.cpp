/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//// 50.05%, 75%
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t != NULL || s != NULL && t == NULL) return false;
        if (s->val == t->val && isSametree(s, t)) return true;
        if (isSubtree(s->left, t)) return true;
        if (isSubtree(s->right, t)) return true;
        return false;
    }
    
    bool isSametree(TreeNode* s, TreeNode* t)
    {
        if (s == NULL && t != NULL || s != NULL && t == NULL) return false;
        if (s == NULL && t == NULL) return true;
        if (s->val != t->val) return false;
        if (!isSametree(s->left, t->left)) return false;
        if (!isSametree(s->right, t->right)) return false;
        return true;
    }
};
