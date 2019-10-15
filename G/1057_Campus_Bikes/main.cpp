#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


//// 91.21%, 100.00%
class Solution {
private:
    static int cal_man(vector<int> &a, vector<int> &b)
    {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    //// no need to sort
    static bool choice_compare(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first != b.first) return a.first < b.first;
        else return a.second < b.second;
    }

public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // pair<worker_ind, bike_ind>
        vector<vector<pair<int, int>>> bucket(2001, vector<pair<int, int>>());
        int worker_num = workers.size();
        int bike_num = bikes.size();
        vector<bool> bike_ind(bike_num, false);
        vector<int> answer(workers.size(), -1);
        for (int i = 0; i < workers.size(); ++i)
        {
            for (int j = 0; j < bikes.size(); ++j)
            {
                int dis = cal_man(workers[i], bikes[j]);
                bucket[dis].emplace_back(make_pair(i, j));
            }
        }
        int count = 0;
        for (int i = 0; i < 2001; ++i)
        {
            //// no need to sort since you read in sequence
            // sort(bucket[i].begin(), bucket[i].end(), choice_compare);
            for (int j =  0; j < bucket[i].size(); ++j)
            {
                pair<int, int> cur = bucket[i][j];
                if (answer[cur.first] == -1 && !bike_ind[cur.second])
                {
                    bike_ind[cur.second] = true;
                    answer[cur.first] = cur.second;
                    count++;
                    if (count == worker_num) return answer;
                }
            }
        }
        return answer;
    }
};

//// 5.00%, 50.00%
class Solution {
private:
    static int cal_man(vector<int> &a, vector<int> &b)
    {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    static bool choice_compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0]) return a[0] < b[0];
        if (a[1] != b[1]) return a[1] < b[1];
        else return a[2] < b[2];
    }

public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // 0: Manhattan distance, 1: worker_ind, 2: bike_ind
        vector<vector<int>> bas;
        set<int> worker_ind;
        set<int> bike_ind;
        vector<int> answer(workers.size(), 0);
        for (int i = 0; i < workers.size(); ++i)
        {
            for (int j = 0; j < bikes.size(); ++j)
            {
                vector<int> tmp(3, 0);
                tmp[0] = cal_man(workers[i], bikes[j]);
                tmp[1] = i;
                tmp[2] = j;
                bas.emplace_back(tmp);
            }
        }
        sort(bas.begin(), bas.end(), choice_compare);

        int count = 0;
        int cur = 0;
        while (count < workers.size())
        {
            if (worker_ind.find(bas[cur][1]) == worker_ind.end() && bike_ind.find(bas[cur][2]) == bike_ind.end())
            {
                worker_ind.insert(bas[cur][1]);
                bike_ind.insert(bas[cur][2]);
                answer[bas[cur][1]] = bas[cur][2];
                ++count;
            }
            ++cur;
        }
        return answer;
    }
};

//// time limit exceeded
class Solution {
private:
    static int cal_man(vector<int> &a)
    {
        return abs(a[0]-a[2]) + abs(a[1]-a[3]);
    }

    static bool choice_compare(vector<int> &pair_a, vector<int> &pair_b)
    {
        int man_a = cal_man(pair_a);
        int man_b = cal_man(pair_b);
        if (man_a != man_b) return man_a < man_b;
        else
        {
            if (pair_a[4] != pair_b[4]) return pair_a[4] < pair_b[4];
            if (pair_a[5] != pair_b[5]) return pair_a[5] < pair_b[5];
        }
        return true;
    }

public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // 0,1: worker_loc, 2,3: bike_loc, 4: worker_ind, 5: bike_ind
        vector<vector<int>> bas;
        set<int> worker_ind;
        set<int> bike_ind;
        vector<int> answer(workers.size(), 0);
        for (int i = 0; i < workers.size(); ++i)
        {
            for (int j = 0; j < bikes.size(); ++j)
            {
                vector<int> tmp = workers[i];
                tmp.emplace_back(bikes[j][0]);
                tmp.emplace_back(bikes[j][1]);
                tmp.emplace_back(i);
                tmp.emplace_back(j);
                bas.emplace_back(tmp);
            }
        }
        sort(bas.begin(), bas.end(), choice_compare);

        int count = 0;
        int cur = 0;
        while (count < workers.size())
        {
            if (worker_ind.find(bas[cur][4]) == worker_ind.end() && bike_ind.find(bas[cur][5]) == bike_ind.end())
            {
                worker_ind.insert(bas[cur][4]);
                bike_ind.insert(bas[cur][5]);
                answer[bas[cur][4]] = bas[cur][5];
                ++count;
            }
            ++cur;
        }
        return answer;
    }
};