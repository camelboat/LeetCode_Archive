#include <iostream>
#include <map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    map<int, int> index_bas; // first = value, second = index in val_bas
    vector<int> val_bas;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(NULL);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index_bas.find(val) == index_bas.end())
        {
            val_bas.push_back(val);
            index_bas.insert(make_pair(val, val_bas.size()-1));
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index_bas.find(val) != index_bas.end())
        {
            int index = index_bas[val];
            //// swap the element we want to delete with the last element
            //// update the swapped element's index in index_bas
            int last = val_bas.back();
            swap(val_bas[index], val_bas.back());
            val_bas.pop_back();
            index_bas[last] = index;
            index_bas.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        string answer;
        int random_val;
        // random_val = rand()/((RAND_MAX + 1u)/val_bas.size());
        random_val = rand()%val_bas.size();
        return val_bas[random_val];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */