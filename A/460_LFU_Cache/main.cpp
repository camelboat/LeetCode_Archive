#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
private:
    int min_fre;
    int cap;
    unordered_map<int, pair<int, int>> bas; // <key, <val, frequency>>
    unordered_map<int, list<int>> bas_fre; //< frequency, list of keys that have this frequency>
    unordered_map<int, list<int>::iterator> bas_fre_index; // <key, frequency iterator>

public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = bas.find(key);
        if (it == bas.end()) return -1;
        else
        {
            // remove the element from the frequency list
            bas_fre[bas[key].second].erase(bas_fre_index[key]);
            // increase the frequency
            ++bas[key].second;
            // push new frequency back to the frequency list
            bas_fre[bas[key].second].push_back(key);
            // update the frequency iterator
            bas_fre_index[key] = --bas_fre[bas[key].second].end();
            // update the min_fre if needed
            if (bas_fre[min_fre].size() == 0) ++min_fre;
            return bas[key].first;
        }
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        // if the key is already in the map,
        // update the value
        // its other status have been updated through get()
        if (get(key) != -1)
        {
            bas[key].first = value;
            return;
        }

        // if there is not space, eject one key
        if (bas.size() >= cap)
        {
            bas.erase(bas_fre[min_fre].front());
            bas_fre_index.erase(key);
            bas_fre[min_fre].pop_front();
        }

        // insert the new key
        bas[key] = make_pair(value, 1);
        bas_fre[1].push_back(key);
        bas_fre_index[key] = --bas_fre[1].end();
        min_fre = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */