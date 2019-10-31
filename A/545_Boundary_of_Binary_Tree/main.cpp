/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 96.81%, 100/00%
// pre-order traverse and logical judge
class Solution {
private:
    vector<int> left_bound;
    vector<int> right_bound;
    vector<int> leaves;
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        pre_traverse(root, 0);
//         cout << "left_bound: ";
//         for (auto &x: left_bound){
//             cout << x << " ";
//         }
//         cout << "\nright_bound: ";
//         for (auto &x: right_bound){
//             cout << x << " ";
//         }
        
//         cout << "\nleaves: ";
//         for (auto &x: leaves){
//             cout << x << " ";
//         }
        left_bound.insert(left_bound.end(), leaves.begin(), leaves.end());
        reverse(right_bound.begin(), right_bound.end());
        left_bound.insert(left_bound.end(), right_bound.begin(), right_bound.end());
        return left_bound;
    }
    
    // flag: 0: root; 1: left bound; 2: right bound; 3: middle 
    void pre_traverse(TreeNode* root, int flag)
    {
        if (root == NULL) return;
        if (flag == 0) left_bound.emplace_back(root->val);
        else if (flag == 1) left_bound.emplace_back(root->val);
        else if (flag == 2) right_bound.emplace_back(root->val);
        else if (root->left == NULL && root->right == NULL) leaves.emplace_back(root->val);
        int left_flag = 0;
        int right_flag = 0;
        if (flag == 0)
        {
            left_flag = 1;
            right_flag = 2;
        }
        else if (flag == 1)
        {
            left_flag = 1;
            right_flag = root->left == NULL ? 1 : 3;
        }
        else if (flag == 2)
        {
            right_flag = 2;
            left_flag = root->right == NULL ? 2 : 3;
        }
        else if (flag == 3)
        {
            left_flag = 3;
            right_flag = 3;
        }
        pre_traverse(root->left, left_flag);
        pre_traverse(root->right, right_flag);
    }
};
