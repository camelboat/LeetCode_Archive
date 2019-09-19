#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//// simple operator reconstruction
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return cal_distance(a) < cal_distance(b);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), compare);
        points.resize(K);
        return points;
    }

    static double cal_distance(vector<int> &point)
    {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
};

//// redundant priority_dequeue
class Solution {
public:

    struct priority_compare
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return cal_distance(a) > cal_distance(b);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, priority_compare> bas;

        for (int i = 0; i < points.size(); ++i)
        {
            bas.push(points[i]);
        }

        vector<vector<int>> answer;
        for (int i = 0; i < K; ++i)
        {
            answer.emplace_back(bas.top());
            bas.pop();
        }
        return answer;

    }

    static double cal_distance(vector<int> &point)
    {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
};