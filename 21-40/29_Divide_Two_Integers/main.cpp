#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) return INT_MAX;
        long int answer = dividend/divisor; // here you should use multiple minusing
        if (answer > INT_MAX) return INT_MAX;
        if (answer < INT_MIN) return INT_MIN;
        return answer;
    }
};