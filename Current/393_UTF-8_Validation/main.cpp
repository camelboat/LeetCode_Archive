#include <iostream>
#include <string>
#include <vector>

using namespace std;

//// 96.00%, 75.00%
//// c++ binary comparison
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remain_bytes = 0;
        for (auto &intval: data){
            if (remain_bytes == 0)
            {
                if (intval >> 5 == 0b110) remain_bytes = 1;
                else if (intval >> 4 == 0b1110) remain_bytes = 2;
                else if (intval >> 3 == 0b11110) remain_bytes = 3;
                else if (intval >> 7 != 0b0) return false;
            }
            else
            {
                if (intval >> 6 != 0b10) return false;
                remain_bytes--;
            }
        }
        return remain_bytes == 0;
    }
};

//// 5.26%, 87.50%
//// convert int to bin string
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remain_bytes = 0;
        for (auto &intval: data){
            string tmp = dec2bin(intval);
            cout << "tmp = " << tmp << '\n';
            if (remain_bytes != 0)
            {
                if (!(tmp[0] == '1' && tmp[1] == '0')) return false;
                remain_bytes--;
            }
            else if (tmp[0] != '0')
            {
                int num1 = 0;
                while (num1 < 8)
                {
                    if (tmp[num1]=='0') break;
                    num1++;
                }
                if (num1 <= 1 || num1 > 4) return false;
                remain_bytes = num1-1;
            }
        }
        return remain_bytes <= 0;
    }

    static string dec2bin(int data)
    {
        string ans;
        int dig = 0;
        while (dig < 8 && data >= 0)
        {
            ans.insert(0, to_string(data % 2));
            data = data / 2;
            dig++;
        }
        if (dig < 8)
        {
            int comp = 8 - dig;
            ans.insert(0, comp, '0');
        }
        return ans;
    }
};