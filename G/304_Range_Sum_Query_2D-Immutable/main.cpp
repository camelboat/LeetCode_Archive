#include <iostream>
#include <vector>

using namespace std;

//// time limit exceeded
class NumMatrix {
    vector<vector<int>> bas;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        bas = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = 0;
        for (int i = row1; i <= row2; ++i)
        {
            for (int j = col1; j <= col2; ++j)
            {
                answer+=bas[i][j];
            }
        }
        return answer;
    }
};