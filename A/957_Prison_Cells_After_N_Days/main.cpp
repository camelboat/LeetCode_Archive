#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

//// 89.57%, 64.29%
//// simulation
//// only 256 states, quickly fall into the loop,
//// so register the loop pattern
class Solution {
private:
    unordered_map<int, int> bas; // state, appear date
    int cells_size;
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int state = cal_state(cells);
        cells_size = cells.size();
        while (N > 0)
        {
            if (bas.find(state) != bas.end())
            {
                N %= bas[state] - N;
            }
            bas[state] = N;
            
            if (N >= 1)
            {
                N--;
                state = next_state(state);
            }
        }
        return back_vector(state);
    }
    
    int next_state(const int &state)
    {
        int ans = 0;
        for (int i = 1; i < cells_size-1; ++i)
        {
            if (((state >> (i-1)) & 1) == ((state >> (i+1)) & 1))
            {
                ans ^= 1 << i;
            }
        }
        return ans;
    }
    
    
    int cal_state(const vector<int>& cells)
    {
        int res = 0;
        for (auto &x: cells)
        {
            res <<= 1;
            res ^= x;
        }
        return res;
    }
    
    vector<int> back_vector(const int &state)
    {
        vector<int> res(cells_size, 0);
        for (int i = 0; i < cells_size; ++i)
        {
            res[cells_size-i-1] = (state >> i) & 1;
        }
        return res;
    }
};

