#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> bas(board);
        for (int i = 0; i < bas.size(); ++i)
        {
            for (int j = 0; j < bas[0].size(); ++j)
            {
                int tmp = count_neighbor(bas, i, j);
                if (tmp < 2 || tmp > 3) board[i][j] = 0;
                else if (tmp == 3) board[i][j] = 1;
            }
        }
    }

    int count_neighbor(vector<vector<int>>& bas, int i_ind, int j_ind)
    {
        int row = bas.size();
        int col = bas[0].size();
        int res = 0;
        for (int i = i_ind-1; i <= i_ind+1; ++i)
        {
            for (int j = j_ind-1; j <= j_ind+1; ++j)
            {
                if (i >= 0 && i < row && j >=0 && j < col && (i != i_ind || j != j_ind))
                {
                    res+=bas[i][j];
                }
            }
        }
        return res;
    }
};