#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


//// reference https://leetcode.com/problems/text-justification/discuss/376992/C%2B%2B-Runtime-faster-than-100.00-Memory-less-than-100
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        queue<string> q;
        int currWidth = 0;

        for (int i = 0; i < words.size(); ++i)
        {
            if (currWidth+words[i].size() > maxWidth)
            {
                currWidth--;
                int spaces = (maxWidth-currWidth)+(q.size()-1);
                int spacesInBetween = 0;
                int remainder = 0;
                if (q.size()-1 != 0)
                {
                    spacesInBetween = (spaces/(q.size()-1));
                    remainder = spaces%(q.size()-1);
                }

                string lastWord = q.back();
                string Sres = "";

                while (!q.empty())
                {
                    string curr = q.front();
                    q.pop();
                    if (q.size() == 0 && curr == lastWord)
                    {
                        Sres += lastWord;

                        if (spacesInBetween == 0) Sres += string(maxWidth-lastWord.size(), ' ');
                        break;
                    }

                    if (remainder > 0)
                    {
                        Sres += curr + string(spacesInBetween + 1, ' ');
                        remainder--;
                    }
                    else Sres += curr + string(spacesInBetween, ' ');
                }

                answer.emplace_back(Sres);
                currWidth = 0;
                remainder = 0;
            }
            currWidth += words[i].size()+1;
            q.push(words[i]);
        }

        string lastLine = "";
        while (!q.empty())
        {
            lastLine += q.front()+' ';
            q.pop();
        }

        if (lastLine.size() < maxWidth)
        {
            lastLine += string(maxWidth-lastLine.size(), ' ');
        }
        else if (lastLine.size() > maxWidth)
        {
            lastLine.pop_back();
        }
        answer.emplace_back(lastLine);

        return answer;
    }
};