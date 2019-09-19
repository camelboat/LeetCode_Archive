#include <iostream>
#include <string>

using namespace std;

//// my solution
 0 to 3999
class Solution {




public:

//    string intToRoman(int num) {
//        string M[] = {"", "M", "MM", "MMM"};//0,1000,2000,3000
//        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};//0,100,200,300...
//        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};//0,10,20,30...
//        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};//0,1,2,3...
//        return M[num/1000] + C[(num%1000)/100]+ X[(num%100)/10] + I[num%10];
//    }

    string intToRoman(int num) {
        return help_function(num);
    }

    string help_function(int num)
    {
        if (num >= 1000)
        {
            int first_dig = num / 1000;
            switch (first_dig)
            {
                case 3: return "MMM" + help_function(num % 1000);
                case 2: return "MM" + help_function(num % 1000);
                case 1: return "M" + help_function(num % 1000);
            }
        }
        else if (100 <= num && num < 1000)
        {
            int first_dig = num / 100;
            switch (first_dig)
            {
                case 9: return "CM" + help_function(num % 100); break;
                case 8: return "DCCC" + help_function(num % 100); break;
                case 7: return "DCC" + help_function(num % 100); break;
                case 6: return "DC" + help_function(num % 100); break;
                case 5: return "D" + help_function(num % 100); break;
                case 4: return "CD" + help_function(num % 100); break;
                case 3: return "CCC" + help_function(num % 100); break;
                case 2: return "CC" + help_function(num % 100); break;
                case 1: return "C" + help_function(num % 100); break;
            }
        }
        else if (10 <= num && num < 100)
        {
            int first_dig = num / 10;
            switch (first_dig)
            {
                case 9: return "XC" + help_function(num % 10); break;
                case 8: return "LXXX" + help_function(num % 10); break;
                case 7: return "LXX" + help_function(num % 10); break;
                case 6: return "LX" + help_function(num % 10); break;
                case 5: return "L" + help_function(num % 10); break;
                case 4: return "XL" + help_function(num % 10); break;
                case 3: return "XXX" + help_function(num % 10); break;
                case 2: return "XX" + help_function(num % 10); break;
                case 1: return "X" + help_function(num % 10); break;
            }
        }
        else if (0 <= num && num < 10)
        {
            switch (num)
            {
                case 9: return "IX"; break;
                case 8: return "VIII"; break;
                case 7: return "VII"; break;
                case 6: return "VI"; break;
                case 5: return "V"; break;
                case 4: return "IV"; break;
                case 3: return "III"; break;
                case 2: return "II"; break;
                case 1: return "I"; break;
                case 0: return ""; break;
            }
        }
        return "-1";
    }
};