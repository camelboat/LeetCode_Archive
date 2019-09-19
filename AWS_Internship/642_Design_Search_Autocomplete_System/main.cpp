#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class AutocompleteSystem {
    string cur; // current typing content
    struct sentence_t
    {
        string sentence;
        int time;
    };
    map<string, int> bas; // all sentences and times
    vector<sentence_t> bas_cur; // current corresponding sentences
    // vector<sentence_t> answer; // corresponding sentences and times

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i)
        {
            bas[sentences[i]] = times[i];
            sentence_t tmp;
            tmp.sentence = sentences[i];
            tmp.time = times[i];
            bas_cur.emplace_back(tmp);
        }
    }

    vector<string> input(char c) {
        vector<string> answer_r;
        // vector<sentence_t> new_answer;
        // answer = new_answer;
        vector<sentence_t> answer;
        if (c == '#')
        {
            bas[cur]++;
            vector<sentence_t> new_bas_cur;
            bas_cur = new_bas_cur;
            for (auto &x: bas)
            {
                sentence_t tmp;
                tmp.sentence = x.first;
                tmp.time = x.second;
                bas_cur.emplace_back(tmp);
            }
            cur = "";
            for (int i = 0; i < 3 && i < answer.size(); ++i)
            {
                answer_r.emplace_back(answer[i].sentence);
            }
            return answer_r;
        }
        else
        {
            cur+=c;
            for (int i = 0; i < bas_cur.size(); ++i)
            {
                string tar_tmp = bas_cur[i].sentence.substr(0, cur.size());
                // put all corresponding answer into answer
                if (!cur.compare(tar_tmp))
                {
                    sentence_t tmp;
                    tmp.sentence = bas_cur[i].sentence;
                    tmp.time = bas_cur[i].time;
                    answer.emplace_back(tmp);
                }
            }
            // sort the answer and return the first three elements
            sort(answer.begin(), answer.end(), compare_hot);

            bas_cur = answer;
            for (int i = 0; i < 3 && i < answer.size(); ++i)
            {
                answer_r.emplace_back(answer[i].sentence);
            }
            return answer_r;
        }
    }

    static bool compare_hot(sentence_t &a, sentence_t &b)
    {
        if (a.time != b.time) return a.time > b.time;
        else
        {
            for (int i = 0; i < min(a.sentence.size(), b.sentence.size()); ++i)
            {
                if (a.sentence[i] != b.sentence[i]) return (int)a.sentence[i] < (int)b.sentence[i];
            }
        }
        return a.sentence.size() < b.sentence.size();
    }

};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */