/**
    694. Number of Distinct Islands
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.

Example 1:
Input: grid = 
[[1,1,0,0,0],
 [1,1,0,0,0],
 [0,0,0,1,1],
 [0,0,0,1,1]]
Output: 1

Example 2:
Input: grid = 
[[1,1,0,1,1],
 [1,0,0,0,0],
 [0,0,0,0,1],
 [1,1,0,1,1]]
Output: 3

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

Algo: calc hash
find islands: O(N^2) and calc hash -> string("DURL") D - down, U - up, L - left, R - right
compare islands to each other:
	O(N^2)
*/

class Solution {
	using Island = string;
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<Island> islands;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    Island island;
                    checkIsland(grid, i, j, island, 0);
                    islands.insert(move(island));
                }
            }
        }
		return islands.size();
    }
    
private:
    void checkIsland(vector<vector<int>>& grid, int i, int j, Island& island, int cnt) {
        grid[i][j] = 0;
        if (j > 0 && grid[i][j-1] != 0) {
            island += to_string(cnt);
            island += 'L';
            checkIsland(grid, i, j-1, island, cnt+1);
        }
        if (j+1 < grid[0].size() && grid[i][j+1] != 0) {
            island += to_string(cnt);
            island += 'R';
            checkIsland(grid, i, j+1, island, cnt+1);
        }
        if (i > 0 && grid[i-1][j] != 0) {
            island += to_string(cnt);
            island += 'U';
            checkIsland(grid, i-1, j, island, cnt+1);
        }
        if (i+1 < grid.size() && grid[i+1][j] != 0) {
            island += to_string(cnt);
            island += 'D';
            checkIsland(grid, i+1, j, island, cnt+1);
        }
    }
};




