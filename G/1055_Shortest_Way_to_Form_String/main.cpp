#include<vector>

using namespace std;

class Solution {
private:
    vector<int> bas;
public:
    int shortestWay(string source, string target) {
        int answer = 0;
        bas = vector<int>(26, 0);
        for (auto &x: source) bas[x-'a'] = 1;
        for (auto &x: target) if (bas[x-'a'] == 0) return -1;
        for (int i = 0; i < target.size(); )
        {
            if (shortestWay_helper(source, target, i)) answer++;
            else return -1;
        }
        return answer;
    }
    
    bool shortestWay_helper(string &source, string &target, int &start)
    {
        bool flag = false;
        for (auto &x: source)
        {
            if (target[start] == x)
            {
                start++;
                flag = true;
            }
        }
        return flag;
    }
}; 
