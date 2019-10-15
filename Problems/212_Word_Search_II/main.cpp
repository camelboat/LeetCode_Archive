#include <iostream>
#include <vector>

using namespace std;

//// trie
class Solution {
private:
    struct trie_node {
        trie_node *child[26];
        string str;

        trie_node() : str("")
        {
            for (auto &tmp: child) tmp = NULL;
        }
    };

    void insert_trie(trie_node *root, string tar)
    {
        for (auto &cur : tar)
        {
            int i = cur - 'a';
            if (root->child[i] == NULL)
            {
                root->child[i] = new trie_node();
            }
            root = root->child[i];
        }
        root->str = tar;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        // build the trie
        trie_node *root = new trie_node();
        for (auto &cur: words) insert_trie(root, cur);

        // build the visited map
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        vector<string> answer;

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (root->child[board[i][j] - 'a'])
                {
                    search_trie(board, visited, i, j, answer, root->child[board[i][j] - 'a']);
                }
            }
        }
        return answer;
    }

    void search_trie(vector<vector<char>> &board, vector<vector<bool>> &visited,
                     int i, int j, vector<string> &answer, trie_node *root)
    {
        if (!root->str.empty())
        {
            answer.emplace_back(root->str);
            root->str = "";
        }

        visited[i][j] = true;

        // you can create a vector of pairs [<1,0>, <-1,0>, <0,1>, <0,-1>] to simplify
        // the following codes
        if (i < board.size() - 1 && !visited[i + 1][j] && root->child[board[i + 1][j] - 'a'])
        {
            search_trie(board, visited, i + 1, j, answer, root->child[board[i + 1][j] - 'a']);
        }
        if (i > 0 && !visited[i - 1][j] && root->child[board[i - 1][j] - 'a'])
        {
            search_trie(board, visited, i - 1, j, answer, root->child[board[i - 1][j] - 'a']);
        }
        if (j < board[0].size() - 1 && !visited[i][j + 1] && root->child[board[i][j + 1] - 'a'])
        {
            search_trie(board, visited, i, j + 1, answer, root->child[board[i][j + 1] - 'a']);
        }
        if (j > 0 && !visited[i][j - 1] && root->child[board[i][j - 1] - 'a'])
        {
            search_trie(board, visited, i, j - 1, answer, root->child[board[i][j - 1] - 'a']);
        }
        visited[i][j] = false;
    }
};




//// answer modified from problem 79 Word Search
//class Solution {
//public:
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//        vector<string> answer;
//        for (int i = 0; i < words.size(); ++i)
//        {
//            if (exist(board, words[i])) answer.emplace_back(words[i]);
//        }
//        return answer;
//    }
//
//    bool exist(vector<vector<char>>& board, string word) {
//        int m = board.size();
//        int n = board[0].size();
//        for (int i = 0; i < m; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (board[i][j] == word[0])
//                {
//                    if (exist_helper(board, word.substr(1, word.size()-1), i, j)) return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    bool exist_helper(vector<vector<char>>& board, string left_word, int i, int j)
//    {
//        if (left_word.size() == 0) return true;
//        if (i > 0 && board[i-1][j] == left_word[0])
//        {
//            board[i][j] ^= 128; //// !!! transform ascii characters into non-ascii characters
//            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i-1, j))
//            {   board[i][j] ^= 128;
//                return true;
//            };
//            board[i][j] ^= 128; //// transform back
//        }
//        if (j > 0 && board[i][j-1] == left_word[0])
//        {
//            board[i][j] ^= 128;
//            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i, j-1))
//            {
//                board[i][j] ^= 128;
//                return true;
//            }
//            board[i][j] ^= 128;
//        }
//        if (i < board.size()-1 && board[i+1][j] == left_word[0])
//        {
//            board[i][j] ^= 128;
//            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i+1, j))
//            {
//                board[i][j] ^= 128;
//                return true;
//            }
//            board[i][j] ^= 128;
//        }
//        if (j < board[0].size()-1 && board[i][j+1] == left_word[0])
//        {
//            board[i][j] ^= 128;
//            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i, j+1))
//            {
//                board[i][j] ^= 128;
//                return true;
//            }
//            board[i][j] ^= 128;
//        }
//        return false;
//    }
//};





//// slow recursion version
//class Solution {
//public:
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//        vector<string> answer;
//        int row = board.size();
//        int col = board[0].size();
//        vector<vector<bool>> visited;
//        for (int i = 0; i < words.size(); ++i)
//        {
//            initiate_visited(visited, row, col);
//            bool flag = false;
//            for (int k = 0; k < row; ++k)
//            {
//                for (int l = 0; l < col; ++l)
//                {
//                    if (find_singleWord(board, visited, words[i], k, l, 0))
//                    {
//                        answer.emplace_back(words[i]);
//                        flag = true;
//                        break;
//                    }
//                }
//                if (flag) break;
//            }
//        }
//        return answer;
//    }
//
//    void initiate_visited(vector<vector<bool>> &visited, int i, int j)
//    {
//        for (int k = 0; k < i; ++k)
//        {
//            vector<bool> tmp(j, false);
//            visited.emplace_back(tmp);
//        }
//    }
//
//    bool find_singleWord(vector<vector<char>>& board, vector<vector<bool>> visited, string word,
//                        int i, int j, int index)
//    {
//        if (board[i][j] == word[index] && visited[i][j] == false)
//        {
//            visited[i][j] = true;
//            if (index == word.size()-1) return true;
//            if (i < board.size()-1)
//            {
//                if (find_singleWord(board, visited, word, i+1, j, index+1))
//                {
//                    return true;
//                }
//            }
//            if (i > 0)
//            {
//                if (find_singleWord(board, visited, word, i-1, j, index+1))
//                {
//                    return true;
//                }
//            }
//            if (j < board[0].size()-1)
//            {
//                if (find_singleWord(board, visited, word, i, j+1, index+1))
//                {
//                    return true;
//                }
//            }
//            if (j > 0)
//            {
//                if (find_singleWord(board, visited, word, i, j-1, index+1))
//                {
//                    return true;
//                }
//            }
//            visited[i][j] = false;
//        }
//        return false;
//    }
//};