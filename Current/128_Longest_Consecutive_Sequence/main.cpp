#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> bas;
        for (auto &num: nums) {
            bas.insert(num);
        }
        int ans = 0;
        int cur_num;
        int cur_length;
        for (auto &num: bas) {
            if (bas.find(num-1) == bas.end())
            {
                cur_num = num;
                cur_length = 1;
                while (bas.find(cur_num+1) != bas.end())
                {
                    cur_num++;
                    cur_length++;
                }
                ans = ans >= cur_length ? ans : cur_length;
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> test_nums = {100,4,200,1,3,2};
    int ans = test.longestConsecutive(test_nums);
    cout << "ans = " << ans << '\n';
    return 0;
}
