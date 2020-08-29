#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i][0] <= B[j][0] && A[i][1] >= B[j][0] && A[i][1] <= B[j][1]) {
                ans.push_back(vector<int>{B[j][0], A[i][1]});
                ++i;
            } else if (B[j][0] <= A[i][0] && B[j][1] >= A[i][0] && B[j][1] <= A[i][1]) {
                ans.push_back(vector<int>{A[i][0], B[j][1]});
                ++j;
            } else if (A[i][0] >= B[j][0] && A[i][1] <= B[j][1]) {
                ans.push_back(vector<int>{A[i]});
                ++i;
            } else if (B[j][0] >= A[i][0] && B[j][1] <= A[i][1]) {
                ans.push_back(vector<int>{B[j]});
                ++j;
            } else if (A[i][0] > B[j][1]) {
                ++j;
            } else if (B[j][0] > A[i][1]) {
                ++i;
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<vector<int>> A{{3,5},{9,20}};
    vector<vector<int>> B{{4,5},{7,10},{11,12},{14,15},{16,20}};
    vector<vector<int>> expected_ans = {{4,5},{9,10},{11,12},{14,15},{16,20}};
    vector<vector<int>> ans = test.intervalIntersection(A, B);
    assert(ans == expected_ans);
    return 0;
}
