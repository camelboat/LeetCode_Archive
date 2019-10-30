#include<map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> bas;
        unordered_set<char> foo;
        for (int i = 0; i < s.size(); ++i)
        {
            if (bas.find(s[i]) == bas.end())
            {
                bas.insert(make_pair(s[i], t[i]));
                if (foo.find(t[i]) != foo.end()) return false;
                foo.insert(t[i]);
            }
            else
            {
                if (bas[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
}; 
