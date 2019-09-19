#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s == "" || numRows == 1)
        {
            return s;
        }
        vector <string> output;
        int cycle_unit = 2*numRows - 2;
        int iter = (int)(s.size() / cycle_unit);
        int left = s.length() - iter * cycle_unit;
        int parity = 0;

        // split into iter number of arrays
        for (int i = 0; i < iter; ++i) {
            output.emplace_back(s.substr(i*cycle_unit, cycle_unit));
        }
        if (left != 0)
        {
            parity = 1;
            output.emplace_back(s.substr(iter * cycle_unit, left));
            for (int i = 0; i < cycle_unit - left; ++i)
            {
                output[iter] += '@';
            }
        }

        string answer = "";
        for (int j = 0; j < numRows; ++j) {
            if (j == 0 || j == numRows-1)
            {
                for (int i = 0; i < iter+parity; ++i) {
                    // cout << "j" << j << endl;
                    answer += output[i][j];
                    // cout << output[i][j] << endl;
                    // cout << answer << endl;
                }
            }
            else
            {
                for (int i = 0; i < iter+parity; ++i) {
                    answer += output[i][j];
                    answer += output[i][cycle_unit - j];
                }
            }
        }
        answer.erase(remove(answer.begin(), answer.end(), '@'), answer.end());
        return answer;
    }
};