#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        if (n == 0)
        {
            answer.emplace_back("");
            return answer;
        }
        if (n == 1)
        {
            answer.emplace_back("()");
            return answer;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                // cout << "i = " << i << '\n';
                int fir = i;
                int bac = n-i-1;
                vector<string> fir_s = generateParenthesis(fir);
                vector<string> bac_s = generateParenthesis(bac);
                // cout << bac_s[0] << n <<'\n';
                for (int k = 0; k < fir_s.size(); ++k)
                {
                    for (int l = 0; l < bac_s.size(); ++l)
                    {
                        // cout << n << 'hi' << '\n';
                        answer.emplace_back('(' + fir_s[k] + ')' + bac_s[l]);
                    }
                }
            }
            return answer;
        }
        return answer;
    }
};