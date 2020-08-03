#include <iostream>
#include <algorithm>

using namespace std;

//// 100.00%, 100.00%
//// Switch bulb from left to right one by one, it's that easy.
class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        int state = 0;
        for (auto &c : target) {
            if (c-'0' != state) {
                res++;
                state = 1 - state;
            }
        }
        return res;
    }
};

int main() {
    Solution test;
    string target = "10111";
    cout << test.minFlips(target);
    return 0;
}
