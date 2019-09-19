#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> zero_row;
        vector<int> zero_col;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zero_row.emplace_back(i);
                    zero_col.emplace_back(j);
                }
            }
        }
        for (int i = 0; i < zero_row.size(); ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                matrix[zero_row[i]][k] = 0;
            }
        }
        for (int j = 0; j < zero_col.size(); ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                matrix[k][zero_col[j]] = 0;
            }
        }
    }
};