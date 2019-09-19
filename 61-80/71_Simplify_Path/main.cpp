#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> bas;
        int i = 0;
        int n = path.size();
        while (i < n)
        {
            if (path[i] == '/')
            {
                ++i;
                while (path[i] == '/') ++i; // remove redundant slash

                string tmp = "";            // read letters
                if (i == n) break;
                while (i < n && path[i] != '/') { tmp+=path[i]; ++i; }

                // push valid address into bas
                if (tmp.compare(".") == 0 || tmp.empty()) continue;
                else if (tmp.compare("..") == 0)
                {
                    if (!bas.empty()) bas.pop();
                    else continue;
                }
                else (bas.push(tmp));
            }
        }

        // output
        string answer = "";
        if (bas.empty()) return "/";
        while (!bas.empty())
        {
            answer = bas.top() + answer;
            bas.pop();
            answer = '/' + answer;
        }
        return answer;
    }
};

