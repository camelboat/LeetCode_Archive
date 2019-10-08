#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

//// this problem is hard
//// refer to https://github.com/grandyang/leetcode/issues/126


//// BFS
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);

        // the path length in current loop
        int level = 1;

        // the current minimum path length
        int minLevel = INT_MAX;

        // set to store the words that have already been used
        unordered_set<string> words;
        while (!paths.empty()) {

            // pop the first path
            auto t = paths.front(); paths.pop();

            // if the size of the path is larger than the path
            // length in the current group, then it means there
            // are words that have already been stored into the
            // words, and it will not be the minimum path
            // we erase all elements in words from the dict(since these
            // elements will not show in the result) and clear words
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }

            // get the last word in the path
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;

                    // if the new word is not in the dict, continue
                    if (!dict.count(newLast)) continue;

                    // else, we insert the new word into the current path
                    words.insert(newLast);

                    // generate a new path whose last element is the new word
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);

                    // if the new word is the end word, add the path to answer
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    }

                        // else, add the path to the queue for the next loop
                    else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};