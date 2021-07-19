/**
    994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = 
[[2,1,1],
 [1,1,0],
 [0,1,1]]
Output: 4

Example 2:
Input: grid = 
[[2,1,1],
 [0,1,1],
 [1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

Algo1: bf: O(N^4)
ch = 0
- go through table
	if find 1 and it has 2 in neighbour: 
		set 1->3
		ch += 1
- go throught table:
	3->2
if ch == 0: break;
return if 1not in table ? step : inf

Algo2: graph bfs
make distance table with inf in every cell

Algo3: graph bfs
start from every [2] and count lvl
end_lvl is result
and check for 1s in table

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
		int step = 0;
		do {
			cnt = rotten(grid);
			++step;
		} while (cnt);
		return isAllRotten(grid) ? step-1 : -1;
    }
	
private:
	int rotten(vector<vector<int>>& grid) {
		int cnt = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1 && hasNeighbour(grid, i, j)) {
					grid[i][j] = 3;
					++cnt;
				}
			}
		}
		if (cnt == 0) return cnt;
		int cnt2 = cnt;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 3) {
					grid[i][j] = 2;
					--cnt2;
					if (cnt2 == 0) break;
				}
			}
			if (cnt2 == 0) break;
		}
		return cnt;
	}
	
	bool hasNeighbour(const vector<vector<int>>& grid, int i, int j) {
		if (i > 0 && grid[i-1][j] == 2) return true;
		if (i+1 < grid.size() && grid[i+1][j] == 2) return true;
		if (j > 0 && grid[i][j-1] == 2) return true;
		if (j+1 < grid[0].size() && grid[i][j+1] == 2) return true;
		return false;
	}
	
	bool isAllRotten(const vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) return false;
			}
		}
		return true;
	}
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto dist_table = makeDistanceTable(grid);
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 2) {
					dist_table[i][j] = 0;
					bfs(grid, i, j, dist_table);
				} else if (grid[i][j] == 0) {
					dist_table[i][j] = 0;
				}
			}
		}
		return findMaxDist(dist_table);
    }
	
private:
	vector<vector<int>> makeDistanceTable(const vector<vector<int>>& grid) {
		vector<vector<int>> table(grid.size(), vector<int>(grid[0].size(), INT_MAX));
		return table;
	}
	
	void bfs(const vector<vector<int>>& grid, int si, int sj, vector<vector<int>>& dist_table) {
		queue<tuple<int, int, int>> q;
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
		q.emplace(si, sj, 0);
		while (!q.empty()) {
			auto [i, j, dst] = q.front();
			q.pop();
			if (visited[i][j]) continue;
			visited[i][j] = true;
			if (grid[i][j] == 1 && dst < dist_table[i][j]) {
    			dist_table[i][j] = dst;
			} else if (grid[i][j] == 1) {
			    continue;
			}
			if (i > 0 && grid[i-1][j] == 1 && !visited[i-1][j]) 
			    q.emplace(i-1, j, dst+1);
			if (i+1 < grid.size() && grid[i+1][j] == 1 && !visited[i+1][j]) 
			    q.emplace(i+1, j, dst+1);
			if (j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) 
			    q.emplace(i, j-1, dst+1);
			if (j+1 < grid[0].size() && grid[i][j+1] == 1 && !visited[i][j+1]) 
			    q.emplace(i, j+1, dst+1);
		}
	}
	
	int findMaxDist(const vector<vector<int>>& dist_table) {
	    int max_dist = 0;
	    for (int i = 0; i < dist_table.size(); ++i) {
			for (int j = 0; j < dist_table[0].size(); ++j) {
			    if (dist_table[i][j] == INT_MAX) return -1;
			    max_dist = max(max_dist, dist_table[i][j]);
			}
		}
		return max_dist;
	}
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int max_lvl = bfs(grid);
        for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) return -1;
			}
		}
		return max_lvl;
    }
	
private:
	int bfs(vector<vector<int>>& grid) {
		queue<tuple<int, int, int>> q;
		int max_lvl = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 2) {
				    grid[i][j] = 1;
				    q.emplace(i, j, 0);
				}
			}
		}
		while (!q.empty()) {
			auto [i, j, lvl] = q.front();
			q.pop();
			if (grid[i][j] != 1) continue;
			grid[i][j] = 2;
			max_lvl = max(max_lvl, lvl);
			if (i > 0 && grid[i-1][j] == 1) 
			    q.emplace(i-1, j, lvl+1);
			if (i+1 < grid.size() && grid[i+1][j] == 1) 
			    q.emplace(i+1, j, lvl+1);
			if (j > 0 && grid[i][j-1] == 1) 
			    q.emplace(i, j-1, lvl+1);
			if (j+1 < grid[0].size() && grid[i][j+1] == 1) 
			    q.emplace(i, j+1, lvl+1);
		}
		return max_lvl;
	}
};