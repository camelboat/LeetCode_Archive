#include <iostream>
#include <vector>

using namespace std;

//// 97.19%, 72.73%
//// dfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int answer = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; ++i)
        {
            if (visited[i] == 0)
            {
                dfs(M, visited, i);
                answer++;
            }
        }
        return answer;
    }

    static void dfs(vector<vector<int>>& M, vector<int>& visited, int i)
    {
        for (int j = 0; j < M.size(); ++j)
        {
            if (M[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
};