#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp, dp[i][j] the boarder length of the largest square
        // that uses i,j as the right bottom corner
        if (matrix.empty()) return 0;
        int row = matrix.size();
        int len = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(len, 0));
        int answer = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (matrix[i][j] == '0') continue;
                if (i > 0 && j > 0)
                {
                    int min = dp[i-1][j-1];
                    min = min < dp[i-1][j] ? min : dp[i-1][j];
                    min = min < dp[i][j-1] ? min : dp[i][j-1];
                    dp[i][j] = min+1;
                }
                else dp[i][j] = 1;
                answer = answer > dp[i][j] ? answer : dp[i][j];
            }
        }
        return answer * answer;
    }
};