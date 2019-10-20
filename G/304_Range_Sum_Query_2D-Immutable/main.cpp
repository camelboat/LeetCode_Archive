#include <iostream>
#include <vector>

using namespace std;

//// 99.19%, 100.00%
//// store bas[i+1][j+1] = sumRegion(0,0,i,j)
class NumMatrix {
    vector<vector<int>> bas;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() != 0 && matrix[0].size() != 0)
        {
            bas = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                bas[i+1][j+1] = bas[i][j+1]+bas[i+1][j]-bas[i][j]+matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return bas[row2+1][col2+1]-(bas[row1][col2+1]+bas[row2+1][col1]-bas[row1][col1]);
        // return bas[row2][col2]-(bas[row1-1][col2]+bas[row2][col1-1]-bas[row1-1][col1-1]);
    }
};


//// 43.88%, 8.33%
//// store acc sum for each row
class NumMatrix {
    vector<vector<int>> bas;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i)
        {
            vector<int> tmp;
            tmp.emplace_back(0);
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                tmp.emplace_back(matrix[i][j]+tmp[j]);
            }
            bas.emplace_back(tmp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = 0;
        for (int i = row1; i <= row2; ++i)
        {
            answer+= bas[i][col2+1] - bas[i][col1];
        }
        return answer;
    }
};

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