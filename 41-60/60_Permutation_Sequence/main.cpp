#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int answer_length_left = n;
        int index;
        vector<int> bas;
        for (int i = 1 ; i <= n ; ++i)
        {
            bas.emplace_back(i);
        }
        string answer;
        while (answer_length_left > 0)
        {
            int left_possible = factorial(answer_length_left-1);
            index = (k-1) / left_possible + 1;
            answer+=to_string(bas[index-1]);
            k-= (index-1) * left_possible;
            answer_length_left--;
            bas.erase(bas.begin()+index-1);
        }
        return answer;
    }


    int factorial(int n)
    {
        if (n == 0 || n == 1) return 1;
        return n * factorial(n-1);
    }
};