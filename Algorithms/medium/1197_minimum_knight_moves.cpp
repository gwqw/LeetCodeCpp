/**
    1197. Minimum Knight Moves
In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.

Example 1:
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]

Example 2:
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]

Constraints:
|x| + |y| <= 300

Algo: bfs in N-tree

*/

struct PairHash {
    size_t operator()(pair<int, int> value) const {
        return value.first + value.second * x;
    }
    int x = 37;
    static constexpr int P = 1e9+7;
};

class Solution {
    using Node = pair<int, int>;
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        vector<pair<int, int>> shifts{
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, 
        };
        unordered_set<Node, PairHash> visited(1000, PairHash{});
        queue<pair<Node, int>> q;
        q.emplace(Node{x, y}, 0);
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (node.first == 0 && node.second == 0) return lvl;
            visited.insert(node);
            for (auto shift : shifts) {
                Node new_node = Node{node.first + shift.first, node.second + shift.second};
                if (!visited.count(new_node)) {
                    q.emplace(new_node, lvl+1);
                }
            }
        }
        return -1;
    }
};

class Solution {
    using Node = pair<int, int>;
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        vector<pair<int, int>> shifts{
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, 
        };
        vector<vector<bool>> visited(600, vector<bool>(600, false));
        queue<pair<Node, int>> q;
        q.emplace(Node{x, y}, 0);
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (node.first == 0 && node.second == 0) return lvl;
            visited[node.first+300][node.second+300] = true;
            for (auto shift : shifts) {
                Node new_node = Node{node.first + shift.first, node.second + shift.second};
                if (!visited[new_node.first+300][new_node.second+300]) {
                    q.emplace(new_node, lvl+1);
                }
            }
        }
        return -1;
    }
};
class Solution {
    using Node = pair<int, int>;
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        x = abs(x);
        y = abs(y);
        vector<pair<int, int>> shifts{
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, 
        };
        vector<vector<bool>> visited(600, vector<bool>(600, false));
        queue<pair<Node, int>> q;
        q.emplace(Node{0, 0}, 0);
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (node.first == x && node.second == y) return lvl;
            visited[node.first+300][node.second+300] = true;
            for (auto shift : shifts) {
                Node new_node = Node{node.first + shift.first, node.second + shift.second};
                if (!visited[new_node.first+300][new_node.second+300]) {
                    q.emplace(new_node, lvl+1);
                }
            }
        }
        return -1;
    }
};

class Solution {
    using Node = pair<int, int>;
    static constexpr int MAX_CAP = 310;
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        x = abs(x);
        y = abs(y);
        vector<pair<int, int>> shifts{
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, 
        };
        vector<vector<int>> visited(2*MAX_CAP, vector<int>(2*MAX_CAP, 0));
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited[0][0] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int lvl = visited[node.first+MAX_CAP][node.second+MAX_CAP];
            if (node.first == x && node.second == y) return lvl;
            for (auto shift : shifts) {
                Node new_node = Node{node.first + shift.first, node.second + shift.second};
                if (!visited[new_node.first+MAX_CAP][new_node.second+MAX_CAP]) {
                    q.push(new_node);
                    visited[new_node.first+MAX_CAP][new_node.second+MAX_CAP] = lvl+1;
                }
            }
        }
        return -1;
    }
};