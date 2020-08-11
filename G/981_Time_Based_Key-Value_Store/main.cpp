#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

//// 67.59%, 61.5%
//// Map+binary search(upper_bound), use vector to store <timestamp, val>.
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> dict;
    static bool my_compare(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;
    }

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        dict[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (dict.find(key) == dict.end()) return "";
        auto it = upper_bound(dict[key].begin(), dict[key].end(), make_pair(timestamp, ""), my_compare);
        if (it == dict[key].begin()) return "";
        return prev(it,1)->second;
    }
};

//// you should realize that the timestamp will only increase
//// so that you don't need to sort the vector by yourself
class TimeMap {
private:
    // <string, priority_queue<pair<value, timestamp>>
    unordered_map<string, vector<pair<string, int>>> bas;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (bas.find(key) == bas.end())
        {
            vector<pair<string,int>> tmp;
            tmp.emplace_back(make_pair(value, timestamp));
            bas[key] = tmp;
        }
        else bas[key].emplace_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {
        if (bas.find(key) == bas.end()) return "";
        else
        {
            if (bas[key][0].second > timestamp) return "";
            int index = -1;
            for (int i = bas[key].size()-1; i >= 0; --i)
            {
                if (bas[key][i].second <= timestamp)
                {
                    index = i; break;
                }
            }
            return bas[key][index].first;
        }
    }
};

//// two maps, a little faster, but time complexity is still O(N)
class TimeMap {
private:

    // <string, priority_queue<pair<value, timestamp>>
    unordered_map<string, unordered_map<int, string>> bas;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (bas.find(key) == bas.end())
        {
            unordered_map<int, string> tmp;
            tmp.insert(make_pair(timestamp, value));
            bas[key] = tmp;
        }
        else bas[key].insert(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (bas.find(key) == bas.end()) return "";
        else
        {
            for (int i = timestamp; i >= 0; --i)
            {
                if (bas[key].find(i) != bas[key].end()) return bas[key][i];
            }
            return "";
        }
    }
};


//// priority_queue, very slow
class TimeMap {
private:
    struct time_compare
    {
        bool operator()(pair<string, int> a, pair<string, int> b)
        {
            return a.second < b.second;
        }
    };

    // <string, priority_queue<pair<value, timestamp>>
    unordered_map<string, priority_queue<pair<string,int>, vector<pair<string, int>>, time_compare>> bas;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (bas.find(key) == bas.end())
        {
            priority_queue<pair<string,int>, vector<pair<string, int>>, time_compare> tmp;
            tmp.emplace(make_pair(value, timestamp));
            bas[key] = tmp;
        }
        else bas[key].emplace(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {
        if (bas.find(key) ==bas.end())
        {
            return "";
        }
        else
        {
            vector<pair<string,int>> tmp;
            while (!bas[key].empty() && bas[key].top().second > timestamp)
            {
                tmp.emplace_back(bas[key].top());
                bas[key].pop();
            }
            if (!bas[key].empty())
            {
                string res = bas[key].top().first;
                for (int i = 0; i < tmp.size(); ++i) bas[key].emplace(tmp[i]);
                return res;
            }
            else
            {
                for (int i = 0; i < tmp.size(); ++i) bas[key].emplace(tmp[i]);
                return "";
            }
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */