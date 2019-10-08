#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector <string> &banned)
    {
        string answer = "";
        int max = 0;

        //// convert each words into lowercase and stores in map
        //// with <word, appear_times>
        unordered_map<string, int> bas;
        int i = 0;
        while (i < paragraph.size())
        {
            string cur = next_word(paragraph, i);
            if (bas.find(cur) == bas.end()) bas[cur] = 1;
            else bas[cur]++;
        }

        for (int i = 0; i < banned.size(); ++i) bas[banned[i]] = 0;

        for (auto &x: bas)
        {
            if (x.second > max)
            {
                answer = x.first;
                max = x.second;
            }
        }
        return answer;
    }

    string next_word(string &paragraph, int &i)
    {
        string answer;
        for (; i < paragraph.size(); ++i)
        {
            char cur_char = paragraph[i];
            if (cur_char != '!' && cur_char != '?' && cur_char != ','
                && cur_char != ';' && cur_char != '.' && cur_char != ' ' && cur_char != '\'')
            {
                if (isupper(cur_char)) cur_char = tolower(cur_char);
                answer += cur_char;
            } else break;
        }
        while (paragraph[i] == '!' || paragraph[i] == '?' || paragraph[i] == ','
               || paragraph[i] == ';' || paragraph[i] == '.' || paragraph[i] == ' ' || paragraph[i] == '\'')
        {
            ++i;
        }
        return answer;
    }
};