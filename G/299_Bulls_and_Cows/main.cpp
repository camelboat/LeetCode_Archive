#include<iostream>
#include<unordered_map>

using namespace std;

//// 94.14%, 53.85%
class Solution {
private:
    unordered_map<char, int> bas;
    
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.size(); ++i)
        {
            if (bas.find(secret[i]) == bas.end()) bas.insert(make_pair(secret[i], 1));
            else bas[secret[i]]++;
        }
        for (int i = 0; i < guess.size(); ++i)
        {
            if (guess[i] == secret[i]) 
            {
                bull++;
                bas[secret[i]]--;
            }           
        }
        for (int i = 0; i < guess.size(); ++i)
        {
            if (guess[i] != secret[i] && bas.find(guess[i]) != bas.end() && bas[guess[i]] > 0)
            {
                bas[guess[i]]--;
                cow++;
            }            
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
}; 
