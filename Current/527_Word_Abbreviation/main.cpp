#include <iostream>
#include <map>
#include <vector>

using namespace std;


//// 27.69%, 21.54%
//// Trie + Group.
class Solution {
private:
    struct TreeNode {
        vector<TreeNode *> children;
        int count;

        TreeNode() : children(vector<TreeNode *>(26, nullptr)), count(0) {}
    };

    void insertTreeNode(TreeNode *root, const string &word) {
        TreeNode *cur = root;
        for (int i = 1; i < word.size(); ++i) {
            char letter = word[i];
            cur->count++;
            if (cur->children[letter - 'a'] == nullptr) {
                cur->children[letter - 'a'] = new TreeNode();
            }
            cur = cur->children[letter - 'a'];
        }
    }

public:
    vector<string> wordsAbbreviation(vector<string> &dict) {
        map<pair<string, int>, vector<pair<string, int>>> my_map; // <<"first_letter"+"final_letter", length>,<word, index>>
        for (int i = 0; i < dict.size(); ++i) {
            my_map[{dict[i].substr(0, 1) + dict[i].substr(dict[i].size() - 1), dict[i].size()}].push_back({dict[i], i});
        }
        vector<string> ans(dict.size());

        for (auto &length_words: my_map) {
            TreeNode *trie = new TreeNode();
            for (auto &word_ind: length_words.second) {
                insertTreeNode(trie, word_ind.first);
            }
            for (auto &word_ind: length_words.second) {
                TreeNode *cur = trie;
                string &word = word_ind.first;
                int i = 1;
                for (; i < word.size(); ++i) {
                    if (cur->count == 1) break;
                    cur = cur->children[word[i] - 'a'];
                }
                if (word.size() - i > 2 && word.size() > 3) {
                    ans[word_ind.second] = word.substr(0, i) + to_string(word.size() - i - 1) + word[word.size() - 1];
                } else {
                    ans[word_ind.second] = word;
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution test;
    vector<string> dict{"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
    vector<string> ans = test.wordsAbbreviation(dict);
    for (auto &word: ans) {
        cout << word << " ";
    }
    cout << '\n';
    return 0;
}
