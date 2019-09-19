#include <iostream>
#include <vector>

using namespace std;

//// define dp[i][j] to be true if s[0..i) mataches p[0..j), and false otherwise
//// 1. dp[i][j] = dp[i-1][j-1] if single match(. or any other character)
//// 2. dp[i][j] = dp[i][j-2] if p[j-1] is '*' and matches for 0 time
//// 3. dp[i][j] = dp[i-1][j] if p[j-1] == '*' and single match

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j-1] != '*')
                {
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
                else
                {
                    dp[i][j] = dp[i][j-2] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }
        return dp[m][n];
    }
};

//// below is naive solution

//class Solution {
//public:
//
//    struct pair_t
//    {
//        // type 1 .
//        // type 2 . *
//        // type 3 one character
//        // type 4 one character *
//        int type;
//        char character = '@';
//    };
//
//    bool isMatch(string s, string p) {
//        int s_start = 0;
//        int p_start = 0;
//        s = s+'#';
//        bool pass_flag = false;
//
////        while (p_start < p.size())
////        {
////            pair_t pair_str = p_parsing(p, p_start);
////            cout << "type: " << pair_str.type << endl;
////            cout << "character: " << pair_str.character << endl;
////        }
//
//        while (s_start < s.size() && p_start < p.size())
//        {
//            pair_t pair = p_parsing(p, p_start);
//            if (!single_pair(s, p, s_start, pair))
//            {
//                return false;
//            }
//            s_start++;
//        }
//        return true;
//    }
//
//    // return if from start of s can pair p
//    // move start to the next pair location if true
//    bool single_pair(string &s, string &p, int &s_start, pair_t pair)
//    {
//        if (pair.type == 1)
//        {
//            s_start++;
//            return true;
//        }
//        else if (pair.type == 2)
//        {
//            char start = s[s_start];
//            while (s[s_start])
//            {
//                s_start++;
//            }
//            return true;
//        }
//        else if (pair.type == 3)
//        {
//            if (s[s_start] == pair.character)
//            {
//                s_start++;
//                return true;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        else if (pair.type == 4)
//        {
//            if (s[s_start] == pair.character)
//            {
//                char start = pair.character;
//                while (s[s_start] == )
//            }
//        }
//        return true;
//    }
//
//    pair_t p_parsing(string &p, int &p_start)
//    {
//        pair_t pair_profile = {};
//        if (p_start == p.size()-1)
//        {
//            if (p[p_start] >= 'a' && p[p_start+1] <= 'z')
//            {
//                pair_profile.type = 3;
//                pair_profile.character = p[p_start];
//            }
//            else if (p[p_start] == '.')
//            {
//                pair_profile.type = 1;
//                pair_profile.character = '.';
//            }
//            p_start++;
//            return pair_profile;
//        }
//
//        if (p[p_start] == '.')
//        {
//            if (p[p_start+1] == '*')
//            {
//                pair_profile.type = 2;
//                pair_profile.character = '.';
//                p_start++;
//            }
//            else
//            {
//                pair_profile.type = 1;
//                pair_profile.character = '.';
//            }
//            p_start++;
//        }
//        else
//        {
//            if (p[p_start+1] == '*')
//            {
//                pair_profile.type = 4;
//                pair_profile.character = p[p_start];
//                p_start++;
//            } else{
//                pair_profile.type = 3;
//                pair_profile.character = p[p_start];
//            }
//            p_start++;
//        }
//        return pair_profile;
//    }
//};