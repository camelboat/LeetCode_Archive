#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int point = 0;
        int answer = 0;
        while (point < s.size()-1)
        {
            char cur = s[point];
            char nex = s[point+1];
            int tmp = charromanToInt(cur);
            int tmp_compare = charromanToInt(nex);
            answer+= tmp>=tmp_compare ? tmp : -tmp;
            point++;
        }
        answer+=charromanToInt(s[s.size()-1]);
        return answer;
    }

    int charromanToInt(char c)
    {
        switch (c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }
};