#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    // vector<vector<int>> bas;
    vector<int> check; // 0...n-1 for row, n...2n-1 for col, 2n, 2n+1 for diagonal
    int board_size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        check = vector<int>(2*n+2, 0);
        board_size = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = -1+(player%2)*2;
        int tar = board_size*add;
        check[row]+=add;
        if (check[row] == tar) return tar > 0 ? 1 : 2;
        check[board_size+col]+=add;
        if (check[board_size+col] == tar) return tar > 0 ? 1 : 2;
        if (row == col)
        {
            check[2*board_size]+=add;
            if (check[2*board_size] == tar) return tar > 0 ? 1 : 2;
        }
        if (row == -col + board_size-1)
        {
            check[2*board_size+1]+=add;
            if (check[2*board_size+1] == tar) return tar > 0 ? 1 : 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */