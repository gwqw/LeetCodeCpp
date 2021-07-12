/**
    447. Number of Boomerangs
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

Example 1:
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].

Example 2:
Input: points = [[1,1],[2,2],[3,3]]
Output: 2

Example 3:
Input: points = [[1,1]]
Output: 0

Constraints:
n == points.length
1 <= n <= 500
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.

Algo1: bf (tle)

Algo2: for each point make dict[distance]->cnt
for i in n:
    make dict[distance]->cnt (i != j)
    for cnt in dict:
        res += A_cnt^2 = n! / (n-2)! = n*(n-1)
*/

class Solution {
public:
    int numberOfBoomerangs(const vector<vector<int>>& points) {
        int n = (int)points.size();
        int cnt = 0;
        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i+1 < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                d[i][j] = calcDistance(points[i], points[j]);
            }
        }
        
        for (int i = 0; i+2 < n; ++i) {
            for (int j = i+1; j+1 < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (d[i][j] == d[i][k]) {
                        cnt += 2;
                    }
                    if (d[i][j] == d[j][k]) {
                        cnt += 2;
                    }
                    if (d[i][k] == d[j][k]) {
                        cnt += 2;
                    }
                }
            }
        }
        return cnt;
    }
    
private:
    int calcDistance(const vector<int>& lhs, const vector<int>& rhs) {
        int x = lhs[0] - rhs[0];
        int y = lhs[1] - rhs[1];
        return x*x + y*y;
    }
};

class Solution {
public:
    int numberOfBoomerangs(const vector<vector<int>>& points) {
        int n = (int)points.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> dist;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                ++dist[calcDistance(points[i], points[j])];
            }
            for (auto [_, c] : dist) {
                if (c < 2) continue;
                cnt += an2(c);
            }
        }
        return cnt;
    }
    
private:
    int calcDistance(const vector<int>& lhs, const vector<int>& rhs) {
        int x = lhs[0] - rhs[0];
        int y = lhs[1] - rhs[1];
        return x*x + y*y;
    }
    
    int an2(int n) {
        return n * (n-1);
    }
};

[[0,0],[1,0],[2,0]]
[[1,1],[2,2],[3,3]]
[[1,1]]
[[0,0],[1,0],[-1,0],[0,1],[0,-1]]