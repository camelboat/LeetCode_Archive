#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int m = matrix.size(); // row number
       vector<int> answer;
       if (m == 0) return answer;
       int n = matrix[0].size(); // col number
       int start_i = 0;
       int start_j = -1;
       int direction = 0; // 0: right, 1: down, 2: left, 3: up
       for (int i = m-1, j = n; i >= 0 && j >= 0; --i, --j)
       {
           if (j != 0) print_row(matrix, start_i, start_j, direction, j, answer);
           if (i != 0) print_col(matrix, start_i, start_j, direction, i, answer);
       }

       return answer;
   }

   void print_row(vector<vector<int>>& matrix, int& start_i, int& start_j, int& direction, int step, vector<int>& answer)
   {
       if (direction == 0)
       {
           int j;
           for (j = 1; j <= step; ++j) answer.emplace_back(matrix[start_i][start_j+j]);
           start_j = start_j+step;
       }
       else if (direction == 2)
       {
           int j;
           for (int j = 1; j <= step; ++j) answer.emplace_back(matrix[start_i][start_j-j]);
           start_j = start_j-step;
       }
       direction = (direction+1)%4;
   }

   void print_col(vector<vector<int>>& matrix, int& start_i, int& start_j, int& direction, int step, vector<int>& answer)
   {
       if (direction == 1)
       {
           int i;
           for (i = 1; i <= step; ++i) answer.emplace_back(matrix[start_i+i][start_j]);
           start_i = start_i+step;
       }
       else if (direction == 3)
       {
           int i;
           for (i = 1; i <= step; ++i) answer.emplace_back(matrix[start_i-i][start_j]);
           start_i = start_i-step;
       }
       direction = (direction+1)%4;
   }
};
