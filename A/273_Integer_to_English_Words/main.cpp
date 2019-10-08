#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string answer;
        answer = numberToWords_helper(num);
        int i = answer.size()-1;
        while (answer[i] == ' ') --i;
        return answer.substr(0, i+1);

    }

    string numberToWords_helper(int num)
    {
        if (num <= 19 && num >= 0) {return single_num(num);}
        else if (num <= 99 && num >= 20) {return twodigits_num(num/10) + numberToWords_helper(num % 10);}
        else if (num <= 999 && num >= 100)
        {
            return numberToWords_helper(num/100) + "Hundred " + numberToWords_helper(num % 100);
        }
        else if (num <= 999999 && num >= 1000)
        {
            return numberToWords_helper(num/1000) + "Thousand " + numberToWords_helper(num % 1000);
        }
        else if (num <= 999999999 && num >= 1000000)
        {
            return numberToWords_helper(num / 1000000) + "Million " + numberToWords_helper(num % 1000000);
        }
        else if (num <= 9999999999 && num >= 1000000000)
        {
            return numberToWords_helper(num / 1000000000) + "Billion " + numberToWords_helper(num % 1000000000);
        }
        return "-1";
    }

    string single_num(int num)
    {
        switch(num)
        {
            // case 0: return "Zero "; break;
            case 1: return "One "; break;
            case 2: return "Two "; break;
            case 3: return "Three "; break;
            case 4: return "Four "; break;
            case 5: return "Five "; break;
            case 6: return "Six "; break;
            case 7: return "Seven "; break;
            case 8: return "Eight "; break;
            case 9: return "Nine "; break;
            case 10: return "Ten "; break;
            case 11: return "Eleven "; break;
            case 12: return "Twelve "; break;
            case 13: return "Thirteen "; break;
            case 14: return "Fourteen "; break;
            case 15: return "Fifteen "; break;
            case 16: return "Sixteen "; break;
            case 17: return "Seventeen "; break;
            case 18: return "Eighteen "; break;
            case 19: return "Nineteen "; break;
            default: return "";
        }
    }

    string twodigits_num(int num)
    {
        switch(num)
        {
            case 2: return "Twenty "; break;
            case 3: return "Thirty "; break;
            case 4: return "Forty "; break;
            case 5: return "Fifty "; break;
            case 6: return "Sixty "; break;
            case 7: return "Seventy "; break;
            case 8: return "Eighty "; break;
            case 9: return "Ninety "; break;
            default: return "-1";
        }
    }
};