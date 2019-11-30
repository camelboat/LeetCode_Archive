#include <iostream>
#include <vector>

using namespace std;

//// 91.31%, 80.49%
class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = -1;
        int n = s.size();
        for (int i = 0; i < n/2; ++i)
        {
            right = n-i-1;
            s[i]^=s[right];
            s[right]^=s[i];
            s[i]^=s[right];
        }
    }
};