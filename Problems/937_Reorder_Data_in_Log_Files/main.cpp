#include <iostream>
#include <string>
#include <vector>

using namespace std;

//// should use new comparator for both letter and digit
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> log_letter;
        vector<string> log_digit;
        for (int i = 0; i < logs.size(); ++i)
        {
            if (log_type(logs[i]) == 2) log_digit.emplace_back(logs[i]);
            else log_letter.emplace_back(logs[i]);
        }

        // sort the log_letter
        sort(log_letter.begin(), log_letter.end(), sort_letter);
        for (int i = 0; i < log_letter.size(); ++i) logs[i] = log_letter[i];
        for (int i = 0; i < log_digit.size(); ++i) logs[i+log_letter.size()] = log_digit[i];
        return logs;
    }

    static bool sort_letter (string &i,string &j)
    {
        int i_start;
        int j_start;
        string id_i = get_id(i, i_start);
        string id_j = get_id(j, j_start);
        if (i.substr(i_start).compare(j.substr(j_start))) return i.substr(i_start) < j.substr(j_start);
        else return id_i < id_j;
    }

    static int log_type(string &log)
    {
        int i = 0;
        while(log[i] != ' ') ++i;
        if (log[i+1]-'0' <= 9 && log[i+1]-'0' >= 0) return 2;
        return 1;
    }

    static string get_id(string &log, int &start)
    {
        string id = "";
        start = 0;
        while (log[start] != ' ') {id+=log[start]; ++start;}
        ++start;
        return id;
    }
};