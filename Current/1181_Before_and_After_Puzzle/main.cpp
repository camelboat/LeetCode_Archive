#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//// 90.44%, 100.00%
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        map<string, vector<int>> first_bas; // map<first word, phrase index>
        map<string, vector<int>> last_bas; // map<last word, phrase index>

        for (int p = 0; p < phrases.size(); ++p)
        {
            string phrase = phrases[p];
            string tmp;
            string first_word;
            string last_word;
            vector<string> phrase_list;
            for (int i = 0; i < phrase.size(); ++i)
            {
                while (i < phrase.size() && phrase[i] != ' ')
                {
                    tmp+=phrase[i];
                    ++i;
                }
                phrase_list.emplace_back(tmp);
                tmp = "";
            }
            first_word = phrase_list[0];
            last_word = phrase_list[phrase_list.size()-1];
            if (first_bas.find(first_word) == first_bas.end())
            {
                first_bas[first_word] = vector<int>{p};
            }
            else first_bas[first_word].emplace_back(p);
            if (last_bas.find(last_word) == last_bas.end())
            {
                last_bas[last_word] = vector<int>{p};
            }
            else last_bas[last_word].emplace_back(p);
        }

//         for (auto &str: first_bas)
//         {
//             for (auto &ind: str.second)
//             {
//                 cout << phrases[ind] << '\n';
//                 cout << "first string is " << str.first << '\n';
//             }
//         }

//         for (auto &str: last_bas)
//         {
//             for (auto &ind: str.second)
//             {
//                 cout << phrases[ind] << '\n';
//                 cout << "last string is " << str.first << '\n';
//             }
//         }

        vector<string> answer;
        unordered_set<string> visited;

        for (auto &str: last_bas)
        {
            if (first_bas.find(str.first) != first_bas.end())
            {
                for (auto &last_ind: str.second)
                {
                    for (auto &first_ind: first_bas[str.first])
                    {
                        if (last_ind != first_ind)
                        {
                            string tmp = phrases[last_ind]+phrases[first_ind].substr(str.first.size());
                            if (visited.find(tmp) == visited.end())
                            {
                                visited.insert(tmp);
                                answer.emplace_back(tmp);
                            }
                        }
                    }
                }
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};