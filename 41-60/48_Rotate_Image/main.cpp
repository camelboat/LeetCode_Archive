#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int rotate = n/2;
        for (int i = 0; i < rotate; ++i)
        {
            for (int j = i; j < n-i-1; ++j)
            {
                swap_four(matrix, i, j, n);
            }
        }
    }

    void swap_four(vector<vector<int>>& matrix, int i, int j , int n)
    {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n-j-1][i];
        matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
        matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
        matrix[j][n-i-1] = tmp;

    }
};