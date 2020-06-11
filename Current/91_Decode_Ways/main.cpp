#include <iostream>
#include <vector>

using namespace std;

//// 100.00%, 62.36%
//// dp
class Solution {
public:
    int numDecodings(string s) {
        int right = s.size()-1;
        vector<int> res = vector<int>(s.size()+1, 0);
        res[0] = 1;
        if (s[0] == '0') res[1] = 0;
        else res[1] = 1;
        for (int i = 2; i <= s.size(); ++i)
        {
            if (s[i-1] == '0') res[i] += 0;
            else res[i] += res[i-1];
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) res[i] += res[i-2];
        }
        return res[right+1];
    }
};

int main()
{
    Solution test;
    string test_string = "17";
    cout << test.numDecodings(test_string) << endl;
    return 0;
}
