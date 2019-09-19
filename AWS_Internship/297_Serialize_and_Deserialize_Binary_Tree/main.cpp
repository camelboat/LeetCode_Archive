#include <iostream>
#include <string>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialize_helper(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return deserialize_helper(data, i);
    }

    TreeNode* deserialize_helper(string &data, int &i)
    {
        int count = next_element(data, i);
        string first = data.substr(i, count);
        i = i+count+1;
        if (!first.compare("@")) {TreeNode* root = NULL; return root;}
        else
        {
            int first_val = stoi(first);
            TreeNode*root = new TreeNode(first_val);
            root->left = deserialize_helper(data, i);
            root->right = deserialize_helper(data, i);
            return root;
        }
    }

    string serialize_helper(TreeNode* root)
    {
        if (root == NULL) return "@,";
        string answer = to_string(root->val) + ",";
        answer = answer + serialize_helper(root->left) + serialize_helper(root->right);
        return answer;
    }

    int next_element(string &data, int &i)
    {
        int count = i;
        while(data[count] != ',') ++count;
        return count-i;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));