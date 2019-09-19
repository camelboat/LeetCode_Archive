#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> base(27*9, false);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int tar = board[i][j] - '0';
                if (tar != '.'-'0')
                {
                    // cout << "i " << i << '\n';
                    // cout << "j " << j << '\n';
                    int fir = 9*i+tar-1;
                    if (base[fir]) return false;
                    else base[fir] = true;

                    int sec = 81 + j*9 + tar-1;
                    if (base[sec]) return false;
                    else base[sec] = true;

                    int thi = 162 + ((i/3)*3+j/3)*9+tar-1;
                    if (base[thi]) return false;
                    else base[thi] = true;
                }
            }
        }
        return true;

//         typedef unordered_map<char, int> hashmap;
//         vector<hashmap> base;
//         for (int i = 0; i < 27; ++i)
//         {
//             hashmap tmp;
//             base.emplace_back(tmp);
//         }
//         for (int i = 0; i < 9; ++i)
//         {
//             for (int j = 0; j < 9; ++j)
//             {
//                 // hashmap i (row)
//                 // hashmap 9+j (column)
//                 // hashmap 18+(i/3)*3+j/3 (grid)
//                 if (board[i][j] != '.')
//                 {
//                     if (base[i].find(board[i][j])!=base[i].end()) return false;
//                     else base[i][board[i][j]]++;

//                     int sec = 9+j;
//                     if (base[sec].find(board[i][j])!=base[sec].end()) return false;
//                     else
//                     {
//                         base[sec][board[i][j]]++;
//                     }

//                     int thi = 18+(i/3)*3+(j/3);
//                     if (base[thi].find(board[i][j])!=base[thi].end()) return false;
//                     else base[thi][board[i][j]]++;
//                 }
//             }
//         }
//         return true;
    }
};


// for (int k = 0; k < 27; ++k)
// {
//     cout << "group " << k << '\n';
//     for (auto& x: base[k]) std::cout << " " << x.first << ":" << x.second << '\n';
// }