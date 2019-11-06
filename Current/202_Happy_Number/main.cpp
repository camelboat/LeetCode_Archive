#include<iostream>
#include<unordered_set>

using namespace std;

//// 100.00%, 15.38%
//// one can initialize the set to as 
//// {4, 16, 37, 58, 89, 145, 42, 20}
//// as it's the only possible cycle
class Solution {
private:
    unordered_set<int> bas;
    
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        if (bas.find(n) != bas.end()) return false;
        bas.insert(n);
        int cur_sum = cal_square_sum(n);
        return isHappy(cur_sum);
    }
    
    int cal_square_sum(int n)
    {
        int dig = 0;
        int ans = 0;
        while (n != 0)
        {
            dig = n % 10;
            ans+=dig * dig;
            n = (n-dig)/10;
        }
        return ans;
    }
};
