#include <iostream>
#include <vector>

using namespace std;

//// 27.59%, 7.14%
//// Orz...
//// You are supposed to implement a hash function and then use some kinds of container to store
//// the key - value pair
class MyHashMap {
private:
    vector<int> bas;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        bas = vector<int>(1000000, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        bas[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return bas[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        bas[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap* obj = new MyHashMap();
    int key = 2;
    int value = 2;
    obj->put(key,value);
    int param_2 = obj->get(key);
    obj->remove(key);
    return 0;
}
