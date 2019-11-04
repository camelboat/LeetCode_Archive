#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

//// 94.55%, 37.50%
//// BFS
class Solution {
private:
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    int row_num = 0;
    int col_num = 0;
    
    int cal_num(const int &r, const int &c)
    {
        return r * col_num + c;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> rot_bas;
        unordered_map<int, int> depth_bas; // loc, depth
        row_num = grid.size();
        col_num = grid[0].size();
        for (int i = 0; i < row_num; ++i)
        {
            for (int j = 0; j < col_num; ++j)
            {
                if (grid[i][j] == 2)
                {
                    int loc = cal_num(i, j);
                    rot_bas.push(loc); 
                    depth_bas[loc] = 0;
                }
            }
        }
        
        int answer = 0;
        while (!rot_bas.empty())
        {
            int rot_tmp = rot_bas.front();
            rot_bas.pop();
            int lr = rot_tmp / col_num;
            int lc = rot_tmp % col_num;
            for (int k = 0; k < 4; ++k)
            {
                int r = lr + dr[k];
                int c = lc + dc[k];
                if (r >= 0 && r < row_num && c >= 0 && c < col_num && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    int new_loc = cal_num(r, c);
                    rot_bas.push(new_loc);
                    depth_bas[new_loc] = depth_bas[rot_tmp] + 1;
                    answer = depth_bas[new_loc];
                }
            }
        }
        
        for (auto &row: grid)
        {
            for (auto &x: row) if (x == 1) return -1;
        }
        return answer;
    }
};
