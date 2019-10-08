#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static bool is_larger(string A, string B)
    {
        int size_a = A.size();
        int size_b = B.size();
        int len = size_a < size_b ? size_a : size_b;
        for (int i = 0; i < len; ++i)
        {
            if (A[i] != B[i]) return A[i] < B[i];
        }
        return size_a > len;
    }
public:
    vector<string> read_string(string A)
    {
        vector<string> res;
        for (int i = 0; i < A.size(); ++i)
        {
            string tmp;
            while (A[i] != ' ' && i < A.size())
            {
                tmp+=A[i];
                ++i;
            }
            res.emplace_back(tmp);
        }
        return res;
    }

    vector<int> compare_strings(string A, string B)
    {
        vector<string> vector_A = read_string(A);
        vector<string> vector_B = read_string(B);
        return compare_strings_helper(vector_A, vector_B);
    }

    vector<int> compare_strings_helper(vector<string> A, vector<string> B)
    {
        vector<int> answer(B.size(), 0);
        for (const auto & i : A)
        {
            for (int j = 0; j < B.size(); ++j)
            {
                if (is_larger(B[j], i)) answer[j]++;
            }
        }
        return answer;
    }
};

int main()
{
    Solution test;
//    vector<string> A = {"abcd", "aabc", "bd"};
//    vector<string> B = {"aaa", "aa"};
    string A = "abcd aabc bd";
    string B = "aaa aa";
    vector<int> answer = test.compare_strings(A, B);
    for (auto &x: answer) cout << x << " ";
    return 0;
}