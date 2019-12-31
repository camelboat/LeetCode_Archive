#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

//// 82.96%, 100.00%
class Solution {
private:
    // content -> vector<file path>
    unordered_map<string, vector<string>> bas;

public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> answer;
        for (auto &path: paths) parsing(path);
        for (auto &x: bas)
        {
            if (x.second.size() > 1) answer.emplace_back(x.second);
        }
        return answer;
    }

    void parsing(string& path)
    {
        // read path
        string tmp = "";
        int cur = 0;
        for (; cur < path.size(); ++cur)
        {
            if (path[cur] == ' ') break;
        }
        string current_path = path.substr(0, cur);
        string file_raw = "";
        for (cur = cur+1; cur < path.size(); ++cur)
        {
            if (path[cur] != ' ') file_raw+=path[cur];
            if (path[cur] == ' ' || cur == path.size()-1)
            {
                string file_name = "";
                string file_content = "";
                int j = 0;
                for (; j < file_raw.size(); ++j)
                {
                    if (file_raw[j] == '(') break;
                }
                file_name = file_raw.substr(0, j);
                file_content = file_raw.substr(j);
                bas[file_content].emplace_back(current_path+"/"+file_name);
                file_raw = "";
            }
        }
    }
};

//// 37.86%, 66.67%
class Solution {
private:
    // content -> vector<file path>
    map<string, vector<string>> bas;

public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> answer;
        for (auto &path: paths) parsing(path);
        for (auto &x: bas)
        {
            if (x.second.size() > 1)
            {
                answer.emplace_back(x.second);
            }
        }
        return answer;
    }

    void parsing(string& path)
    {
        // read path
        vector<string> args;
        string tmp = "";
        for (auto &cur: path)
        {
            if (cur != ' ')
            {
                tmp+=cur;
            }
            else
            {
                args.emplace_back(tmp);
                tmp = "";
            }
        }
        args.emplace_back(tmp);
        // read file content, and put into bas
        for (int i = 1; i < args.size(); ++i)
        {
            string file_raw = args[i];
            string file_name = "";
            string file_content = "";
            int j = 0;
            for (j=0; j < file_raw.size(); ++j)
            {
                char cur = file_raw[j];
                if (cur != '(')
                {
                    file_name+=cur;
                }
                else break;
            }
            file_content = file_raw.substr(j);
            bas[file_content].emplace_back(args[0]+"/"+file_name);
        }
    }
};