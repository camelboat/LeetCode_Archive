#include <iostream>

using namespace std;

//// 36.91%, 47.62%
//// Tricky math thinking
class Solution {
public:
    bool canTransform(string start, string end) {
        int i, j ;
        for (i = 0, j = 0; i < start.size() && j < end.size(); ++i, ++j) {
            while (start[i] == 'X' && i < start.size()) ++i;
            while (end[j] == 'X' && j < end.size()) ++j;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j ) return false;

        }
        while (i < start.size()) {
            if (start[i] != 'X') return false;
            ++i;
        }
        while (j < end.size()) {
            if (end[j] != 'X') return false;
            ++j;
        }
        return true;
    }
};




int main() {
    Solution test;
    cout << test.canTransform("RXXLRXRXL", "XRLXXRRLX") << '\n';
    return 0;
}
