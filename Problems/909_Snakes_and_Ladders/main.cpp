#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//// just understand the question!!!
//// read the description carefully!!!

//// dfs
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        //dfs
        queue<int> bas;
        bas.push(1);
        int N = board.size();
        unordered_map<int, int> res;
        res[1] = 0;

        while (!bas.empty())
        {
            int cur = bas.front();
            bas.pop();
            if (cur == N*N) return res[cur];
            for (int i = cur+1; i <= cur+6 && i <= N*N; ++i)
            {
                int i_row = N - (i-1)/N - 1;
                int i_col = (N-i_row-1)%2 == 0 ? (i-1)%N : (N-(i-1)%N-1);
                int i_final  = board[i_row][i_col] != -1 ? board[i_row][i_col] : i;
                if (res.find(i_final) == res.end())
                {
                    res[i_final] = res[cur]+1;
                    bas.push(i_final);
                }
            }
        }
        return -1;
    }
};