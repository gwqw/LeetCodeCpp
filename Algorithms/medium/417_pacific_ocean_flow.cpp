/**
    417. Pacific Atlantic Water Flow
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:
Input: heights = 
[[1,2,2,3,5],
 [3,2,3,4,4],
 [2,4,5,3,1],
 [6,7,1,4,5],
 [5,1,1,2,4]]
Output: 
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = 
[[2,1],
 [1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]

Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5

Algo: floodfill from edges
colors: 0 not filled, 1 -pacific, 2 - atlantic, 3 - both
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(const vector<vector<int>>& h) {
        vector<vector<int>> color(h.size(), vector<int>(h[0].size()));
        // fill pacific
        for (size_t j = 0; j < h[0].size(); ++j) {
            floodfillPacific(h, color, 0, j);
        }
        for (size_t i = 1; i < h.size(); ++i) {
            floodfillPacific(h, color, i, 0);
        }
        
        // fill atlantic
        for (size_t j = 0; j < h[0].size(); ++j) {
            floodfillAtlantic(h, color, h.size()-1, j);
        }
        for (size_t i = 0; i+1 < h.size(); ++i) {
            floodfillAtlantic(h, color, i, h[0].size()-1);
        }
        // count 3
        vector<vector<int>> res;
        for (int i = 0; i < color.size(); ++i) {
            for (int j = 0; j < color[0].size(); ++j) {
                if (color[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    
private:
    void floodfillPacific(const vector<vector<int>>& h, vector<vector<int>>& color, 
        int i, int j) 
    {
        if (color[i][j] == 1 || color[i][j] == 3) return;
        color[i][j] = color[i][j]+1;
        if (i > 0 && h[i][j] <= h[i-1][j]) floodfillPacific(h, color, i-1, j);
        if (i+1 < h.size() && h[i][j] <= h[i+1][j]) floodfillPacific(h, color, i+1, j);
        if (j > 0 && h[i][j] <= h[i][j-1]) floodfillPacific(h, color, i, j-1);
        if (j+1 < h[0].size() && h[i][j] <= h[i][j+1]) floodfillPacific(h, color, i, j+1);
    }
    
    void floodfillAtlantic(const vector<vector<int>>& h, vector<vector<int>>& color, 
        int i, int j) 
    {
        if (color[i][j] == 2 || color[i][j] == 3) return;
        color[i][j] = color[i][j]+2;
        if (i > 0 && h[i][j] <= h[i-1][j]) floodfillAtlantic(h, color, i-1, j);
        if (i+1 < h.size() && h[i][j] <= h[i+1][j]) floodfillAtlantic(h, color, i+1, j);
        if (j > 0 && h[i][j] <= h[i][j-1]) floodfillAtlantic(h, color, i, j-1);
        if (j+1 < h[0].size() && h[i][j] <= h[i][j+1]) floodfillAtlantic(h, color, i, j+1);
    }
    
    void printMatrix(const vector<vector<int>>& color) {
        for (int i = 0; i < color.size(); ++i) {
            for (int j = 0; j < color[0].size(); ++j) {
                cout << color[i][j] << " ";
            }
            cout << '\n';
        }
    }
};