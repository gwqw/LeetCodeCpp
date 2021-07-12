/**
    1466. Reorder Routes to Make All Paths Lead to the City Zero
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
It's guaranteed that each city can reach city 0 after reorder.

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

Constraints:
2 <= n <= 5 * 10^4
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi

Algo: graph and dfs
*/

class Solution {
public:
    int minReorder(int n, const vector<vector<int>>& connections) {
        vector<unordered_set<int>> edges(n);
        vector<vector<int>> graph(n);
        for (const auto& con : connections) {
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
            edges[con[0]].insert(con[1]);
        }
        vector<char> visited(n);
        visited[0] = 1;
        int cnt = 0;
        dfs(graph, 0, visited, edges, cnt);
        return cnt;
    }
    
private:
    void dfs(const vector<vector<int>>& graph, int start, vector<char>& visited,  const vector<unordered_set<int>>& edges, int& cnt) {
        for (int node : graph[start]) {
            if (visited[node]) continue;
            if (!edges[node].count(start)) {
                ++cnt;
            }
            visited[node] = true;
            dfs(graph, node, visited, edges, cnt);
        }
    }
};