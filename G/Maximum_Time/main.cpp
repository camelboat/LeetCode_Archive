#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string maximum_time(string s) {
        string answer;
        answer+= s[0]=='?' ? (s[1] > '3' && s[1] != '?' ? '1' : '2') : s[0];
        answer+= s[1]=='?' ? (answer[0] == '2' ? '3' : '9') : s[1];
        answer+=":";
        answer+= s[3]=='?' ? '5' : s[3];
        answer+= s[4]=='?' ? '9' : s[4];
        return answer;
    }
};

int main()
{
    Solution test;
    cout << test.maximum_time("?4:59") << '\n';
    cout << test.maximum_time("23:5?") << '\n';
    cout << test.maximum_time("2?:22") << '\n';
    cout << test.maximum_time("0?:??") << '\n';
    cout << test.maximum_time("??:??") << '\n';
    return 0;
}

