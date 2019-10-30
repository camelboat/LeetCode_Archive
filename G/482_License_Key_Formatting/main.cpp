#include<iostream>
#include<string>

using namespace std;

//// 94.04%, 10.34%
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string answer = "";
        int count = 0;
        for (int i = S.size()-1; i>=0;)
        {
            while (count < K && i >= 0)
            {
                if (S[i] == '-') --i;
                else{
                    answer+= (char)toupper(S[i]);
                    ++count;
                    --i;
                }
            }
            if (count == K) answer+='-';
            count = 0;
        }
        answer = answer[answer.size()-1] == '-' ? answer.substr(0, answer.size()-1) : answer;
        string ans = "";
        for (int i = answer.size()-1; i >= 0; --i) ans+=answer[i];
        return ans;
    }
};

