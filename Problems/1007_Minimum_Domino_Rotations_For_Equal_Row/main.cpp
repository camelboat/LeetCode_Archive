#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int can_1 = A[0];
        int can_2 = B[0];
        int count_1 = 1;
        int count_2 = 1;
        int count_12 = 0;
        int count_22 = 0;
        bool jud_1 = true;
        bool jud_2 = true;
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] != can_1 && B[i] != can_1) jud_1 = false;
            if (A[i] != can_2 && B[i] != can_2) jud_2 = false;
            if (!jud_1 && ! jud_2) return -1;
            if (jud_1) count_1+= A[i] == can_1 ? 1 : 0;
            if (jud_1) count_12+= B[i] == can_1 ? 1 : 0;
            if (jud_2) count_2+= B[i] == can_2 ? 1 : 0;
            if (jud_2) count_22+= A[i] == can_2 ? 1 : 0;
        }
        if (jud_1)
        {
            count_1 = count_1 < A.size()-count_1 ? count_1 : A.size()-count_1;
            count_1 = count_1 < count_12 ? count_1 : count_12;
            count_1 = count_1 < A.size() - count_12 ? count_1 : A.size()-count_12;
        }
        else count_1 = A.size();
        if (jud_2)
        {
            count_2 = count_2 < B.size() - count_2 ? count_2 : B.size()-count_2;
            count_2 = count_2 < count_22 ? count_2 : count_22;
            count_2 = count_2 < B.size() - count_22 ? count_2 : B.size() - count_22;
        }
        else count_2 = A.size();
        return count_1 < count_2 ? count_1 : count_2;
    }
};