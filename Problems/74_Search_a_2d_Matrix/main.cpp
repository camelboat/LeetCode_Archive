#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0) return false;
        int i = search_row(matrix, target);
        cout << "i = " << i << '\n';
        if (i == -1) return false;
        int j = search_col(matrix[i], target);
        if (j == -1) return false;
        return true;
    }

    int search_row(vector<vector<int>>& matrix, int target)
    {
        int top = 0;
        int bottom = matrix.size();
        int m = matrix.size();
        int n = matrix[0].size()-1;
        int i_mid;
        while (top <= bottom && top < m)
        {
            i_mid = (top + bottom)/2;
            // cout << "top = " << top << '\n';
            // cout << "bottom = " << bottom << '\n';
            // cout << "i_mid = " << i_mid << '\n';
            if (target < matrix[i_mid][0])
            {
                bottom = i_mid-1;
            }
            else if (target > matrix[i_mid][n])
            {
                top = i_mid+1;
            }
            else return i_mid;
        }
        return -1;
    }

    int search_col(vector<int> &line, int target)
    {
        int left = 0;
        int right = line.size();
        int j_mid;
        while (left <= right)
        {
            j_mid = (left + right) / 2;
            if (target < line[j_mid])
            {
                right = j_mid-1;
            }
            else if (target > line[j_mid])
            {
                left = j_mid+1;
            }
            else return j_mid;
        }
        return -1;
    }
};