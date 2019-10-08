#include <iostream>
#include <vector>

using namespace std;

//// Search Space Reduction
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int pt_row = matrix.size()-1;
        int pt_col = 0;
        while (pt_row >= 0 && pt_col < matrix[0].size())
        {
            int cur = matrix[pt_row][pt_col];
            if (cur == target) return true;
            if (cur < target) pt_col++;
            if (cur > target) pt_row--;
        }
        return false;
    }
};

//// can use binary search for both row and col at the same time

//// can also use divide-and-conquer
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        return searchMatrix_helper(matrix, 0, 0, matrix[0].size()-1, matrix.size()-1, target);
    }

    bool searchMatrix_helper(vector<vector<int>>& matrix, int left, int top, int right, int bottom, int target)
    {
        if (left > right || top > bottom) return false;
        if (target > matrix[bottom][right] || target < matrix[top][left]) return false;

        int mid = left + (right-left)/2;
        int row = top;
        while (row <= bottom && matrix[row][mid] <= target)
        {
            if (matrix[row][mid] == target) return true;
            row++;
        }

        return (searchMatrix_helper(matrix, left, row, mid-1, bottom, target) ||
                searchMatrix_helper(matrix, mid+1, top, right, row-1, target));
    }
};

//// for each row, use binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int col = matrix[0].size();
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (target >= matrix[i][0] && target <= matrix[i][col-1])
            {
                if (searchRow(matrix[i], target)) return true;
            }
        }
        return false;
    }

    bool searchRow(vector<int>& row, int target)
    {
        int left = 0;
        int right = row.size();
        while (left <= right)
        {
            int mid = (left+right)/2;
            if (row[mid] == target) return true;
            else if (row[mid] > target) right = mid-1;
            else if (row[mid] < target) left = mid+1;
        }
        return false;
    }
};