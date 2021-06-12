/**
    356. Line Reflection
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points symmetrically, in other words, answer whether or not if there exists a line that after reflecting all points over the given line the set of the original points is the same that the reflected ones.

Note that there can be repeated points.

Follow up:
Could you do better than O(n2) ?

Example 1:
Input: points = [[1,1],[-1,1]]
Output: true
Explanation: We can choose the line x = 0.

Example 2:
Input: points = [[1,1],[-1,-1]]
Output: false
Explanation: We can't choose a line.

Constraints:
n == points.length
1 <= n <= 10^4
-10^8 <= points[i][j] <= 10^8

Algo1: 2 pointers: O(NlogN), O(N)
- split point at d[y] -> array of x (v)
- for v in d:
    - sort v O(NlogN)
    - remove non-unique
    - check for reflection O(N) and calc d = (max + min) / 2
    - if false: return false O(1)
- return true

Algo2: same but use set instead of sort
*/

class Solution {
public:
    bool isReflected(const vector<vector<int>>& points) {
        // split
        unordered_map<int, vector<int>> dict;
        int minx = INT_MAX;
        int maxx = INT_MIN;
        for (const auto& p : points) {
            int x = p[0];
            int y = p[1];
            dict[y].push_back(x);
            minx = min(minx, x);
            maxx = max(maxx, x);
        }
        int d = minx + maxx;

        // check for each line
        for (auto& [_, v] : dict) {
            if (!checkReflected(v, d)) return false;
        }
        return true;
    }
    
private:
    bool checkReflected(vector<int>& line, int d0) {
        sort(line.begin(), line.end());
        line.erase(unique(line.begin(), line.end()), line.end());
        
        if (line.size() == 1) return 2*line[0] == d0;
        for (size_t i = 0; i < line.size() / 2; ++i) {
            int d = line[i] + line[line.size()-i-1];
            if (d != d0) return false;
        }
        if (line.size() % 2 == 1) {
            if (2*line[line.size() / 2] != d0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isReflected(const vector<vector<int>>& points) {
        // split
        unordered_map<int, unordered_set<int>> dict;
        int minx = INT_MAX;
        int maxx = INT_MIN;
        for (const auto& p : points) {
            int x = p[0];
            int y = p[1];
            dict[y].insert(x);
            minx = min(minx, x);
            maxx = max(maxx, x);
        }
        int d = minx + maxx;

        // check for each line
        for (const auto& [_, v] : dict) {
            if (!checkReflected(v, d)) return false;
        }
        return true;
    }
    
private:
    bool checkReflected(const unordered_set<int>& line, int d0) {
        for (int x : line) {
            if (x == d0) continue;
            int xp = d0 - x;
            if (!line.count(xp)) return false;
        }
        return true;
    }
};