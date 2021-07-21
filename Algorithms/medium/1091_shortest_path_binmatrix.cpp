/**
    1091. Shortest Path in Binary Matrix
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
- All the visited cells of the path are 0.
- All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

Algo: bfs in graph + floodfill tle. O(N) N -- number of cells, O(N) mem

Algo2: same but paste lvl in grid

Algo3: 2-directional bfs

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;
        const array<pair<int, int>, 8> shifts = 
            {pair{-1,-1}, pair{-1,0}, pair{-1,1},
             pair{0,-1},          pair{0,1},
             pair{1,-1},  pair{1,0},  pair{1,1},
            };
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 1);
        while (!q.empty()) {
            auto [r,c,lvl] = q.front();
            q.pop();
            if (r+1 == n && c+1 == m) return lvl;
            grid[r][c] = 1;
            for (auto [rs,cs] : shifts) {
                if (0 <= r + rs && r + rs < n &&
                    0 <= c + cs && c + cs < m &&
                    grid[r+rs][c+cs] == 0
                    )
                {
                    q.emplace(r+rs, c+cs, lvl+1);                
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;
        const array<pair<int, int>, 8> shifts = 
            {pair{-1,-1}, pair{-1,0}, pair{-1,1},
             pair{0,-1},          pair{0,1},
             pair{1,-1},  pair{1,0},  pair{1,1},
            };
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 1;
        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            int dst = grid[r][c];
            if (r+1 == n && c+1 == m) return dst;
            for (auto [rs,cs] : shifts) {
                if (0 <= r + rs && r + rs < n &&
                    0 <= c + cs && c + cs < m &&
                    grid[r+rs][c+cs] == 0
                    )
                {
                    q.emplace(r+rs, c+cs);                
                    grid[r+rs][c+cs] = dst+1;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;
        const array<pair<int, int>, 8> shifts = 
            {pair{-1,-1}, pair{-1,0}, pair{-1,1},
             pair{0,-1},          pair{0,1},
             pair{1,-1},  pair{1,0},  pair{1,1},
            };
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        if (n == 1 && m == 1) return 1;
        queue<pair<int, int>> qfrom;
        qfrom.emplace(0, 0);
        grid[0][0] = 1;
        queue<pair<int, int>> qto;
        qto.emplace(n-1, m-1);
        grid[n-1][m-1] = -1;
        while (!qfrom.empty() && !qto.empty()) {
            {
                auto [r,c] = qfrom.front();
                qfrom.pop();
                int dst = grid[r][c];
                for (auto [rs,cs] : shifts) {
                    if (0 <= r + rs && r + rs < n &&
                        0 <= c + cs && c + cs < m)
                    {
                        if (grid[r+rs][c+cs] == 0) {
                            qfrom.emplace(r+rs, c+cs);                
                            grid[r+rs][c+cs] = dst+1;
                        } else if (grid[r+rs][c+cs] < 0) {
                            return dst - grid[r+rs][c+cs];
                        }
                    }
                }
            }
            {
                auto [r,c] = qto.front();
                qto.pop();
                int dst = grid[r][c];
                for (auto [rs,cs] : shifts) {
                    if (0 <= r + rs && r + rs < n &&
                        0 <= c + cs && c + cs < m)
                    {
                        if (grid[r+rs][c+cs] == 0) {
                            qto.emplace(r+rs, c+cs);                
                            grid[r+rs][c+cs] = dst-1;
                        } else if (grid[r+rs][c+cs] > 1) {
                            return grid[r+rs][c+cs] - dst;
                        }
                    }
                }
            }
        }
        return -1;
    }
};