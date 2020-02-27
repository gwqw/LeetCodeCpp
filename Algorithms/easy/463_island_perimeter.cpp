/**
    463. Island Perimeter
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island 
(i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Example:
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

Algo: O(N2), O(1)
- go through cells
    if cell:
        - add 4 - neighb
        
algo: calc boarders
- calc horizontal borders
- calc vertical border
- calc left, right, up and down borders
        
Algo: O(IslCells) + O(IslCells)
- find first cell (!=0)
- check its perimeter: 4 - neigh
- recursive go to its neigh 
*/

class Solution {
public:
    int islandPerimeter(const vector<vector<int>>& grid) {
        size_t row_count = grid.size();
        if (row_count == 0) return 0;
        size_t col_count = grid[0].size();
        int perimeter = 0;
        for (size_t i = 0; i < row_count; ++i) {
            for (size_t j = 0; j < col_count; ++j) {
                if (grid[i][j]) {
                    perimeter += 4 - getNeigh(grid, i, j);
                }
            }
        }
        return perimeter;
    }
private:
    int getNeigh(const vector<vector<int>>& grid, size_t r, size_t c) {
        int neigh = 0;
        if (r > 0 && grid[r-1][c]) {
            ++neigh;
        }
        if (r+1 < grid.size() && grid[r+1][c]) {
            ++neigh;
        }
        if (c > 0 && grid[r][c-1]) {
            ++neigh;
        }
        if (c+1 < grid[0].size() && grid[r][c+1]) {
            ++neigh;
        }
        return neigh;
    }
};
