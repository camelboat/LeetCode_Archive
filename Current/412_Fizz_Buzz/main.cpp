//// 96.9%, 93.3%
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer(n,"");
        for (int i = 0; i < n; ++i) answer[i] = to_string(i+1);
        for (int i = 2; i < n; i+=3) answer[i] = "Fizz";
        for (int i = 4; i < n; i+=5) answer[i] = "Buzz";
        for (int i = 14; i < n; i+=15) answer[i] = "FizzBuzz";
        return answer;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int i = 1; i <= n; ++i)
        {
            answer.emplace_back(getNumber(i));
        }
        return answer;
    }
    
    string getNumber(int &n)
    {
        if (n%15 == 0) return "FizzBuzz";
        if (n%3 == 0) return "Fizz";
        if (n%5 == 0) return "Buzz";
        return to_string(n);
    }  
};
