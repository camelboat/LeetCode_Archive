#include<iostream>
#include<unordered_set>
#include<vector>
#include<stack>

using namespace std;

//// 10.45%, 8.33%
class Solution {
private:
    unordered_set<string> unique_answer;
    
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answer;
        string current = "";
        
        // calculate the minimum number
        stack<char> bas;
        int min_remove = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                bas.push('(');
            }
            else if (s[i] == ')')
            {
                if (bas.empty()) min_remove++;
                else bas.pop();
            }
        }
        min_remove+=bas.size();
        cout << "min_remove = " << min_remove << '\n';
        int left = s.size()-min_remove;
        helper(s, 0, 0, 0, current, answer, left, 0);
        return answer;
    }
    
    void helper(string s, int leftcount, int rightcount, int cur, string current, vector<string> &answer, int &left, int removedCount)
    {
        if ((abs(rightcount - leftcount)) > s.size()-cur) return;
        if (removedCount > s.size()-left) return;
        if (cur == s.size())
        {
            if (rightcount == leftcount && current.size() == left && unique_answer.find(current) == unique_answer.end())
            {
                unique_answer.insert(current);
                answer.emplace_back(current);    
            }
            return;
        }
        char tmp = s[cur];
        if (tmp == ')')
        {
            helper(s, leftcount, rightcount, cur+1, current, answer, left, removedCount+1);
            rightcount++;
            if (rightcount > leftcount) return;
            current+=')';
            helper(s, leftcount, rightcount, cur+1, current, answer, left, removedCount);
        }
        else if (tmp == '(')
        {
            helper(s, leftcount, rightcount, cur+1, current, answer, left, removedCount+1);
            leftcount++;
            current+='(';
            helper(s, leftcount, rightcount, cur+1, current, answer, left, removedCount);
        }
        else{
            current+=tmp;
            helper(s, leftcount, rightcount, cur+1, current, answer, left, removedCount);
        }
        return;
    }
    
};
