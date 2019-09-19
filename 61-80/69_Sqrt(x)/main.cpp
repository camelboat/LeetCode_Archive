#include <iostream>

//// binary search
class Solution {
public:
    int mySqrt(int x) {
        unsigned long lef = 0;
        unsigned long rig = x;
        unsigned long tmp = 0;
        unsigned long mid;
        while (rig >= lef)
        {
            mid = (lef + rig) / 2;
            if (mid * mid > x)
            {
                rig = mid-1;
            }
            else if (mid * mid < x)
            {
                tmp = mid;
                lef = mid + 1;
            }
            else return mid;
        }
        return tmp;
    }
};

//// simplest way
class Solution {
public:
    int mySqrt(int x) {
        unsigned long answer;
        for (answer = 0; answer * answer < x; ++answer) {}
        if (answer * answer == x) return answer;
        return answer-1;
    }
};