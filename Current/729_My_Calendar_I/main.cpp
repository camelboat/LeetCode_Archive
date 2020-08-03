#include <iostream>

using namespace std;

//// 98.26%, 65.85%
//// using balance tree to store the calendar
class MyCalendar {
private:
    struct Tree {
        int start;
        int end;
        Tree* left;
        Tree* right;
        Tree(int new_start, int new_end) : start(new_start), end(new_end), left(nullptr), right(nullptr) {}
    };

    bool insertTree(int start, int end, Tree* root) {
        if (start >= root->end) {
            if (root->right == nullptr) {
                root->right = new Tree(start, end);
                return true;
            }
            return insertTree(start, end, root->right);
        } else if (end <= root->start) {
            if (root->left == nullptr) {
                root->left = new Tree(start, end);
                return true;
            }
            return insertTree(start, end, root->left);
        } return false;
    }

    Tree* calendar;

public:
    MyCalendar() {
        calendar = nullptr;
    }

    bool book(int start, int end) {
        if (calendar == nullptr) {
            calendar = new Tree(start, end);
            return true;
        } else {
            return insertTree(start, end, calendar);
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


int main() {
    MyCalendar test;
    cout << test.book(10, 20) << '\n';
    cout << test.book(15, 25) << '\n';
    cout << test.book(20, 30) << '\n';
    return 0;
}
