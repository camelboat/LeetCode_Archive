#include <iostream>
#include <string>
#include <vector>

using namespace std;

//// Brute force (Time Limited Exceeded)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {    
        for (int i = wordDict.size()-1; i >= 0; --i)
        {
            if (!s.compare(wordDict[i])) return true;
            
            if (!s.substr(0, wordDict[i].size()).compare(wordDict[i]))
            {
                if (wordBreak(s.substr(wordDict[i].size()), wordDict)) return true;
            }
        }
        return false;
    }
};


 //// BFS
 class Solution {
 public:
     bool wordBreak(string s, vector<string>& wordDict) {
         set<string> bas;
         for (int i = 0; i < wordDict.size(); ++i) bas.emplace(wordDict[i]);
         queue<int> search;
         vector<int> visit(s.size(), 0);
         search.emplace(0);
         while (!search.empty())
         {
             int start = search.front();
             search.pop();
             if (visit[start] == 0)
             {
                 for (int end = start + 1; end <= s.size(); end++)
                 {
                     if (bas.find(s.substr(start, end-start)) != bas.end())
                     {
                         search.emplace(end);
                         if (end == s.size()) return true;
                     }
                 }
                 visit[start] = 1;
             }
         }
         return false;
     }
 };
