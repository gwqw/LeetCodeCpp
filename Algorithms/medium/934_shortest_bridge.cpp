/**
    934. Shortest Bridge
In a given 2D binary array grid, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

Example 1:
Input: grid = 
[[0,1],
[1,0]]
Output: 1

Example 2:
Input: grid = 
[[0,1,0],
 [0,0,0],
 [0,0,1]]
Output: 2

Example 3:
Input: grid = 
[[1,1,1,1,1],
 [1,0,0,0,1],
 [1,0,1,0,1],
 [1,0,0,0,1],
 [1,1,1,1,1]]
Output: 1

Constraints:
2 <= grid.length == grid[0].length <= 100
grid[i][j] == 0 or grid[i][j] == 1

Algo:
find 1 island and push all i,j to queue
start bfs from this queue
*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool is_found = false;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    is_found = true;
                    break;
                }
            }
            if (is_found) break;
        }
        int lvl = 0;
        while (!q.empty()) {
            queue<pair<int, int>> cq;
            while (!q.empty()) {
                auto [i,j] = q.front(); q.pop();
                if (grid[i][j] == 3) continue;
                if (grid[i][j] == 1) return lvl-1;
                grid[i][j] = 3;
                if (j > 0 && grid[i][j-1] != 3) cq.emplace(i, j-1);
                if (j+1 < grid[0].size() && grid[i][j+1] != 3) cq.emplace(i, j+1);
                if (i > 0 && grid[i-1][j] != 3) cq.emplace(i-1, j);
                if (i+1 < grid.size() && grid[i+1][j] != 3) cq.emplace(i+1, j);
            }
            q = move(cq);
            ++lvl;
        }
        return lvl;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || 
            grid[i][j] != 1) return;
        q.emplace(i, j);
        grid[i][j] = 2;
        dfs(grid, i, j-1, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i+1, j, q);
    }
};

[[3,3],
 [1,3]]
 
 0,0, 1,1
 lvl=1
 
1,0