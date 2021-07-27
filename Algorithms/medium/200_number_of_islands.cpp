/**
    200. Number of Islands
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.
    
Algo1: graph search linked components(dfs): O(n*m)

Algo2: floodfill: change to 0 using dfs: O(n*m)

Algo3: disjoint sets (union find)

*/

//Algo1
bool operator<(const pair<int,int>& lhs, const pair<int,int>& rhs) {
    return make_tuple(lhs.first, lhs.second) < make_tuple(rhs.first, rhs.second);
}

class Solution {
    using Matrix = vector<vector<char>>;
    using Node = pair<int, int>;
public:
    int numIslands(const vector<vector<char>>& grid) {
        size_t n = grid.size();
        if (n == 0) return 0;
        size_t m = grid[0].size();
        if (m == 0) return 0;
        set<Node> visited;
        int isl_count = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == '0' || visited.count(Node{i,j})) continue;
                dfs(i, j, grid, visited);
                ++isl_count;
            }
        }
        return isl_count;
    }
    
private:
    void dfs(size_t i, size_t j, const Matrix& grid, set<Node>& visited) {
        if (grid[i][j] == '0' || visited.count(Node{i,j})) return;
        visited.insert(Node{i,j});
        size_t n = grid.size();
        size_t m = grid[0].size();
        if (i > 0) {
            dfs(i-1, j, grid, visited);
        }
        if (i+1 < n) {
            dfs(i+1, j, grid, visited);
        }
        if (j > 0) {
            dfs(i, j-1, grid, visited);
        }
        if (j+1 < m) {
            dfs(i, j+1, grid, visited);
        }
    }
};

class Solution {
    using Matrix = vector<vector<char>>;
public:
    int numIslands(const vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        Matrix visited(n, vector<char>(m,0));
        int isl_count = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == '0' || visited[i][j] == 1) continue;
                dfs(i, j, grid, visited);
                ++isl_count;
            }
        }
        return isl_count;
    }
    
private:
    void dfs(size_t i, size_t j, const Matrix& grid, Matrix& visited) {
        if (grid[i][j] == '0' || visited[i][j] == 1) return;
        visited[i][j] = 1;
        if (i > 0) {
            dfs(i-1, j, grid, visited);
        }
        if (i+1 < n) {
            dfs(i+1, j, grid, visited);
        }
        if (j > 0) {
            dfs(i, j-1, grid, visited);
        }
        if (j+1 < m) {
            dfs(i, j+1, grid, visited);
        }
    }
    
    size_t n = 0;
    size_t m = 0;
};

// Algo2
class Solution {
    using Matrix = vector<vector<char>>;
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        int isl_count = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                dfs(i, j, grid);
                ++isl_count;
            }
        }
        return isl_count;
    }
    
private:
    void dfs(size_t i, size_t j, Matrix& grid) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        if (j+1 < m) dfs(i, j+1, grid);
        if (j > 0) dfs(i, j-1, grid);
        if (i+1 < n) dfs(i+1, j, grid);
        if (i > 0) dfs(i-1, j, grid);
    }
    
    size_t n = 0;
    size_t m = 0;
};

// union find
using Matrix = vector<vector<char>>;

struct UnionFind {
    UnionFind(const Matrix& grid) 
        : parent((grid.size()+1) * (grid[0].size()+1), -1), 
          rank((grid.size()+1) * (grid[0].size()+1))
    {
        int m = (int)grid[0].size();
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == '1') {
                    parent[r*m + c] = r*m + c;
                    ++cnt;
                }
            }
        }
    }
    
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void unionSet(int i, int j) {
        int i_id = find(i);
        int j_id = find(j);
        if (i_id == j_id) return;
        if (rank[i_id] >= rank[j_id]) {
            parent[j_id] = i_id;
            if (rank[i_id] == rank[j_id]) {
                ++rank[i_id];
            }
        } else {
            parent[i_id] = j_id;
        }
        --cnt;
    }

    vector<int> parent;
    vector<int> rank;
    int cnt = 0;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        UnionFind uf(grid);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (grid[i][j] == '0') continue;
                grid[i][j] = '0';
                if (i > 0 && grid[i-1][j] == '1') uf.unionSet(lineIdx(i, j), lineIdx(i-1, j));
                if (i+1 < n && grid[i+1][j] == '1') uf.unionSet(lineIdx(i, j), lineIdx(i+1, j));
                if (j > 0 && grid[i][j-1] == '1') uf.unionSet(lineIdx(i, j), lineIdx(i, j-1));
                if (j+1 < m && grid[i][j+1] == '1') uf.unionSet(lineIdx(i, j), lineIdx(i, j+1));
            }
        }
        return uf.cnt;
    }
    
private:
    int lineIdx(int r, int c) const {
        return r*m + c;
    }
    
    size_t n = 0;
    size_t m = 0;
};
