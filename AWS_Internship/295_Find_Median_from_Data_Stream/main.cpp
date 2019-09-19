#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<>> bas_small;
    priority_queue<int, vector<int>, greater<>> bas_large;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (bas_small.empty() && bas_large.empty()) bas_small.push(num);
        else if (num <= bas_large.top()) bas_small.push(num);
        else if (num > bas_large.top()) bas_large.push(num);
        if (bas_small.size() > bas_large.size())
        {
            int tmp = bas_small.top();
            bas_small.pop();
            bas_large.push(tmp);
        }
        else if (bas_large.size() > bas_small.size())
        {
            int tmp = bas_large.top();
            bas_large.pop();
            bas_small.push(tmp);
        }
    }

    double findMedian() {
        int m = bas_small.size();
        int n = bas_large.size();
        if (m == n) return (double)(bas_small.top() + bas_large.top())/2;
        if (m == n+1) return bas_small.top();
        if (n == m+1) return bas_large.top();
        return -1;
    }

    void print_heaps()
    {
        cout << "left max = " << bas_small.top() << '\n';
        cout << "right min = " << bas_large.top() << '\n';
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */