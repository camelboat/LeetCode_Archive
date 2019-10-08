#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int answer = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    cout << "check at " << i << j << '\n';
                    bool connect = false;
                    bfs(grid, i, j);
                    if (!connect) answer++;
                }
            }
        }
        return answer;
    }

    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '@';
        if (i < m-1 && grid[i+1][j] == '1') bfs(grid, i+1, j);
        if (j < n-1 && grid[i][j+1] == '1') bfs(grid, i, j+1);
        if (i > 0 && grid[i-1][j] == '1') bfs(grid, i-1, j);
        if (j > 0 && grid[i][j-1] =='1') bfs(grid, i, j-1);
    }

    void print_grid(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    }
};