#include <iostream>

using namespace std;

//// 65.74%, 61.96%
//// Linked list
class HitCounter {
private:
    struct data_node {
        int timestamp;
        data_node* next;
    };
    data_node *head;
    data_node *tail;
    int cur_time;
    int ans;

public:
    /** Initialize your data structure here. */
    HitCounter() {
        head = nullptr;
        tail = nullptr;
        ans = 0;
        cur_time = 0;
    }

    void Update() {
        cout << "update at " << cur_time << '\n';
        while (head != nullptr && head->timestamp <= cur_time - 300) {
            data_node* tmp = head;
            ans--;
            head = head -> next;
            delete tmp;
        }
        if (head == nullptr) tail = nullptr;
    }


    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        cout << "hit at " << timestamp << '\n';
        if (tail == nullptr) {
            tail = new data_node {timestamp, nullptr};
            head = tail;
            ans++;
        } else {
            data_node* next_node = new data_node{timestamp, nullptr};
            tail->next = next_node;
            tail = tail->next;
            ans++;
        }
        cur_time = timestamp;
        Update();
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        cout << "getHits at" << timestamp << '\n';
        cur_time = timestamp;
        Update();
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

int main() {
    HitCounter test;
    test.hit(2);
    test.hit(3);
    test.hit(4);
    cout << test.getHits(300) << '\n';
    cout << test.getHits(301) << '\n';
    cout << test.getHits(302) << '\n';
    cout << test.getHits(303) << '\n';
    cout << test.getHits(304) << '\n';
    test.hit(501);
    cout << test.getHits(600) << '\n';
    return 0;
}
