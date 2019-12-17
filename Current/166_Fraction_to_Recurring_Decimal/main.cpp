#include <iostream>
#include <unordered_map>

using namespace std;

//// 100.00%, 93.33%
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long int n = numerator;
        long int d = denominator;
        string answer;
        string tmp;
        bool decimal = false;
        unordered_map<long int, int> repeat;

        // first get the part that is before the decimal point
        if ((n > 0 && d < 0) || (n < 0 && d > 0)) answer += "-";
        answer += to_string(abs(n / d));
        n = n % d;
        if (n == 0) return answer;
        answer += ".";

        int count = 0;
        while (n != 0)
        {
            n *= 10;
            cout << "n=" << n << '\n';
            int cur = abs(n / d);
            if (repeat.find(n) != repeat.end())
            {
                int start = repeat[n];
                string non_repeat = tmp.substr(0, start);
                answer += non_repeat + "(" + tmp.substr(start) + ")";
                return answer;
            } else
            {
                repeat[n] = count;
                count++;
                tmp += to_string(cur);
            }
            n = n % d;
        }
        answer += tmp;
        return answer;
    }
};

//// 100.00%, 6.67%
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        long int n = numerator;
        long int d = denominator;
        string answer = "";
        string tmp = "";
        bool decimal = false;
        unordered_map<long int, string> repeat;

        // first get the part that is before the decimal point
        if ((n > 0 && d < 0) || (n < 0 && d > 0)) answer += "-";
        answer += to_string(abs(n / d));
        n = n % d;
        if (n == 0) return answer;
        answer += ".";

        while (n != 0)
        {
            n *= 10;
            cout << "n=" << n << '\n';
            int cur = abs(n / d);
            if (repeat.find(n) != repeat.end())
            {
                string non_repeat = repeat[n];
                answer += non_repeat + "(" + tmp.substr(non_repeat.size()) + ")";
                return answer;
            } else
            {
                repeat[n] = tmp;
                tmp += to_string(cur);
            }
            n = n % d;
        }
        answer += tmp;
        return answer;
    }
};