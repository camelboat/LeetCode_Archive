#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
//         vector<bool> base(27*9, false);
//         for (int i = 0; i < 9; ++i)
//         {
//             for (int j = 0; j < 9; ++j)
//             {
//                 int tar = board[i][j] - '0';
//                 if (tar != '.'-'0')
//                 {
//                     // cout << "i " << i << '\n';
//                     // cout << "j " << j << '\n';
//                     int fir = 9*i+tar-1;
//                     if (base[fir]) return false;
//                     base[fir] = true;

//                     int sec = 81 + j*9 + tar-1;
//                     if (base[sec]) return false;
//                     base[sec] = true;

//                     int thi = 162 + ((i/3)*3+j/3)*9+tar-1;
//                     base[thi] = true;
//                 }
//             }
//         }
        solveSudoku_helper(board);
        return;
    }

    bool solveSudoku_helper(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char tar = board[i][j];
                if (tar == '.')
                {
                    // cout << "i = " << i << '\n';
                    // cout << "j = " << j << '\n';
                    char count = '1';
                    while (count <= '9')
                    {
                        // cout << "count = " << count-'0' << '\n';
                        if (!pointJudge(board, i, j, count)) ++count;
                        else
                        {
                            board[i][j] = count;
                            if (solveSudoku_helper(board)) return true;
                            else board[i][j] = '.';
                            ++count;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool pointJudge(vector<vector<char>> &board, int &i, int &j, char &tar)
    {
        // cout << "here\n";
        // judge row
        for (int k = 0; k < 9; ++k)
        {
            if (tar == board[i][k])
            {
                // cout << "not pass at " << i << k << '\n';
                // cout << "1\n";
                // cout << board[i][k] << '\n';
                return false;
            }
        }

        // judge column
        for (int k = 0; k < 9; ++k)
        {
            if (tar == board[k][j])
            {
                // cout << "2\n";
                return false;
            }
        }

        // judge grid
        int grid_i = i/3*3;
        int grid_j = j/3*3;

        for (int k = grid_i; k < grid_i + 3; ++k)
        {
            for (int l = grid_j; l < grid_j + 3; ++l)
            {
                if (tar == board[k][l])
                {
                    // cout << "3\n";
                    return false;
                }
            }
        }
        // cout << tar << " pass test\n";
        return true;
    }
};