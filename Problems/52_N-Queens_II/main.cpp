#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board;
        int output = 0;
        int i_start = 0;
        solveNQueens_helper(n, board, i_start, output);
        return output;
    }

    // n: chessboard width, q_num: existing queens number, board_tmp: working chessboard
    bool solveNQueens_helper(int n, vector<string> &board_tmp,
                             int i_start, int &output)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i_start == 0)
            {
                board_tmp = new_puzzle(n);
                // cout << "ho\n";
            }
            if (q_valid(board_tmp, n, i_start, j))
            {
                board_tmp[i_start][j] = 'Q';
                if (i_start == n-1)
                {
                    output++;
                    board_tmp[i_start][j] = '.';
                    return true;
                }
                else
                {
                    solveNQueens_helper(n, board_tmp, i_start+1, output);
                    board_tmp[i_start][j] = '.';
                }
            }
        } return false;
    }

    bool q_valid(vector<string> &board_tmp, int n, int i, int j)
    {
        for (int index = 0; index < n; ++index)
        {
            if (board_tmp[index][j] == 'Q' && index != i) return false;
        }

        // check oblique
        // NW to SE
        // calculate start point
        int i_tmp = i;
        int start = j;
        while (i_tmp != 0 && start != 0) {i_tmp--; start--;}
        for (int index_i = i_tmp; start < n && index_i < n; ++start, ++index_i)
        {
            if (board_tmp[index_i][start] == 'Q') return false;
        }
        // NE to SW
        i_tmp = i;
        start = j;
        while (i_tmp != 0 && start != n-1) {i_tmp--; start++;}
        for (int index_i = i_tmp; start > 0 && index_i < n; --start, ++index_i)
        {
            if (board_tmp[index_i][start] == 'Q') return false;
        }
        return true;
    }

    vector<string> new_puzzle(int n)
    {
        vector<string> puzzle;
        for (int i = 0; i < n; ++i)
        {
            string tmp = "";
            for (int j = 0; j < n; ++j) tmp+=".";
            puzzle.emplace_back(tmp);
        }
        return puzzle;
    }



    void print_board(vector<string> &board_tmp, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << board_tmp[i][j];
            }
            cout << '\n';
        }
    }
};