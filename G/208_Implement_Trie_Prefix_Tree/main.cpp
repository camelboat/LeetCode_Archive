#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//// 94.39%, 40.00%
//// dynamic array
class Trie {
private:
    struct TrieNode{
        TrieNode *child[26];
        bool end;
        TrieNode() : end(false) {for (int i = 0; i < 26; ++i) child[i] = NULL;}
    };

    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int ind = word[i]-'a';
            if (cur->child[ind] == NULL)
            {
                cur->child[ind] = new TrieNode();
            }
            cur = cur->child[ind];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int ind = word[i]-'a';
            if (cur->child[ind] == NULL) return false;
                // if (i == word.size()-1 && cur->end == false) return false;
            else cur = cur->child[ind];
        }
        return cur->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int ind = prefix[i]-'a';
            if (cur->child[ind] == NULL) return false;
            else cur = cur->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 *
 */

//// 23.05%, 70.00%
//// unordered_map
class Trie {
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> child;
        bool end;
        TrieNode() : child(unordered_map<char, TrieNode*>()), end(false){}
    };

    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        root->end = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (auto &tmp: word)
        {
            if (cur->child.find(tmp) == cur->child.end())
            {
                cur->child[tmp] = new TrieNode();
            }
            cur = cur->child[tmp];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (auto &tmp: word)
        {
            if (cur->child.find(tmp) == cur->child.end()) return false;
            else cur = cur->child[tmp];
        }
        return cur->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto &tmp: prefix)
        {
            if (cur->child.find(tmp) == cur->child.end()) return false;
            else cur = cur->child[tmp];
        }
        return true;
    }
};

//// 54.90%, 16.67%
//// vector implementation
class Trie {
private:
    struct TrieNode{
        vector<TrieNode*> child;
        bool end;
        TrieNode() : child(vector<TrieNode*>(26, NULL)), end(false){}
    };

    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        root->end = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int ind = word[i]-'a';
            if (cur->child[ind] == NULL)
            {
                cur->child[ind] = new TrieNode();
            }
            cur = cur->child[ind];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int ind = word[i]-'a';
            if (cur->child[ind] == NULL) return false;
            // if (i == word.size()-1 && cur->end == false) return false;
            else cur = cur->child[ind];
        }
        return cur->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int ind = prefix[i]-'a';
            if (cur->child[ind] == NULL) return false;
            else cur = cur->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */