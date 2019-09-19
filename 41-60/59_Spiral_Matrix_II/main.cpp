#include <iostream>
#include <vector>

using namespace std;

//// modified from q54_Spiral_Matrix
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer;
        vector<int> tmp(n, 0);
        for (int i = 0; i < n; ++i) answer.emplace_back(tmp);
        int start_i = 0;
        int start_j = -1;
        int direction = 0; // 0: right, 1: down, 2: left, 3: up
        for (int i = n-1, j = n, count = 1; i >= 0 && j >= 0; --i, --j)
        {
            if (j != 0) print_row(answer, start_i, start_j, direction, j, count);
            if (i != 0) print_col(answer, start_i, start_j, direction, i, count);
        }
        return answer;
    }

    void print_row(vector<vector<int>>& matrix, int& start_i, int& start_j, int& direction, int step, int &count)
    {
        if (direction == 0)
        {
            int j;
            for (j = 1; j <= step; ++j) {matrix[start_i][start_j+j] = count; count++; }
            start_j = start_j+step;
        }
        else if (direction == 2)
        {
            int j;
            for (int j = 1; j <= step; ++j) {matrix[start_i][start_j-j] = count; count++; };
            start_j = start_j-step;
        }
        direction = (direction+1)%4;
    }

    void print_col(vector<vector<int>>& matrix, int& start_i, int& start_j, int& direction, int step, int &count)
    {
        if (direction == 1)
        {
            int i;
            for (i = 1; i <= step; ++i) {matrix[start_i+i][start_j] = count; count++; };
            start_i = start_i+step;
        }
        else if (direction == 3)
        {
            int i;
            for (i = 1; i <= step; ++i) {matrix[start_i-i][start_j] = count; count++; };
            start_i = start_i-step;
        }
        direction = (direction+1)%4;
    }
};