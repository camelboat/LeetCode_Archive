#include<iostream>
#include<string>

using namespace std;

//// 70.49%, 58.62%
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
        int size = answer.size();
        for (int i = 0; i <= (int)answer.size() / 2 - 1; ++i)
        {
            int tar = size-i-1;
            answer[i] ^= answer[tar];
            answer[tar] ^= answer[i];
            answer[i] ^= answer[tar];
        }
        return answer;
    }
};



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

