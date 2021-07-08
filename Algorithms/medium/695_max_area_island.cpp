/**
    695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = 
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

Algo: dfs(worse) or floodfill(better)

*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    floodfill(grid, i, j, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
    
private: 
    void floodfill(vector<vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || j < 0 || i+1 > grid.size() || j+1 > grid[0].size() 
            || grid[i][j] == 0) return;
        grid[i][j] = 0;
        ++area;
        floodfill(grid, i-1, j, area);
        floodfill(grid, i+1, j, area);
        floodfill(grid, i, j-1, area);
        floodfill(grid, i, j+1, area);
    }
};