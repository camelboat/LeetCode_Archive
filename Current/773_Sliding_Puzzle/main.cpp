#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//// 7.2%, 16.67%
//// bfs, can optimize by turning vector<vector<int>> board into string
class Solution {
private:
    vector<vector<int>> move_step{{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> final_state{{1,2,3},{4,5,0}};
    map<vector<vector<int>>, int> visited; // <board, level>

    vector<pair<vector<int>, vector<vector<int>>>> find_next_states(pair<vector<int>, vector<vector<int>>> &val)
    {
        vector<pair<vector<int>, vector<vector<int>>>> res;
        for (auto & step: move_step)
        {
            vector<int> next_position{val.first[0] + step[0], val.first[1] + step[1]};
            if (next_position[0] >= 0 && next_position[0] <= 1 && next_position[1] >= 0 && next_position[1] <= 2)
            {
                vector<vector<int>> tmp_state = val.second;
                int tmp = val.second[next_position[0]][next_position[1]];
                tmp_state[next_position[0]][next_position[1]] = 0;
                tmp_state[val.first[0]][val.first[1]] = tmp;
                res.emplace_back(make_pair(next_position, tmp_state));
            }
        }
        return res;
    }

    static void print_board(vector<vector<int>> &board)
    {
        cout << board[0][0] << " " << board[0][1] << " " << board[0][2] << '\n';
        cout << board[1][0] << " " << board[1][1] << " " << board[1][2] << "\n\n";
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> position_0 = vector<int>(2,0);
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 0)
                {
                    position_0[0] = i; position_0[1] = j;
                }
            }
        }
        // cout << "initial position at " << position_0[0] << " " << position_0[1] << '\n';
        queue<pair<vector<int>, vector<vector<int>>>> bas;
        bas.push(make_pair(position_0, board));
        visited[board] = 0;
        while (!bas.empty())
        {
            pair<vector<int>, vector<vector<int>>> cur = bas.front();
            bas.pop();
//            print_board(cur.second);
            if (cur.second == final_state) return visited[cur.second];
            if (visited[cur.second] > 18) return -1;
            vector<pair<vector<int>, vector<vector<int>>>> next_states = find_next_states(cur);
            for (auto &next_state : next_states)
            {
                if (visited.find(next_state.second) == visited.end())
                {
                    bas.emplace(next_state);
                    visited[next_state.second] = visited[cur.second]+1;
                }
            }
        }
        return -1;
    }
};

int main() {
//    vector<vector<int>> test_board = {{1,2,3},{4,0,5}};
    vector<vector<int>> test_board = {{3,2,4},{1,5,0}};
//    vector<vector<int>> test_board = {{4,1,2},{5,0,3}};
//    vector<vector<int>> test_board = {{1,2,3},{5,4,0}};
    Solution test;
    cout << test.slidingPuzzle(test_board);
    return 0;
}
