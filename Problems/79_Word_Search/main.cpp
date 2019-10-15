#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (exist_helper(board, word.substr(1, word.size()-1), i, j)) return true;
                }
            }
        }
        return false;
    }

    bool exist_helper(vector<vector<char>>& board, string left_word, int i, int j)
    {
        if (left_word.size() == 0) return true;
        if (i > 0 && board[i-1][j] == left_word[0])
        {
            board[i][j] ^= 128; //// !!! transform ascii characters into non-ascii characters
            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i-1, j)) return true;
            board[i][j] ^= 128; //// transform back
        }
        if (j > 0 && board[i][j-1] == left_word[0])
        {
            board[i][j] ^= 128;
            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i, j-1)) return true;
            board[i][j] ^= 128;
        }
        if (i < board.size()-1 && board[i+1][j] == left_word[0])
        {
            board[i][j] ^= 128;
            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i+1, j)) return true;
            board[i][j] ^= 128;
        }
        if (j < board[0].size()-1 && board[i][j+1] == left_word[0])
        {
            board[i][j] ^= 128;
            if(exist_helper(board, left_word.substr(1, left_word.size()-1), i, j+1)) return true;
            board[i][j] ^= 128;
        }
        return false;
    }
};