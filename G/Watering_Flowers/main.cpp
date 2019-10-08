#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int watering_flowers(vector<int> &plants, int capacity1, int capacity2)
    {
        int n = plants.size();
        int both;
        if (n % 2 == 0) both = n/2;
        else both = (n-1)/2;
        int cur1 = 0;
        int cur2 = 0;
        int res = 0;
        for (int i = 0; i < both; ++i)
        {
            if (cur1 < plants[i])
            {
                cur1 = capacity1;
                res++;
            }
            cur1-= plants[i];
            if (cur2 < plants[n-i])
            {
                cur2 = capacity2;
                res++;
            }
            cur2-=plants[i];
        }
        if (n%2 == 0) return res;
        else
        {
            if (cur1+cur2 < plants[both+1]) res++;
            return res;
        }
    }

};

int main()
{
    Solution test;
    vector<int> plants = {2,4,5,1,2};
    int capacity1 = 5;
    int capacity2 = 7;
    int answer = test.watering_flowers(plants, capacity1, capacity2);
    cout << answer << '\n';
    return 0;
}