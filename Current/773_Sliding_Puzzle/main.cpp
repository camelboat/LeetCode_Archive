#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//// 83.56% , 100.00%
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string final_state = "123450";
        unordered_set<string> visited;
        vector<vector<int>> possible_step = {
                {1, 3},
                {0, 2, 4},
                {1, 5},
                {0, 4},
                {1, 3, 5},
                {2, 4}
        };
        string myboard;
        for (auto &row : board)
        {
            for (auto & x : row) myboard+=to_string(x);
        }
        int position_0 = 0;
        for (int i = 0; i < myboard.length(); ++i)
        {
            if (myboard[i] == '0')
            {
                position_0 = i; break;
            }
        }

        queue<tuple<int, string, int>> bas; // <position_0, board, level>
        bas.emplace(make_tuple(position_0, myboard, 0));
        visited.insert(myboard);

        int tmp_position_0;
        string tmp_board;
        int cur_level;

        while (!bas.empty())
        {
            tie(tmp_position_0, tmp_board, cur_level) = bas.front();
            bas.pop();
            if (tmp_board == final_state) return cur_level;
            for (auto & possible_position : possible_step[tmp_position_0])
            {
                swap(tmp_board[possible_position], tmp_board[tmp_position_0]);
                if (visited.find(tmp_board) == visited.end())
                {
                    bas.emplace(make_tuple(possible_position, tmp_board, cur_level+1));
                    visited.insert(tmp_board);
                }
                swap(tmp_board[possible_position], tmp_board[tmp_position_0]);
            }
        }
        return -1;
    }
};


//// 27.45%, 16.67%
//// convert to 1-d vector
//class Solution {
//private:
//    vector<int> final_state{1,2,3,4,5,0};
//    map<vector<int>, int> visited; // <board, level>
//    map<int, vector<int>> possible_step;
//
//public:
//    int slidingPuzzle(vector<vector<int>>& board) {
//        possible_step[0] = vector<int>{1,3};
//        possible_step[1] = vector<int>{0,2,4};
//        possible_step[2] = vector<int>{1,5};
//        possible_step[3] = vector<int>{0,4};
//        possible_step[4] = vector<int>{1,3,5};
//        possible_step[5] = vector<int>{2,4};
//
//        vector<int> myboard;
//        for (auto &row : board)
//        {
//            for (auto & x : row)
//            {
//                myboard.emplace_back(x);
//            }
//        }
//        int position_0 = 0;
//        for (int i = 0; i < 6; ++i)
//        {
//            if (myboard[i] == 0)
//            {
//                position_0 = i; break;
//            }
//        }
//
//        queue<pair<int, vector<int>>> bas;
//        bas.push(make_pair(position_0, myboard));
//        visited[myboard] = 0;
//        while (!bas.empty())
//        {
//            pair<int, vector<int>> cur = bas.front();
//            bas.pop();
//            if (cur.second == final_state) return visited[cur.second];
//            vector<pair<int, vector<int>>> next_states;
//            for (auto & possible_position : possible_step[cur.first])
//            {
//                vector<int> tmp = cur.second;
//                swap(tmp[possible_position], tmp[cur.first]);
//                next_states.emplace_back(make_pair(possible_position, tmp));
//            }
//
//            for (auto &next_state : next_states)
//            {
//                if (visited.find(next_state.second) == visited.end())
//                {
//                    bas.emplace(next_state);
//                    visited[next_state.second] = visited[cur.second]+1;
//                }
//            }
//        }
//        return -1;
//    }
//};

//// 7.2%, 16.67%
//// bfs, can optimize by turning vector<vector<int>> board into string (or just one-dimensional vector)
//class Solution {
//private:
//    vector<vector<int>> move_step{{0,1},{1,0},{0,-1},{-1,0}};
//    vector<vector<int>> final_state{{1,2,3},{4,5,0}};
//    map<vector<vector<int>>, int> visited; // <board, level>
//    map<vector<int>, vector<vector<int>>> possible_step;
//
//    vector<pair<vector<int>, vector<vector<int>>>> find_next_states(pair<vector<int>, vector<vector<int>>> &val)
//    {
//        vector<pair<vector<int>, vector<vector<int>>>> res;
//        for (auto & next_position : possible_step[val.first])
//        {
//            vector<vector<int>> tmp_state = val.second;
//            int tmp = val.second[next_position[0]][next_position[1]];
//            tmp_state[next_position[0]][next_position[1]] = 0;
//            tmp_state[val.first[0]][val.first[1]] = tmp;
//            res.emplace_back(make_pair(next_position, tmp_state));
//        }
//        return res;
//    }
//
//    static void print_board(vector<vector<int>> &board)
//    {
//        cout << board[0][0] << " " << board[0][1] << " " << board[0][2] << '\n';
//        cout << board[1][0] << " " << board[1][1] << " " << board[1][2] << "\n\n";
//    }
//
//public:
//    int slidingPuzzle(vector<vector<int>>& board) {
//        vector<int> position_0 = vector<int>(2,0);
//        for (int i = 0; i < board.size(); ++i)
//        {
//            for (int j = 0; j < board[0].size(); ++j)
//            {
//                if (board[i][j] == 0)
//                {
//                    position_0[0] = i; position_0[1] = j;
//                }
//            }
//        }
//        // cout << "initial position at " << position_0[0] << " " << position_0[1] << '\n';
//
//        possible_step[{0,0}] = vector<vector<int>>{{0,1}, {1,0}};
//        possible_step[{0,1}] = vector<vector<int>>{{0,0}, {0,2}, {1,1}};
//        possible_step[{0,2}] = vector<vector<int>>{{0,1}, {1,2}};
//        possible_step[{1,0}] = vector<vector<int>>{{0,0}, {1,1}};
//        possible_step[{1,1}] = vector<vector<int>>{{0,1}, {1,0}, {1,2}};
//        possible_step[{1,2}] = vector<vector<int>>{{0,2}, {1,1}};
//
//        queue<pair<vector<int>, vector<vector<int>>>> bas;
//        bas.push(make_pair(position_0, board));
//        visited[board] = 0;
//        while (!bas.empty())
//        {
//            pair<vector<int>, vector<vector<int>>> cur = bas.front();
//            bas.pop();
////            print_board(cur.second);
//            if (cur.second == final_state) return visited[cur.second];
//            if (visited[cur.second] > 18) return -1;
//            vector<pair<vector<int>, vector<vector<int>>>> next_states = find_next_states(cur);
//            for (auto &next_state : next_states)
//            {
//                if (visited.find(next_state.second) == visited.end())
//                {
//                    bas.emplace(next_state);
//                    visited[next_state.second] = visited[cur.second]+1;
//                }
//            }
//        }
//        return -1;
//    }
//};

int main() {
    vector<vector<int>> test_board = {{1,2,3},{4,0,5}};
//    vector<vector<int>> test_board = {{3,2,4},{1,5,0}};
//    vector<vector<int>> test_board = {{4,1,2},{5,0,3}};
//    vector<vector<int>> test_board = {{1,2,3},{5,4,0}};
    Solution test;
    cout << test.slidingPuzzle(test_board);
    return 0;
}
