#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//// 84.33%, 80.00%
//// two pointer
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int answer = -1;
        for (int i = 0; i < A.size()-1; ++i)
        {
            for (int j = A.size()-1; j > i; --j)
            {
                if (A[i] + A[j] < K && answer < A[i]+A[j]) 
                {
                    answer = A[i]+A[j];
                    break;
                }
            }
        }
        return answer;
    }
};


//// 18.04%, 10.00%
//// unordered_map + naive linear search
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        unordered_map<int, int> bas;
        for (int i = 0; i < A.size(); ++i) bas[A[i]] = i;
        int answer = -1;
        for (int k = 0; k < A.size(); ++k)
        {
            int x = A[k];
            int max_tar = K-x-1;
            for (int i = max_tar; i > 0; --i)
            {
                if (bas.find(i) != bas.end() && bas[i] != k)
                {
                    if (answer < i + x) answer = i+x;
                }
            }
        }
        return answer;
    }
};

